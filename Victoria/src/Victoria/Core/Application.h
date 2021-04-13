#pragma once

#include "Victoria/Core/Base.h"

#include "Victoria/Core/Window.h"
#include "Victoria/Layer/LayerStack.h"
#include "Victoria/Events/Events.h"
#include "Victoria/Events/ApplicationEvents.h"

#include "Victoria/ImGui/ImGuiLayer.h"
#include "Victoria/Core/Timestep.h"

int main(int argc, char** argv);

namespace Victoria
{
	class Application
	{
	public:
		Application(const std::string& name = "Victoria App");
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

} 
