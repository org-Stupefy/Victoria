#pragma once

#include <Victoria.h>
#include "Panels/ScenePanel.h"
#include "Victoria/Renderer/EditorCamera.h"	

namespace Victoria
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void OnUpdate(Timestep ts) override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;
	private:
		bool OnKeyPressed(KeyPressedEvent& e);
		bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

		void NewScene();
		void OpenScene();
		void SaveSceneAs();
		void SaveScene();
		void RenderPanels();
		void RenderGizmos();
		void EntryPopUp();
		void AboutPopUp();
		
	private:
		Victoria::OrthographicCameraController m_CameraController;

		// Temp
		Ref<VertexArray> m_SquareVA;
		Ref<Shader> m_FlatColorShader;
		Ref<FrameBuffer> m_Framebuffer;

		Ref<Scene> m_ActiveScene;
		Ref<Texture2D> m_CheckerboardTexture;

		Entity m_SquareEntity;
		Entity m_CameraEntity;
		Entity m_SecondCamera;

		Entity m_HoveredEntity;

		bool m_PrimaryCamera = true;
		EditorCamera m_EditorCamera;

		int m_GizmoType = -1;
		bool m_ViewportFocused = false, m_ViewportHovered = false;
		std::string m_ActiveFilepath = std::string();
		
		glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
		glm::vec2 m_ViewportBounds[2];
		glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
		glm::vec4 m_ClearColor = { 0.141f,0.145f,0.192f,1.0f };
		
		// Panels
		ScenePanel m_ScenePanel;
		//Panel Bools
		bool m_ShowScenePanel = true;
		bool m_ShowPropertiesPanel = true;
		bool m_AboutPopUp = false;
	};
}
