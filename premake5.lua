workspace "2D_Template"
    filename "main"
    configurations { "Debug", "Release" }
    platforms { "Win64" }

project "2D_Template"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    architecture "x86_64"
    
    targetdir "bin/%{cfg.buildcfg}"
    objdir "obj/%{cfg.buildcfg}"

    files { "src/header/*.h", "src/*.cpp" }
    links { "raylib", "gdi32", "winmm", "opengl32" }
    includedirs { "libs/includes" }

    filter "action:gmake"
        libdirs { "libs/binaries/mingw" }
        postbuildcommands {
            "{COPY} libs/binaries/mingw/raylib.dll bin/%{cfg.buildcfg}"
        }

    filter "action:vs*"
        libdirs { "libs/binaries/msvc" }
        postbuildcommands {
            "{COPY} libs/binaries/msvc/raylib.dll bin/%{cfg.buildcfg}"
        }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"