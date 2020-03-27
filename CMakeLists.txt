# cmake_minimum_required(VERSION <specify CMake version here>)
project(Hollow)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lncurses")
add_executable(Hollow main.cpp Player/Player.cpp Player/Player.h Events/RandomEvent.cpp Events/RandomEvent.h Resources/Item.cpp Resources/Item.h Resources/Enemy.cpp Resources/Enemy.h Events/RawEvent.cpp Events/RawEvent.h Resources/Chest.cpp Resources/Chest.h Util.cpp Util.h)
