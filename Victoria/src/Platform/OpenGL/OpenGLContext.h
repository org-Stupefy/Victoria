#pragma once

#include "Victoria/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Victoria
{
	class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

    private:
        GLFWwindow *m_WindowHandle;
    };
} 
