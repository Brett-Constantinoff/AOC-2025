#include <Pch.hpp>

#include <Clock.hpp>
#include <Days/Days.hpp>

using namespace aoc;

int main()
{
	Clock c;
	{
		Day1 day1;
		day1.Complete();

		Day2 day2;
		day2.Complete();

		Day3 day3;
		day3.Complete();
	}
	c.Stop();

	spdlog::info("AOC 2025 Solve Time - {} seconds", c.Elapsed() / 1000.0f);
}