/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/


#include "animation.h"
#include "entity.h"
#include "obstacle.h"
#include "laser.h"
#include "player.h"
#include "powerup.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace sf;

Sprite entity::temp_sprite;

Sprite powerup::powerup_sprite;
bool powerup::onMap = false;

Sprite red_laser::S_red_laser;
Sprite blue_laser::S_blue_laser;
Sprite power_laser_red::S_power_laser_red;
Sprite power_laser_blue::S_power_laser_blue;


SoundBuffer player::walk_sound_buffer;
SoundBuffer player::laser_sound_buffer;
SoundBuffer player::pwr_laser_sound_buffer;

Sprite player1::S_p1_fade_in;
Sprite player1::S_p1_right;
Sprite player1::S_p1_left;
Sprite player1::S_p1_up;
Sprite player1::S_p1_down;
Sprite player1::S_p1_down_left;
Sprite player1::S_p1_down_right;
Sprite player1::S_p1_up_left;
Sprite player1::S_p1_up_right;
Sprite player1::S_p1_death;

Sound player1::p1death_sound;

Sprite player2::S_p2_fade_in;
Sprite player2::S_p2_right;
Sprite player2::S_p2_left;
Sprite player2::S_p2_up;
Sprite player2::S_p2_down;
Sprite player2::S_p2_down_left;
Sprite player2::S_p2_down_right;
Sprite player2::S_p2_up_left;
Sprite player2::S_p2_up_right;
Sprite player2::S_p2_death;

Sound player2::p2death_sound;

Sprite barrel::S_barrel;
Sprite crates::S_crates;
Sprite fence1::S_fence1;
Sprite fence2::S_fence2;
Sprite smallRock::S_smallRock;
Sprite largeRock::S_largeRock;



