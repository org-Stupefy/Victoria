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

		int major, minor, nrAttributes;
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
		glGetIntegerv(GL_MAJOR_VERSION, &major);
		glGetIntegerv(GL_MINOR_VERSION, &minor);
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);

		VC_CORE_INFO("OpenGL Info:");
		VC_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		VC_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		VC_CORE_INFO("  Version (string): {0}", glGetString(GL_VERSION));
		VC_CORE_INFO("  Version (integer): {0}.{1}", major, minor);
		VC_CORE_INFO("  GLSL Version: {0}", glGetString(GL_SHADING_LANGUAGE_VERSION));
		VC_CORE_INFO("  Maximum number of vertex attributes supported: {0}", nrAttributes);

		VC_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Victoria requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		VC_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
