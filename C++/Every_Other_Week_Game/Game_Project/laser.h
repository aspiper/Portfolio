/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 1/4/2021.
//

#ifndef GAME_PROJECT_LASER_H
#define GAME_PROJECT_LASER_H


#include "entity.h"



class laser : public entity //This is the generic laser class. All lasers inherit their basic properties from this
{
public:

    laser(std::string name, float input_x, float input_y, float input_dx, float input_dy);

    double findAngle() const;
    virtual void change_laser_hitbox(double angle);
    void update();
};

class red_laser : public laser
{
public:

    static Sprite S_red_laser;

    red_laser(std::string name, float input_x, float input_y, float input_dx, float input_dy);

};

class blue_laser : public laser
{
public:
    static Sprite S_blue_laser;

    blue_laser(std::string name, float input_x, float input_y, float input_dx, float input_dy);

};

class power_laser : public laser
{
public:
    power_laser(std::string name, float input_x, float input_y, float input_dx, float input_dy);

    void change_laser_hitbox(double angle);
    void update();

};
class power_laser_red : public power_laser
{
public:
    static Sprite S_power_laser_red;
    power_laser_red(float input_x, float input_y, float input_dx, float input_dy);
};

class power_laser_blue : public power_laser
{
public:
    static Sprite S_power_laser_blue;
    power_laser_blue(float input_x, float input_y, float input_dx, float input_dy);
};

#endif //GAME_PROJECT_LASER_H
