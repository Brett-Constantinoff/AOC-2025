#include <Pch.hpp>

#include <Days/Day5/Day5.hpp>
#include <Helpers.hpp>

#include <spdlog/spdlog.h>

namespace aoc
{
	Day5::Day5()
		: Day(5), m_ranges{},
		m_mergedRanges{},
		m_invalidIngredients{},
		m_validIngredients{}
	{
		ReadFileIntoVector(m_fileData, m_path.append("Day5\\day5.txt"));
	}

	Day5::~Day5()
	{

	}

	void Day5::Solve()
	{
		// find the end of the valid ranges
		auto it = std::find(m_fileData.begin(), m_fileData.end(), "");
		const std::size_t rangeEnd = std::distance(m_fileData.begin(), it);
		const std::size_t ingredientsStart = rangeEnd + 1;

		const std::size_t size = m_fileData.size();

		ProcessRanges(rangeEnd);

		for (std::size_t i = ingredientsStart; i < size - 1; ++i)
		{
			const int64_t n = StrToLongInt(m_fileData[i]);
			const bool res = ValidIngredient(n);

			if (res)
			{
				m_part1++;
			}
		}
	}

	void Day5::ProcessRanges(const std::size_t rangeEnd)
	{
		std::vector<std::string> range{};

		for (std::size_t i = 0; i < rangeEnd; ++i)
		{
			range.reserve(2);

			const std::string& s = m_fileData[i];
			SplitString(range, s, '-');

			const int64_t start = StrToLongInt(range[0]);
			const int64_t stop = StrToLongInt(range[1]);

			m_ranges.emplace_back(start, stop);

			range.clear();
		}

		m_mergedRanges.reserve(m_ranges.size());

		std::sort(m_ranges.begin(), m_ranges.end(),
			[](auto& a, auto& b) { return a.Start < b.Start; });

		/*
			The way this works is as follows, say we have the following ranges [1, 3], [5, 15], [14, 20],
			our merged ranges always includes the smallest range so {[1, 3]}

			When we get to the new range of [5-9] we check:
				* is 5 <= 4 (3 + 1)
				* its not so we add a new range and our ranges become {[1, 3], [5, 15]}
			
			When we get to the range of [14, 20], now we check against [5, 15]:
				* is 5 <= 20 + 1
				* it is, so now we modify our ranges to be {[1, 3], [5, 20]}
		*/
		m_mergedRanges.emplace_back(m_ranges[0].Start, m_ranges[0].Stop);
		for (const auto& r : m_ranges)
		{
			auto& back = m_mergedRanges.back();

			if (r.Start <= back.Stop + 1)
			{
				back.Stop = std::max(back.Stop, r.Stop);
			}
			else
			{
				m_mergedRanges.emplace_back(r.Start, r.Stop);
			}
		}

		/*
			With our example above of {[1, 3], [5, 20]}

			All we have to do now is calculate the difference in ranges so:
				* 3 - 1 + 1 = 3
				* 20 - 5 + 1 = 16
				* 16 + 3 = 19

			If we look at the numbers in these ranges they are:
				* 1, 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 = 19 digits
		*/
		for (const auto& r : m_mergedRanges)
		{
			m_part2 += r.Stop - r.Start + 1;
		}
	}

	const bool Day5::ValidIngredient(const int64_t n)
	{
		if (m_validIngredients.contains(n))
		{
			return true;
		}
		if (m_invalidIngredients.contains(n))
		{
			return false;
		}

		for (const auto& range : m_ranges)
		{
			if (range.InRange(n))
			{
				m_validIngredients.insert(n);
				return true;
			}
		}

		m_invalidIngredients.insert(n);
		return false;
	}
}