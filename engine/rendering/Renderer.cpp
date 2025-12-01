#include "Renderer.h"
#include "../core/Logging.h"

#include <glad/glad.h>

namespace nebula {

void Renderer::Init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::Shutdown() {
}

void Renderer::SetClearColor(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
}

void Renderer::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& shader) {
    shader->Bind();
    vertexArray->Bind();
    glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
}

bool Renderer::OnRegister() {
    Log::Info("Renderer Registered");
    Init();
    return true;
}

void Renderer::OnUpdate(float dt) {
    // Render frame
    Clear();
}

void Renderer::OnShutdown() {
    Log::Info("Renderer Shutdown");
}

} // namespace nebula
