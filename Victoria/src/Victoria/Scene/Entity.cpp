#include "vcpch.h"

#include "Victoria/Scene/Entity.h"

namespace Victoria
{
	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{

	}

}
