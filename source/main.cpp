#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"

#include "Rectangle.h"
#include "Transform.h"

#include <chrono>
#include <thread>
#include <cmath>

using namespace std;

int main()
{
    char  Opcja;
    PzG::LaczeDoGNUPlota  Lacze;
    std::fstream i("../data/vertex.xy", std::ios::in | std::ios::out | std::ios::trunc);


    Rectangle<double> a(1, 2, 2, 1, 4, 2, 3, 3);

    i << a << std::endl;
    i << a[0] << std::endl;

    i.close();

    Transform t1;
    t1.rotate(2).scale(1.001);

    Lacze.DodajNazwePliku("../data/vertex.xy")
            .ZmienSposobRys(PzG::SR_Ciagly)
            .ZmienSzerokosc(10).ZmienKolor(0xFF0000);
    Lacze.DodajNazwePliku("../data/vertex.xy")
            .ZmienSposobRys(PzG::SR_Punktowy)
            .ZmienSzerokosc(2).ZmienKolor(0xFF0000);

    Matrix22<double> b(std::cos(M_PI / 180), -std::sin(M_PI / 180), std::sin(M_PI / 180), std::cos(M_PI / 180));


    while (true)
    {
        Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

        Lacze.ZmienTrybRys(PzG::TR_2D);
        Lacze.UstawZakresY(-5,5);
        Lacze.UstawZakresX(-5,5);
        Lacze.Rysuj();


        t1.transform(a);
        a = b * a;

        i.open("../data/vertex.xy", std::ios::in | std::ios::out | std::ios::trunc);

        i << a << std::endl;
        i << a[0] << std::endl;

        i.close();

        std::this_thread::sleep_for(chrono::milliseconds (500));
    }


    cout << "Aby zakonczyc nacisnij ENTER ..." << flush;
    cin >> noskipws >> Opcja;
}