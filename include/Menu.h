//
// Created by rafal on 08.04.2021.
//

#ifndef ROTATION2D_MENU_H
#define ROTATION2D_MENU_H

#include "Transform.h"
#include "GNUPlot.h"

class Menu
{
private:
    Transform transform;
    Rectangle<double> rectangle;
    int loop_times;
    GNUPlot plot;
public:
    Menu();
    explicit Menu(Rectangle<double> rec);

    void setRotation(double r);
    void setRotationAroundZero(double r);
    void setTranslate(Vector2D<double> t);
    void setScale(double s);
    void setLoop(int l);
    void print_vertex() const;
    void print_sides() const;
    void print_options() const;
    void run();
    void simulate();

    void makeMenu();
};


#endif //ROTATION2D_MENU_H
