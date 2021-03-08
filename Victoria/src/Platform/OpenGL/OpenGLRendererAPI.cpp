#include "vcpch.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Victoria {

	void OpenGLMessageCallback(
		unsigned source,
		unsigned type,
		unsigned id,
		unsigned severity,
		int length,
		const char* message,
		const void* userParam)
	{
		switch (severity)
		{
		case GL_DEBUG_SEVERITY_HIGH:         VC_CORE_CRITICAL(message); return;
		case GL_DEBUG_SEVERITY_MEDIUM:       VC_CORE_ERROR(message); return;
		case GL_DEBUG_SEVERITY_LOW:          VC_CORE_WARN(message); return;
		case GL_DEBUG_SEVERITY_NOTIFICATION: VC_CORE_TRACE(message); return;
		}

		VC_CORE_ASSERT(false, "Unknown severity level!");
	}

	void OpenGLRendererAPI::Init()
	{
		VC_PROFILE_FUNCTION();

#ifdef VC_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);

		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}
}
