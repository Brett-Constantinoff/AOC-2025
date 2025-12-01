#pragma once

#include <string>
#include <vector>

namespace aoc
{
	class Day1
	{
	public:
		Day1();
		~Day1();

		void Solve();

	private:
		std::vector<std::string> m_fileData;
		int32_t m_part1;
		int32_t m_part2;
	};
}