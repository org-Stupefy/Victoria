#pragma once

#include "Victoria/Renderer/RendererAPI.h"
#include <glad/glad.h>

namespace Victoria {

	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void Init() override;
	};
}
