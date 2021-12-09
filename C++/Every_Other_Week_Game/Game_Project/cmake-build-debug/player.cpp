//
// Created by austi_000 on 1/4/2021.
//

#include "player.h"


player1::player1(std::string input_name, float input_x, float input_y, float input_dx, float input_dy) : entity{input_name , input_x , input_y, input_dx , input_dy, true}, laser_cooldown{0}, powerup_countdown{0}
{
    animation.settings(S_p1_fade_in,.85,.85,11,118,110,8);
    sethitbox(get_x(), get_y(), get_x() + 103, get_y() + 90);
    direction = spawn;
    update();
}
/*************************************************************
 *
 *  Class: player1
 *
 *  Function: update
 *
 *  This function retrieves the latest information about player1 for use by the rest of the program
 *
 *************************************************************/
void player1::update()
{
    //This updates the current position of player1 within the game
    set_x(get_x() + get_dx());
    set_y(get_y() + get_dy());

    //This block  of else if statements returns the direction which player1 is moving in, and pauses the walking animation if player1 is standing still.
    if (get_dx() > 0 && get_dy() == 0)
    {
        if (direction != right)
        {
            animation.settings(S_p1_right,.5,.5,10,183,180,5);
        }
        direction = right;
        sethitbox(get_x(), get_y(), get_x() + 92, get_y() + 87);

    }
    else if (get_dx() > 0 && get_dy() > 0)
    {
        if (direction != down_right)
        {
            animation.settings(S_p1_down_right,.5,.5,10,217,195,4);
        }
        direction = down_right;
        sethitbox(get_x(), get_y(), get_x() + 109, get_y() + 98);

    }
    else if (get_dx() == 0 && get_dy() > 0)
    {
        if (direction != down)
        {
            animation.settings(S_p1_down,.5,.5,10,205,188,5);
        }
        direction = down;
        sethitbox(get_x(), get_y(), get_x() + 104, get_y() + 95);

    }
    else if (get_dx() < 0 && get_dy() > 0)
    {
        if (direction != down_left)
        {
            animation.settings(S_p1_down_left,.5,.5,10,220,200,4);
        }
        direction = down_left;
        sethitbox(get_x(), get_y(), get_x() + 110, get_y() + 100);

    }
    else if (get_dx() < 0 && get_dy() == 0)
    {
        if (direction != left)
        {
            animation.settings(S_p1_left,.5,.5,10,184,177,5);
        }
        direction = left;
        sethitbox(get_x(), get_y(), get_x() + 92, get_y() + 85);


    }
    else if (get_dx() < 0 && get_dy() < 0)
    {
        if (direction != up_left)
        {
            animation.settings(S_p1_up_left,.5,.5,10,224,170,4);
        }
        direction = up_left;
        sethitbox(get_x() +10 , get_y(), get_x() + 112, get_y() + 85);

    }
    else if (get_dx() == 0 && get_dy() < 0)
    {
        if (direction != up)
        {
            animation.settings(S_p1_up,.5,.5,10,245,186,4);
        }
        direction = up;
        sethitbox(get_x() + 15, get_y(), get_x() + 123, get_y() + 93);


    }
    else if (get_dx() >0 && get_dy() < 0)
    {
        if (direction != up_right)
        {
            animation.settings(S_p1_up_right,.5,.5,10,239,180,4);
        }
        direction = up_right;
        sethitbox(get_x(), get_y(), get_x() + 110, get_y() + 90);

    }
    else if (direction == spawn)
    {
        if (get_frames_alive() == 36)
        {
            direction = down;
            animation.settings(S_p1_down,.5,.5,10,205,188,5);
            sethitbox(get_x(), get_y(), get_x() + 103, get_y() + 94);
        }
    }
    else if (direction == death)
    {
        if (death_timer <= 0)
        {
            set_life(false);
        }

        death_timer -= 1;
    }
    if(get_dx() == 0 && get_dy() == 0 && direction != spawn && direction != death)
    {
        animation.pause();
    }
    else
    {
        animation.resume();
    }

    animation.update(get_x(), get_y());
    increase_frames_alive();

    if(laser_cooldown > 0)
    {laser_cooldown -= 1;}

    if (powerup_countdown > 0)
    {   powerup_countdown -= 1;}
}

