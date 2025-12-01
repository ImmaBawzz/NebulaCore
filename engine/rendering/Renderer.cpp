#include "Renderer.h"
#include "../core/Logging.h"

namespace nebula {

bool Renderer::OnRegister() {
    Log::Info("Renderer Registered");
    return true;
}

void Renderer::OnUpdate(float dt) {
    // Render frame
}

void Renderer::OnShutdown() {
    Log::Info("Renderer Shutdown");
}

} // namespace nebula
