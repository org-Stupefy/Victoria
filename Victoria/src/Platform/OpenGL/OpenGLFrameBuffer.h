#pragma once

#include "Victoria/Renderer/FrameBuffer.h"
#include <glad/glad.h>

namespace Victoria
{
	class OpenGLFrameBuffer
	{
	public:
		OpenGLFrameBuffer(const FrameBufferSpecification& specification);
		~OpenGLFrameBuffer();

		void Bind();
		void UnBind();
	private:
		uint32_t m_RendererID = 0;;
	};
}
