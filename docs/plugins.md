# NebulaCore Plugins

NebulaCore uses a plugin system to extend functionality.

## Creating a Plugin

1. Inherit from `nebula::IModule`.
2. Implement `GetName`, `OnRegister`, `OnUpdate`, and `OnShutdown`.
3. Use `NEBULA_REGISTER_MODULE` macro to register your plugin.

## Example

```cpp
#include "Module.h"
#include "PluginMacros.h"

class MyCustomPlugin : public nebula::IModule {
public:
    std::string GetName() const override { return "MyCustomPlugin"; }
    bool OnRegister() override { return true; }
    void OnUpdate(float dt) override { }
    void OnShutdown() override { }
};

NEBULA_REGISTER_MODULE(MyCustomPlugin);
```
