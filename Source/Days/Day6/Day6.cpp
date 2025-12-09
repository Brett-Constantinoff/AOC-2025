#include <Pch.hpp>

#include <Days/Day6/Day6.hpp>
#include <Helpers.hpp>

#include <array>
#include <algorithm>
#include <numeric>
#include <spdlog/fmt/fmt.h>

namespace aoc
{
	Day6::Day6() 
		: Day(6),
		m_ops{},
		m_columns{}
	{
		ReadFileIntoVector(m_fileData, m_path.append("Day6\\day6.txt"));
	}

	Day6::~Day6()
	{

	}

	void Day6::Solve()
	{
		GetOperators();
		
		std::vector<int64_t> part1Sums(m_columns);
		std::vector<int64_t> part2Sums(m_columns);

		std::vector<std::string> parts = {};
		parts.resize(m_columns);

		bool part2Solved = false;

		// solve
		for (const auto& row : m_fileData)
		{
			SplitString(parts, row, NULL, m_columns);

			// part 1
			for (std::size_t i = 0; i < m_columns; ++i)
			{
				UpdateColumn(parts[i], part1Sums, i);
			}

			if (!part2Solved)
			{
				const std::size_t rowSize = row.size();
				std::size_t col = 0;
				for (std::size_t i = 0; i < rowSize; ++i)
				{
					std::string s = "";
					bool newCol = true;

					for (const auto& row : m_fileData)
					{
						const char c = row[i];
						if (std::isdigit(c))
						{
							s += c;
							newCol = false;
						}
					}
					if (!s.empty())
					{
						UpdateColumn(s, part2Sums, col);
					}

					// if we hit an entire column of spaces, were on a new col
					if (newCol)
					{
						++col;
					}
				}
			}
			
			part2Solved = true;
		}

		m_part1 = std::reduce(part1Sums.begin(), part1Sums.end(), int64_t(0));
		m_part2 = std::reduce(part2Sums.begin(), part2Sums.end(), int64_t(0));
	}

	void Day6::GetOperators()
	{
		std::string& back = m_fileData.back();
		StripWhiteSpace(back);

		for (auto& c : back)
		{
			m_ops.emplace_back(c);
		}

		m_fileData.pop_back();

		m_columns = m_ops.size();
	}

	void Day6::UpdateColumn(
		const std::string& val,
		std::vector<int64_t>& sums, 
		const std::size_t col
		)
	{
		int64_t num = StrToLongInt(val);

		const char op = m_ops[col];
		int64_t& sum = sums[col];

		if (op == '+')
		{
			sum += num;
		}
		else
		{
			if (sum == 0)
			{
				sum = 1;
			}
			sum *= num;
		}
	}
}