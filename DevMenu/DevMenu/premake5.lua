project "DevMenu"
    --With console
    --kind "ConsoleApp"

    --Without console
    kind "WindowedApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("../bin/" .. outputdir .. "/%{prj.name}")
    objdir("../bin-int/" .. outputdir .. "/%{prj.name}")

    files{
        "src/**.cpp",
        "header/**.h",
        "imgui/**.h",
        "imgui/**.cpp",
    }

    includedirs {
        "header",
        "imgui",
    }

    defines {
        "WINDOWS"
    }

    filter { "configurations:Debug" }
        buildoptions "/MTd"
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        buildoptions "/MT"
        runtime "Release"
        optimize "on"