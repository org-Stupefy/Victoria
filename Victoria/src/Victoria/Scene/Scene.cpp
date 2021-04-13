#include "vcpch.h"
#include "Victoria/Scene/Scene.h"

#include "Victoria/Scene/Components.h"
#include "Victoria/Scene/Entity.h"

#include <glm/glm.hpp>

namespace Victoria
{

	Scene::Scene()
	{

	}

	Scene::~Scene()
	{

	}

	Entity Scene::CreateEntity(const std::string& name /*= std::string()*/)
	{
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag.Tag = name.empty() ? "Entity" : name;
		return entity;
	}

	void Scene::DestroyEntity(Entity entity)
	{
		m_Registry.destroy(entity);
	}

}
