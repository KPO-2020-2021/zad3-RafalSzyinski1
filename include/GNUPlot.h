//
// Created by rafal on 07.04.2021.
//

#ifndef ROTATION2D_GNUPLOT_H
#define ROTATION2D_GNUPLOT_H

#include <string>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include "lacze_do_gnuplota.hh"

#include "Rectangle.h"

class GNUPlot
{
private:
    std::string vertexFile;

    static const int color = 1;
    static const int thickness = 5;
    static const int plotWidth = 5;
    static const int plotHeight = 5;

    PzG::LaczeDoGNUPlota plot;
    void draw();
public:
    GNUPlot();

    template<typename T>
    void draw(const Rectangle<T>& rec);

    template<typename T>
    void draw(const Vector2D<T>& vec);
};

template<typename T>
void GNUPlot::draw(const Rectangle<T> &rec)
{
    std::ofstream os(vertexFile);
    if (!os)
    {
        std::cerr << "Cannot open " << vertexFile << std::endl;
        return;
    }
    os << rec << std::endl;
    os << rec[0] << std::endl;
    os.close();

    while(os.is_open())
    {}

    draw();
}

template<typename T>
void GNUPlot::draw(const Vector2D<T> &vec)
{
    std::ofstream os(vertexFile);
    if (!os)
    {
        std::cerr << "Cannot open " << vertexFile << std::endl;
        return;
    }
    os << 0 << " " << 0 << std::endl;
    os << vec << std::endl;

    os.close();

    while(os.is_open())
    {}

    draw();
}


#endif //ROTATION2D_GNUPLOT_H
