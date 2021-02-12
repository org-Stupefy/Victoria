#pragma once

#include "Victoria/Events/Events.h"
#include "Victoria/Core/KeyCodes.h"

namespace Victoria
{
    class KeyEvent : public Event
    {
    public:
        KeyCode GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(const KeyCode keycode)
            : m_KeyCode(keycode)
        {
        }

        KeyCode m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(const KeyCode keycode, const unsigned int repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount)
        {
        }

        unsigned int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }
        EVENT_CLASS_TYPE(KeyPressed)
    private:
        unsigned int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(const KeyEvent keyCode)
            : KeyEvent(keyCode)
        {
        }
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

    class KeyTypedEvent : public KeyEvent
    {
    public:
        KeyTypedEvent(const KeyEvent keycode)
            : KeyEvent(keycode)
        {
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTyped)
    };
} // namespace Victoria
