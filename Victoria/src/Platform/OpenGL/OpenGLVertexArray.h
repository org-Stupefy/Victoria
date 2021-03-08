#pragma once

#include "Victoria/Renderer/VertexArray.h"
#include <glad/glad.h>

namespace Victoria
{
    class OpenGLVertexArray :public VertexArray
    {
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		void Bind();
		void UnBind();

		virtual void AddVertexBuffer();

	private:
		uint32_t m_RendererID;
		uint32_t m_VertexBufferIndex = 0;

    };
} 
