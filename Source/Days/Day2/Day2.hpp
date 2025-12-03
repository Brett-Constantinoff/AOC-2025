#pragma once

#include <Days/Day.hpp>

#include <vector>
#include <string>

namespace aoc
{
	class Day2 : public Day
	{
	public:
		Day2();
		~Day2();

		void Solve() override;

	private:
		void FindRepeatingDigits(const int32_t start, const int32_t stop);

	private:
		int32_t m_part1;
		int32_t m_part2;
	};
}