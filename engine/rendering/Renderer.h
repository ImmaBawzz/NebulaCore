#pragma once
#include "../core/Module.h"

namespace nebula {

class Renderer : public IModule {
public:
    std::string GetName() const override { return "Renderer"; }
    bool OnRegister() override;
    void OnUpdate(float dt) override;
    void OnShutdown() override;
};

} // namespace nebula
