#pragma once

#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

namespace aoc 
{
	[[nodiscard]] int32_t StrToInt(const std::string str)
	{
		return std::stoi(str);
	}

	[[nodiscard]] inline std::string GetRootPath()
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
}