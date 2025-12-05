#pragma once

#include <Days/Day.hpp>

namespace aoc
{
	class Day4 : public Day<int32_t, int32_t>
	{
		struct Positions
		{
			char left = '0';
			char right = '0';
			char topLeft = '0';
			char topRight = '0';
			char top = '0';
			char bottom = '0';
			char bottomLeft = '0';
			char bottomRight = '0';

			constexpr inline [[nodiscard]] const int32_t GetRollCount() const
			{
				const char roll = '@';

				int32_t count = 0;
				count += left == roll ? 1 : 0;
				count += right == roll ? 1 : 0;
				count += topLeft == roll ? 1 : 0;
				count += topRight == roll ? 1 : 0;
				count += top == roll ? 1 : 0;
				count += bottom == roll ? 1 : 0;
				count += bottomLeft == roll ? 1 : 0;
				count += bottomRight == roll ? 1 : 0;

				return count;
			}
		};

	public:
		Day4();
		~Day4();

	private:
		void Solve() override;
		void GetPositions(
			Positions& positions,
			const std::string& row,
			std::size_t rowSize,
			std::size_t rows,
			std::size_t i, std::size_t j);
	};
}