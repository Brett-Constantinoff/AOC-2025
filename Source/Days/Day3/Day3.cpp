#include <Pch.hpp>
#include <spdlog/spdlog.h>

#include <Helpers.hpp>
#include <Days/Day3/Day3.hpp>

namespace aoc
{
	Day3::Day3() :
		Day(3)
	{
		ReadFileIntoVector(m_fileData, m_path.append("Day3\\day3.txt"));
	}

	Day3::~Day3()
	{

	}

	void Day3::Solve()
	{
		for (const auto& s : m_fileData)
		{
			m_part1 += StrToInt(FindLargestSubSequence(s, 2));
			m_part2 += StrToLongInt(FindLargestSubSequence(s, 12));
		}
	}

	std::string Day3::FindLargestSubSequence(const std::string& str, int32_t len)
	{
		std::string seq;
		seq.reserve(len);

		int32_t size = static_cast<int32_t>(str.size());
		int32_t canRemove = size - len;

		for (const auto& c : str)
		{
			while (!seq.empty() && c > seq.back() && canRemove > 0)
			{
				seq.pop_back();
				--canRemove;
			}

			seq.push_back(c);
		}

		//return a substring of our len
		return seq.length() > len ? seq.substr(0, len) : seq;
	}
}