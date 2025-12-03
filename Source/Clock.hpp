#pragma once

#include <chrono>

namespace aoc
{
    class Clock
    {
    public:
        static void Start();
        static void Stop();
        [[nodiscard]] static long long Elapsed();

    private:
        Clock() = delete;
        ~Clock() = delete;

        static std::chrono::steady_clock::time_point m_start;
        static std::chrono::steady_clock::time_point m_stop;
    };
}
