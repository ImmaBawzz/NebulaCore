#include "Window.h"
#include "Logging.h"

namespace nebula {

static bool s_GLFWInitialized = false;

Window::Window(const WindowProps& props) : m_Data(props), m_Window(nullptr) {}

Window::~Window() {
    OnShutdown();
}

bool Window::OnRegister() {
    Log::Info("Creating window " + m_Data.Title + " (" + std::to_string(m_Data.Width) + "x" + std::to_string(m_Data.Height) + ")");

    if (!s_GLFWInitialized) {
        int success = glfwInit();
        if (!success) {
            Log::Error("Could not initialize GLFW!");
            return false;
        }
        s_GLFWInitialized = true;
    }

    m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        Log::Error("Could not create GLFW window!");
        return false;
    }

    glfwMakeContextCurrent(m_Window);
    glfwSetWindowUserPointer(m_Window, &m_Data);

    return true;
}

void Window::OnUpdate(float dt) {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
}

void Window::OnShutdown() {
    if (m_Window) {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }
    // Note: We might want to terminate GLFW only when the last window is destroyed or app shuts down.
    // For now, let's assume one window per app.
    if (s_GLFWInitialized) {
        glfwTerminate();
        s_GLFWInitialized = false;
    }
}

bool Window::ShouldClose() const {
    return glfwWindowShouldClose(m_Window);
}

} // namespace nebula
