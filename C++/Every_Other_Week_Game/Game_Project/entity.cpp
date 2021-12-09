/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 8/16/2020.
//

#include "entity.h"
#include <cmath>

using namespace sf;

entity::entity(std::string input_name, float input_x, float input_y, float input_dx, float input_dy, bool is_solid, bool is_bouncy) : animation{temp_sprite}, name{input_name}, x{input_x}, y{input_y}, dx{input_dx}, dy{input_dy}, life{true}, solid{is_solid}, bouncy{is_bouncy}, entity_hitbox{0,0,0,0}, frames_alive{0}
{}

entity::~entity()
{}

void entity::update()
{}

/***********
 *
 *  Class: entity
 *
 *  Member Name: sethitbox
 *
 *  This member sets the rectangle in which the entity can be hit according to inputted coordinates.
 *  (x1, y1) represents the top-left corner of the rectangle, and (x2,y2) represents the bottom-right corner
 *
 **********/

void entity::sethitbox(double new_x1, double new_y1, double new_x2, double new_y2)
{
    entity_hitbox.set_x1(new_x1);
    entity_hitbox.set_y1(new_y1);
    entity_hitbox.set_x2(new_x2);
    entity_hitbox.set_y2(new_y2);
    entity_hitbox.set_center_x(new_x1 + (new_x2 - new_x1)/2);
    entity_hitbox.set_center_y(new_y1 + (new_y2 - new_y1)/2);

    entity_hitbox.setCornerAngles();
}


/***********
 *
 *  Class: entity
 *
 *  Member Names: solid_check, bouncy_check
 *
 *  These members return what the physical properties of the entity are. The game's physics treats entities
 *  differently according to their solidness or bounciness
 *
 **********/

bool entity::solid_check() const
{
    return solid;
}

bool entity::bouncy_check() const
{
    return bouncy;
}


/********
 *
 *  Class: entity
 *
 *  Member Name: collide
 *
 *  This member compares the position of a second entity with its own entity, and returns whether or not
 *  the two are colliding.
 *
 ********/
bool entity::collide(entity &other)
{
    if (entity_hitbox.get_x1() > other.entity_hitbox.get_x2() || other.entity_hitbox.get_x1() > entity_hitbox.get_x2())
    {
        return false;
    }
    else if (entity_hitbox.get_y1() > other.entity_hitbox.get_y2() || other.entity_hitbox.get_y1() > entity_hitbox.get_y2())
    {
        return false;
    }
    else
    {
        return true;
    }
}


/********
 *
 *  Class: entity
 *
 *  Member Name: getCollisionAngle
 *
 *  This member is used whenever a collision takes place and more information is needed.
 *  It returns the angle at which the collision takes place.
 *  It is needed to tell on which side of an entity the collision happened
 *
 ********/
double entity::getCollisionAngle(entity &other)
{
    double angle;
    double x_comparison_point; //The x coordinate from which the angle of collision is determined from
    double y_comparision_point; //The y coordinate from which the angle of collision is determined from
    double y_dc_to_cp; //y distance from center of one object to the comparison point
    double x_dc_to_cp; //x distance from center one object to the comparision point

    if (bouncy_check())
    {
        x_comparison_point = get_dx() * (-2) + entity_hitbox.get_center_x();  //To accurately find the angle of collision, we need to find a point
        y_comparision_point = get_dy() * (-2) + entity_hitbox.get_center_y(); //on the projectile's path which is not inside the other object's
                                                                             //hitbox. So, we use integration and work backwards to find where
                                                                             //the bullet would have been 2 frames ago
                                                                             //(assuming it had the same trajectory 2 frames ago)
    }
    else
    {
        x_comparison_point = entity_hitbox.get_center_x();                  //A collision involving a solid object without a constant speed
        y_comparision_point = entity_hitbox.get_center_y();                 //is more accurately measured if the comparision point
    }                                                                       //is simply the object's center of mass

    x_dc_to_cp = other.entity_hitbox.get_center_x() - x_comparison_point;
    y_dc_to_cp = other.entity_hitbox.get_center_y() - y_comparision_point;


    angle = std::atan(y_dc_to_cp/x_dc_to_cp) * (180/M_PI);

    if(y_dc_to_cp < 0 && x_dc_to_cp > 0)
    {
        angle += 180;
    }
    else if (y_dc_to_cp > 0 && x_dc_to_cp > 0)
    {
        angle += 180;
    }
    else if (y_dc_to_cp > 0 && x_dc_to_cp < 0)
    {
        angle += 360;
    }
    else if (angle == 0 && std::signbit(angle) == false) //If the angle (value of zero) is negative. Note that 0 can have a sign in c++
    {
        angle += 180;
    }

    return angle;
}




/*********
 *
 *  Member Names: increase_frames_alive, get_frames_alive
 *
 *  increase_frames_alive should be seen in almost every entity's 'update' function, and is used
 *  to keep track of how long the entity has existed
 *
 *  frames_alive is primarily used to stop lasers from bouncing around indefinitely
 *
 *********/
void entity::increase_frames_alive()
{
    frames_alive += 1;
}

int entity::get_frames_alive() const
{
    return frames_alive;
}


/*********
 *
 * Getters and setters for variables in the 'entity' class
 *
 *********/


std::string entity::getName()
{
    return name;
}

float entity::get_x() const
{   return x;}

void entity::set_x(float new_x)
{   x = new_x;}

float entity::get_y() const
{   return y;}

void entity::set_y(float new_y)
{   y = new_y;}

float entity::get_dx() const
{   return dx;}

void entity::set_dx(float new_dx)
{   dx = new_dx;}

float entity::get_dy() const
{   return dy;}

void entity::set_dy(float new_dy)
{   dy = new_dy;}

bool entity::get_life()
{   return life;}

void entity::set_life(bool input_life)
{   life = input_life;}











