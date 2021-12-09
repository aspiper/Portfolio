//
// Created by austi_000 on 8/16/2020.
//

#ifndef GAME_PROJECT_ENTITY_H
#define GAME_PROJECT_ENTITY_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include "rectangle.h"
#include "animation.h"


class entity {
public:

    static sf::Sprite temp_sprite;

    enum entity_direction {spawn, death, up, up_right, right, down_right, down, down_left, left, up_left};
    entity_direction direction;
    Animation animation = Animation(temp_sprite);

    entity(std::string name, float input_x, float input_y, float input_dx, float input_dy, bool is_solid, bool is_bouncy);

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

    uint64_t get_frames_alive() const;
    void increase_frames_alive();

    bool collide(entity other);
    double getCollisionAngle(entity other);

private:
    std::string name;
    bool life;
    bool solid;
    bool bouncy;
    float x;
    float y;
    float dx;
    float dy;
    uint64_t frames_alive;
};

#endif //GAME_PROJECT_ENTITY_H
