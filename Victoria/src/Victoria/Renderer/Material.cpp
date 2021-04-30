#include "vcpch.h"
#include "Victoria/Renderer/Material.h"

namespace Victoria
{
	Ref<Material> Material::Create(const Ref<Shader>& shader)
	{
		return 0;
		//return Ref<Material>::Ref<shader>;
	}

	Material::Material(const Ref<Shader>& shader)
		:m_Shader(shader)
	{
	}

	void Material::Bind(uint32_t index)
	{
		m_Shader->Bind();

		if (m_MaterialSpecification.AlbedoTexToggle && m_AlbedoMap)
			m_AlbedoMap->Bind(0);

		if (m_MaterialSpecification.NormalTexToggle && m_NormalMap)
			m_NormalMap->Bind(1);

		if (m_MaterialSpecification.MetallicTexToggle && m_MetallicMap)
			m_MetallicMap->Bind(2);

		if (m_MaterialSpecification.RoughnessTexToggle && m_RoughnessMap)
			m_RoughnessMap->Bind(3);

		if (m_MaterialSpecification.AOTexToggle && m_AOMap)
			m_AOMap->Bind(4);

		/*m_CBuffer->SetData(&m_MaterialSpecification);*/
	}
}
