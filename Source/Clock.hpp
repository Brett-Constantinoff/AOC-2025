#pragma once

#include <chrono>

namespace aoc
{
    class Clock
    {
    public:
        Clock()
        {
            m_start = std::chrono::steady_clock::now();
        }

        inline void Stop()
        {
            m_stop = std::chrono::steady_clock::now();
        }

        inline [[nodiscard]] int64_t Elapsed() const
        {
            return std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start).count();
        }

    private:
        std::chrono::steady_clock::time_point m_start;
        std::chrono::steady_clock::time_point m_stop;
    };
}
