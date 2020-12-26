cmake_minimum_required(VERSION 3.10.2)
project(TurboHiker)

set(CMAKE_CXX_STANDARD 14)

add_executable(TurboHiker
        src/main.cpp
        )

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(TurboHiker sfml-audio sfml-graphics sfml-window sfml-system)
