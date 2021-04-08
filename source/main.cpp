#include <iostream>
#include "Menu.h"

int main()
{
    Menu menu;
    char option;
    bool exit = false;
    while (!exit)
    {
        menu.print_options();
        std::cin >> option;

        switch (option)
        {
            case 'R':
            {
                double r;
                std::cout << "Angle (radian): ";
                std::cin >> r;
                menu.setRotation(r);
            }break;
            case 'Z':
            {
                double r;
                std::cout << "Angle (radian): ";
                std::cin >> r;
                menu.setRotationAroundZero(r);
            }break;
            case 'T':
            {
                Vector2D<double> t;
                std::cout << "Translate vector (x y):";
                std::cin >> t;
                menu.setTranslate(t);
            }break;
            case 'S':
            {
                double s;
                std::cout << "Scale: ";
                std::cin >> s;
                menu.setScale(s);
            }break;
            case 'L':
            {
                int l;
                std::cout << "Number of loops: ";
                std::cin >> l;
                menu.setLoop(l);
            }break;
            case 'P':
            {
                menu.print_vertex();
            }break;
            case 'p':
            {
                menu.print_sides();
            }break;
            case 'r':
            {
                menu.run();
            }break;
            case 's':
            {
                menu.simulate();
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