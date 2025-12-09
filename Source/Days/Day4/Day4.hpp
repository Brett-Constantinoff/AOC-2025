#pragma once

#include <Days/Day.hpp>

namespace aoc
{
	class Day4 : public Day<int32_t, int32_t>
	{
		struct Positions
		{
			char Left = '0';
			char Right = '0';
			char TopLeft = '0';
			char TopRight = '0';
			char Top = '0';
			char Bottom = '0';
			char BottomLeft = '0';
			char BottomRight = '0';

			constexpr inline [[nodiscard]] const int32_t GetRollCount() const
			{
				const char roll = '@';

				int32_t count = 0;
				count += Left == roll ? 1 : 0;
				count += Right == roll ? 1 : 0;
				count += TopLeft == roll ? 1 : 0;
				count += TopRight == roll ? 1 : 0;
				count += Top == roll ? 1 : 0;
				count += Bottom == roll ? 1 : 0;
				count += BottomLeft == roll ? 1 : 0;
				count += BottomRight == roll ? 1 : 0;

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