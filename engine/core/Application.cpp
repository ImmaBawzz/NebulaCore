#include "Application.h"
#include "Window.h"
#include "Logging.h"
#include <chrono>
#include <thread>

namespace nebula {

Application* Application::s_Instance = nullptr;

Application::Application() {
    s_Instance = this;
    m_Window = std::make_shared<Window>();
    RegisterModule(m_Window);
}

void Application::RegisterModule(std::shared_ptr<IModule> module) {
    if (module->OnRegister()) {
        m_Modules.push_back(module);
    }
}

void Application::Run() {
    m_Running = true;

    auto previous = std::chrono::high_resolution_clock::now();

    while (m_Running) {
        auto now = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float>(now - previous).count();
        previous = now;

        if (m_Window->ShouldClose()) {
            m_Running = false;
        }

        for (auto& module : m_Modules) {
            module->OnUpdate(dt);
        }

        // Basic loop control to prevent 100% CPU usage in empty loop
        // std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    for (auto& module : m_Modules) {
        module->OnShutdown();
    }
}

} // namespace nebula
