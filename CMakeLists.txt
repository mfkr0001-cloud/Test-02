cmake_minimum_required(VERSION 3.21)
project(Ha VERSION 1.0.0)

find_package(Geode REQUIRED)

add_geode_mod(ha
    src/main.cpp
)
