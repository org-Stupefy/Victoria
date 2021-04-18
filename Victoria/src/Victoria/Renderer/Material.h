#pragma once

#include "Victoria/Renderer/Shader.h"
#include "Victoria/Renderer/Texture.h"

namespace Victoria
{
	struct MaterialSpecification
	{
		glm::vec3 Color = { 1.0f, 1.0f, 1.0f };
		float Shininess = 32.0f;
	};

	class Material
	{
	public:
		Material() = default;
		~Material() = default;
	private:
		Ref<Shader> m_Shader;
		std::vector<Ref<Texture2D>> m_Texture;
		MaterialSpecification m_MaterialSpec;
	};
}

