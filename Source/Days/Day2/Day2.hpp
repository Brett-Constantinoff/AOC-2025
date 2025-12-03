#pragma once

#include <Days/Day.hpp>

#include <vector>
#include <string>

namespace aoc
{
	class Day2 : public Day<int64_t, int64_t>
	{
	public:
		Day2();
		~Day2();

		void Solve() override;

	private:
		void FindRepeatingDigits(const int64_t start, const int64_t stop);
	};
}