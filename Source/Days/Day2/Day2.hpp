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
		void FindRepeatingDigits(const int64_t start, const int64_t stop);

	private:
		int64_t m_part1;
		int64_t m_part2;
	};
}