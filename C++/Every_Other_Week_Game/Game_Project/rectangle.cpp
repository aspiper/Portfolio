/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 1/3/2021.
//

#include "rectangle.h"
#include <cmath>

rectangle::rectangle(double input_x1 = 0, double input_y1 = 0, double input_x2 = 0, double input_y2 = 0) : x1{input_x1}, y1{input_y1}, x2{input_x2}, y2{input_y2}
{}

/****************
 *
 *  Class: rectangle
 *
 *  Member Name: setCornerAngles
 *
 *  Because the collision-detection in this game is angle-based, and all entities are rectangular,
 *  it is important to find the angles of all 4 corners of the rectangle relative to the center of mass.
 *  The angles calculated here will be used in the main program to tell the game what range of angles in a collision with this object
 *  counts as a collision from the top, left, etc.
 *
 ****************/

void rectangle::setCornerAngles()
{
    double this_x; //This is the x coordinate of whatever corner is being measured
    double this_y; //This is the y coordinate of whatever cornes is being measured

    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {   //Top left corner
            this_x = x1;
            this_y = y1;
        }
        else if (i == 1)
        {   //Top right corner
            this_x = x2;
            this_y = y1;
        }
        else if (i == 2)
        {   //Bottom right corner
            this_x = x2;
            this_y = y2;
        }
        else
        {   //Bottom left corner
            this_x = x1;
            this_y = y2;
        }

        double y_distance = (center_y - this_y);
        double x_distance = (center_x - this_x);
        double angle = std::atan(y_distance/x_distance) * (180/M_PI);

        if(y_distance < 0 && x_distance > 0)
        {
            angle += 180;
        }
        else if (y_distance > 0 && x_distance > 0)
        {
            angle += 180;
        }
        else if (y_distance > 0 && x_distance < 0)
        {
            angle += 360;
        }

        if (i == 0)
        {
            top_left_angle = angle;
        }
        else if (i == 1)
        {
            top_right_angle = angle;
        }
        else if (i == 2)
        {
            bottom_right_angle = angle;
        }
        else
        {
            bottom_left_angle = angle;
        }
    }
}


/******
*
* Below are the getters and setters for the rectangle class
*
********/

double rectangle::get_x1() const
{
    return x1;
}

void rectangle::set_x1(double new_x1)
{
    x1 = new_x1;
}

double rectangle::get_y1() const
{
    return y1;
}

void rectangle::set_y1(double new_y1)
{
    y1 = new_y1;
}

double rectangle::get_x2() const
{
    return x2;
}

void rectangle::set_x2(double new_x2)
{
    x2 = new_x2;
}

double rectangle::get_y2() const
{
    return y2;
}

void rectangle::set_y2(double new_y2)
{
    y2 = new_y2;
}

double rectangle::get_center_x() const
{
    return center_x;
}

void rectangle::set_center_x(double new_center_x)
{
    center_x = new_center_x;
}

double rectangle::get_center_y() const
{
    return center_y;
}

void rectangle::set_center_y(double new_center_y)
{
    center_y = new_center_y;
}