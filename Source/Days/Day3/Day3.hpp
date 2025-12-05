#include <Days/Day.hpp>

namespace aoc
{
	class Day3 : public Day<int32_t, int64_t>
	{
	public:
		Day3();
		~Day3();

	private:
		void Solve() override;

	private:
		[[nodiscard]] std::string FindLargestSubSequence(const std::string& str, int32_t len);
	};
}