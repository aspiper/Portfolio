/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 1/4/2021.
//

#include "player.h"

player::player(std::string input_name, float input_x, float input_y, float input_dx, float input_dy) : entity{input_name, input_x, input_y, input_dx, input_dy, true}, laser_cooldown{0}, powerup_countdown{0}
{
    walk_sound.setBuffer(walk_sound_buffer);
    walk_sound.setLoop(true);

    laser_sound.setBuffer(laser_sound_buffer);
    pwr_laser_sound.setBuffer(pwr_laser_sound_buffer);
}

void player::update()
{}

void player::die()
{}

int player::get_laser_cooldown() const
{   return laser_cooldown;}

void player::elapse_laser_cooldown_time()
{   laser_cooldown -= 1;}

/*************************************************************
 *
 *  Class: player
 *
 *  Function: reset_laser_cooldown
 *
 *  This sets the laser cooldown to 7 frames. Which means that the player must wait 7 frames
 *  before they can shoot another laser.
 *
 *************************************************************/
void player::reset_laser_cooldown()
{   laser_cooldown = 7;}

int player::get_powerup_countdown() const
{   return powerup_countdown;}

void player::elapse_powerup_countdown()
{
    if (powerup_countdown > 0)
    {
        powerup_countdown -= 1;
    }
}

/*************************************************************
 *
 *  Class: player
 *
 *  Function: powerup_activate
 *
 *  This sets the powerup countdown to 150, which allows the player to shoot power lasers for 150 frames,
 *  or 5 seconds in real time
 *
 *************************************************************/
void player::powerup_activate()
{   powerup_countdown = 150;}


/*************************************************************
 *
 *  Class: player
 *
 *  Function: start_death_timer
 *
 *  This sets the death timer to 37, which means that the player will show the death animation
 *  for 37 frames, or a little over 1 second in real time.
 *
 *************************************************************/
void player::start_death_timer()
{   death_timer = 37;}

void player::elapse_death_timer()
{   death_timer -= 1;}

int player::get_death_timer()
{   return death_timer;}



player1::player1(std::string input_name, float input_x, float input_y, float input_dx, float input_dy) : player{input_name , input_x , input_y, input_dx , input_dy}
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
 *  Function: update (from virtual 'update' member in entity parent class)
 *
 *  This function retrieves the latest information about player1 for use by the rest of the program
 *  and updates its position within space
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
        if (get_death_timer() <= 0)
        {
            set_life(false);
        }

        elapse_death_timer();
    }
    if(get_dx() == 0 && get_dy() == 0 && direction != spawn && direction != death)
    {
        animation.pause();
        walk_sound.pause();
    }
    else
    {
        animation.resume();
        if (direction != spawn && direction != death && walk_sound.getStatus() != SoundSource::Playing)
        {
            walk_sound.play();
        }

    }

    animation.update(get_x(), get_y());
    increase_frames_alive();

    if(get_laser_cooldown() > 0)
    {   elapse_laser_cooldown_time();} //The time until the player can shoot again is reduced by one frame

    if (get_powerup_countdown() > 0)
    {   elapse_powerup_countdown();}
}

/*************************************************************
 *
 *  Class: player1
 *
 *  Function: die (see virtual 'die' in 'player' class)
 *
 *  This starts the death animation for the player, and essentially
 *  prepares the player entity to be removed from the game.
 *
 *************************************************************/

void player1::die()
{
    set_dx(0);
    set_dy(0);
    direction = death;
    animation.settings(S_p1_death,.74,.74,11,137,130,7);
    p1death_sound.play();

    start_death_timer();
}

player2::player2(std::string input_name, float input_x, float input_y, float input_dx, float input_dy) : player{input_name , input_x , input_y, input_dx , input_dy}
{
    animation.settings(S_p2_fade_in,.65,.65,11,152,145,6);
    sethitbox(get_x(), get_y(), get_x() + 101, get_y() + 94);
    direction = spawn;
    update();
}




/*************************************************************
 *
 *  Class: player2
 *
 *  Function: update (from virtual 'update' member in entity parent class)
 *
 *  This function retrieves the latest information about player2 for use by the rest of the program
 *  and updates its position within space
 *
 *************************************************************/

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
        if (get_death_timer() <= 0)
        {
            set_life(false);
        }

        elapse_death_timer();
    }

    if(get_dx() == 0 && get_dy() == 0 && direction != spawn && direction != death)
    {
        animation.pause();
        walk_sound.pause();
    }
    else
    {
        animation.resume();

        if (direction != spawn && direction != death && walk_sound.getStatus() != SoundSource::Playing)
        {
            walk_sound.play();
        }

    }

    if (get_laser_cooldown() > 0)
    {   elapse_laser_cooldown_time();} //The time until the player can shoot again is reduced by one frame

    if (get_powerup_countdown() > 0)
    {   elapse_powerup_countdown();}

    animation.update(get_x(), get_y());
    increase_frames_alive();
}


/*************************************************************
 *
 *  Class: player2
 *
 *  Function: die (see virtual 'die' in 'player' class)
 *
 *  This starts the death animation for the player, and essentially
 *  prepares the player entity to be removed from the game.
 *
 *************************************************************/
void player2::die()
{
    set_dx(0);
    set_dy(0);
    direction = death;
    animation.settings(S_p2_death,.67,.67,11,147,140,7);
    p2death_sound.play();

    start_death_timer();
}