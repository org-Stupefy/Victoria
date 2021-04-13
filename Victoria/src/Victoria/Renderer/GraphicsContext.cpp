#include "vcpch.h"
#include "Victoria/Renderer/GraphicsContext.h"

#include "Victoria/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Victoria
{
	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    VC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		VC_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
