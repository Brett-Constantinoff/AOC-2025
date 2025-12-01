#include <Pch.hpp>

#include <Days/Days.hpp>

using namespace aoc;

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	Day1 day1;
	day1.Solve();

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	spdlog::info("AOC 2025 Solve Time - {}ms", duration);
}