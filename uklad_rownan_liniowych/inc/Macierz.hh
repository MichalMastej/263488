#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "rozmiar.h"
#include "Wektor.hh"

class Macierz {

    Wektor wiersz[ROZMIAR];

    public:

    Macierz();
    Macierz(double tab[ROZMIAR][ROZMIAR]);

    const Wektor &operator [] (int wie) const;
    Wektor &operator [] (int wie);

    const double operator() (int wie, int kol) const;
    double& operator() (int wie, int kol);

    Macierz operator + (Macierz mac);
    Wektor operator * (Wektor wek);

    void zamien(int ktory, int z_ktorym);
    void transponuj();
};

std::istream &operator >> (std::istream &input, Macierz &mac);
std::ostream &operator << (std::ostream &output, Macierz &mac);

#endif