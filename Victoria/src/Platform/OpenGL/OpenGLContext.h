#pragma once

struct GLFWwindow;

namespace Victoria
{
    class OpenGLContext
    {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

    private:
        GLFWwindow *m_WindowHandle;
    };
} // namespace Victoria