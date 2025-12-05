#include <Pch.hpp>

#include <Helpers.hpp>
#include <Days/Days.hpp>

using namespace aoc;

int main()
{
	{
		int64_t beforeMem = GetMemoryUsedBytes();

		Day1 day1;
		Day2 day2;
		Day3 day3;
		Day4 day4;

		int64_t solveTime =
			day1.Complete() +
			day2.Complete() +
			day3.Complete() +
			day4.Complete();

		int64_t afterMem = GetMemoryUsedBytes();

		spdlog::info("AOC 2025 Solve Time - {} seconds", solveTime / 1000.0f);
		spdlog::info("AOC 2025 Memory Usage - {} KB", (afterMem - beforeMem) / 1024);
	}
}