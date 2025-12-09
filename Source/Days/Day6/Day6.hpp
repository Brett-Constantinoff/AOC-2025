#pragma once

#include <Days/Day.hpp>

namespace aoc
{
	class Day6 : public Day<int64_t, int64_t>
	{
	public:
		Day6();
		~Day6();

	private:
		void Solve() override;
		void GetOperators();
		void UpdateColumn(
			const std::string& val,
			std::vector<int64_t>& sums,
			const std::size_t col
		);

	private:
		std::vector<char> m_ops;
		std::size_t m_columns;
	};
}