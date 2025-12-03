#include <Pch.hpp>

#include <Helpers.hpp>
#include <spdlog/spdlog.h>
#include <Days/Day1/Day1.hpp>

namespace aoc
{
	Day1::Day1() :
        m_part1{},
        m_part2{}
	{
		ReadFileIntoVector(m_fileData, m_path.append("Day1\\day1.txt"));
	}

	Day1::~Day1()
	{
	}

    void Day1::Solve()
    {
        int32_t pos = 50;
        for (const auto& str : m_fileData)
        {
            std::string subStr = str.substr(1);
            int32_t rotation = StrToInt(subStr);
            char dir = str[0];

            int32_t dist = dir == 'L'
                ? -rotation
                : rotation;

            int32_t absDist = abs(dist);
            int32_t target = dist > 0
                ? (-pos % 100 + 100) % 100
                : (pos % 100 + 100) % 100;

            int32_t first = target == 0
                ? 100
                : target;

            if (first <= absDist)
            {
                m_part2++;
                m_part2 += (absDist - first) / 100;
            }
           
            m_part1 += (pos % 100 + 100) % 100 == 0;

            pos += dist;
        }

        spdlog::info("-----DAY1-----");
        spdlog::info("Part1: {}    Part2: {}", m_part1, m_part2);
    }
}