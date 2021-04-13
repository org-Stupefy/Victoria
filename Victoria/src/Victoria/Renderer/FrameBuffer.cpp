#include "vcpch.h"

#include "Victoria/Renderer/FrameBuffer.h"
#include "Victoria/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLFrameBuffer.h"

namespace Victoria
{
	Ref<FrameBuffer> FrameBuffer::Create(const FrameBufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    VC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFrameBuffer>(spec);
		}

		VC_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
