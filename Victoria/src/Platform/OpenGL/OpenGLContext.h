#pragma once

struct GLFWwindow;

namespace Victoria
{
    class OpenGLContext
    {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

		virtual void Init() ;
		virtual void SwapBuffers() ;

    private:
        GLFWwindow *m_WindowHandle;
    };
} 
