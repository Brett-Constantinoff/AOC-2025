project "Days"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    architecture "x64"

    targetdir "%{wks.location}/build/bin/%{cfg.buildcfg}"
    objdir "%{wks.location}/build/bin-int/%{cfg.buildcfg}"

    files 
    { 
        "Days/**.cpp",
        "Days/**.hpp",
        "**.cpp",
        "**.hpp"
    }

    pchheader "Pch.hpp"
    pchsource "Pch.cpp"

    includedirs {
        "%{wks.location}/Source/", 
        "%{wks.location}/External/Logging/include/",
    }

    libdirs {
        "%{wks.location}/build/bin/%{cfg.buildcfg}" 
    }

    filter "configurations:Debug"
        defines { "DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"