#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "rozmiar.h"
#include "Wektor.hh"

class Macierz {

    Wektor size[ROZMIAR];

    public:

    Macierz(Wektor [ROZMIAR]);
    Macierz operator + (Macierz mac);
    Wektor operator * (Wektor wek);
};

std::istream &operator >> (std::istream &input, Macierz &mac);
std::ostream &operator << (std::ostream &output, Macierz &mac);

#endif