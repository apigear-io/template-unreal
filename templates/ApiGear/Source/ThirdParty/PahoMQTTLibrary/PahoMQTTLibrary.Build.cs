// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

using System;
using System.Diagnostics;
using System.IO;
using UnrealBuildTool;

public class PahoMQTTLibrary : ModuleRules
{
	static readonly string PahoVersion = "v1.3.14";
	static readonly string PahoRepo = "https://github.com/eclipse-paho/paho.mqtt.c.git";

	public PahoMQTTLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
		bRequiresImplementModule = false;

		string CloneDir = Path.Combine(ModuleDirectory, "paho.mqtt.c");
		string SrcDir = Path.Combine(CloneDir, "src");
		string BuildDir = Path.Combine(ModuleDirectory, "build_" + Target.Platform.ToString());

		// paho.mqtt.c keeps the "-static" suffix on its static-library target on
		// Windows but strips it elsewhere, and the VS generator places artifacts
		// under a per-config subdirectory while make/ninja do not.
		string LibDir;
		string LibName;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			LibDir = Path.Combine(BuildDir, "src", "Release");
			LibName = "paho-mqtt3as-static.lib";
		}
		else
		{
			LibDir = Path.Combine(BuildDir, "src");
			LibName = "libpaho-mqtt3as.a";
		}

		EnsurePahoSource(CloneDir);
		EnsurePahoBuild(CloneDir, BuildDir, Target, Path.Combine(LibDir, LibName));

		PublicIncludePaths.Add(SrcDir);

		PublicDefinitions.AddRange(new string[] {
			"PAHO_MQTT_STATIC=1",
			"OPENSSL=1"
		});

		PublicAdditionalLibraries.Add(Path.Combine(LibDir, LibName));

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicSystemLibraries.AddRange(new string[] { "Ws2_32.lib", "Iphlpapi.lib", "Crypt32.lib", "Rpcrt4.lib" });
		}

		AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");
	}

	void EnsurePahoSource(string CloneDir)
	{
		if (Directory.Exists(Path.Combine(CloneDir, "src")))
		{
			return;
		}

		string LockFile = Path.Combine(ModuleDirectory, ".clone_lock");
		try
		{
			using (var fs = new FileStream(LockFile, FileMode.CreateNew, FileAccess.Write))
			{
				ClonePaho(CloneDir);
			}
		}
		catch (IOException)
		{
			int waited = 0;
			while (File.Exists(LockFile) && waited < 120000)
			{
				System.Threading.Thread.Sleep(1000);
				waited += 1000;
			}
			if (!Directory.Exists(Path.Combine(CloneDir, "src")))
			{
				throw new BuildException("Paho MQTT C source not found after waiting for parallel clone. " +
					"Ensure git is installed and " + PahoRepo + " is reachable.");
			}
		}
		finally
		{
			try { File.Delete(LockFile); } catch {}
		}
	}

	void EnsurePahoBuild(string CloneDir, string BuildDir, ReadOnlyTargetRules Target, string LibPath)
	{
		if (File.Exists(LibPath))
		{
			return;
		}

		Directory.CreateDirectory(BuildDir);

		string OpenSSLInfo = FindOpenSSLDir(Target);

		string CmakeArgs = string.Join(" ", new string[] {
			"-DCMAKE_BUILD_TYPE=Release",
			"-DCMAKE_POSITION_INDEPENDENT_CODE=ON",
			"-DPAHO_WITH_SSL=ON",
			"-DPAHO_BUILD_STATIC=ON",
			"-DPAHO_BUILD_SHARED=OFF",
			"-DPAHO_BUILD_SAMPLES=OFF",
			"-DPAHO_BUILD_DOCUMENTATION=OFF",
			"-DPAHO_ENABLE_TESTING=OFF",
			"-DPAHO_HIGH_PERFORMANCE=OFF"
		});

		if (!string.IsNullOrEmpty(OpenSSLInfo))
		{
			string[] Parts = OpenSSLInfo.Split(';');
			if (Parts.Length == 3)
			{
				CmakeArgs += " -DOPENSSL_ROOT_DIR=\"" + Parts[0] + "\"";
				CmakeArgs += " -DOPENSSL_INCLUDE_DIR=\"" + Parts[1] + "\"";

				if (Target.Platform == UnrealTargetPlatform.Win64)
				{
					// FindOpenSSL.cmake on MSVC uses find_library(LIB_EAY_*) /
					// find_library(SSL_EAY_*) and constructs OPENSSL_*_LIBRARY
					// from those. Pre-set the input cache vars so find_library
					// skips its own search (which only probes lib/VC/* layouts).
					string SslLib = Path.Combine(Parts[2], "libssl.lib");
					string CryptoLib = Path.Combine(Parts[2], "libcrypto.lib");
					CmakeArgs += " -DLIB_EAY_RELEASE=\"" + CryptoLib + "\"";
					CmakeArgs += " -DLIB_EAY_DEBUG=\"" + CryptoLib + "\"";
					CmakeArgs += " -DSSL_EAY_RELEASE=\"" + SslLib + "\"";
					CmakeArgs += " -DSSL_EAY_DEBUG=\"" + SslLib + "\"";
				}
				else
				{
					CmakeArgs += " -DOPENSSL_SSL_LIBRARY=\"" + Path.Combine(Parts[2], "libssl.a") + "\"";
					CmakeArgs += " -DOPENSSL_CRYPTO_LIBRARY=\"" + Path.Combine(Parts[2], "libcrypto.a") + "\"";
				}
			}
		}

		// Use cmake's pre-3.13 invocation form (positional source arg, run from
		// the build dir) so we work with the older cmake shipped on Ubuntu
		// 18.04-based UE containers as well as modern cmake.
		CmakeArgs += " \"" + CloneDir + "\"";
		RunCommand("cmake", CmakeArgs, "CMake configure", BuildDir);

		// '--parallel' was added in cmake 3.12; older cmake (3.10 on Ubuntu 18.04)
		// rejects it. Use the legacy 'cmake --build <dir> -- <flag>' form which
		// passes the flag to the underlying build tool. Flag spelling differs:
		// MSBuild (the Visual Studio generator backend on Windows) takes /m:N,
		// while make and ninja take -j N.
		int NumCores = Environment.ProcessorCount;
		string ParallelFlag = (Target.Platform == UnrealTargetPlatform.Win64)
			? "/m:" + NumCores
			: "-j " + NumCores;
		RunCommand("cmake", "--build \"" + BuildDir + "\" --config Release -- " + ParallelFlag, "CMake build");
	}

	string FindOpenSSLDir(ReadOnlyTargetRules Target)
	{
		string EngineDir = Path.GetFullPath(EngineDirectory);
		string OpenSSLBase = Path.Combine(EngineDir, "Source", "ThirdParty", "OpenSSL");

		if (!Directory.Exists(OpenSSLBase))
		{
			return "";
		}

		foreach (string VersionDir in Directory.GetDirectories(OpenSSLBase))
		{
			if (Target.Platform == UnrealTargetPlatform.Win64)
			{
				string IncludeDir = Path.Combine(VersionDir, "include", "Win64", "VS2015");
				string LibDir = Path.Combine(VersionDir, "lib", "Win64", "VS2015", "Release");
				if (Directory.Exists(IncludeDir) && Directory.Exists(LibDir))
				{
					return VersionDir + ";" + IncludeDir + ";" + LibDir;
				}
				continue;
			}

			// UE 5.x layout: include/Unix/openssl + lib/Unix/<triplet>/
			{
				string IncludeDir = Path.Combine(VersionDir, "include", "Unix");
				string LibDir = Path.Combine(VersionDir, "lib", "Unix", "x86_64-unknown-linux-gnu");
				if (Directory.Exists(IncludeDir) && Directory.Exists(LibDir))
				{
					return VersionDir + ";" + IncludeDir + ";" + LibDir;
				}
			}

			// UE 4.27 layout: include/Linux/<triplet>/openssl + lib/Linux/<triplet>/
			{
				string IncludeDir = Path.Combine(VersionDir, "include", "Linux", "x86_64-unknown-linux-gnu");
				string LibDir = Path.Combine(VersionDir, "lib", "Linux", "x86_64-unknown-linux-gnu");
				if (Directory.Exists(IncludeDir) && Directory.Exists(LibDir))
				{
					return VersionDir + ";" + IncludeDir + ";" + LibDir;
				}
			}
		}

		return "";
	}

	void ClonePaho(string CloneDir)
	{
		Console.WriteLine("PahoMQTTLibrary: cloning " + PahoRepo + " " + PahoVersion + " ...");
		RunCommand("git", "clone --depth 1 --branch " + PahoVersion + " " + PahoRepo + " \"" + CloneDir + "\"", "git clone");
	}

	void RunCommand(string Command, string Args, string Description, string WorkingDir = null)
	{
		Console.WriteLine("PahoMQTTLibrary: " + Description + " ...");

		var psi = new ProcessStartInfo(Command, Args)
		{
			UseShellExecute = false,
			RedirectStandardOutput = true,
			RedirectStandardError = true,
			CreateNoWindow = true,
			WorkingDirectory = WorkingDir ?? ""
		};

		// Drain stdout/stderr asynchronously. With redirection enabled, a
		// child that writes more than the OS pipe buffer (~4 KiB on Windows)
		// blocks until the parent reads, so a synchronous WaitForExit alone
		// deadlocks on noisy builds like paho's MSBuild output.
		var Stdout = new System.Text.StringBuilder();
		var Stderr = new System.Text.StringBuilder();
		Process p = new Process { StartInfo = psi };
		p.OutputDataReceived += (s, e) => { if (e.Data != null) lock (Stdout) Stdout.AppendLine(e.Data); };
		p.ErrorDataReceived  += (s, e) => { if (e.Data != null) lock (Stderr) Stderr.AppendLine(e.Data); };

		try
		{
			p.Start();
		}
		catch (System.ComponentModel.Win32Exception)
		{
			throw new BuildException("PahoMQTTLibrary: failed to start " + Command +
				". Ensure " + Command + " is installed and on PATH.");
		}
		p.BeginOutputReadLine();
		p.BeginErrorReadLine();

		const int TimeoutMs = 1800000;
		if (!p.WaitForExit(TimeoutMs))
		{
			try { p.Kill(); } catch {}
			throw new BuildException("PahoMQTTLibrary: " + Description + " timed out after " + (TimeoutMs / 1000) + " seconds.");
		}
		// Wait again with no timeout so the async output handlers flush.
		p.WaitForExit();

		if (p.ExitCode != 0)
		{
			throw new BuildException("PahoMQTTLibrary: " + Description + " failed (exit " + p.ExitCode + "):\n" +
				Stderr.ToString() + "\n" + Stdout.ToString());
		}
	}
}
