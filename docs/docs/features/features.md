---
sidebar_position: 2
sidebar_label: "Features"
title: "Unreal Engine Template Features Overview"
description: "Overview of ApiGear Unreal Engine template features: Core API generation, stub implementations, OLink networking, Message Bus IPC, and runtime monitoring."
keywords: [unreal engine features, olink, message bus, stubs, monitor, api generation]
---

import CodeBlock from '@theme/CodeBlock';
import helloWorldModuleComponent from '!!raw-loader!./data/helloworld.module.yaml';

# Features

This guide explains how to use the generated code, what features are available, and their benefits.

:::info
A feature is a part of the template that generates a specific aspect of the code. For example, the `api` feature generates the core API interfaces.
:::

## Get started

This template generates Unreal Engine plugins from your API definitions. The generated code integrates seamlessly with both Blueprints and C++.

:::note
Basic Unreal Engine knowledge is recommended. Familiarity with Unreal's plugin system, Blueprints, and C++ module structure will help you get the most out of the generated code.
:::

### Code generation

Follow the documentation for [code generation](/docs/guide/quick-start) in general and [CLI](/docs/cli/generate) or the [Studio](/docs/studio/intro) tools.
Or try first the [quick start guide](../quickstart/index.md) which shows how to prepare an API and generate code from it.

:::tip
For questions regarding the template please go to our [discussions page](https://github.com/orgs/apigear-io/discussions). For feature requests or bug reports please use our [issue tracker](https://github.com/apigear-io/template-unreal/issues).
:::

### Example API

The following code snippet contains the _API_ definition which is used throughout this guide to demonstrate the generated code and its usage.

<details>
    <summary>Hello World API (click to expand)</summary>
    <CodeBlock language="yaml" showLineNumbers>{helloWorldModuleComponent}</CodeBlock>
</details>

## Features

### Core Features

Features generate Unreal Engine plugins from your _API_ definition. These can be used to implement working services and directly integrate them into your Unreal project.

- [api](api.md) - generates the core interfaces, data types (structs, enums), and abstract base classes. Provides both Blueprint-compatible interfaces and native C++ access.

```mermaid
graph TD
    subgraph Application[" Your Application "]
        App[Application Code]
    end

    subgraph API[" API Layer "]
        Interface[Interfaces, Structs & Enums]
    end

    App -->|uses| Interface
```

*Overview: Your application programs against the generated API interfaces.*

Each feature can be selected using the solution file or via the command line tool.

:::note
_Features are case sensitive, make sure to always **use lower-case.**_
:::

:::tip
The _meta_ feature `all` enables all specified features of the template. If you want to see the full extent of the generated code, `all` is the easiest solution.
:::

## Folder structure

This graph shows the folder structure generated for a module with the `api` feature. Each ApiGear module becomes an Unreal plugin.

```bash
📂ue_project/Plugins
 ┗ 📂IoWorld
   ┣ 📜IoWorld.uplugin
   ┣ 📂Config
   ┗ 📂Source
     ┗ 📂IoWorldAPI
```

:::note
The module name `io.world` is converted to PascalCase `IoWorld` for Unreal naming conventions. Each feature generates a separate Unreal module within the plugin.
:::
