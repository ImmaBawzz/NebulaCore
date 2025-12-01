#include "ScriptingAPI.h"
#include "../core/Logging.h"

namespace nebula {

bool ScriptingEngine::OnRegister() {
    Log::Info("Scripting Engine Registered");
    return true;
}

void ScriptingEngine::OnUpdate(float dt) {
    // Update scripts
}

void ScriptingEngine::OnShutdown() {
    Log::Info("Scripting Engine Shutdown");
}

} // namespace nebula
