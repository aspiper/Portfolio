/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 8/16/2020.
//

#ifndef GAME_PROJECT_ENTITY_H
#define GAME_PROJECT_ENTITY_H

#include "rectangle.h"
#include "animation.h"
#include <string>



class entity {
public:

    static Sprite temp_sprite; //This is a blank sprite that the entity's animation is set to use when newly constructed.
                               //It is changed out for the proper sprite in each entity's individual constructor

    enum entity_direction {spawn, death, up, up_right, right, down_right, down, down_left, left, up_left};
    entity_direction direction;
    Animation animation;

    entity(std::string name, float input_x = 0, float input_y = 0, float input_dx = 0, float input_dy = 0, bool is_solid = false, bool is_bouncy = false);
    virtual ~entity();

    virtual void update();

    rectangle entity_hitbox;
    void sethitbox(double new_x1, double new_y1, double new_x2, double new_y2);

    std::string getName();

    bool solid_check() const;
    bool bouncy_check() const;

    bool get_life();
    void set_life(bool input_life);

    float get_x() const;
    void set_x(float new_x);

    float get_y() const;
    void set_y(float new_y);

    float get_dx() const;
    void set_dx(float new_dx);

    float get_dy() const;
    void set_dy(float new_dy);

    int get_frames_alive() const;
    void increase_frames_alive();

    bool collide(entity &other);
    double getCollisionAngle(entity &other);

private:
    std::string name;
    bool life; //If 'life' is set to false, then the computer will remove the entity from the game

    bool solid; //By giving every entity basic properties such as being solid or bouncy, it gives the entity class
    bool bouncy; //some modularity, and allows more types of entities to be made in the future with greater ease
    float x;
    float y;
    float dx;
    float dy;
    int frames_alive;
};

#endif //GAME_PROJECT_ENTITY_H
