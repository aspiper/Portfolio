//
// Created by austi_000 on 1/7/2021.
//

#include "powerup.h"



powerup::powerup(float input_x, float input_y) : entity{"powerup", input_x, input_y, 0, 0, false, false}
{
    onMap = true;
    animation.settings(powerup_sprite, 1, 1, 5,63,40,6);
    sethitbox(get_x(),get_y(), get_x() + 60, get_y() + 40);
}

powerup::~powerup()
{
    onMap = false;
}

void powerup::update()
{
    animation.update(get_x(),get_y());
    increase_frames_alive();
}