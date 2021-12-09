//
// Created by austi_000 on 1/7/2021.
//

#ifndef GAME_PROJECT_POWERUP_H
#define GAME_PROJECT_POWERUP_H

#include "entity.h"

class powerup : public entity
{
public:

    static Sprite powerup_sprite;
    static bool onMap;

    powerup(float input_x, float input_y);
    ~powerup();

    void update();
};


#endif //GAME_PROJECT_POWERUP_H
