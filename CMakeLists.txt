cmake_minimum_required(VERSION 3.21)

project(GDToolsReplayLab VERSION 0.2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

if (NOT DEFINED ENV{GEODE_SDK})
    include(FetchContent)
    FetchContent_Declare(
        Geode
        GIT_REPOSITORY https://github.com/geode-sdk/geode.git
        GIT_TAG main
    )
    FetchContent_MakeAvailable(Geode)
else()
    add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)
endif()

setup_geode_mod(GDToolsReplayLab)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

target_sources(GDToolsReplayLab PRIVATE ${SOURCES})
