#include "vcpch.h"
#include "Platform/Windows/WindowWindows.h"

#include "Victoria/Events/ApplicationEvents.h"
#include "Victoria/Events/MouseEvents.h"
#include "Victoria/Events/KeyEvents.h"

#include <glad/glad.h>

namespace Victoria
{
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description)
    {
        VC_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window *Window::Create(const WindowProperties &properties)
    {
        return new WindowWindows(properties);
    }

    WindowWindows::WindowWindows(const WindowProperties &properties)
    {
		VC_PROFILE_FUNCTION();
        Init(properties);
    }

    WindowWindows::~WindowWindows()
    {
		VC_PROFILE_FUNCTION();
        Shutdown();
    }

    void WindowWindows::Init(const WindowProperties &properties)
    {
		VC_PROFILE_FUNCTION();
        m_Data.Title = properties.Title;
        m_Data.Width = properties.Width;
        m_Data.Height = properties.Height;

        VC_CORE_INFO("Creating window {0} ({1}, {2})", properties.Title, properties.Width, properties.Height);

        if (!s_GLFWInitialized)
        {
            // TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            VC_CORE_ASSERT(success, "Could not intialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)properties.Width, (int)properties.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		VC_CORE_ASSERT(status, "Failed to initialize GLAD");
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.EventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, 1);
                data.EventCallback(event);
                break;
            }
            }
        });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
				break;
			}
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffset, double yOffset) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos) {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });
    }

	void WindowWindows::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

    void WindowWindows::OnUpdate()
	{
		VC_PROFILE_FUNCTION();
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowWindows::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowWindows::IsVSync() const
    {
        return m_Data.VSync;
    }

} 
