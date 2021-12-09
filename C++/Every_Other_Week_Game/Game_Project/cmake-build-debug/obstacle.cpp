//
// Created by austi_000 on 1/2/2021.
//

#include "obstacle.h"

obstacle::obstacle(std::string name, float input_x, float input_y) : entity{name, input_x, input_y, 0, 0, true}
{
}

void obstacle::update()
{
    increase_frames_alive();
}

/***************
 *
 * Below are the constructors for the various obstacles in the game.
 * The objects are created, then stay put the entire game.
 *
 ********************/

barrel::barrel(float input_x, float input_y) : obstacle{"barrel", input_x, input_y}
{
    animation.settings(S_barrel,.4,.4,0, 210, 244, 1);
    animation.update(get_x(),get_y());
    sethitbox(get_x(),get_y(),get_x() + 84, get_y() + 98);

}

crates::crates(float input_x, float input_y) : obstacle("crates", input_x, input_y)
{
    animation.settings(S_crates, .4, .4, 0, 396, 354, 1);
    animation.update(get_x(),get_y());
    sethitbox(get_x(),get_y(), get_x() + 157, get_y() + 142);

}

fence1::fence1(float input_x, float input_y) : obstacle("fence1", input_x, input_y)
{
    animation.settings(S_fence1, .4, .4, 0, 210, 112, 1);
    animation.update(get_x(),get_y());
    sethitbox(get_x(),get_y(), get_x() + 82,get_y() + 44);
}

fence2::fence2(float input_x, float input_y) : obstacle("fence2", input_x, input_y)
{
    animation.settings(S_fence2,.4,.4,0,303,112,1);
    animation.update(get_x(),get_y());
    sethitbox(get_x(),get_y(), get_x() + 121, get_y() + 45);
}

smallRock::smallRock(float input_x, float input_y) : obstacle("smallRock", input_x, input_y)
{
    animation.settings(S_smallRock,.4,.4,0,210,67,1);
    animation.update(get_x(),get_y());
    sethitbox(get_x(),get_y(), get_x() + 84, get_y() + 30);
}

largeRock::largeRock(float input_x, float input_y) : obstacle("largeRock", input_x, input_y)
{
    animation.settings(S_largeRock,.4,.4,0,210,178,1);
    animation.update(get_x(),get_y());
    sethitbox(get_x(),get_y(), get_x() + 84, get_y() + 71);

}