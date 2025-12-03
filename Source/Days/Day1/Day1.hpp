#pragma once

#include <Days/Day.hpp>

#include <string>
#include <vector>

namespace aoc
{
	class Day1 : public Day<int32_t, int32_t>
	{
	public:
		Day1();
		~Day1();

		void Solve() override;
	};
}