workspace "Advent of Code 2025"
    configurations { "Debug", "Release" }
    startproject "Days"
    flags { "MultiProcessorCompile" }

    filter "action:vs*"
        buildoptions { "/utf-8" }

    filter "configurations:Debug"
        defines { "DEBUG", "DEBUG_SHADER" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"

group "AOC-2025"
    include "Source/days.lua"