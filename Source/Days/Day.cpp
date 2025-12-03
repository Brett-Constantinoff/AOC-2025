#include <Pch.hpp>

#include <Helpers.hpp>
#include <Days/Day.hpp>

namespace aoc
{
	Day::Day() :
		m_fileData{}
	{
		m_path = GetRootPath().append("\\Source\\Days\\");
	}

	Day::~Day()
	{
		m_fileData.clear();
	}
}