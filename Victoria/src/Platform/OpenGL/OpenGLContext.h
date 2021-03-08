#pragma once

#include "Victoria/Renderer/GraphicsContext.h"
#include <glad/glad.h>

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
