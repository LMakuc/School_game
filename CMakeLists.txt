cmake_minimum_required(VERSION 3.21)
project(Prvi)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        D:/SDL/Knjižnice/SDL2/include
        D:/SDL/Knjižnice/SDL2_image-2.0.1/include
)
link_directories(
        D:/SDL/Knjižnice/SDL2/lib/x64
        D:/SDL/Knjižnice/SDL2_image-2.0.1/lib/x64

)

add_executable(Prvi
        main.cpp
        Code/Game/Game.h
        Code/Game/Game.cpp
        Code/GameObject/GameObject.h
        Code/GameObject/GameObject.cpp
        Code/TextureManager/TextureManager.h
        Code/TextureManager/TextureManager.cpp
        Code/Map/Map.h
        Code/Map/Map.cpp
        Code/RandomObjects/RandomObjects.h
        Code/RandomObjects/RandomObjects.cpp
        Code/Objects/Animal.h
        Code/Objects/Animal.cpp
        Code/Objects/Scientist.h
        Code/Objects/Scientist.cpp)

target_link_libraries(Prvi SDL2main SDL2 SDL2_image)

#set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")