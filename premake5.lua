-- premake5.lua
workspace "CPPTemplate"
    configurations { "Debug", "Release" }

SRCDIR = "src"
BUILDDIR = "build"
OBJDIR = "%{BUILDDIR}/obj"


project "muhhae"
    kind "ConsoleApp"
    language "C++"

    buildoptions {"-std=c++23", "-Wall"}

    targetdir "%{BUILDDIR}/%{cfg.buildcfg}"
    objdir "%{OBJDIR}/%{cfg.buildcfg}"

    files {
        "%{SRCDIR}/**.h",
        "%{SRCDIR}/**.hpp", 
        "%{SRCDIR}/**.cpp"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"