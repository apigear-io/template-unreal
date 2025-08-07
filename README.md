# Epic Games Unreal Engine template

This is a code generation template for the ApiGear integration suite. It generates an Unreal Engine C++ plugin with full blueprint support based on an object API model and eases the integration of external data into any Unreal Engine project.

Check out the [quick start documentation](https://apigear-io.github.io/template-unreal/quickstart).
For more details on *ApiGear* please visit [apigear.io](https://apigear.io) or the [*ApiGear* documentation](https://docs.apigear/).

## Output - Unreal Engine plugin

### Technologies

We aim for full feature parity between usage from within Blueprints or UE C++.

|   |Client|Service|Network Client|Network Service|Simulation Client|
|---| :---: | :---: | :---: | :---: | :---: |
|Blueprint|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:| :heavy_check_mark: (v3.x and later) |:heavy_check_mark:|
|UE C++|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark:|:heavy_check_mark: (v3.x and later)|:heavy_check_mark:|

> :bulb: **Explanation**
>
> An API has two sides. One *client* side which usually consumes events, data or triggers functions. And the *service* side which produces the data, events to be consumed by the client or reacts to function calls.
>
> In modern architectures these two sides are often distributed in a network. Therefore the plugin can also connect to remote services as a *network client*.
>
> Furthermore, the plugin can also be connected as *simulation client* to *ApiGear*s simulation tools. [More information](https://docs.apigear.io/docs/advanced/simulation/intro)
### Compatibility

The generated plugin code is regularly tested in these configurations:
| platform | UE4.25 | UE4.27 | UE5.4 | UE5.5 | UE5.6 |
|----------| :---: | :---: | :---: |  :---: |  :---: |
| Windows  |:heavy_check_mark: (until v2.x)|:heavy_check_mark:|:heavy_check_mark:| :heavy_check_mark:| :heavy_check_mark:|
| Linux    |:heavy_check_mark: (until v2.x)|:heavy_check_mark:|:heavy_check_mark:| :heavy_check_mark:| :heavy_check_mark:|
## Code Generation Features

The template offers the following feature switches which can be enabled during code generation:
* `api`: create interface files and an abstract implementation
* `stubs`: create a stub implementation in C++ with some test cases
* `plugin`: create a fully functional plugin with including the stub implementations and tests
* `monitor`: create a thin decorator class which can be used to log traffic going through API layer
* `olink`: create the adaption layer for the [OLink](https://docs.apigear.io/docs/advanced/protocols/objectlink/intro) protocol. This can be used to connect to the simulation or other technologies like python, pure c++ etc..
* `msgbus`: create the adaption layer for the [UE MsgBus](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Messaging) protocol. This can be used for communication inside the same UE app or between different instances, including across network interfaces.
