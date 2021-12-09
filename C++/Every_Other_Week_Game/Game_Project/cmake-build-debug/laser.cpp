//
// Created by austi_000 on 1/4/2021.
//

#include "laser.h"

laser::laser(std::string name, float input_x, float input_y, float input_dx, float input_dy) : entity{name, input_x, input_y, input_dx, input_dy, false, true}
{}

red_laser::red_laser(std::string name, float input_x, float input_y, float input_dx, float input_dy): laser{name , input_x , input_y, input_dx , input_dy}
{
    animation.settings(S_red_laser,.75,.75,0,50,20,1);
    sethitbox(get_x(), get_y(), get_x() +38, get_y() + 15);
}

blue_laser::blue_laser(std::string name, float input_x, float input_y, float input_dx, float input_dy): laser{name , input_x , input_y, input_dx , input_dy}
{
    animation.settings(S_blue_laser,.75,.75,0,50,20,1);
    sethitbox(get_x(), get_y(), get_x() +38, get_y() + 15);
}

power_laser::power_laser(std::string name, float input_x, float input_y, float input_dx, float input_dy) : laser{name, input_x, input_y, input_dx, input_dy}
{}

power_laser_red::power_laser_red(float input_x, float input_y, float input_dx, float input_dy) : power_laser{"red_laser", input_x, input_y, input_dx, input_dy}
{
    animation.settings(S_power_laser_red,.75,.75,0,53,26,1);
}

power_laser_blue::power_laser_blue(float input_x, float input_y, float input_dx, float input_dy) : power_laser{"blue_laser", input_x, input_y, input_dx, input_dy}
{
    animation.settings(S_power_laser_blue,.75,.75,0,53,26,1);
}

void laser::update()
{
    set_x(get_x() + get_dx());
    set_y(get_y() + get_dy());

    animation.setAngle(findAngle());
    animation.update(get_x(),get_y());


    increase_frames_alive();
    sethitbox(get_x(), get_y(), get_x() +35, get_y() + 13);
    change_laser_hitbox(findAngle());

}



/****
 *
 *  Class: laser
 *
 *  Function: findAngle
 *
 *  This function takes the velocity vector of the laser and returns the angle at which it is moving in
 *
 ****/
double laser::findAngle() const
{
    double angle;

    if(get_dx() == 0 && get_dy() > 0)
    {
        angle = 90;
    }
    else if (get_dx() == 0 && get_dy() < 0)
    {
        angle = 270;
    }
    else if (get_dx() > 0 && get_dy() == 0)
    {
        angle = 0;
    }
    else if(get_dx() < 0 && get_dy() == 0)
    {
        angle = 180;
    }
    else if (std::abs(get_dx()) == std::abs(get_dy()))
    {
        if (get_dx() == get_dy() && get_dx() > 0)
        {
            angle = 45;
        }
        else if (get_dx() > get_dy())
        {
            angle = 315;
        }
        else if (get_dx() < get_dy())
        {
            angle = 135;
        }
        else if (get_dx() == get_dy() && get_dx() < 0)
        {
            angle = 225;
        }
    }
    else
    {
        angle = std::atan(get_dy()/get_dx()) * (180/M_PI);

        if(get_dx() < 0 && get_dy() != 0)
        {
            angle += 180;
        }
    }
    return angle;
}

void laser::change_laser_hitbox(double angle)
{
    if (angle == 0)
    {
        sethitbox(get_x(), get_y(), get_x() +35, get_y() + 13);
    }
    else if (angle == 180)
    {
        sethitbox(get_x() -35, get_y() -13, get_x(), get_y());
    }
    else if (angle == 90)
    {
        sethitbox(get_x() -11, get_y() +30, get_x(), get_y());
    }
    else if (angle == 270)
    {
        sethitbox(get_x() +11, get_y() -30, get_x(), get_y());
    }
    else if (angle == 45)
    {
        sethitbox(get_x() + 15, get_y() +22, get_x() +21, get_y() + 28);
    }
    else if (angle == 315)
    {
        sethitbox(get_x() + 21, get_y() -22, get_x() +27, get_y() - 16);
    }
    else if (angle == 135)
    {
        sethitbox(get_x() - 27, get_y() +14, get_x() -21, get_y() + 20);
    }
    else if (angle == 225)
    {
        sethitbox(get_x() - 21, get_y() -28, get_x() -15, get_y() - 22);
    }

}

void power_laser::change_laser_hitbox(double angle)
{
    if (angle == 0)
    {
        sethitbox(get_x(), get_y(), get_x() + 40, get_y() + 18);
    }
    else if (angle == 180)
    {
        sethitbox(get_x() - 40, get_y() - 18, get_x(), get_y());
    }
    else if (angle == 90)
    {
        sethitbox(get_x() -18, get_y() +40, get_x(), get_y());
    }
    else if (angle == 270)
    {
        sethitbox(get_x() +18, get_y() -40, get_x(), get_y());
    }
    else if (angle == 45)
    {
        sethitbox(get_x() + 11, get_y() + 29, get_x() +23, get_y() + 17);
    }
    else if (angle == 315)
    {
        sethitbox(get_x() + 23, get_y() -29, get_x() +35, get_y() - 17);
    }
    else if (angle == 135)
    {
        sethitbox(get_x() - 35, get_y() + 11, get_x() - 23, get_y() + 23);
    }
    else if (angle == 225)
    {
        sethitbox(get_x() - 23, get_y() -35, get_x() - 35, get_y() - 23);
    }


}



void power_laser::update()
{
    set_x(get_x() + get_dx());
    set_y(get_y() + get_dy());

    animation.setAngle(findAngle());
    animation.update(get_x(),get_y());
    sethitbox(get_x(), get_y(), get_x() +40, get_y() + 18);
    increase_frames_alive();
    change_laser_hitbox(findAngle());
}
