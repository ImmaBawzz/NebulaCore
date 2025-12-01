#pragma once
#include <string>

namespace nebula {

class IModule {
public:
    virtual ~IModule() = default;
    virtual std::string GetName() const = 0;
    virtual bool OnRegister() = 0;   // called when engine loads module
    virtual void OnUpdate(float dt) = 0;
    virtual void OnShutdown() = 0;
};

} // namespace nebula