int main() {

/****
 *  The game window is configured and the game's state machine (to switch between the title screen, game, credits, etc.)
 *  is initialized here
 ****/
    const int width = 1600;
    const int height = 900;
    RenderWindow window(VideoMode(width, height), "Game");
    window.setFramerateLimit(30);
    Image icon;
    icon.loadFromFile("images/misc/icon.png");
    window.setIcon(182, 183, icon.getPixelsPtr());
    window.setTitle("Every Other Week");

    enum State {title, ingame, credits, controls};
    State game_state = title;

/************
*  The game's font is initialized here
**************/
    Font game_font;
    if (!game_font.loadFromFile("fonts/PressStart2P-Regular.ttf"))
    {
        std::cout<<"The file PressStart2P-Regular.ttf could not be found."<< std::endl;
        return EXIT_FAILURE;
    }

/******
 * The game's music and sounds are initialized here
 *******/

    Music game_theme_music;
    if (!game_theme_music.openFromFile("Audio/Music/Every_Other_Week.ogg"))
    {
        std::cout<<"The file Every_Other_Week_Theme.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    game_theme_music.setVolume(60);

    SoundBuffer fightBuffer;
    if (!fightBuffer.loadFromFile("Audio/voiceover/fight.ogg"))
    {
        std::cout<<"The file fight.ogg could not be found"<< std::endl;
        return EXIT_FAILURE;
    }
    Sound fight;
    fight.setBuffer(fightBuffer);

    SoundBuffer p1wins_buffer;
    if (!p1wins_buffer.loadFromFile("Audio/voiceover/p1wins.ogg"))
    {
        std::cout<<"The file p1wins.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    Sound p1wins_sound;
    p1wins_sound.setBuffer(p1wins_buffer);

    SoundBuffer p2wins_buffer;
    if (!p2wins_buffer.loadFromFile("Audio/voiceover/p2wins.ogg"))
    {
        std::cout<<"The file p2wins.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    Sound p2wins_sound;
    p2wins_sound.setBuffer(p2wins_buffer);

    SoundBuffer tie_game_buffer;
    if (!tie_game_buffer.loadFromFile("Audio/voiceover/tie_game.ogg"))
    {
        std::cout<<"The file tie_game.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    Sound tie_game_sound;
    tie_game_sound.setBuffer(tie_game_buffer);


    SoundBuffer p1deathBuffer;
    if (!p1deathBuffer.loadFromFile("Audio/voiceover/p1death.ogg"))
    {
        std::cout<<"The file p1death.ogg could not be found"<< std::endl;
    }
    player1::p1death_sound.setBuffer(p1deathBuffer);

    SoundBuffer p2deathBuffer;
    if(!p2deathBuffer.loadFromFile("Audio/voiceover/p2death.ogg"))
    {
        std::cout<<"The file p2death.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    player2::p2death_sound.setBuffer(p2deathBuffer);
    player2::p2death_sound.setVolume(50);

    //walk_sound_buffer was initialized earlier along with the other static class members
    if (!player::walk_sound_buffer.loadFromFile("Audio/misc/walking.ogg"))
    {
        std::cout<<"The file walking.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }

    if (!player::laser_sound_buffer.loadFromFile("Audio/misc/laser.ogg"))
    {
        std::cout<<"The file laser.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }

    if (!player::pwr_laser_sound_buffer.loadFromFile("Audio/misc/power_laser.ogg"))
    {
        std::cout<<"The file power_laser.ogg could not be found."<< std::endl;
        return EXIT_FAILURE;
    }



/*************************
 * Textures and sprites are initialized here
 **********************/



    Texture title_screen_texture;
    Sprite  title_screen;

    Texture map_texture;
    Sprite map;

    Texture powerup_texture;

    Texture barrel_texture;
    Texture crates_texture;
    Texture fence1_texture;
    Texture fence2_texture;
    Texture smallRock_texture;
    Texture largeRock_texture;

    Texture red_laser_texture;
    Texture blue_laser_texture;
    Texture power_laser_red_texture;
    Texture power_laser_blue_texture;

    Texture p1_fade_in_texture;
    Texture p1_death_texture;
    Texture p1_right;
    Texture p1_left;
    Texture p1_up;
    Texture p1_down;
    Texture p1_up_right;
    Texture p1_up_left;
    Texture p1_down_left;
    Texture p1_down_right;

    Texture p2_fade_in_texture;
    Texture p2_death_texture;
    Texture p2_right;
    Texture p2_left;
    Texture p2_up;
    Texture p2_down;
    Texture p2_up_right;
    Texture p2_up_left;
    Texture p2_down_left;
    Texture p2_down_right;

    Texture p1_example_texture;
    Sprite S_p1_example;
    Texture p2_example_texture;
    Sprite S_p2_example;
    Texture powerup_example_texture;
    Sprite S_powerup_example;

/************************
   Textures and sprites are loaded in this section.
 ************************/

    //Miscellaneous textures

    if (!title_screen_texture.loadFromFile("images/Backgrounds/EveryOtherWeekTitle.png"))
    {
        std::cout<<"The file Title_screen.png could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    title_screen.setTexture(title_screen_texture);
    if (!powerup_texture.loadFromFile("images/misc/Powerup.PNG"))
    {
        std::cout<<"The file Powerup.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    powerup::powerup_sprite.setTexture(powerup_texture);


    if(!map_texture.loadFromFile("images/Backgrounds/EveryOtherMap.PNG"))
    {
        std::cout<<"The file EveryOtherMap.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    map.setTexture(map_texture);

    //Obstacle textures

    if (!barrel_texture.loadFromFile("images/Obstacles/barrel.PNG"))
    {
        std::cout<<"The file barrel.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    barrel::S_barrel.setTexture(barrel_texture);

    if(!crates_texture.loadFromFile("images/Obstacles/crates.PNG"))
    {
        std::cout<<"The file crates.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    crates::S_crates.setTexture(crates_texture);

    if(!fence1_texture.loadFromFile("images/Obstacles/fence1.PNG"))
    {
        std::cout<<"The file fence1.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    fence1::S_fence1.setTexture(fence1_texture);

    if(!fence2_texture.loadFromFile("images/Obstacles/fence2.PNG"))
    {
        std::cout<<"The file fence2.PNG could not be found." << std::endl;

        return EXIT_FAILURE;
    }
    fence2::S_fence2.setTexture(fence2_texture);

    if(!smallRock_texture.loadFromFile("images/Obstacles/smallRock.PNG"))
    {
        std::cout<<"The file smallRock.PNG could not be found." << std::endl;

        return EXIT_FAILURE;
    }
    smallRock::S_smallRock.setTexture(smallRock_texture);

    if(!largeRock_texture.loadFromFile("images/Obstacles/largeRock.PNG"))
    {
        std::cout<<"The file largeRock.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    largeRock::S_largeRock.setTexture(largeRock_texture);

    //Laser textures

    if (!red_laser_texture.loadFromFile("images/lasers/LaserNormal.PNG"))
    {
        std::cout<<"The file LaserNormal.PNG could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    red_laser::S_red_laser.setTexture(red_laser_texture);

    if (!blue_laser_texture.loadFromFile("images/lasers/BlueLaser.PNG"))
    {
        std::cout<<"The file BlueLaser.PNG could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    blue_laser::S_blue_laser.setTexture(blue_laser_texture);

    if(!power_laser_red_texture.loadFromFile("images/lasers/red_laser_powerup.PNG"))
    {
        std::cout<<"The file red_laser_powerup.PNG could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    power_laser_red::S_power_laser_red.setTexture(power_laser_red_texture);

    if(!power_laser_blue_texture.loadFromFile("images/lasers/BlueLaserPowerup.PNG"))
    {
        std::cout<<"The file BlueLaserPowerup.PNG could not be found."<<std::endl;
        return EXIT_FAILURE;
    }
    power_laser_blue::S_power_laser_blue.setTexture(power_laser_blue_texture); //PLACEHOLDER/DEBUG

    //Player 1 textures
    if(!p1_fade_in_texture.loadFromFile("images/player1/p1_fade_in.PNG"))
    {
        std::cout<<"The file p1_fade_in.PNG could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    player1::S_p1_fade_in.setTexture(p1_fade_in_texture);

    if(!p1_death_texture.loadFromFile("images/player1/player1_death.PNG"))
    {
        std::cout<<"The file player1_death.PNG could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    player1::S_p1_death.setTexture(p1_death_texture);

    if(!p1_right.loadFromFile("images/player1/p1right.PNG"))
    {
        std::cout<<"The file p1right.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_right.setTexture(p1_right);

    if(!p1_left.loadFromFile("images/player1/p1left.png"))
    {
        std::cout<<"The file p1left.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_left.setTexture(p1_left);

    if(!p1_up.loadFromFile("images/player1/p1up.png"))
    {
        std::cout<<"The file p1up.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_up.setTexture(p1_up);

    if(!p1_down.loadFromFile("images/player1/p1down.png"))
    {
        std::cout<<"The file p1down.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_down.setTexture(p1_down);

    if(!p1_down_left.loadFromFile("images/player1/p1downleft.png"))
    {
        std::cout<<"The file p1downleft.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_down_left.setTexture(p1_down_left);

    if(!p1_down_right.loadFromFile("images/player1/p1downright.png"))
    {
        std::cout<<"The file p1downright.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_down_right.setTexture(p1_down_right);

    if(!p1_up_left.loadFromFile("images/player1/p1upleft.png"))
    {
        std::cout<<"The file p1upleft.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_up_left.setTexture(p1_up_left);

    if(!p1_up_right.loadFromFile("images/player1/p1upright.png"))
    {
        std::cout<<"The file p1upright.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player1::S_p1_up_right.setTexture(p1_up_right);




    //Player 2 textures
    if(!p2_fade_in_texture.loadFromFile("images/player2/p2_fade_in.PNG"))
    {
        std::cout<<"The file p2_fade_in.PNG could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    player2::S_p2_fade_in.setTexture(p2_fade_in_texture);

    if(!p2_death_texture.loadFromFile("images/player2/player2_death.PNG"))
    {
        std::cout<<"The file player2_death.PNG could not be found."<< std::endl;
        return EXIT_FAILURE;
    }
    player2::S_p2_death.setTexture(p2_death_texture);

    if(!p2_right.loadFromFile("images/player2/p2right.PNG"))
    {
        std::cout<<"The file p2right.PNG could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_right.setTexture(p2_right);

    if(!p2_left.loadFromFile("images/player2/p2left.PNG"))
    {
        std::cout<<"The file p2left.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_left.setTexture(p2_left);

    if(!p2_up.loadFromFile("images/player2/p2up.PNG"))
    {
        std::cout<<"The file p2up.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_up.setTexture(p2_up);

    if(!p2_down.loadFromFile("images/player2/p2down.PNG"))
    {
        std::cout<<"The file p2down.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_down.setTexture(p2_down);

    if(!p2_down_left.loadFromFile("images/player2/p2downleft.PNG"))
    {
        std::cout<<"The file p2downleft.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_down_left.setTexture(p2_down_left);

    if(!p2_down_right.loadFromFile("images/player2/p2downright.PNG"))
    {
        std::cout<<"The file p2downright.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_down_right.setTexture(p2_down_right);

    if(!p2_up_left.loadFromFile("images/player2/p2upleft.PNG"))
    {
        std::cout<<"The file p2upleft.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_up_left.setTexture(p2_up_left);

    if(!p2_up_right.loadFromFile("images/player2/p2upright.PNG"))
    {
        std::cout<<"The file p2upright.png could not be found."<< std::endl;

        return EXIT_FAILURE;
    }
    player2::S_p2_up_right.setTexture(p2_up_right);

    //Controls screen example textures

    if (!p1_example_texture.loadFromFile("images/controls_screen/Player1_example.PNG"))
    {
        std::cout<<"The file Player1_example.PNG could not be found."<<std::endl;
        return EXIT_FAILURE;
    }
    S_p1_example.setTexture(p1_example_texture);

    if(!p2_example_texture.loadFromFile("images/controls_screen/Player2_example.PNG"))
    {
        std::cout<<"The file Player2_example.PNG could not be found."<<std::endl;
        return EXIT_FAILURE;
    }
    S_p2_example.setTexture(p2_example_texture);

    if(!powerup_example_texture.loadFromFile("images/controls_screen/Powerup_example.png"))
    {
        std::cout<<"The file Powerup_example.png could not be found."<<std::endl;
        return EXIT_FAILURE;
    }
    S_powerup_example.setTexture(powerup_example_texture);


    ////////////////////////////////

    std::vector<entity*> entities;


    entity *game_barrel;
    entity *game_crates;
    entity *game_fence1;
    entity *game_fence2;
    entity *game_smallRock;
    entity *game_largeRock;


    game_barrel = new barrel(670,440);
    game_crates = new crates(405,263);
    game_fence1 = new fence1(1175,330);
    game_fence2 = new fence2(240,500);
    game_smallRock = new smallRock(925, 250);
    game_largeRock = new largeRock(975, 510);

    entities.push_back(game_barrel);
    entities.push_back(game_crates);
    entities.push_back(game_fence1);
    entities.push_back(game_fence2);
    entities.push_back(game_smallRock);
    entities.push_back(game_largeRock);

    //When the player entities are created later in the program, they will need to be dynamically casted
    //so that their member functions can be accessed. Their dynamic-cast pointers are initialized here.
    player1* player1_dynamic_casted = nullptr;
    player2* player2_dynamic_casted = nullptr;


    const rectangle player_boundary(50,110,1380,690);
    bool restart_needed = false;
    bool end_game = false;
    int endgame_timer = 180; //After a game is won, this is how long it takes the game to return to the title screen
                             //This is so that the winner can bask in their glory for a bit :P
    const int score_needed = 5; //This is the score that a player needs to win the game
    int player1_score = 0;
    int player2_score = 0;

    //Preparing the title screen
    Text title_text;
    title_text.setFont(game_font);
    title_text.setFillColor(Color::Black);
    title_text.setCharacterSize(68);
    title_text.setPosition(233,200);
    title_text.setString("Every Other Week");

    Text play_game;
    play_game.setFillColor(Color::Black);
    play_game.setFont(game_font);
    play_game.setCharacterSize(44);
    play_game.setPosition(425,375);
    play_game.setString("Enter: Play game");

    Text other_options;
    other_options.setFont(game_font);
    other_options.setFillColor(Color::Black);
    other_options.setCharacterSize(44);
    other_options.setPosition(500,450);
    other_options.setString(" T: Controls \n\n C: Credits");
    other_options.setLetterSpacing(.75);


    //Preparing the credits screen
    Text credits_text;
    credits_text.setFont(game_font);
    credits_text.setFillColor(Color::Black);
    credits_text.setCharacterSize(34);
    credits_text.setPosition(125,225);
    credits_text.setString("Code written by Austin Piper \n\nAnimations and artwork by Grace Byers \n\nMusic composed by Andrew Piper \n\nVoiceover by David Reisner \n\n\n\nPress esc to return to title screen");

    //Preparing the controls screen

    RectangleShape controls_backdrop;
    controls_backdrop.setFillColor(Color(85,210,255,230));
    controls_backdrop.setSize(Vector2f(1550,850));
    controls_backdrop.setPosition(20,20);

    S_powerup_example.setPosition(708,550);
    S_p1_example.setPosition(200,100);
    S_p2_example.setPosition(1215,100);

    Text p1_controls;
    p1_controls.setFont(game_font);
    p1_controls.setFillColor(Color::Black);
    p1_controls.setCharacterSize(24);
    p1_controls.setPosition(50, 300);
    p1_controls.setString("Player 1:\n\n\nTo move, use the WASD keys \n\nTo shoot a laser,\npress the spacebar \n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPress esc to return to the title screen");

    Text p2_controls;
    p2_controls.setFont(game_font);
    p2_controls.setFillColor(Color::Black);
    p2_controls.setCharacterSize(24);
    p2_controls.setPosition(900,300);
    p2_controls.setString("Player 2:\n\n\nTo move, use the arrow keys \n\nTo shoot a laser,\npress the right shift key");

    Text powerup_explain;
    powerup_explain.setFont(game_font);
    powerup_explain.setFillColor(Color::Black);
    powerup_explain.setCharacterSize(16);
    powerup_explain.setPosition(350,500);
    powerup_explain.setString("Watch out for power-ups!\nIf you find one, you'll be able to shoot power lasers!");


    Text premise;
    premise.setFont(game_font);
    premise.setFillColor(Color::Black);
    premise.setCharacterSize(18);
    premise.setPosition(400,150);
    premise.setString("The other player just stole YOUR lunch money! \nWhat are YOU gonna do about it?");

    //Preparing the in-game text
    Text game_score;
    game_score.setFont(game_font);
    game_score.setString("Player 1: " + std::to_string(player1_score) + "\t\t  Player 2: " +std::to_string(player2_score));
    game_score.setCharacterSize(40);
    game_score.setFillColor(Color::Black);
    int game_score_alpha = 255; //This is used to set the 'alpha' value of the game_score text later
    game_score.setPosition(115,200);


    Text player1_wins;
    player1_wins.setFont(game_font);
    player1_wins.setString("Player 1 Wins");
    player1_wins.setCharacterSize(32);
    player1_wins.setFillColor(Color::Black);
    player1_wins.setPosition(550,200);

    Text player2_wins;
    player2_wins.setFont(game_font);
    player2_wins.setString("Player 2 Wins");
    player2_wins.setCharacterSize(32);
    player2_wins.setFillColor(Color::Black);
    player2_wins.setPosition(550,200);

    Text tie_game;
    tie_game.setFont(game_font);
    tie_game.setString("The game was a tie!");
    tie_game.setCharacterSize(32);
    tie_game.setFillColor(Color::Black);
    tie_game.setPosition(450,200);


    int round_length = 0; //This keeps track of the length of the current round in frames. Useful for coordinating
    //the animated text

    //Main game loop begins here
    while(window.isOpen()) {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {   window.close();}
        }

        if (game_state == title)
        {
            window.clear(Color::Black);
            window.draw(title_screen);
            window.draw(title_text);
            window.draw(play_game);
            window.draw(other_options);
            window.display();

            if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                game_state = ingame;
                player1_score = 0;
                player2_score = 0;
                game_score.setString("Player 1: " + std::to_string(player1_score) + "\t\t  Player 2: " +std::to_string(player2_score));
                end_game = false;
                restart_needed = true;
                game_theme_music.play();
                game_theme_music.setLoop(true);
            }
            else if (Keyboard::isKeyPressed(Keyboard::C))
            {
                game_state = credits;
            }
            else if (Keyboard::isKeyPressed(Keyboard::T))
            {
                game_state = controls;

                for (int i = 1; i <= 5; i++)
                {
                    window.clear(Color::Black);
                    window.draw(map);

                    controls_backdrop.setSize(Vector2f(i * 310, i * 170));
                    window.draw(controls_backdrop);
                    window.display();
                }
            }
        }
        else if (game_state == credits)
        {
            window.clear(Color::Black);
            window.draw(map);
            window.draw(credits_text);
            window.display();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                game_state = title;
            }
        }
        else if (game_state == controls)
        {
            window.clear(Color::White);

            window.draw(map);
            window.draw(controls_backdrop);
            window.draw(S_p1_example);
            window.draw(S_p2_example);
            window.draw(S_powerup_example);
            window.draw(premise);
            window.draw(powerup_explain);
            window.draw(p1_controls);
            window.draw(p2_controls);

            window.display();

            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                game_state = title;

                round_length = 0;
                for (int i = 1; i <= 5; i++)
                {
                    window.draw(map);
                    controls_backdrop.setSize(Vector2f(1550 - (i * 310), 850 - (i * 170)));
                    window.draw(controls_backdrop);
                    window.display();
                }
            }
        }
        else if (game_state == ingame)
        {
            //In this loop, the game looks at each entity and makes each one perform actions as necessary
            for (int i = 0; i < entities.size(); i++)
            {
                //Players cannot do anything while they are spawning or dying
                if (entities[i]->getName() == "player1" && entities[i]->direction != entity::entity_direction::spawn && entities[i]->direction != entity::entity_direction::death)
                {   //Move player1 within the game according to WASD
                    if (Keyboard::isKeyPressed(Keyboard::W))
                    {
                        entities[i]->set_dy(-7.5);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::A))
                    {
                        entities[i]->set_dx(-7.5);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::S))
                    {
                        entities[i]->set_dy(7.5);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::D))
                    {
                        entities[i]->set_dx(7.5);
                    }

                    //Stop player1 from moving if W, A, S, or D are not pressed
                    if (!(Keyboard::isKeyPressed(Keyboard::S)) && !(Keyboard::isKeyPressed(Keyboard::W)))
                    {
                        entities[i]->set_dy(0);
                    }
                    if (!(Keyboard::isKeyPressed(Keyboard::A)) && !(Keyboard::isKeyPressed(Keyboard::D)))
                    {
                        entities[i]->set_dx(0);
                    }

                    //Player 1 shoots a laser if the spacebar is pressed
                    if (Keyboard::isKeyPressed(Keyboard::Space) && player1_dynamic_casted->get_laser_cooldown() <= 0)
                    {
                        entity *bullet;

                        if (player1_dynamic_casted->get_powerup_countdown() <= 0)
                        {
                            player1_dynamic_casted->laser_sound.play(); //Play the normal laser sound effect
                            if (entities[i]->direction == entity::right)
                            {
                                bullet = new red_laser("red_laser", entities[i]->get_x() + 120,entities[i]->get_y() + 54, 15, 0);
                            }
                            else if (entities[i]->direction == entity::down_right)
                            {
                                bullet = new red_laser{"red_laser", entities[i]->get_x() + 85,entities[i]->get_y() + 105,10.6066, 10.6066};
                            }
                            else if (entities[i]->direction == entity::down)
                            {
                                bullet = new red_laser{"red_laser", entities[i]->get_x() + 98, entities[i]->get_y() + 95, 0, 15};
                            }
                            else if (entities[i]->direction == entity::down_left)
                            {
                                bullet = new red_laser{"red_laser", entities[i]->get_x() + 15,entities[i]->get_y() + 110, -10.6066, 10.6066};
                            }
                            else if (entities[i]->direction == entity::up_left)
                            {
                                bullet = new red_laser{"red_laser", entities[i]->get_x() - 39,entities[i]->get_y() + 10, -10.6066, -10.6066};
                            }
                            else if (entities[i]->direction == entity::left)
                            {
                                bullet = new red_laser("red_laser", entities[i]->get_x() - 39,entities[i]->get_y() + 67, -15, 0);
                            }
                            else if (entities[i]->direction == entity::up)
                            {
                                bullet = new red_laser("red_laser", entities[i]->get_x() - 3, entities[i]->get_y() - 16,0, -15);
                            }
                            else if (entities[i]->direction == entity::up_right)
                            {
                                bullet = new red_laser("red_laser", entities[i]->get_x() + 133,entities[i]->get_y() + 3, 10.6066, -10.6066);
                            }
                        }
                        else
                        {
                            player1_dynamic_casted->pwr_laser_sound.play();
                            if (entities[i]->direction == entity::right)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() + 120, entities[i]->get_y() + 54,15 * 1.5, 0);
                            }
                            else if (entities[i]->direction == entity::down_right)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() + 85, entities[i]->get_y() + 105,10.6066 * 1.5, 10.6066 * 1.5);
                            }
                            else if (entities[i]->direction == entity::down)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() + 98, entities[i]->get_y() + 73, 0,15 * 1.5);
                            }
                            else if (entities[i]->direction == entity::down_left)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() + 15, entities[i]->get_y() + 110,-10.6066 * 1.5, 10.6066 * 1.5);
                            }
                            else if (entities[i]->direction == entity::up_left)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() - 39, entities[i]->get_y() + 10,-10.6066 * 1.5, -10.6066 * 1.5);
                            }
                            else if (entities[i]->direction == entity::left)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() - 39, entities[i]->get_y() + 67,-15 * 1.5, 0);
                            }
                            else if (entities[i]->direction == entity::up)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() - 3, entities[i]->get_y() + 40, 0,-15 * 1.5);
                            }
                            else if (entities[i]->direction == entity::up_right)
                            {
                                bullet = new power_laser_red(entities[i]->get_x() + 133, entities[i]->get_y() + 3, 10.6066 * 1.5, -10.6066 * 1.5);
                            }
                        }
                        entities.push_back(bullet);

                        player1_dynamic_casted->reset_laser_cooldown();
                    }
                }
                    //Players cannot move while they are spawning or dying
                else if (entities[i]->getName() == "player2" && entities[i]->direction != entity::entity_direction::spawn && entities[i]->direction != entity::entity_direction::death)
                {   //Move player2 according to the arrow keys
                    if (Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        entities[i]->set_dy(-7.5);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Left))
                    {
                        entities[i]->set_dx(-7.5);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Down))
                    {
                        entities[i]->set_dy(7.5);
                    }
                    if (Keyboard::isKeyPressed(Keyboard::Right))
                    {
                        entities[i]->set_dx(7.5);
                    }

                    //Stop player2 from moving if no arrow keys are pressed
                    if (!(Keyboard::isKeyPressed(Keyboard::Down)) && !(Keyboard::isKeyPressed(Keyboard::Up)))
                    {
                        entities[i]->set_dy(0);
                    }
                    if (!(Keyboard::isKeyPressed(Keyboard::Left)) && !(Keyboard::isKeyPressed(Keyboard::Right)))
                    {
                        entities[i]->set_dx(0);
                    }

                    //Player 2 shoot a laser if the right shift key is pressed
                    if (Keyboard::isKeyPressed(Keyboard::RShift) && player2_dynamic_casted->get_laser_cooldown() <= 0)
                    {
                        entity *bullet;

                        if (player2_dynamic_casted->get_powerup_countdown() <= 0)
                        {
                            player2_dynamic_casted->laser_sound.play(); //Play the normal laser sound effect
                            if (entities[i]->direction == entity::right)
                            {
                                bullet = new blue_laser("blue_laser", entities[i]->get_x() + 99, entities[i]->get_y() + 57, 15, 0);
                            }
                            else if (entities[i]->direction == entity::down_right)
                            {
                                bullet = new blue_laser{"blue_laser", entities[i]->get_x() + 94, entities[i]->get_y() + 102, 10.6066, 10.6066};
                            }
                            else if (entities[i]->direction == entity::down)
                            {
                                bullet = new blue_laser{"blue_laser", entities[i]->get_x() + 100, entities[i]->get_y() + 95, 0, 15};
                            }
                            else if (entities[i]->direction == entity::down_left)
                            {
                                bullet = new blue_laser{"blue_laser", entities[i]->get_x() + 17, entities[i]->get_y() + 105, -10.6066, 10.6066};
                            }
                            else if (entities[i]->direction == entity::up_left)
                            {
                                bullet = new blue_laser{"blue_laser", entities[i]->get_x() - 39,entities[i]->get_y() + 15, -10.6066, -10.6066};
                            }
                            else if (entities[i]->direction == entity::left)
                            {
                                bullet = new blue_laser("blue_laser", entities[i]->get_x() - 39, entities[i]->get_y() + 73, -15, 0);
                            }
                            else if (entities[i]->direction == entity::up)
                            {
                                bullet = new blue_laser("blue_laser", entities[i]->get_x(), entities[i]->get_y() - 17, 0, -15);
                            }
                            else if (entities[i]->direction == entity::up_right)
                            {
                                bullet = new blue_laser("blue_laser", entities[i]->get_x() + 110,entities[i]->get_y() + 25, 10.6066, -10.6066);
                            }
                        }
                        else
                        {
                            player2_dynamic_casted->pwr_laser_sound.play();
                            if (entities[i]->direction == entity::right)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() + 120, entities[i]->get_y() + 54, 15 * 1.5, 0);
                            }
                            else if (entities[i]->direction == entity::down_right)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() + 85, entities[i]->get_y() + 105, 10.6066 * 1.5, 10.6066 * 1.5);
                            }
                            else if (entities[i]->direction == entity::down)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() + 98, entities[i]->get_y() + 73, 0, 15 * 1.5);
                            }
                            else if (entities[i]->direction == entity::down_left)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() + 15, entities[i]->get_y() + 110, -10.6066 * 1.5, 10.6066 * 1.5);
                            }
                            else if (entities[i]->direction == entity::up_left)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() - 39, entities[i]->get_y() + 10, -10.6066 * 1.5, -10.6066 * 1.5);
                            }
                            else if (entities[i]->direction == entity::left)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() - 39, entities[i]->get_y() + 67,-15 * 1.5, 0);
                            }
                            else if (entities[i]->direction == entity::up)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() - 3, entities[i]->get_y() + 40, 0,-15 * 1.5);
                            }
                            else if (entities[i]->direction == entity::up_right)
                            {
                                bullet = new power_laser_blue(entities[i]->get_x() + 133, entities[i]->get_y() + 3, 10.6066 * 1.5, -10.6066 * 1.5);
                            }
                        }
                        entities.push_back(bullet);
                        player2_dynamic_casted->reset_laser_cooldown();
                    }
                }
                else if (entities[i]->getName() == "red_laser" || entities[i]->getName() == "blue_laser") //Remove a laser from the game if it goes offscreen
                {
                    if (entities[i]->get_x() > 1650
                    || entities[i]->get_x() < -50
                    || entities[i]->get_y() < -50
                    || entities[i]->get_y() > 950)
                    {
                        entities[i]->set_life(false);
                    }
                }
                if (entities[i]->solid_check()) //This keeps the players and all solid objects within the playing area
                {
                    if (entities[i]->get_x() < player_boundary.get_x1() && entities[i]->get_dx() < 0)
                    {
                        entities[i]->set_dx(0);
                    }
                    else if (entities[i]->entity_hitbox.get_x2() > player_boundary.get_x2() && entities[i]->get_dx() > 0)
                    {
                        entities[i]->set_dx(0);
                    }
                    if (entities[i]->get_y() < player_boundary.get_y1() && entities[i]->get_dy() < 0)
                    {
                        entities[i]->set_dy(0);
                    }
                    else if (entities[i]->entity_hitbox.get_y2() > player_boundary.get_y2() && entities[i]->get_dy() > 0)
                    {
                        entities[i]->set_dy(0);
                    }
                }
                if (entities[i]->bouncy_check() && entities[i]->get_frames_alive() > 120) //Bouncy objects are removed after a set time of being alive. This is so that they can't bounce off of other objects for forever
                {
                    entities[i]->set_life(false);
                }
            }
            //This checks for collisions between entities within the game
            for (int i = 0; i < entities.size(); i++)
            {
                for (int j = 0; j < entities.size(); j++)
                 {
                    if (entities[i] != entities[j] && entities[i]->collide(*entities[j]))
                    {
                        if ((entities[i]->getName() == "player1" && entities[j]->getName() == "blue_laser")
                        || entities[i]->getName() == "player2" && entities[j]->getName() == "red_laser")
                        {
                            entities[j]->set_life(false);

                            //Add a point to the player who won the round
                            if (entities[i]->getName() == "player1")
                            {
                                if (entities[i]->direction != entity::entity_direction::death)
                                 {
                                     player2_score += 1;
                                     player1_dynamic_casted->die();
                                 }
                            }
                            else
                            {
                                if (entities[i]->direction != entity::entity_direction::death)
                                {
                                   player1_score += 1;
                                   player2_dynamic_casted->die();
                                }
                            }
                            game_score.setString("Player 1: " + std::to_string(player1_score) + "\t\t  Player 2: " +std::to_string(player2_score));

                        }

                        if ((entities[i]->getName() == "player1" && entities[j]->getName() == "powerup")
                        || (entities[i]->getName() == "player2" && entities[j]->getName() == "powerup"))
                        {
                            if (entities[i]->getName() == "player1")
                            {
                                player1_dynamic_casted->powerup_activate();
                            }
                            else
                            {
                                player2_dynamic_casted->powerup_activate();
                            }
                            entities[j]->set_life(false);
                        }

                        if ((entities[i]->solid_check() && entities[j]->solid_check())) //If both objects are solid, then the collision acts according to the angle at which it takes place
                        {

                            if ((entities[i]->getCollisionAngle(*entities[j]) >= entities[j]->entity_hitbox.top_right_angle && entities[i]->getCollisionAngle(*entities[j]) <= 360)
                            || (entities[i]->getCollisionAngle(*entities[j]) >= 0 && entities[i]->getCollisionAngle(*entities[j]) <= entities[j]->entity_hitbox.bottom_right_angle))
                            {
                                if (entities[i]->get_dx() < 0)
                                 {  entities[i]->set_dx(0);}
                            }
                            else if (entities[i]->getCollisionAngle(*entities[j]) > entities[j]->entity_hitbox.bottom_right_angle && entities[i]->getCollisionAngle(*entities[j]) <= entities[j]->entity_hitbox.bottom_left_angle)
                            {
                                if (entities[i]->get_dy() < 0)
                                 {  entities[i]->set_dy(0);}
                            }
                            else if (entities[i]->getCollisionAngle(*entities[j]) > entities[j]->entity_hitbox.bottom_left_angle && entities[i]->getCollisionAngle(*entities[j]) <= entities[j]->entity_hitbox.top_left_angle)
                            {
                                if (entities[i]->get_dx() > 0)
                                {   entities[i]->set_dx(0);}
                            }
                            else if (entities[i]->getCollisionAngle(*entities[j]) > entities[j]->entity_hitbox.top_left_angle && entities[i]->getCollisionAngle(*entities[j]) < entities[j]->entity_hitbox.top_right_angle)
                            {
                                if (entities[i]->get_dy() > 0)
                                {   entities[i]->set_dy(0);}
                            }
                        }
                        else if (entities[i]->bouncy_check() && entities[j]->solid_check()) //This makes bouncy objects 'bounce' off of solid objects
                        {
                            if ((entities[i]->getCollisionAngle(*entities[j]) >= entities[j]->entity_hitbox.top_right_angle && entities[i]->getCollisionAngle(*entities[j]) <= 360)
                            || (entities[i]->getCollisionAngle(*entities[j]) >= 0 && entities[i]->getCollisionAngle(*entities[j]) <= entities[j]->entity_hitbox.bottom_right_angle))
                            {
                                entities[i]->set_dx(entities[i]->get_dx() * -1);
                            }
                            else if (entities[i]->getCollisionAngle(*entities[j]) > entities[j]->entity_hitbox.bottom_right_angle && entities[i]->getCollisionAngle(*entities[j]) <= entities[j]->entity_hitbox.bottom_left_angle)
                            {
                                entities[i]->set_dy(entities[i]->get_dy() * -1);
                            }
                            else if (entities[i]->getCollisionAngle(*entities[j]) > entities[j]->entity_hitbox.bottom_left_angle && entities[i]->getCollisionAngle(*entities[j]) <= entities[j]->entity_hitbox.top_left_angle)
                            {
                                entities[i]->set_dx(entities[i]->get_dx() * -1);
                            }
                            else if (entities[i]->getCollisionAngle(*entities[j]) > entities[j]->entity_hitbox.top_left_angle && entities[i]->getCollisionAngle(*entities[j]) < entities[j]->entity_hitbox.top_right_angle)
                            {
                                entities[i]->set_dy(entities[i]->get_dy() * -1);
                            }
                            else if (entities[i]->getCollisionAngle(*entities[j]) == entities[j]->entity_hitbox.top_right_angle //If the collision is exactly in a corner
                            || entities[i]->getCollisionAngle(*entities[j]) == entities[j]->entity_hitbox.bottom_right_angle
                            || entities[i]->getCollisionAngle(*entities[j]) == entities[j]->entity_hitbox.bottom_left_angle
                            || entities[i]->getCollisionAngle(*entities[j]) == entities[j]->entity_hitbox.top_left_angle)
                            {
                                entities[i]->set_dx(entities[i]->get_dx() * -1);
                                entities[i]->set_dy(entities[i]->get_dy() * -1);
                            }
                        }
                    }
                }
            }


            if (rand() % 200 == 0 && !powerup::onMap)
            {
                entity *spawned_powerup;
                spawned_powerup = new powerup((rand() % 1330) + 50, (rand() % 580) + 110);
                entities.push_back(spawned_powerup);

                for (int i = 0; i < entities.size(); i++)
                {
                    if (spawned_powerup->collide(*entities[i]) && entities[i]->getName() != "powerup")
                    {   spawned_powerup->set_life(false);}
                }
            }

            for (int i = 0; i < entities.size();) { //This cleans up the game and removes any entities that have 'died' or are supposed to disappear
                if (entities[i]->get_life() == false)
                {
                    if (entities[i]->getName() == "player1" || entities[i]->getName() == "player2")
                    {
                        if (player1_score < score_needed && player2_score < score_needed) //Reset the game board for another round
                        {
                            restart_needed = true;
                        }
                        else //Start the process of ending the game and returning to the title screen
                        {
                            if (!end_game)
                            {
                                end_game = true;
                                endgame_timer = 120;
                            }

                        }

                    }

                    entity *temp = entities[i];
                    entities.erase(entities.begin() + i);
                    delete temp;
                }
                else
                {
                    i++;
                }
            }

            //
            // Entities and text (if needed) are drawn to the screen below this point
            //
            window.clear(Color::Black);
            window.draw(map);
            for (int i = 0; i < entities.size(); i++)
            {
                entities[i]->update();
                window.draw(entities[i]->animation.sprite);
            }

            if (round_length <= 210) //Show the game's score at the start of each round and fade it out as the round begins
            {
                if (round_length > 30)
                {
                    game_score.setFillColor(Color(0, 0, 0, game_score_alpha));

                    if (game_score_alpha >= 5)
                    {   game_score_alpha -= 5;}

                }
                window.draw(game_score);

                if (round_length == 36 && player1_score == 0 && player2_score == 0) //Play the 'fight' voiceover if it is the starting round
                {   fight.play();}
            }

            if (restart_needed) //Reset the game board to prepare it for another round
            {
                for (int i = 0; i < entities.size();)
                {
                    if (entities[i]->getName() == "player1"
                        || entities[i]->getName() == "player2"
                        || entities[i]->getName() == "red_laser"
                        || entities[i]->getName() == "blue_laser"
                        || entities[i]->getName() == "powerup")
                    {
                        entity *temp = entities[i];
                        entities.erase(entities.begin() + i);
                        delete temp;
                    }
                    else
                    {
                        i++;
                    }
                }

                entity *Player1;
                Player1 = new player1("player1", 200, 360, 0, 0);
                player1_dynamic_casted = dynamic_cast<player1 *>(Player1);
                entities.push_back(Player1);

                entity *Player2;
                Player2 = new player2("player2", 1200, 410, 0, 0);
                player2_dynamic_casted = dynamic_cast<player2 *>(Player2);
                entities.push_back(Player2);
                //As mentioned earlier, I am dynamically casting player1 and player2 so that I can use functions exclusive to them in the main program loop

                round_length = 0;
                game_score_alpha = 255;
                game_score.setFillColor(Color(0, 0, 0, 255));
                restart_needed = false;
            }
            else if (end_game) //Prepare the game to end and return to the title screen
            {
                if (player1_score == player2_score)
                {   window.draw(tie_game);}
                else if (player1_score > player2_score)
                {   window.draw(player1_wins);}
                else
                {   window.draw(player2_wins);}

                if (endgame_timer == 120)
                {
                    if (player1_score == score_needed && player2_score == score_needed)
                    {   tie_game_sound.play();}
                    else if (player1_score == score_needed)
                    {   p1wins_sound.play();}
                    else
                    {   p2wins_sound.play();}
                }

                if (endgame_timer <= 0) //Teturn to the title screen if the endgame_timer is done
                {
                    game_state = title;
                    game_theme_music.stop();
                }
                endgame_timer -= 1;
            }

            window.display();
            round_length += 1;


        } //This is the end of the 'ingame' segment
    }
    return 0;
}
