cmake_minimum_required(VERSION 3.5)

project(sdl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
include_directories(C:/SDL2-2.0.20/include)
link_directories(C:/SDL2-2.0.20/lib)
link_libraries(Mingw32 SDL2main SDL2_image SDL2_ttf SDL2_mixer SDL2)

add_executable(sdl main.cpp SDL_include.h Game.h Game.cpp
    State.h State.cpp Sprite.h Sprite.cpp Music.h Music.cpp
    img/ocean.jpg audio/stageState.ogg)
