#pragma once

#include "Victoria/Core/Window.h"
#include "Victoria/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Victoria
{
    class WindowWindows : public Window
    {
	public:
		WindowWindows(const WindowProperties& props);
		virtual ~WindowWindows();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProperties& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		Scope<GraphicsContext> m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
} 
