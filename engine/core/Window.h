#pragma once
#include "Module.h"
#include <GLFW/glfw3.h>
#include <string>
#include <functional>

namespace nebula {

struct WindowProps {
    std::string Title;
    int Width;
    int Height;

    WindowProps(const std::string& title = "Nebula Engine",
                int width = 1280,
                int height = 720)
        : Title(title), Width(width), Height(height) {}
};

class Window : public IModule {
public:
    Window(const WindowProps& props = WindowProps());
    virtual ~Window();

    std::string GetName() const override { return "Window"; }
    bool OnRegister() override;
    void OnUpdate(float dt) override;
    void OnShutdown() override;

    int GetWidth() const { return m_Data.Width; }
    int GetHeight() const { return m_Data.Height; }
    GLFWwindow* GetNativeWindow() const { return m_Window; }
    bool ShouldClose() const;

private:
    GLFWwindow* m_Window;
    WindowProps m_Data;
};

} // namespace nebula
