cmake_minimum_required(VERSION 3.10)

project(Example_addtwo)

# set WSTP DeveloperKit directory
set(WSTPDirectory ${CMAKE_SOURCE_DIR}/../DeveloperKit)
if(WIN32)
    set(WSTPDirectory ${WSTPDirectory}/Windows-x86-64)
elseif(UNIX)
    set(WSTPDirectory ${WSTPDirectory}/Linux-x86-64)
endif()

# set include directory, library directory and 'WSPREP'  path
include_directories(${WSTPDirectory}/CompilerAdditions)
link_directories(${WSTPDirectory}/CompilerAdditions)
if(WIN32)
    set(WSPREP ${WSTPDirectory}/CompilerAdditions/wsprep.exe)
elseif(UNIX)
    set(WSPREP ${WSTPDirectory}/CompilerAdditions/wsprep)
endif()

if(WIN32)
add_custom_target(WSTPDynamicLib
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${WSTPDirectory}/SystemAdditions/wstp64i4.dll ${CMAKE_BINARY_DIR}/wstp64i4.dll
)
elseif(UNIX)
add_custom_target(WSTPDynamicLib
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${WSTPDirectory}/SystemAdditions/libWSTP64i4.so ${CMAKE_BINARY_DIR}/libWSTP64i4.so
)
endif()


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

function(add_WSTP_executable EXE)
    if(WIN32)
        add_executable(${EXE} WIN32 ${SOURCES})
        target_link_libraries(${EXE} wstp64i4 wstp64i4m wstp64i4s)
    elseif(UNIX)
        add_executable(${EXE} ${SOURCES})
        target_link_libraries(${EXE} WSTP64i4 pthread uuid dl rt)
    endif()
    add_dependencies(${EXE} WSTPDynamicLib)
endfunction()


WSTPTemplate(addtwo.tm)
set(SOURCES main.cpp addtwo.tm.cpp)

add_WSTP_executable(${PROJECT_NAME})
