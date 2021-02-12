#pragma once

#include "Victoria/Layer/Layer.h"

namespace Victoria
{
    Layer::Layer(const std::string &debugname)
        : m_DebugName(debugname)
    {
    }

    Layer::~Layer()
    {
    }

} // namespace Victoria