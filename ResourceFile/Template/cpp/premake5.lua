-- premake5.lua
-- created by muhhae

include ("staticlib.lua") --for vcpkg to choose static library for linking

workspace "App"
    configurations { "Debug", "Release" }
    platform "x64" 

project "App"
    kind "ConsoleApp" --App Type
    language "C++" --Languange

    cppdialect "C++latest"
    systemversion "latest" --latest version for windows

    links {

    } 

    targetdir "bin/%{cfg.buildcfg}" 
    objdir "obj/%{cfg.buildcfg}"

    files { 
        "App/**.cpp",
    }

    includedirs {
        "App",
    }

    characterset ("Unicode") --unicode for windows
    staticruntime "On" --static runtime for msvc
    dpiawareness "High" --dpi awareness for windows

    flags {
        "MultiProcessorCompile" --multi processor compile for msvc
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"