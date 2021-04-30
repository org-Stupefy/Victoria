#pragma once

#include "Victoria/Renderer/Shader.h"
#include "Victoria/Renderer/Texture.h"

namespace Victoria
{
	struct MaterialSpecification
	{
		glm::vec3 Albedo = { 1.0f, 1.0f, 1.0f };
		float Metallic = 0.0f;

		float Roughness = 0.0f;
		float AO = 1.0f;
		int AlbedoTexToggle = 0;
		int MetallicTexToggle = 0;

		int AOTexToggle = 0;
		int RoughnessTexToggle = 0;
		int NormalTexToggle = 0;
		float __Padding0;
	};

	class Material
	{
	public:
		Material() = default;
		Material(const Ref<Shader>&shader);
		~Material() = default;

		void Bind(uint32_t index);
		Ref<Shader>& GetShader() { return m_Shader; }

		MaterialSpecification& GetMaterialSpecification() { return m_MaterialSpecification; }
		static Ref<Material> Material::Create(const Ref<Shader>&shader);
	public:
		//All maps (Should we use an array?)
		Ref<Texture2D> m_AlbedoMap;   //Register 0
		Ref<Texture2D> m_NormalMap;   //Register 1
		Ref<Texture2D> m_MetallicMap; //Register 2
		Ref<Texture2D> m_RoughnessMap;//Register 3
		Ref<Texture2D> m_AOMap;       //Register 4
		bool m_Flipped;
	private:
		Ref<Shader> m_Shader;
		MaterialSpecification m_MaterialSpecification;
	private:
		friend class MaterialPanel;
	};
}

