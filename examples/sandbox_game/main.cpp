#include "core/Application.h"
#include "core/PluginAPI.h"
#include "rendering/Renderer.h"
#include "rendering/Buffer.h"
#include "rendering/Shader.h"
#include "rendering/Texture.h"
#include "scripting/ScriptingAPI.h"

// Example of a game-specific module
class GameModule : public nebula::IModule {
public:
    std::string GetName() const override { return "GameModule"; }

    bool OnRegister() override {
        // Triangle Data with UVs
        float vertices[] = {
            // Position         // UV
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
             0.0f,  0.5f, 0.0f, 0.5f, 1.0f
        };

        uint32_t indices[] = { 0, 1, 2 };

        m_VertexArray = std::make_shared<nebula::VertexArray>();
        
        std::shared_ptr<nebula::VertexBuffer> vertexBuffer = std::make_shared<nebula::VertexBuffer>(vertices, sizeof(vertices));
        // Layout: Position (3 floats), UV (2 floats)
        nebula::BufferLayout layout = {
            { nebula::ShaderDataType::Float3, "a_Position" },
            { nebula::ShaderDataType::Float2, "a_TexCoord" }
        };
        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        std::shared_ptr<nebula::IndexBuffer> indexBuffer = std::make_shared<nebula::IndexBuffer>(indices, sizeof(indices) / sizeof(uint32_t));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        // Create a Checkerboard Texture
        m_Texture = std::make_shared<nebula::Texture2D>(2, 2);
        uint32_t data[] = { 0xFFFFFFFF, 0xFF0000FF, 0xFF0000FF, 0xFFFFFFFF }; // White, Red, Red, White (RGBA)
        m_Texture->SetData(data, sizeof(data));

        // Basic Shader with Texture
        std::string vertexSrc = R"(
            #version 330 core
            layout(location = 0) in vec3 a_Position;
            layout(location = 1) in vec2 a_TexCoord;
            
            out vec2 v_TexCoord;

            void main() {
                v_TexCoord = a_TexCoord;
                gl_Position = vec4(a_Position, 1.0);
            }
        )";

        std::string fragmentSrc = R"(
            #version 330 core
            layout(location = 0) out vec4 color;
            
            in vec2 v_TexCoord;
            
            uniform sampler2D u_Texture;

            void main() {
                color = texture(u_Texture, v_TexCoord);
            }
        )";

        m_Shader = std::make_shared<nebula::Shader>(vertexSrc, fragmentSrc);
        m_Shader->Bind();
        m_Shader->SetUniformInt("u_Texture", 0); // Slot 0

        return true;
    }

    void OnUpdate(float dt) override {
        m_Texture->Bind(0);
        nebula::Renderer::Submit(m_VertexArray, m_Shader);
    }

    void OnShutdown() override {}

private:
    std::shared_ptr<nebula::VertexArray> m_VertexArray;
    std::shared_ptr<nebula::Shader> m_Shader;
    std::shared_ptr<nebula::Texture2D> m_Texture;
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
