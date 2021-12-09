//
// Created by austi_000 on 8/9/2020.
//

#include <vector>
#include <string>
#include "animation.h"


using namespace sf;

Animation::Animation(Sprite input_sprite, float input_x = 0, float input_y = 0, float input_scale_x = 1, float input_scale_y = 1, int input_frames = 10, int input_rect_width = 100, int input_rect_height = 100, int input_sheet_width = 5): sprite{input_sprite}, x{input_x}, y{input_y}, scale_x{input_scale_x}, scale_y{input_scale_y}, frames{input_frames}, rect_height{input_rect_height}, rect_width{input_rect_width}, sheet_width{input_sheet_width}
{
    sprite.setPosition(Vector2f(x, y));
    sprite.setScale(Vector2f(scale_x,scale_y));
}



/***********************************************************************************
 *
 * Class member: set_sprite
 *
 * This class member sets the sprite which is used by the animation object
 *
 *********************************/

void Animation::set_sprite(Sprite new_sprite)
{
    sprite = new_sprite;
}


/*********
 *
 *  Member Name: update
 *
 *  This member is used at the end of almost every 'update' of an entity. It is used to keep the game's sprites
 *  in their proper places on the screen, and to scroll through each sprite's spritesheet, giving the illusion of motion.
 *
 *********/
void Animation::update(float x, float y)
{
    //Moves the animation to its proper place, if applicable
    sprite.setPosition(x,y);

    if(!stop) //This section changes the current frame of the animation
    {


        if (frame_count >= sheet_width && !(frame_count >= sheet_width * 2))
        {
            sprite.setTextureRect(IntRect (rect_width * (frame_count - sheet_width),rect_height,rect_width ,rect_height));
        }
        else if (frame_count >= (sheet_width * 2))
        {
            sprite.setTextureRect(IntRect (rect_width * (frame_count - (2 * sheet_width)),(rect_height * 2),rect_width ,rect_height));
        }
        else
        {
            sprite.setTextureRect(IntRect (rect_width * frame_count,0,rect_width ,rect_height));
        }

        frame_count += 1; //This keeps track of which frame the animation is currently displaying

        if (frame_count > frames)
        {
            frame_count = 0;
        }
    }
}



/***********
 *
 *  Member name: settings
 *
 *  This member is used to tweak various aspects of an animation as it is needed
 *
 *************/
void Animation::settings(Sprite input_sprite, float input_scale_x, float input_scale_y, int input_frames, int input_rect_width, int input_rect_height, int input_sheet_width)
{
    sprite = input_sprite;
    scale_x = input_scale_x;
    scale_y = input_scale_y;
    frames = input_frames;
    rect_width = input_rect_width;
    rect_height = input_rect_height;
    sheet_width = input_sheet_width;

    sprite.setScale(Vector2f(scale_x,scale_y));

    update(x,y);
}


/**********
 *
 *  Member Names: pause , resume
 *
 *  These members tell the rest of the animation to either continue animating, or to freeze in place
 *
 *********/
void Animation::pause()
{
    stop = true;
}

void Animation::resume()
{
    stop = false;
}


/********
 *
 *  Member Name: setAngle
 *
 *  This member rotates the animation's sprite according to an inputted angle.
 *  This is used most commonly when a laser is shot at different angles
 *
 ********/
void Animation::setAngle(double input_angle)
{
    sprite.setRotation(input_angle);
}