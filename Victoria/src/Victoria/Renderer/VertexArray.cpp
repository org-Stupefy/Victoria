#include "vcpch.h"

#include "Victoria/Renderer/VertexArray.h"

#include "Victoria/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Victoria
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    VC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		VC_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
