#include "vcpch.h"

#include "Victoria/ImGui/ImGuiLayer.h"

#include <imgui.h>
#include <examples/imgui_impl_glfw.h>
#include <examples/imgui_impl_opengl3.h>

#include "Victoria/Core/Application.h"

// TEMPORARY
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include "ImGuizmo.h"

namespace Victoria
{
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{

	}

	void ImGuiLayer::OnAttach()
	{
		// IMGUI SETUP
		VC_PROFILE_FUNCTION();

		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoTaskBarIcons;
		//io.ConfigFlags |= ImGuiConfigFlags_ViewportsNoMerge;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsClassic();
		float size = 17.0f;
		io.Fonts->AddFontFromFileTTF("assets//fonts//Montserrat//Montserrat-Medium.ttf",size);

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		SetDarkThemeColors();

		Application& app = Application::Get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());
		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
		VC_PROFILE_FUNCTION();

		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		if (m_BlockEvents)
		{
			ImGuiIO& io = ImGui::GetIO();
			event.Handled |= event.IsInCategory(EventCategoryMouse) & io.WantCaptureMouse;
			event.Handled |= event.IsInCategory(EventCategoryKeyboard) & io.WantCaptureKeyboard;
		}
	}

	void ImGuiLayer::Begin()
	{
		VC_PROFILE_FUNCTION();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGuizmo::BeginFrame();
	}

	void ImGuiLayer::End()
	{
		VC_PROFILE_FUNCTION();

		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}

	void ImGuiLayer::SetDarkThemeColors()
	{
		auto& style = ImGui::GetStyle();
		auto& colors = ImGui::GetStyle().Colors;

		style.TabRounding = 3.5f;
		style.FrameRounding = 3.5f;
		style.PopupRounding = 3.5f;
		style.ScrollbarRounding = 3.5f;
		style.GrabRounding = 3.5f;
		style.WindowTitleAlign = ImVec2(0.5f, 0.5f);

		ImVec4 blackMain, purple, blackLightShade, blackLightShade2;
		blackMain = { 0.121f,0.121f,0.14f,1.0f };
		blackLightShade = { 0.141f,0.145f,0.192f,1.0f };
		purple = { 0.411f,0.329f,0.796f,1.0f };
		blackLightShade2 = { 0.172f,0.172f,0.227f,1.0f };

		colors[ImGuiCol_WindowBg] = blackMain;

		// Headers
		colors[ImGuiCol_Header] = blackMain;
		colors[ImGuiCol_HeaderHovered] = purple;
		colors[ImGuiCol_HeaderActive] = blackLightShade;

		// Checkbox
		colors[ImGuiCol_CheckMark] = purple;

		// Buttons
		colors[ImGuiCol_Button] = blackMain;
		colors[ImGuiCol_ButtonHovered] = purple;
		colors[ImGuiCol_ButtonActive] = blackLightShade;

		// Frame BG
		colors[ImGuiCol_FrameBg] = blackMain;
		colors[ImGuiCol_FrameBgHovered] = purple;
		colors[ImGuiCol_FrameBgActive] = blackLightShade;

		// Tabs
		colors[ImGuiCol_Tab] = blackMain;
		colors[ImGuiCol_TabHovered] = blackLightShade2;
		colors[ImGuiCol_TabActive] = purple;
		colors[ImGuiCol_TabUnfocused] = blackLightShade;
		colors[ImGuiCol_TabUnfocusedActive] = blackMain;

		// Title
		colors[ImGuiCol_TitleBg] = blackMain;
		colors[ImGuiCol_TitleBgActive] = blackMain;
		colors[ImGuiCol_TitleBgCollapsed] = blackMain;
	}
}
