#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"

class UkladRownanLiniowych{

    Macierz A;
    Wektor b;

    public:

    Macierz get_value_mac();
    Wektor get_value_wek();

    Wektor oblicz(UkladRownanLiniowych &url);

    friend Wektor oblicz_wektor_bledu(UkladRownanLiniowych url, Wektor x);

    friend std::istream &operator>> (std::istream &input, UkladRownanLiniowych &url);
    friend std::ostream &operator<< (std::ostream &output, UkladRownanLiniowych &url);
};

std::istream &operator>> (std::istream &input, UkladRownanLiniowych &url);
std::ostream &operator<< (std::ostream &output, UkladRownanLiniowych &url);

Wektor oblicz_wektor_bledu(UkladRownanLiniowych url, Wektor x);

#endif