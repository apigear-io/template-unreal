---
sidebar_position: 2
---
import Figure from '@site/src/components/figure'
import QuickStartCommon from "@site/docs/_quickstart_common.md"

# Quick-Start

The Quick-Start guide explains how to, in few steps, get from an API to a functional *Unreal Engine* plugin.

<QuickStartCommon />

## 5. How to use the plugin

### Project folder structure

For the code generation we assume that both *ApiGear* files reside in an `apigear` subfolder next to the *Unreal Engine* project.
In this case the folder structure should look similar to this.
```bash
📦ue_docs_example_project
 ┣ 📂apigear
 ┃ ┣ 📜helloworld.solution.yaml
 ┃ ┗ 📜helloworld.module.yaml
 ┣ 📂ue_docs
 ┃ ┣ 📂Config
 ┃ ┣ 📂Content
 ┃ ┣ 📂Platforms
 # highlight-next-line
 ┃ ┣ 📂Plugins
 ┃ ┣ 📂Source
 ┃ ┗ 📜ue_docs.uproject
```
Using the the solution file from the previous paragraph the code will be generated in the `ue_docs/Plugins` folder.

The generated code can be used with *Blueprints* and *C++*. The following paragraphs show how this can be achieved.
Make sure to have the generated plugin code in your projects plugins directory as noted in the [previous section](#4-generate-code).

### Blueprint

Open your project in the Unreal Editor and choose a *Blueprint* where you want to use the interface.
In this *Blueprint* we first get the *GameInstance* subsystem of the type *Io World Hello*.
<Figure caption="Get subsystem in blueprint" src="/img/quick-start/quick-start-blueprint-get-subsystem.png" />

On this subsystem we can choose the *asynchronous say* function.
<Figure caption="Choose method on interface in blueprint" src="/img/quick-start/quick-start-blueprint-choose-method.png" />

The complete setup to say "Hello world" on begin play.
<Figure caption="Hello interface example in blueprint" src="/img/quick-start/quick-start-blueprint-complete.png" />

### C++ 

For any C++ module (e.g. your project's, or another plugin's) to have access to the generated interface, you must specify a dependency to it in the dependent module's `.Build.cs` file.  The name of the Unreal Engine module that is generated from each ApiGear module is a PascalCase transformation with punctuation removed.  `io.world`, for example, becomes `IoWorld`.

```cs showLineNumbers title="ue_docs.Build.cs"
PrivateDependencyModuleNames.AddRange(new string[] { "IoWorld" });
```

Afterwards, we can simply include the header files for the `api` interface, the `stub` implementation and use it.

```cpp showLineNumbers title="ue_docsGameModeBase.cpp"
#include "ue_docsGameModeBase.h"
#include "Implementation/IoWorldHello.h"
#include "Generated/api/IoWorld_data.h"
#include "Generated/api/IoWorldHelloInterface.h"

void Aue_docsGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName,Options, ErrorMessage);

	TScriptInterface<IIoWorldHelloInterface> HelloWorldObjPtr = GetGameInstance()->GetSubsystem<UIoWorldHello>();
	FIoWorldMessage MyMsg;
	MyMsg.content = FString("Hello world");
	HelloWorldObjPtr->Say(MyMsg, EIoWorldWhen::IWW_NOW);
}
```
