#pragma once

#include "Victoria/Core/Base.h"
#include "Victoria/Core/Timestep.h"
#include "Victoria/Events/Events.h"

namespace Victoria
{
    class Layer
    {
    public:
        Layer(const std::string &name = "Layer");
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event &event) {}

        const std::string &GetName() const
        {
            return m_DebugName;
        }

    protected:
        std::string m_DebugName;
    };
} // namespace Victoria
