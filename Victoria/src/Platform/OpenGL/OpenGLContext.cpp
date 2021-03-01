#include "vcpch.h"

#include "Platform/OpenGL/OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Victoria
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		VC_CORE_ASSERT(windowHandle,"Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		VC_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		VC_CORE_ASSERT(status, "Failed to initialize Glad!");

		VC_CORE_INFO("OpenGL Info:");
		VC_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		VC_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		VC_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		VC_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Victoria requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		VC_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
