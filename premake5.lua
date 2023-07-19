-- premake5.lua
workspace "CPPTemplate"
    configurations { "Debug", "Release" }

SRCDIR = "src"
BUILDDIR = "build"
OBJDIR = "%{BUILDDIR}/obj"
RESFILE = "ResourceFile"


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

    prebuildcommands { 
        "rm -rf %{BUILDDIR}/%{cfg.buildcfg}/",
        "{COPYDIR} %{RESFILE} %{BUILDDIR}/%{cfg.buildcfg}" 
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"
