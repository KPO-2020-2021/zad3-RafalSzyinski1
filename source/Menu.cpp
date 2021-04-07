//
// Created by rafal on 08.04.2021.
//

#include "Menu.h"
#include "GNUPlot.h"

#include <iostream>
#include <chrono>
#include <thread>

Menu::Menu() : transform(), loop_times(1)
{
    std::cout << "Please enter rectangle (vertexes)" << std::endl;
    for (int i = 0; i < 4; ++i)
        std::cin >> rectangle[i];
}

Menu::Menu(Rectangle<double> rec) : transform(), rectangle(rec), loop_times(1)
{}

void Menu::setRotation(double r)
{
    transform.rotate(r);
}

void Menu::setTranslate(Vector2D<double> t)
{
    transform.translate(t);
}

void Menu::setScale(double s)
{
    transform.scale(s);
}

void Menu::setLoop(int l)
{
    loop_times = l;
}

void Menu::print_vertex() const
{
    std::cout << rectangle << std::endl;
}

void Menu::print_sides() const
{
    auto tab = rectangle.getSizeOfSides();
    for (auto& i : tab)
        std::cout << i << std::endl;
}

void Menu::print_options() const
{
    std::cout << "Menu:" << std::endl;
    std::cout << "R - set Rotation" << std::endl;
    std::cout << "T - set Translate" << std::endl;
    std::cout << "S - set Scale" << std::endl;
    std::cout << "L - set Number Of Loops" << std::endl;
    std::cout << "P - print vertexes" << std::endl;
    std::cout << "p - print size of sides" << std::endl;
    std::cout << "r - run" << std::endl;
    std::cout << "E - exit" << std::endl;
}

void Menu::run()
{
    GNUPlot plot;
    std::cout << "Starting drawing: " << std::endl;
    for (int i = 0; i < loop_times; ++i)
    {
        transform.transform(rectangle);
        plot.draw(rectangle);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

