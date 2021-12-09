cmake_minimum_required(VERSION 3.16)
project(Game_Project)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_NAME "Game")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")


add_executable(${EXECUTABLE_NAME} main.cpp animation.cpp animation.h entity.cpp entity.h laser.cpp laser.h obstacle.cpp obstacle.h player.cpp player.h powerup.cpp powerup.h rectangle.cpp rectangle.h)

configure_file(fonts/PressStart2P-Regular.ttf fonts/PressStart2P-Regular.ttf COPYONLY)

configure_file(images/misc/icon.png images/misc/icon.png COPYONLY)
configure_file(images/misc/Title_screen.png images/misc/Title_screen.png COPYONLY)
configure_file(images/Backgrounds/EveryOtherWeekTitle.png images/Backgrounds/EveryOtherWeekTitle.png COPYONLY)
configure_file(images/Backgrounds/Title_screen_text.PNG images/Backgrounds/Title_screen_text.PNG COPYONLY)

configure_file(images/misc/temp_texture.png images/misc/temp_texture.png COPYONLY)

configure_file(images/misc/Powerup.PNG images/misc/Powerup.PNG COPYONLY)

configure_file(images/lasers/LaserNormal.PNG images/lasers/LaserNormal.PNG COPYONLY)
configure_file(images/lasers/red_laser_powerup.PNG images/lasers/red_laser_powerup.PNG COPYONLY)
configure_file(images/lasers/BlueLaser.PNG images/lasers/BlueLaser.PNG COPYONLY)
configure_file(images/lasers/BlueLaserPowerup.PNG images/lasers/BlueLaserPowerup.PNG COPYONLY)

configure_file(images/player1/p1right.PNG images/player1/p1right.PNG COPYONLY)
configure_file(images/player1/p1down.png images/player1/p1down.png COPYONLY)
configure_file(images/player1/p1downleft.png images/player1/p1downleft.png COPYONLY)
configure_file(images/player1/p1downright.png images/player1/p1downright.png COPYONLY)
configure_file(images/player1/p1left.png images/player1/p1left.png COPYONLY)
configure_file(images/player1/p1up.png images/player1/p1up.png COPYONLY)
configure_file(images/player1/p1upleft.png images/player1/p1upleft.png COPYONLY)
configure_file(images/player1/p1upright.png images/player1/p1upright.png COPYONLY)
configure_file(images/player1/p1_fade_in.PNG images/player1/p1_fade_in.PNG COPYONLY)
configure_file(images/player1/player1_death.PNG images/player1/player1_death.PNG COPYONLY)

configure_file(images/player2/p2down.PNG images/player2/p2down.PNG COPYONLY)
configure_file(images/player2/p2downleft.PNG images/player2/p2downleft.PNG COPYONLY)
configure_file(images/player2/p2downright.PNG images/player2/p2downright.PNG COPYONLY)
configure_file(images/player2/p2left.PNG images/player2/p2left.PNG COPYONLY)
configure_file(images/player2/p2right.PNG images/player2/p2right.PNG COPYONLY)
configure_file(images/player2/p2up.PNG images/player2/p2up.PNG COPYONLY)
configure_file(images/player2/p2upleft.PNG images/player2/p2upleft.PNG COPYONLY)
configure_file(images/player2/p2upright.PNG images/player2/p2upright.PNG COPYONLY)
configure_file(images/player2/p2_fade_in.PNG images/player2/p2_fade_in.PNG COPYONLY)
configure_file(images/player2/player2_death.PNG images/player2/player2_death.PNG COPYONLY)

configure_file(images/Backgrounds/EveryOtherMap.PNG images/Backgrounds/EveryOtherMap.PNG COPYONLY)

configure_file(images/Obstacles/barrel.PNG images/Obstacles/barrel.PNG COPYONLY)
configure_file(images/Obstacles/crates.PNG images/Obstacles/crates.PNG COPYONLY)
configure_file(images/Obstacles/fence1.PNG images/Obstacles/fence1.PNG COPYONLY)
configure_file(images/Obstacles/fence2.PNG images/Obstacles/fence2.PNG COPYONLY)
configure_file(images/Obstacles/largeRock.PNG images/Obstacles/largeRock.PNG COPYONLY)
configure_file(images/Obstacles/smallRock.PNG images/Obstacles/smallRock.PNG COPYONLY)

configure_file(images/controls_screen/Player1_example.PNG images/controls_screen/Player1_example.PNG COPYONLY)
configure_file(images/controls_screen/Player2_example.PNG images/controls_screen/Player2_example.PNG COPYONLY)
configure_file(images/controls_screen/Powerup_example.png images/controls_screen/Powerup_example.png COPYONLY)

configure_file(Audio/Music/Every_Other_Week.ogg Audio/Music/Every_Other_Week.ogg COPYONLY)
configure_file(Audio/voiceover/p1wins.ogg Audio/voiceover/p1wins.ogg COPYONLY)
configure_file(Audio/voiceover/p2wins.ogg Audio/voiceover/p2wins.ogg COPYONLY)
configure_file(Audio/voiceover/tie_game.ogg Audio/voiceover/tie_game.ogg COPYONLY)
configure_file(Audio/voiceover/fight.ogg Audio/voiceover/fight.ogg COPYONLY)
configure_file(Audio/voiceover/p2death.ogg Audio/voiceover/p2death.ogg COPYONLY)
configure_file(Audio/voiceover/p1death.ogg Audio/voiceover/p1death.ogg COPYONLY)
configure_file(Audio/misc/walking.ogg Audio/misc/walking.ogg COPYONLY)
configure_file(Audio/misc/laser.ogg Audio/misc/laser.ogg COPYONLY)
configure_file(Audio/misc/power_laser.ogg Audio/misc/power_laser.ogg COPYONLY)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules"  ${CMAKE_MODULE_PATH} )

#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
set(SFML_STATIC_LIBRARIES TRUE)

find_package(SFML 2 COMPONENTS network audio graphics window system)
if(SFML_FOUND)
    find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
    #add_executable(SFMLTest main.cpp)
    target_link_libraries(Game sfml-graphics sfml-audio sfml-window)

endif()