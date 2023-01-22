---
sidebar_position: 2
---
import Figure from '../figure'

# Quick-Start

The Quick-Start guide explains how to, in few steps, get from an API to a functional *Unreal Engine* plugin.

## 1. Install the code generator

Get [ApiGear Studio](https://github.com/apigear-io/studio-releases/releases) or [ApiGear CLI](https://github.com/apigear-io/cli-releases/releases). For more information check the [ApiGear documentation](https://docs.apigear.io/docs/start/install).

## 2. Get the template

There are several options to get the template. Installation via the *Studio* or the *CLI*. Alternatively it is possible to clone or to download it directly from github.

### Installation via ApiGear CLI

You can install the template with `apigear template install apigear-io/template-unreal`. And you can always check whether installation was successful via the `template list` command.
```bash
$ apigear template list
list of templates from registry and cache
name                       | installed | registry | url
apigear-io/template-unreal | false     | true     | https://github.com/apigear-io/template-unreal.git
...
# highlight-next-line
$ apigear template install apigear-io/template-unreal
$ apigear template list
list of templates from registry and cache
name                       | installed | registry | url
apigear-io/template-unreal | true      | true     | https://github.com/apigear-io/template-unreal.git
...
```
When using the *CLI* for installation only the highlighted line is imported.
### Installation via ApiGear Studio

From within the studio the installation is really simple.

1. Open an existing project or create an new one
2. Go to the `Templates` tab
3. Click `Install` on the `apigear-io/template-unreal` entry

<Figure caption="Install the unreal template" src="/img/quick-start/apigear-studio-install-unreal-template.png" />

### Clone from github

In case you want to check or modify the source code of the template, it is easier to clone or download the repository. The repository does not need to be part of the project, but can be stored anywhere on the computer.
```bash
$ git clone https://github.com/apigear-io/template-unreal.git
```

## 3. Set up an ApiGear project

For a project we need two files. Both should be in a folder called `apigear` next to each other.
* The solution file which specifies what `APIs` and which template to use for it.
* And at least one `API` module file.

Those files can be created manually or alternatively, one can also use the *Studio* to create a new project and modify the two example files.

### Solution file
Create a [solution](https://docs.apigear.io/docs/start/first_steps#create-a-solution) file.
The example below specifies
* the `helloworld.module.yaml` which contains the API in *line 8*
* the output directory in *line 9*
* the `apigear-ui/template-unreal` to be used in *line 10*. This can also be a path to a local copy of the template.
* enables the `stubs` feature of the template, a simple implementation in *line 13*.

```yaml title="helloworld.solution.yaml" showLineNumbers
schema: "apigear.solution/1.0"
name: ue_docs
version: "0.1"

layers:
  - name: ue_docs
    inputs:
      - helloworld.module.yaml
    output: ../ue_docs
    template: apigear-io/template-unreal
    force: true
    features:
      - stubs
```

### API module file
Use your favorite text editor to create the `helloworld.module.yaml` with the example content:

```yaml title="helloworld.module.yaml" showLineNumbers
schema: apigear.module/1.0
name: io.world
version: "1.0"

interfaces:
  - name: Hello
    properties:
      - { name: last, type: Message }
    operations:
      - name: say
        params:
          - { name: msg, type: Message }
          - { name: when, type: When }
        return:
          type: int
    signals:
      - name: justSaid
        params:
          - { name: msg, type: Message }
enums:
  - name: When
    members:
      - { name: Now, value: 0 }
      - { name: Soon, value: 1 }
      - { name: Never, value: 2 }
structs:
  - name: Message
    fields:
      - { name: content, type: string }
```

## 4. Generate code

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
### Generate via CLI

The following snippet shows how to generate code using the CLI.

```bash
$ apigear generate solution apigear/helloworld.solution.yaml 
17:52:20 INF generated 92 files in 30ms. (33 write, 0 skip, 59 copy) topic=gen
```
* `generate` tells the CLI that it should generate code
* `solution` specifies that we want to run a solution file
  

### Generate via Studio

1. Open the project
2. Go to the `Solutions` tab
3. Click `Run` on the `helloworld.solution.yaml` entry


<Figure caption="Generate code" src="/img/quick-start/apigear-studio-generate-code.png" />

## 5. How to use the plugin

The generated code can be used with *Blueprints* and *C++*. The following paragraphs show how this can be achieved.
Make sure to have the generated plugin code in your projects plugins directory as noted in the [previous section](#4-generate-code).
### Blueprint

Open your project in the Unreal Editor and choose a *Blueprint* where you want to use the interface.
In this *Blueprint* we first create an object of the type *Io World Hello*. This can then be  directly used or stored in a variable.
In the screenshot we use the *asynchronous say* function to say "Hello world".

<Figure caption="Hello interface blueprint" src="/img/quick-start/quick-start-blueprint.png" />

### C++ 

Since the generated interface is used outside of its own module, we have to add the module identifier to the list of dependency modules in the dependent module e.g. your project's or another plugin's module.
To do this, open the dependents module, e.g. `ue_docs.Build.cs`, and add *IoWorld* to the `PublicDependencyModuleNames`. *IoWorld* is the demo module's name in the example.
```cs showLineNumbers title="ue_docs.Build.cs"
PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "IoWorld" });
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

	// Note: UObjects should be referenced from an Unreal type or property, otherwise they might be removed by garbage collection
	IIoWorldHelloInterface* HelloWorldObjPtr = NewObject<UIoWorldHello>();
	FIoWorldMessage MyMsg;
	MyMsg.content = FString("Hello world");
	HelloWorldObjPtr->Say(MyMsg, EIoWorldWhen::NOW);
}
```
:::caution
UObjects should be referenced from an Unreal type or property, otherwise they might be removed by garbage collection.
For more information check the [object handling documentation](https://docs.unrealengine.com/unreal-object-handling-in-unreal-engine/#garbagecollection).
:::
