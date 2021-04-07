//
// Created by rafal on 07.04.2021.
//

#include "GNUPlot.h"

GNUPlot::GNUPlot()
{
    vertexFile = "../data/vertex.xy";

    plot.DodajNazwePliku(vertexFile.c_str())
    .ZmienKolor(color)
    .ZmienSzerokosc(thickness)
    .ZmienSposobRys(PzG::SR_Ciagly)
    .ZmienEtykiete("plot");

    plot.UstawZakresX(-plotWidth, plotWidth);
    plot.UstawZakresY(-plotHeight, plotHeight);
}

void GNUPlot::draw()
{
    plot.Inicjalizuj();
    plot.Rysuj();
}