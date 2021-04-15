#pragma once

#include "Victoria/Scene/Scene.h"

namespace YAML
{
	class Node;
	class Emitter;
}

namespace Victoria
{
	class SceneSerializer
	{
	public:
		SceneSerializer(const Ref<Scene>& scene);

		void SerializeText(const std::string& filepath);
		void SerializeBinary(const std::string& filepath);
	
		bool DeserializeText(const std::string& filepath);
		bool DeserializeBinary(const std::string& filepath);

	private:
		void SerializeRendererSettings(YAML::Emitter& out);
		void DeserializeRendererSettings(YAML::Node& data);

	private:
		Ref<Scene> m_Scene;
	};
}

