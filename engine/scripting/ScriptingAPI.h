#pragma once
#include "../core/Module.h"

namespace nebula {

class ScriptingEngine : public IModule {
public:
    std::string GetName() const override { return "ScriptingEngine"; }
    bool OnRegister() override;
    void OnUpdate(float dt) override;
    void OnShutdown() override;
};

} // namespace nebula
