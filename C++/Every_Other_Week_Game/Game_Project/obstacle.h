/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 1/2/2021.
//

#ifndef GAME_PROJECT_OBSTACLE_H
#define GAME_PROJECT_OBSTACLE_H

#include "entity.h"


class obstacle : public entity
{
public:

    obstacle(std::string name, float input_x, float input_y);

    void update();
};

class barrel : public obstacle
{
public:
    static Sprite S_barrel;

    barrel(float input_x, float input_y);
};

class crates : public obstacle
{
public:
    static Sprite S_crates;

    crates(float input_x, float input_y);
};

class fence1 : public obstacle
{
public:
    static Sprite S_fence1;

    fence1(float input_x, float input_y);
};

class fence2 : public obstacle
{
public:
    static Sprite S_fence2;

    fence2(float input_x, float input_y);
};

class smallRock : public obstacle
{
public:
    static Sprite S_smallRock;

    smallRock(float input_x, float input_y);
};

class largeRock : public obstacle
{
public:
    static Sprite S_largeRock;

    largeRock(float input_x, float input_y);
};

#endif //GAME_PROJECT_OBSTACLE_H
