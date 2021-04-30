#pragma once

#include "Victoria/Renderer/OrthographicCamera.h"

#include "Victoria/Renderer/Texture.h"

#include "Victoria/Renderer/Camera.h"
#include "Victoria/Renderer/EditorCamera.h"

namespace Victoria {

	class SceneRenderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera, const glm::mat4& transform);
		static void BeginScene(const EditorCamera& camera);
		static void BeginScene(const OrthographicCamera& camera); // TODO: Remove
		static void EndScene();
		static void Flush();
	};

}
