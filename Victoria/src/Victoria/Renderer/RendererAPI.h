#pragma once

#include "Victoria/Core/Base.h"
#include <glm/glm.hpp>

namespace Victoria
{
	class RendererAPI
	{
	public:
		enum class API
		{
			None=0,
			OpenGL =1,
			Vulkan = 2
		};

	public:
		virtual ~RendererAPI() = default;

		virtual void Init() = 0;
		
		static API GetAPI() { return s_API; }

	private:
		static API s_API;
	};
}
