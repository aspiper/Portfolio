/*********************
 * The contents of this file are Copyright (C) 2021 by Austin Piper
 **********************/
//
// Created by austi_000 on 8/9/2020.
//

#ifndef GAME_PROJECT_ANIMATION_H
#define GAME_PROJECT_ANIMATION_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Animation
{
public:
    Sprite sprite;
    bool stop;


    Animation(Sprite input_sprite, int input_x = 0, int input_y = 0, float input_scale_x = 1, float input_scale_y = 1, int input_frames = 10, int input_rect_width = 100, int input_rect_height = 100, int input_sheet_width = 5);

    void settings(Sprite input_sprite, float input_scale_x, float input_scale_y, int input_frames, int input_rect_width, int input_rect_height, int input_sheet_width);

    void setAngle(double input_angle);

    void update(int x, int y);

    void pause(); //This member pauses the animation at the current frame.
    void resume(); //This member resumes the animation

private:


    int rect_width; //rect_width and rect_height are the dimensions of a single frame of an animation
    int rect_height;

    float scale_x; //The dimensions of the sprite are stretched by factors of scale_x and scale_y
    float scale_y;

    int x; //These are the 'x' and 'y' coordinates of the top-left corner of the animation
    int y;

    int frames; //This is the amount of frames of an animation. Frames are counted from 0, so if the image contains 5 frames, this will be set to 4. (0,1,2,3,4 for 5 frames in all)
    int sheet_width; //This is how many frames are in each horizontal row of the spritesheet used
    int frame_count = 0; //frame_count is used to keep track of the current frame displayed.
};
#endif //GAME_PROJECT_ANIMATION_H
