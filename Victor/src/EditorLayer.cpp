#include "EditorLayer.h"

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ImGuizmo.h>

#include "UIUtility/UIUtility.h"
#include "Victoria/Scene/SceneSerializer.h"
#include "Victoria/Utility/PlatformUtils.h"

namespace Victoria
{
	EditorLayer::EditorLayer()
		:Layer("Editor Layer"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
	{

	}

	void EditorLayer::OnAttach()
	{
		VC_PROFILE_FUNCTION();

		m_CheckerboardTexture = Texture2D::Create("assets/textures/Checkerboard.png");

		FrameBufferSpecification fbSpec;
		fbSpec.Attachments = { FrameBufferTextureFormat::RGBA8, FrameBufferTextureFormat::RED_INTEGER, FrameBufferTextureFormat::Depth };
		fbSpec.Width = 1280;
		fbSpec.Height = 720;
		m_Framebuffer = FrameBuffer::Create(fbSpec);

		m_ActiveScene = CreateRef<Scene>();

		m_EditorCamera = EditorCamera(30.0f, 1.778f, 0.1f, 1000.0f);

		m_ScenePanel.SetContext(m_ActiveScene);
	}

	void EditorLayer::OnDetach()
	{
		VC_PROFILE_FUNCTION();
	}


	void EditorLayer::OnUpdate(Timestep ts)
	{
		VC_PROFILE_FUNCTION();

		if (FrameBufferSpecification spec = m_Framebuffer->GetSpecification();
			m_ViewportSize.x > 0.0f && m_ViewportSize.y > 0.0f && // zero sized framebuffer is invalid
			(spec.Width != m_ViewportSize.x || spec.Height != m_ViewportSize.y))
		{
			m_Framebuffer->Resize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
			m_CameraController.OnResize(m_ViewportSize.x, m_ViewportSize.y);
			m_EditorCamera.SetViewportSize(m_ViewportSize.x, m_ViewportSize.y);
			m_ActiveScene->OnViewportResize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
		}

		// Update
		if (m_ViewportFocused)
			m_CameraController.OnUpdate(ts);

		m_EditorCamera.OnUpdate(ts);

		// Render
		Renderer2D::ResetStats();
		m_Framebuffer->Bind();
		RenderCommand::SetClearColor(m_ClearColor);
		RenderCommand::Clear();

		// Clear our entity ID attachment to -1
		m_Framebuffer->ClearAttachment(1, -1);

		// Update scene
		m_ActiveScene->OnUpdateEditor(ts, m_EditorCamera);

		auto [mx, my] = ImGui::GetMousePos();
		mx -= m_ViewportBounds[0].x;
		my -= m_ViewportBounds[0].y;
		glm::vec2 viewportSize = m_ViewportBounds[1] - m_ViewportBounds[0];
		my = viewportSize.y - my;
		int mouseX = (int)mx;
		int mouseY = (int)my;

		if (mouseX >= 0 && mouseY >= 0 && mouseX < (int)viewportSize.x && mouseY < (int)viewportSize.y)
		{
			int pixelData = m_Framebuffer->ReadPixel(1, mouseX, mouseY);
			m_HoveredEntity = pixelData == -1 ? Entity() : Entity((entt::entity)pixelData, m_ActiveScene.get());
		}

		m_Framebuffer->Unbind();
	}

	void EditorLayer::OnImGuiRender()
	{
		VC_PROFILE_FUNCTION();

		UI::BeginDockspace();
				ImGui::ShowDemoWindow();
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Logo"))
			{
				if (ImGui::MenuItem("About"))
					m_AboutPopUp = true;
					AboutPopUp();

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New", "Ctrl+N"))
					NewScene();

				if (ImGui::MenuItem("Open...", "Ctrl O"))
					OpenScene();

				ImGui::Separator();
				if (ImGui::MenuItem("Save", "Ctrl S"))
					SaveScene();

				if (ImGui::MenuItem("Save As...", "Ctrl Shift S"))
					SaveSceneAs();

				ImGui::Separator();
				if(ImGui::MenuItem("Import"))
					SaveSceneAs(); //TODO:

				ImGui::Separator();
				if (ImGui::MenuItem("Quit","Ctrl+Q")) Application::Get().Close();

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Edit"))
			{
				if (ImGui::MenuItem("Preferences"))
					SaveSceneAs();//TODO:

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("View"))
			{
				if(ImGui::MenuItem("Scene Hierarchy"))
					m_ShowScenePanel = true;

				if(ImGui::MenuItem("Properties"))
					m_ShowPropertiesPanel = true;

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Render"))
			{
				if (ImGui::MenuItem("Render Image","F12"))
					SaveSceneAs();//TODO:
				
				if(ImGui::MenuItem("Render Animation","Ctrl F12"))
					SaveSceneAs();//TODO:

				ImGui::Separator();
				if (ImGui::MenuItem("View Image", "F11"))
					SaveSceneAs();//TODO:

				if (ImGui::MenuItem("View Animation", "Ctrl F11"))
					SaveSceneAs();//TODO:
				
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		RenderPanels();

		UI::BeginViewport("Editor");
		auto viewportMinRegion = ImGui::GetWindowContentRegionMin();
		auto viewportMaxRegion = ImGui::GetWindowContentRegionMax();
		auto viewportOffset = ImGui::GetWindowPos();
		m_ViewportBounds[0] = { viewportMinRegion.x + viewportOffset.x, viewportMinRegion.y + viewportOffset.y };
		m_ViewportBounds[1] = { viewportMaxRegion.x + viewportOffset.x, viewportMaxRegion.y + viewportOffset.y };

		m_ViewportFocused = ImGui::IsWindowFocused();
		m_ViewportHovered = ImGui::IsWindowHovered();
		Application::Get().GetImGuiLayer()->BlockEvents(!m_ViewportFocused && !m_ViewportHovered);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		m_ViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

		UI::Image(reinterpret_cast<void*>(m_Framebuffer->GetColorAttachmentRendererID(0)), m_ViewportSize);

		RenderGizmos();
		UI::EndViewport();
		UI::EndDockspace();
	}

	void EditorLayer::RenderPanels()
	{
		if (m_ShowScenePanel)
			m_ScenePanel.OnImGuiRender(&m_ShowScenePanel);
	}

	void EditorLayer::RenderGizmos()
	{
		Entity selectedEntity = m_ScenePanel.GetSelectedEntity();
		if (selectedEntity && m_GizmoType != -1)
		{
			ImGuizmo::SetOrthographic(false);
			ImGuizmo::SetDrawlist();
			ImGuizmo::SetRect(m_ViewportBounds[0].x, m_ViewportBounds[0].y, m_ViewportBounds[1].x - m_ViewportBounds[0].x, m_ViewportBounds[1].y - m_ViewportBounds[0].y);

			float windowWidth = (float)ImGui::GetWindowWidth();
			float windowHeight = (float)ImGui::GetWindowHeight();
			ImGuizmo::SetRect(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y, windowWidth, windowHeight);

			// Editor camera
			const glm::mat4& cameraProjection = m_EditorCamera.GetProjection();
			glm::mat4 cameraView = m_EditorCamera.GetViewMatrix();

			// Entity transform
			auto& tc = selectedEntity.GetComponent<TransformComponent>();
			glm::mat4 transform = tc.GetTransform();

			// Snapping
			bool snap = Input::IsKeyPressed(Key::LeftShift);
			float snapValue = 0.5f; // Snap to 0.5m for translation/scale
			// Snap to 45 degrees for rotation
			if (m_GizmoType == ImGuizmo::OPERATION::ROTATE)
				snapValue = 45.0f;

			float snapValues[3] = { snapValue, snapValue, snapValue };

			ImGuizmo::Manipulate(glm::value_ptr(cameraView), glm::value_ptr(cameraProjection),
				(ImGuizmo::OPERATION)m_GizmoType, ImGuizmo::LOCAL, glm::value_ptr(transform),
				nullptr, snap ? snapValues : nullptr);

			if (ImGuizmo::IsUsing())
			{
				glm::vec3 translation, rotation, scale;
				Math::DecomposeTransform(transform, translation, rotation, scale);

				glm::vec3 deltaRotation = rotation - tc.Rotation;
				tc.Translation = translation;
				tc.Rotation += deltaRotation;
				tc.Scale = scale;
			}

			//ImGuizmo::ViewManipulate(glm::value_ptr(cameraView), { 2.0f },)
		}

	}

	void EditorLayer::EntryPopUp()
	{

	}

	void EditorLayer::AboutPopUp()
	{
		if(m_AboutPopUp)
		{
			ImGui::OpenPopup("About");
		}
		if (ImGui::BeginPopupModal("About", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::Text("All those beautiful files will be deleted.\nThis operation cannot be undone!\n\n");
			ImGui::Separator();


			static bool dont_ask_me_next_time = false;
			ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
			ImGui::Checkbox("Don't ask me next time", &dont_ask_me_next_time);
			ImGui::PopStyleVar();

			if (ImGui::Button("OK", ImVec2(120, 0))) { m_AboutPopUp = false; ImGui::CloseCurrentPopup(); }
			ImGui::SetItemDefaultFocus();
			ImGui::SameLine();
			if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
			ImGui::EndPopup();
			/*ImGui::OpenPopup("Test");
			if (ImGui::BeginPopup("Test"))
			{
				ImGui::Text("Aquarium");
				ImGui::EndPopup();
			}*/
		}
	}

	void EditorLayer::OnEvent(Event& e)
	{
		m_CameraController.OnEvent(e);
		m_EditorCamera.OnEvent(e);

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<KeyPressedEvent>(VC_BIND_EVENT_FN(EditorLayer::OnKeyPressed));
		dispatcher.Dispatch<MouseButtonPressedEvent>(VC_BIND_EVENT_FN(EditorLayer::OnMouseButtonPressed));
	}

	bool EditorLayer::OnKeyPressed(KeyPressedEvent& e)
	{
		// Shortcuts
		if (e.GetRepeatCount() > 0)
			return false;

		bool control = Input::IsKeyPressed(Key::LeftControl) || Input::IsKeyPressed(Key::RightControl);
		bool shift = Input::IsKeyPressed(Key::LeftShift) || Input::IsKeyPressed(Key::RightShift);

		switch (e.GetKeyCode())
		{
			case Key::N: if (control) NewScene();  break;
			case Key::O: if (control) OpenScene(); break;
			case Key::S: if (control) SaveScene(); if (control && shift) SaveSceneAs(); break;
			/*case Key::F12: RenderImage(); if (control) ViewRenderedImage(); break;
			case Key::F11: RenderAnimation(); if (control) ViewRenderedAnimation(); break;*/

			// Gizmos
			case Key::Q: if (!ImGuizmo::IsUsing()) m_GizmoType = -1;                             break;
			case Key::W: if (!ImGuizmo::IsUsing()) m_GizmoType = ImGuizmo::OPERATION::TRANSLATE; break;
			case Key::E: if (!ImGuizmo::IsUsing()) m_GizmoType = ImGuizmo::OPERATION::ROTATE;    break;
			case Key::R: if (!ImGuizmo::IsUsing()) m_GizmoType = ImGuizmo::OPERATION::SCALE;     break;
		}
		return false;
	}

	bool EditorLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		if (e.GetMouseButton() == Mouse::ButtonLeft)
		{
			if (m_ViewportHovered && !ImGuizmo::IsOver() && !Input::IsKeyPressed(Key::LeftAlt))
				m_ScenePanel.SetSelectedEntity(m_HoveredEntity);
		}
		return false;
	}


	void EditorLayer::NewScene()
	{
		m_ActiveScene = CreateRef<Scene>();
		m_ActiveScene->OnViewportResize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
		m_ScenePanel.SetContext(m_ActiveScene);
	}

	void EditorLayer::OpenScene()
	{
		std::optional<std::string> filepath = FileHandling::OpenFile("Victoria Scene (*.vic)\0*.vic\0");
		if (filepath)
		{
			m_ActiveFilepath = *filepath;
			m_ActiveScene = CreateRef<Scene>();
			m_ActiveScene->OnViewportResize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
			m_ScenePanel.SetContext(m_ActiveScene);

			SceneSerializer serializer(m_ActiveScene);
			serializer.DeserializeText(*filepath);
		}
	}

	void EditorLayer::SaveSceneAs()
	{
		std::optional<std::string> filepath = FileHandling::SaveFile("Victoria Scene (*.vic)\0*.vic\0");
		if (filepath)
		{
			SceneSerializer serializer(m_ActiveScene);
			serializer.SerializeText(*filepath);
		}
	}

	void EditorLayer::SaveScene()
	{
		if (m_ActiveFilepath.empty())
			SaveSceneAs();
		else
		{
			/*SceneSerializer serializer(m_ActiveScene, this);
			serializer.SerializeText(m_ActiveFilepath);
			VC_CORE_INFO("Scene Saved!");*/
		}
	}
}
