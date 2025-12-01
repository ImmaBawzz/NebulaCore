#include "core/Application.h"
#include "core/PluginAPI.h"
#include "rendering/Renderer.h"
#include "scripting/ScriptingAPI.h"

// Example of a game-specific module
class GameModule : public nebula::IModule {
public:
    std::string GetName() const override { return "GameModule"; }
    bool OnRegister() override { return true; }
    void OnUpdate(float dt) override {
        // Game logic here
    }
    void OnShutdown() override {}
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
