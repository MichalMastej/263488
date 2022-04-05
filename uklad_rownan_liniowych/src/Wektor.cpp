#include <iostream>
#include "Wektor.hh"

Wektor::Wektor(){}

Wektor Wektor::operator + (Wektor &wek){}

Wektor Wektor::operator - (Wektor &wek){}

Wektor Wektor::operator * (double &tmp){}

Wektor Wektor::operator / (double &tmp){}

std::istream &operator >> (std::istream &input, Wektor &wek){}
std::ostream &operator << (std::ostream &output, Wektor &wek){}