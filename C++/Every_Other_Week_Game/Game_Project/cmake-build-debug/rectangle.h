//
// Created by austi_000 on 1/3/2021.
//

#ifndef GAME_PROJECT_RECTANGLE_H
#define GAME_PROJECT_RECTANGLE_H


class rectangle
{
public:

    rectangle(double input_x1, double input_y1, double input_x2, double input_y2);

    double get_x1() const;
    void set_x1(double new_x1);

    double get_y1() const;
    void set_y1(double new_y1);

    double get_x2() const;
    void set_x2(double new_x2);

    double get_y2() const;
    void set_y2(double new_y2);

    double get_center_x() const;
    void set_center_x(double new_center_x);

    double get_center_y() const;
    void set_center_y(double new_center_y);

    void setCornerAngles();

    double top_right_angle;
    double bottom_right_angle;
    double bottom_left_angle;
    double top_left_angle;

private:

    double x1;
    double y1;

    double x2;
    double y2;

    double center_x;
    double center_y;
};


#endif //GAME_PROJECT_RECTANGLE_H
