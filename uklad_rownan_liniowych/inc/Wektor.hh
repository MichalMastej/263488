#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include "rozmiar.h"

class Wektor
{
    double rozmiar[ROZMIAR];

    public:

    Wektor(double [ROZMIAR]);

    Wektor operator + (Wektor &wek);
    Wektor operator - (Wektor &wek);
    Wektor operator * (double &tmp);
    Wektor operator / (double &tmp);

};

std::ostream& operator << (std::ostream &output, const Wektor &wek);
std::istream& operator >> (std::istream &input, Wektor &wek);

#endif