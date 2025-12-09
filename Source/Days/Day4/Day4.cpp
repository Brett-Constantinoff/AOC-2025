#include <Pch.hpp>

#include <Helpers.hpp>
#include <Days/Day4/Day4.hpp>

namespace aoc
{
	Day4::Day4()
		: Day(4)
	{
		ReadFileIntoVector(m_fileData, m_path.append("Day4\\day4.txt"));
	}

	Day4::~Day4()
	{

	}

	void Day4::Solve()
	{
		bool updated = true;
		int32_t iteration = 1;
		Positions pos = {};

		while (updated)
		{
			updated = false;

			std::size_t rows = m_fileData.size();

			std::vector<std::string> result;
			FastVecCopy(result, m_fileData, rows);

			for (std::size_t i = 0; i < rows; ++i)
			{
				const std::string& row = m_fileData[i];
				std::size_t rowSize = row.size();

				for (std::size_t j = 0; j < rowSize; ++j)
				{
					if (row[j] != '@')
					{
						continue;
					}

					GetPositions(pos, m_fileData[i], rowSize, rows, i, j);

					if (pos.GetRollCount() < 4)
					{
						result[i][j] = '.';
						if (iteration == 1)
						{
							m_part1++;
							m_part2++;
						}
						else
						{
							m_part2++;
						}
						updated = true;
					}
				}
			}
			iteration++;
			m_fileData = std::move(result);
		}
	}

	void Day4::GetPositions(
		Positions& positions, 
		const std::string& row, 
		std::size_t rowSize, 
		std::size_t rows,
		std::size_t i, std::size_t j)
	{
		const bool isTop = i == 0;
		const bool isBottom = i == rows - 1;
		const bool isLeft = j == 0;
		const bool isRight = j == rowSize - 1;

		positions.Left = isLeft
			? '0'
			: row[j - 1];

		positions.TopLeft = isTop
			? '0'
			: isLeft
			? '0'
			: m_fileData[i - 1][j - 1];

		positions.Right = isRight
			? '0'
			: row[j + 1];

		positions.TopRight = isTop
			? '0'
			: isRight
			? '0'
			: m_fileData[i - 1][j + 1];

		positions.Top = isTop
			? '0'
			: m_fileData[i - 1][j];

		positions.Bottom = isBottom
			? '0'
			: m_fileData[i + 1][j];

		positions.BottomLeft = isBottom
			? '0'
			: isLeft
			? '0'
			: m_fileData[i + 1][j - 1];

		positions.BottomRight = isBottom
			? '0'
			: isRight
			? '0'
			: m_fileData[i + 1][j + 1];
	}
}