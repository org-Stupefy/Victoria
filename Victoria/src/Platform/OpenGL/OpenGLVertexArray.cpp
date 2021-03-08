#include "vcpch.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Victoria
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		VC_PROFILE_FUNCTION();

		glGenVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		VC_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::Bind()
	{
		VC_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::UnBind()
	{
		VC_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer()
	{
		VC_PROFILE_FUNCTION();

	}
} 
