cmake_minimum_required(VERSION 3.10)

project(HelloLibraryLink)

if(UNIX)
    set(MathematicaInstallationDir "/usr/local/Wolfram/Mathematica/12.2")
    set(MathematicaIncludeDir "${MathematicaInstallationDir}/SystemFiles/IncludeFiles/C")
elseif(WIN32)
    set(MathematicaInstallationDir "C:/Program Files/Wolfram Reasearch/Mathematica/12.2")
    set(MathematicaIncludeDir "${MathematicaInstallationDir}/SystemFiles/IncludeFiles/C")
endif()



file(GLOB SOURCES src/*.cpp)

set(LIBRARY_NAME mylib)

add_library(${LIBRARY_NAME}
    SHARED
    ${SOURCES}
)

target_include_directories(
    ${LIBRARY_NAME} SYSTEM
    PUBLIC inc 
    PRIVATE ${MathematicaIncludeDir}
)
