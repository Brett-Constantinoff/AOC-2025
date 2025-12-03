#pragma once

#include <vector>
#include <string>

namespace aoc
{
	class Day
	{
	public:
		Day();
		~Day();

		virtual void Solve() = 0;

	protected:
		std::vector<std::string> m_fileData;
		std::string m_path;
	};
}