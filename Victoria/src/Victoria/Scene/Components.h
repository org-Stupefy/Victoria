#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#include "Victoria/Scene/SceneCamera.h"

//#include "Victoria/Renderer/Mesh.h"
#include "Victoria/Renderer/Texture.h"

#include "Victoria/Core/UUID.h"

namespace Victoria
{
	struct UUIDCcomponent
	{
		UUID ID = 0;
	};

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std ::string& tag)
			:Tag(tag){}
	};

	struct TransformComponent
	{
		glm::vec3 Translation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Rotation = { 0.0f, 0.0f, 0.0f };
		glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::vec3& translation)
			:Translation(translation){}

		glm::mat4 GetTransform() const
		{
			glm::mat4 rotation = glm::toMat4(glm::quat(Rotation));

			return glm::translate(glm::mat4(1.0f), Translation) * rotation * glm::scale(glm::mat4(1.0f), Scale);
		}

		void Reset() { Translation = { 0.0f, 0.0f, 0.0f }; Rotation = { 0.0f, 0.0f, 0.0f }; Scale = { 1.0f, 1.0f, 1.0f }; }
	};

	struct CameraComponent
	{
		SceneCamera Camera;
		bool Primary = true; // TODO: think about moving to Scene
		bool FixedAspectRatio = false;

		CameraComponent() = default;
		CameraComponent(const CameraComponent&) = default;

		void Reset()
		{
			Primary = true;
			FixedAspectRatio = false;
		}
	};

	struct SpriteRendererComponent
	{
		glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };
		Ref<Texture2D> Texture = nullptr;
		std::string TextureFilepath;
		float TilingFactor = 1.0f;

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4& color)
			: Color(color) {}

		/*void SetTexture(const std::string& filepath)
		{
			Texture = Texture2D::Create(filepath);
			Renderer::Submit<Texture2D>(Texture);
			TextureFilepath = filepath;
		}

		void RemoveTexture() { Texture = nullptr; TextureFilepath = ""; }

		void Reset()
		{
			Color = { 1.0f, 1.0f, 1.0f, 1.0f };
			RemoveTexture();
		}*/
	};

	/*struct MeshComponent
	{
		Ref<Victoria::Mesh> Mesh;
		std::string MeshFilepath;

		MeshComponent() = default;
		MeshComponent(const MeshComponent&) = default;

		void SetFilePath(std::string& path) { MeshFilepath = path; }
		void Reset() { Mesh = nullptr; MeshFilepath.clear(); }
	};*/
}
