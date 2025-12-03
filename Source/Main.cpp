#include <Pch.hpp>

#include <Clock.hpp>
#include <Days/Days.hpp>

using namespace aoc;

int main()
{
	Clock::Start();
	{
		Day1 day1;
		day1.Solve();

		Day2 day2;
		day2.Solve();

		Day3 day3;
		day3.Solve();
	}
	Clock::Stop();

	spdlog::info("AOC 2025 Solve Time - {} seconds", Clock::Elapsed() / 1000.0f);
}