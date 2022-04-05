#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

class UkladRownanLiniowych{

    public:
    Macierz A;
    Wektor b;

    Wektor oblicz(UkladRownanLiniowych &url);
};

std::istream &operator >> (std::istream &input, UkladRownanLiniowych &url);
std::ostream &operator << (std::ostream &output, UkladRownanLiniowych &url);

#endif