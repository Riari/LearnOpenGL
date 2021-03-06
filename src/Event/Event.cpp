#include "Event/Event.hpp"

using namespace Iris;

Event::Event(float timestamp) : m_timestamp(timestamp) {}

float Event::GetTimestamp() const
{
    return m_timestamp;
}
