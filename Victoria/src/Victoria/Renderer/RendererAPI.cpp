#include "vcpch.h"

#include "Victoria/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Victoria
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;
}
