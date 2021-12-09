/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 1/4/2021.
//

#ifndef GAME_PROJECT_PLAYER_H
#define GAME_PROJECT_PLAYER_H

#include "entity.h"
#include <SFML/Audio.hpp>

class player : public entity
{
public:

    static SoundBuffer walk_sound_buffer;
    static SoundBuffer laser_sound_buffer;
    static SoundBuffer pwr_laser_sound_buffer;
    Sound walk_sound;
    Sound laser_sound;
    Sound pwr_laser_sound;


    player(std::string input_name, float input_x, float input_y, float input_dx, float input_dy);

    void update();
    virtual void die(); //This sets off the process of the character 'dying'

    int get_laser_cooldown() const;
    void elapse_laser_cooldown_time();
    void reset_laser_cooldown();

    int get_powerup_countdown() const; //This tells for how many frames longer the player's powerup will be active
    void elapse_powerup_countdown();
    void powerup_activate(); //Reset the powerup_countdown, which allows the player to shoot power lasers for a set time.

    int get_death_timer();
    void start_death_timer();
    void elapse_death_timer();

private:
    int laser_cooldown; //This is how long a player must wait after shooting a laser before they can shoot again
    int powerup_countdown; //This is how long a player will shoot power lasers for after getting a powerup
    int death_timer; //gives how long the player's death animation will run for when the player dies

};

class player1 : public player
{
public:
    static Sprite S_p1_fade_in;
    static Sprite S_p1_death;
    static Sprite S_p1_right;
    static Sprite S_p1_left;
    static Sprite S_p1_up;
    static Sprite S_p1_down;
    static Sprite S_p1_up_right;
    static Sprite S_p1_up_left;
    static Sprite S_p1_down_left;
    static Sprite S_p1_down_right;

    static Sound p1death_sound;


    player1(std::string name, float input_x, float input_y, float input_dx, float input_dy);

    void update();
    void die(); //This sets off the process of the character 'dying'

};

class player2 : public player
{
public:
    static Sprite S_p2_fade_in;
    static Sprite S_p2_death;
    static Sprite S_p2_right;
    static Sprite S_p2_left;
    static Sprite S_p2_up;
    static Sprite S_p2_down;
    static Sprite S_p2_up_right;
    static Sprite S_p2_up_left;
    static Sprite S_p2_down_left;
    static Sprite S_p2_down_right;

    static Sound p2death_sound;


    player2(std::string name, float input_x, float input_y, float input_dx, float input_dy);

    void update();
    void die();
};


#endif //GAME_PROJECT_PLAYER_H
