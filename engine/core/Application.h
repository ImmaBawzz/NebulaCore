#pragma once
#include <vector>
#include <memory>
#include "Module.h"

namespace nebula {

class Window;

class Application {
public:
    Application();
    virtual ~Application() = default;

    void RegisterModule(std::shared_ptr<IModule> module);
    void Run();

    static Application& Get() { return *s_Instance; }
    Window& GetWindow() { return *m_Window; }

private:
    bool m_Running = false;
    std::vector<std::shared_ptr<IModule>> m_Modules;
    std::shared_ptr<Window> m_Window;
    static Application* s_Instance;
};

} // namespace nebula
