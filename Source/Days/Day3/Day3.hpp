#include <Days/Day.hpp>

namespace aoc
{
	class Day3 : public Day
	{
	public:
		Day3();
		~Day3();

		void Solve() override;
		[[nodiscard]] std::string FindLargestSubSequence(const std::string& str, int32_t len);


	private:
		int32_t m_part1;
		int64_t m_part2;
	};
}