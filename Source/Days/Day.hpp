#pragma once

#include <Clock.hpp>
#include <Helpers.hpp>

#include <vector>
#include <string>

namespace aoc
{
    template <typename T1 = int64_t, typename T2 = int64_t>
    class Day
    {
    public:
        Day(const int32_t day) : 
            m_day{day},
            m_solveTime{},
            m_part1{},
            m_part2{}
        {
            m_path = GetRootPath().append("\\Source\\Days\\");
        }

        virtual ~Day() = default;

        inline void Complete()
        {
            Clock c;
            {
                Solve();
            }
            c.Stop();
            m_solveTime = c.Elapsed();

            Display();
        }

    protected:
        virtual void Solve() = 0;

    private:
        inline void Display()
        {
            spdlog::info("----- DAY {} -----", m_day);
            spdlog::info("{:<12} : {}", "Part 1", m_part1);
            spdlog::info("{:<12} : {}", "Part 2", m_part2);
            spdlog::info("{:<12} : {} s", "Solve Time", m_solveTime / 1000.0f);
        }

    protected:
        std::vector<std::string> m_fileData;
        std::string m_path;
        int64_t m_solveTime;
        int32_t m_day;

        T1 m_part1;
        T2 m_part2;
    };
}