void player1::die()
{
    set_dx(0);
    set_dy(0);
    direction = death;
    animation.settings(S_p1_death,.74,.74,11,137,130,7);

    death_timer = 37;
}

player2::player2(std::string input_name, float input_x, float input_y, float input_dx, float input_dy) : entity{input_name , input_x , input_y, input_dx , input_dy, true}, laser_cooldown{0}, powerup_countdown{0}
{
    animation.settings(S_p2_fade_in,.65,.65,11,152,145,6);
    sethitbox(get_x(), get_y(), get_x() + 101, get_y() + 94);
    direction = spawn;
    update();
}

void player2::update()
{
    //This updates the current position of player2 within the game
    set_x(get_x() + get_dx());
    set_y(get_y() + get_dy());

    //This block of else if statements returns the direction which player1 is moving in, and pauses the walking animation if player1 is standing still.
    if (get_dx() > 0 && get_dy() == 0)
    {
        if (direction != right)
        {
            animation.settings(S_p2_right,.55,.55,10,177,168,5);
        }
        direction = right;
        sethitbox(get_x(), get_y(), get_x() + 97, get_y() + 92);

    }
    else if (get_dx() > 0 && get_dy() > 0)
    {
        if (direction != down_right)
        {
            animation.settings(S_p2_down_right,.55,.55,10,190,175,5);
        }
        direction = down_right;
        sethitbox(get_x(), get_y(), get_x() + 105, get_y() + 96);

    }
    else if (get_dx() == 0 && get_dy() > 0)
    {
        if (direction != down)
        {
            animation.settings(S_p2_down,.55,.55,10,183,170,5);
        }
        direction = down;
        sethitbox(get_x(), get_y(), get_x() + 101, get_y() + 94);

    }
    else if (get_dx() < 0 && get_dy() > 0)
    {
        if (direction != down_left)
        {
            animation.settings(S_p2_down_left,.60,.60,10,170,160,5);
        }
        direction = down_left;
        sethitbox(get_x(), get_y(), get_x() + 98, get_y() + 90);

    }
    else if (get_dx() < 0 && get_dy() == 0)
    {
        if (direction != left)
        {
            animation.settings(S_p2_left,.55,.55,10,191,180,5);
        }
        direction = left;
        sethitbox(get_x(), get_y(), get_x() + 105, get_y() + 99);

    }
    else if (get_dx() < 0 && get_dy() < 0)
    {
        if (direction != up_left)
        {
            animation.settings(S_p2_up_left,.55,.55,10,209,157,4);
        }
        direction = up_left;
        sethitbox(get_x() + 10, get_y(), get_x() + 115, get_y() + 86);

    }
    else if (get_dx() == 0 && get_dy() < 0)
    {
        if (direction != up)
        {
            animation.settings(S_p2_up,.55,.55,10,207,156,4);
        }
        direction = up;
        sethitbox(get_x() + 10, get_y(), get_x() + 114, get_y() + 86);

    }
    else if (get_dx() >0 && get_dy() < 0)
    {
        if (direction != up_right)
        {
            animation.settings(S_p2_up_right,.6,.6,10,196,150,5);
        }
        direction = up_right;
        sethitbox(get_x(), get_y(), get_x() + 105, get_y() + 86);

    }
    else if (direction == spawn)
    {

        if (get_frames_alive() == 36)
        {
            direction = down;
            animation.settings(S_p2_down,.55,.55,10,183,170,5);
            sethitbox(get_x(), get_y(), get_x() + 101, get_y() + 94);
        }

    }
    else if (direction == death)
    {
        if (death_timer <= 0)
        {
            set_life(false);
        }

        death_timer -= 1;
    }

    if(get_dx() == 0 && get_dy() == 0 && direction != spawn && direction != death)
    {
        animation.pause();
    }
    else
    {
        animation.resume();
    }

    if (laser_cooldown > 0)
    {   laser_cooldown -= 1;}

    if (powerup_countdown > 0)
    {   powerup_countdown -= 1;}

    animation.update(get_x(), get_y());
    increase_frames_alive();
}

void player2::die()
{
    set_dx(0);
    set_dy(0);
    direction = death;
    animation.settings(S_p2_death,.67,.67,11,147,140,7);

    death_timer = 37;
}