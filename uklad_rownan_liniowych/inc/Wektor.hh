#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include "rozmiar.h"

class Wektor{
    
    double wyraz[ROZMIAR];

    public:

    Wektor();
    Wektor(double tab[ROZMIAR]);

    double operator[] (int index) const;
    double &operator[] (int inedx);

    Wektor operator+ (Wektor &wek);
    Wektor operator- (Wektor &wek);
    Wektor operator* (double &tmp);
    Wektor operator/ (double &tmp);

    double iloczyn_skalarny(Wektor wek_2);
};

std::ostream& operator<< (std::ostream &output, const Wektor &wek);
std::istream& operator>> (std::istream &input, Wektor &wek);

#endif