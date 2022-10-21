//go:build mage

package main

import (
	"log"

	"github.com/magefile/mage/sh"
)

const (
	goldenDir = "goldenmaster"
	tmpDir    = "tmp"
	apisDir   = "testbed-apis"
)

func must(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func gitClone(url, dir string) {
	must(sh.RunV("git", "clone", "--depth=1", url, dir))
}

func runDiff(dir1, dir2 string) {
	must(sh.RunV("git", "--no-pager", "diff", "--no-index", dir1, dir2))
}

func goInstall(pkg string) {
	must(sh.RunV("go", "install", pkg))
}
func genSol(sol string) {
	must(sh.RunV("apigear", "g", "sol", sol))
}

func rmDir(dir string) {
	must(sh.Rm(dir))
}

// Install installs the apigear cli and testbed-apis.
func Install() {
	goInstall("github.com/apigear-io/cli/cmd/apigear@latest")
}

// Master generates the golden master.
func Master() {
	rmDir(goldenDir)
	genSol("./apigear/goldenmaster.solution.yaml")
}

// Diff runs the generator and compares the output with the golden master.
func Diff() {
	genSol("./apigear/test.solution.yaml")
	runDiff(goldenDir, tmpDir)
}

// Clean removes all generated files.
func Clean() {
	rmDir(tmpDir)
	rmDir(apisDir)
}

func DiffOnly() {
	runDiff(goldenDir, tmpDir)
}

func GenTest() {
	rmDir(tmpDir)
	genSol("./apigear/test.solution.yaml")
}

// automatically format all goldenmaster files according to the clang-format
func FormatStyle() {
	must(sh.RunV("bash", "-c", "find goldenmaster/Plugins -type f -iname '*.h' -not -path '*ThirdParty*' -o -type f -iname '*.cpp' -not -path '*ThirdParty*' | xargs clang-format -i"))
}

// test whether the goldenmaster files are formatted according to the clang-format
func TestStyle() {
	must(sh.RunV("bash", "-c", "clang-format --version && find goldenmaster/Plugins -type f -iname '*.h' -not -path '*ThirdParty*' -o -type f -iname '*.cpp' -not -path '*ThirdParty*' | xargs clang-format --dry-run --Werror"))
}
