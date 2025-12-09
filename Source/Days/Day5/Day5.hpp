#pragma once

#include <Days/Day.hpp>

#include <set>

namespace aoc
{
	class Day5 : public Day<int64_t, int64_t>
	{
		struct Range
		{
			int64_t Start = 0;
			int64_t Stop = 0;

			Range(const int64_t start, const int64_t stop) :
				Start{start}, Stop{stop}
			{
			}

			[[nodiscard]] inline const bool InRange(const int64_t n) const
			{
				return n >= Start && n <= Stop;
			}
		};

	public:
		Day5();
		~Day5();

	private:
		void Solve() override;
		void ProcessRanges(const std::size_t rangeEnd);
		[[nodiscard]] const bool ValidIngredient(const int64_t n);

	private:
		std::vector<Range> m_ranges;
		std::vector<Range> m_mergedRanges;
		std::set<int64_t> m_invalidIngredients;
		std::set<int64_t> m_validIngredients;
	};
}