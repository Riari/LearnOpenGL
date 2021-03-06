#pragma once

#include <typeindex>

namespace Iris
{
    class Event
    {
    public:
        explicit Event(float timestamp = 0.0f);
        [[nodiscard]] float GetTimestamp() const;

    private:
        const float m_timestamp;
    };
}