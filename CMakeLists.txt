cmake_minimum_required(VERSION 3.16)
project(code)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

add_executable(code
        Basic/Basic.cpp
        Basic/evalstate.cpp
        Basic/exp.cpp
        Basic/parser.cpp
        Basic/program.cpp
        Basic/Utils/error.cpp Basic/Utils/error.hpp Basic/Utils/tokenScanner.cpp Basic/Utils/tokenScanner.hpp
        Basic/Utils/strlib.cpp
        )