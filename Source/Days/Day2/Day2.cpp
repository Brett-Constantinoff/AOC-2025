#include <Pch.hpp>

#include <Helpers.hpp>
#include <Days/Day2/Day2.hpp>

#include <spdlog/spdlog.h>
#include <unordered_set>
#include <vector>

namespace aoc
{
	Day2::Day2() :
        Day(2)
	{
		ReadFileIntoVector(m_fileData, m_path.append("Day2\\day2.txt"), ',');
	}

	Day2::~Day2()
	{

	}

	void Day2::Solve()
	{
		std::unordered_map<char, int32_t> m = {};
		for (const auto& s : m_fileData)
		{
			size_t pos = s.find('-');

			int64_t start = StrToLongInt(s.substr(0, pos));
			int64_t stop = StrToLongInt(s.substr(pos + 1));

			FindRepeatingDigits(start, stop);
		}
	}

    void Day2::FindRepeatingDigits(const int64_t start, const int64_t stop)
    {
        for (int64_t i = start; i <= stop; ++i)
        {
            int64_t n = i;
            int32_t digits = 0;
            int64_t tmp = n;
            while (tmp > 0)
            {
                tmp /= 10;
                digits++;
            }

            if (digits % 2 == 0)
            {
                int32_t half = digits / 2;
                int64_t divisor = 1;
                for (int32_t j = 0; j < half; j++)
                {
                    divisor *= 10;
                }

                int64_t left = n / divisor;
                int64_t right = n % divisor;

                if (left == right)
                {
                    m_part1 += n;
                }
            }

            for (int32_t k = 1; k <= digits / 2; k++)
            {
                if (digits % k != 0)
                {
                    continue;
                }

                int32_t repeatCount = digits / k;

                int64_t pow10k = 1;
                for (int32_t p = 0; p < digits - k; p++)
                {
                    pow10k *= 10;
                }

                int64_t pattern = n / pow10k;

                int64_t rebuilt = 0;
                int64_t multiplier = 1;
                for (int32_t j = 0; j < repeatCount; j++)
                {
                    rebuilt = rebuilt * static_cast<int64_t>(std::pow(10, k)) + pattern;
                }

                if (rebuilt == n)
                {
                    m_part2 += n;
                    break;
                }
            }
        }
    }

}