#pragma once
#include "../core/Module.h"
#include "Shader.h"
#include "Buffer.h"
#include <memory>

namespace nebula {

class Renderer : public IModule {
public:
    std::string GetName() const override { return "Renderer"; }
    static void Init();
    static void Shutdown();

    static void SetClearColor(float r, float g, float b, float a);
    static void Clear();

    static void Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader);

    // Internal
    bool OnRegister() override;
    void OnUpdate(float dt) override;
    void OnShutdown() override;
};

} // namespace nebula
