cmake_minimum_required(VERSION 3.14)

project(sample_project
        VERSION 0.1.0
        DESCRIPTION "Sample modern CMake project"
        LANGUAGES CXX
        )

# Enable build caching
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
endif ()

# Set "main project only" options
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # CHANGE PROJECT NAME HERE
    if (SAMPLE_PROJECT_BUILD_TESTS)
        include(CTest)
    endif ()
endif ()

add_subdirectory(extern)
add_subdirectory(src)

# CHANGE PROJECT NAME HERE TOO
if ((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR SAMPLE_PROJECT_BUILD_TESTS) AND BUILD_TESTS)
    add_subdirectory(test)
endif ()