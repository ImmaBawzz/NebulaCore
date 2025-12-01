#include "core/Application.h"
#include "core/PluginAPI.h"
#include "rendering/Renderer.h"
#include "rendering/Buffer.h"
#include "rendering/Shader.h"
#include "scripting/ScriptingAPI.h"

// Example of a game-specific module
class GameModule : public nebula::IModule {
public:
    std::string GetName() const override { return "GameModule"; }

    bool OnRegister() override {
        // Triangle Data
        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
             0.5f, -0.5f, 0.0f,
             0.0f,  0.5f, 0.0f
        };

        uint32_t indices[] = { 0, 1, 2 };

        m_VertexArray = std::make_shared<nebula::VertexArray>();
        
        std::shared_ptr<nebula::VertexBuffer> vertexBuffer = std::make_shared<nebula::VertexBuffer>(vertices, sizeof(vertices));
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        std::shared_ptr<nebula::IndexBuffer> indexBuffer = std::make_shared<nebula::IndexBuffer>(indices, sizeof(indices) / sizeof(uint32_t));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        // Basic Shader
        std::string vertexSrc = R"(
            #version 330 core
            layout(location = 0) in vec3 a_Position;
            void main() {
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSrc = R"(
            #version 330 core
            layout(location = 0) out vec4 color;
            void main() {
                color = vec4(0.8, 0.2, 0.3, 1.0);
            }
        )";

        m_Shader = std::make_shared<nebula::Shader>(vertexSrc, fragmentSrc);

        return true;
    }

    void OnUpdate(float dt) override {
        nebula::Renderer::Submit(m_VertexArray, m_Shader);
    }

    void OnShutdown() override {}

private:
    std::shared_ptr<nebula::VertexArray> m_VertexArray;
    std::shared_ptr<nebula::Shader> m_Shader;
};

int main() {
    nebula::Application app;

    // Register core modules manually for now, or use the PluginRegistry if they were registered via macros
    // For this example, let's register them manually to ensure they are linked and working
    app.RegisterModule(std::make_shared<nebula::Renderer>());
    app.RegisterModule(std::make_shared<nebula::ScriptingEngine>());
    app.RegisterModule(std::make_shared<GameModule>());

    // Also load any auto-registered plugins
    auto modules = nebula::PluginRegistry::Instance().CreateAllModules();
    for (auto& m : modules) {
        app.RegisterModule(m);
    }

    app.Run();
    return 0;
}
