#include <Pch.hpp>

#include <Clock.hpp>

namespace aoc
{
    std::chrono::steady_clock::time_point Clock::m_start;
    std::chrono::steady_clock::time_point Clock::m_stop;

    void Clock::Start()
    {
        m_start = std::chrono::steady_clock::now();
    }

    void Clock::Stop()
    {
        m_stop = std::chrono::steady_clock::now();
    }

    long long Clock::Elapsed()
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start).count();
    }
}
