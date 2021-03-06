//
// Created by rafal on 08.04.2021.
//

#include "Menu.h"
#include "GNUPlot.h"

#include <iostream>
#include <chrono>
#include <thread>

Menu::Menu() : transform(), loop_times(1), plot()
{
    std::cout << "Please enter rectangle (vertexes)" << std::endl;
    for (int i = 0; i < 4; ++i)
        std::cin >> rectangle[i];
}

Menu::Menu(Rectangle<double> rec) : transform(), rectangle(rec), loop_times(1), plot()
{}

void Menu::setRotation(double r)
{
    transform.rotate(r);
}

void Menu::setRotationAroundZero(double r)
{
    transform.rotateAroundZero(r);
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
    std::cout << "Z - set Rotation Around Zero" << std::endl;
    std::cout << "T - set Translate" << std::endl;
    std::cout << "S - set Scale" << std::endl;
    std::cout << "L - set Number Of Loops" << std::endl;
    std::cout << "P - print vertexes" << std::endl;
    std::cout << "p - print size of sides" << std::endl;
    std::cout << "r - run" << std::endl;
    std::cout << "s - simulate" << std::endl;
    std::cout << "E - exit" << std::endl;
}

void Menu::run()
{
    std::cout << "Starting drawing: " << std::endl;
    for (int i = 0; i < loop_times; ++i)
    {
        transform.transform(rectangle);
        plot.draw(rectangle);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    transform.clear();
    loop_times = 1;
}


void Menu::simulate()
{
    for (int i = 0; i < loop_times; ++i)
    {
        transform.transform(rectangle);
    }
    transform.clear();
    loop_times = 1;
    std::cout << "End of simulation";
}

void Menu::makeMenu()
{
    char option;
    bool exit = false;
    while (!exit)
    {
        print_options();
        std::cin >> option;

        switch (option)
        {
            case 'R':
            {
                double r;
                std::cout << "Angle (degree): ";
                std::cin >> r;
                setRotation(r);
            }break;
            case 'Z':
            {
                double r;
                std::cout << "Angle (degree): ";
                std::cin >> r;
                setRotationAroundZero(r);
            }break;
            case 'T':
            {
                Vector2D<double> t;
                std::cout << "Translate vector (x y):";
                std::cin >> t;
                setTranslate(t);
            }break;
            case 'S':
            {
                double s;
                std::cout << "Scale: ";
                std::cin >> s;
                setScale(s);
            }break;
            case 'L':
            {
                int l;
                std::cout << "Number of loops: ";
                std::cin >> l;
                setLoop(l);
            }break;
            case 'P':
            {
                print_vertex();
            }break;
            case 'p':
            {
                print_sides();
            }break;
            case 'r':
            {
                run();
            }break;
            case 's':
            {
                simulate();
            }break;
            case 'E':
            {
                exit = true;
            }break;
            default:
            {
                std::cout << "This option is not available" << std::endl;
            }break;
        }
    }
}