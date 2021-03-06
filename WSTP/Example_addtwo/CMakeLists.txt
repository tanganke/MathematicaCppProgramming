cmake_minimum_required(VERSION 3.10)

project(Example_addtwo)

set(EXE ${PROJECT_NAME})
set(WSTPDirectory ${CMAKE_SOURCE_DIR}/../DeveloperKit/Windows-x86-64)
if(WIN32)
    set(WSPREP ${WSTPDirectory}/CompilerAdditions/wsprep.exe)
endif()

include_directories(${WSTPDirectory}/CompilerAdditions)
link_directories(${WSTPDirectory}/CompilerAdditions)
link_libraries(wstp64i4 wstp64i4m wstp64i4s)

function(WSTPTemplate file)
if(${ARGC} EQUAL 1)
    add_custom_command(
        OUTPUT ${file}.cpp
        COMMAND ${WSPREP} ${CMAKE_SOURCE_DIR}/${file} -o ${file}.cpp
        DEPENDS ${CMAKE_SOURCE_DIR}/${file}
        VERBATIM
    )
elseif(${ARGC} GREATER 1)
    foreach(arg ${ARGN})
        WSTPTemplate(${arg})
    endforeach()
endif()
endfunction()

if(WIN32)
add_custom_target(WSTPDynamicLib
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${WSTPDirectory}/SystemAdditions/wstp64i4.dll ${CMAKE_BINARY_DIR}/wstp64i4.dll
)
endif()

WSTPTemplate(addtwo.tm)
set(SOURCES main.cpp addtwo.tm.cpp)

if(WIN32)
    add_executable(${EXE} WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(${EXE} ${SOURCES})
endif()

add_dependencies(${EXE} WSTPDynamicLib)
