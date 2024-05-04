cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)
project(StreetFighter)
set(CMAKE_CXX_STANDARD 11)
add_executable(SF src/SF.cpp src/game.h src/game.cpp src/player.h src/player.cpp src/ryu.h src/ryu.cpp src/zangief.h src/zangief.cpp src/ken.h src/ken.cpp src/chun_li.h src/chun_li.cpp src/dhalsim.h src/dhalsim.cpp src/new_sagat.h src/new_sagat.cpp src/menu.h src/menu.cpp src/button.h src/button.cpp src/balrog.h src/balrog.cpp src/guile.h src/guile.cpp src/credits.h src/credits.cpp src/sound_manager.h src/sound_manager.cpp src/utils.h src/utils.cpp)

# the below lines probably won't work with vcpkg
# so fuck microsoft and vcpkg
# will have to use manual linking
# or switch to linux

find_package(SFML REQUIRED system window graphics)
target_link_libraries(SF PUBLIC sfml-graphics)
target_link_libraries(SF PUBLIC sfml-system)
target_link_libraries(SF PUBLIC sfml-window)
target_link_libraries(SF PUBLIC sfml-audio)
