#pragma once

#include <chrono>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <sstream>
#include <windows.h>
#include <psapi.h>
#include <cctype>

namespace aoc 
{
	inline [[nodiscard]] std::int64_t GetMemoryUsedBytes()
	{
		PROCESS_MEMORY_COUNTERS pmc{};
		GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		return pmc.WorkingSetSize;
	}

	inline void GetStringDigitsOnly(
		std::vector<char> digits,
		const std::string& s
	)
	{
		for (char c : s)
		{
			if (std::isdigit(c))
			{
				digits.emplace_back(c);
			}
		}
	}

	inline void StripWhiteSpace(std::string& s)
	{
		s.erase(std::remove_if(s.begin(), s.end(),
			[](unsigned char c) { return std::isspace(c); }),
			s.end());
	}

	inline void SplitString(
		std::vector<std::string>& parts,
		const std::string& s,
		const char delim = NULL,
		const std::size_t count = -1)
	{
		// split and ignore all whitespace
		if (delim == NULL)
		{
			std::stringstream ss(s);
			std::string item = "";

			std::size_t i = 0;
			while (ss >> item)
			{
				if (count != -1)
				{
					parts[i] = item;
					++i;
				}
				else 
				{
					parts.emplace_back(item);
				}
			}
			return;
		}

		std::size_t start = 0;
		std::size_t pos = 0;
		std::size_t i = 0;
		while ((pos = s.find(delim, start)) != std::string::npos) 
		{
			std::string sub = s.substr(start, pos - start);
			if (count != -1)
			{
				parts[i] = sub;
			}
			else
			{
				parts.emplace_back(sub);
			}
			start = pos + 1;
		}

		parts.emplace_back(s.substr(start));
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
		std::string line;

		while (std::getline(fileData, line))
		{
			data.emplace_back(line);
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