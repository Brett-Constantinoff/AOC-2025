#include <Pch.hpp>

#include <Helpers.hpp>
#include <Days/Day2/Day2.hpp>

#include <spdlog/spdlog.h>
#include <unordered_set>
#include <vector>

namespace aoc
{
	Day2::Day2() :
		m_part1{},
		m_part2{}
	{
		ReadFileIntoVector(m_fileData, m_path.append("Day2\\day2.txt"), ',');
	}

	Day2::~Day2()
	{

	}

	void Day2::Solve()
	{
		std::unordered_map<char, int32_t> m = {};
		for (const auto& s : m_fileData)
		{
			size_t pos = s.find('-');

			int32_t start = StrToInt(s.substr(0, pos));
			int32_t stop = StrToInt(s.substr(pos + 1));

			FindRepeatingDigits(start, stop);
		}

		spdlog::info("-----DAY2-----");
		spdlog::info("Part1: {}    Part2: {}", m_part1, m_part2);
	}

	void Day2::FindRepeatingDigits(const int32_t start, const int32_t stop)
	{
		for (int32_t i = start; i <= stop; ++i)
		{
			std::unordered_set<char> d = {};

			std::string s = IntToStr(i);
			const int32_t l = s.length();

			// add each digit to the set, if the length of the set
			// is half the length of the id, its a duplicate
			for (const auto& c : s)
			{
				d.insert(c);
			}

			if (d.size() == (0.5f * l))
			{
				m_part1 += i;
			}
		}
	}
}