#pragma once

#include <sstream>

#include "Victoria/Core/Base.h"
#include "Victoria/Events/Events.h"

namespace Victoria
{
    struct WindowProperties
    {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowProperties(const std::string &title = "Victoria", uint32_t width = 1600, uint32_t height = 900)
            : Title(title), Width(width), Height(height)
        {
        }
    };

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event &e)>;

        virtual ~Window() = default;
        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

        static Window *Create(const WindowProperties &property = WindowProperties());
    };
} 
