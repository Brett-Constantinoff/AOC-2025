#pragma once

#include <chrono>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include <psapi.h>

namespace aoc 
{
	inline [[nodiscard]] std::int64_t GetMemoryUsedBytes()
	{
		PROCESS_MEMORY_COUNTERS pmc{};
		GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		return pmc.WorkingSetSize;
	}

	template<typename T>
	void FastVecCopy(
		std::vector<T>& result,
		const std::vector<T>& original,
		std::size_t size)
	{
		result.resize(size);
		std::copy(original.begin(), original.end(), result.begin());
	}

	inline constexpr [[nodiscard]] const char IntToChar(const int32_t n)
	{
		return '0' + n;
	}

	inline constexpr [[nodiscard]] int32_t CharToInt(const char c)
	{
		return c - '0';
	}

	inline [[nodiscard]] int64_t StrToLongInt(const std::string& str)
	{
		return std::stoll(str);
	}

	inline [[nodiscard]] int32_t StrToInt(const std::string& str)
	{
		return std::stoi(str);
	}

	inline [[nodiscard]] std::string LongIntToStr(const int64_t n)
	{
		return std::to_string(n);
	}

	inline [[nodiscard]] std::string IntToStr(const int32_t n)
	{
		return std::to_string(n);
	}

	inline [[nodiscard]] std::string GetRootPath()
	{
		auto cwd = std::filesystem::current_path();
		return cwd.parent_path().string();
	}

	inline void ReadFileIntoVector(std::vector<std::string>& data, const std::string& file)
	{
		std::ifstream fileData(file);
		std::string s;

		while (fileData >> s)
		{
			data.emplace_back(s);
		}
	}

	inline void ReadFileIntoVector(
		std::vector<std::string>& data,
		const std::string& file,
		const char delim
	)
	{
		std::ifstream fileData(file);
		std::string s;

		while (std::getline(fileData, s, delim)) 
		{
			data.emplace_back(s);
		}
	}
}