//
// Created by austi_000 on 1/4/2021.
//

#ifndef GAME_PROJECT_PLAYER_H
#define GAME_PROJECT_PLAYER_H

#include "entity.h"

class player1 : public entity
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

    int laser_cooldown; //This is how long a player must wait after shooting a laser before they can shoot again
    int powerup_countdown; //This is how long a player will shoot power lasers for after getting a powerup
    int death_timer; //gives how long the player's death animation will run for when the player dies


    player1(std::string name, float input_x, float input_y, float input_dx, float input_dy);

    void update();
    void die(); //This sets off the process of the character 'dying'

};

class player2 : public entity
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

    int laser_cooldown; //This is how long a player must wait after shooting a laser before they can shoot again
    int powerup_countdown; //This is how long a player will shoot power lasers for after getting a powerup
    int death_timer; //gives how long the player's death animation will run for when the player dies

    player2(std::string name, float input_x, float input_y, float input_dx, float input_dy);

    void update();
    void die(); //This sets off the process of the character 'dying'
};


#endif //GAME_PROJECT_PLAYER_H
