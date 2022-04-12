#include <iostream>
#include "Wektor.hh"

Wektor::Wektor(){

    for (int i = 0; i < ROZMIAR; i++){
        wyraz[i] = 0;}
}

Wektor::Wektor(double tab[ROZMIAR]){

    for (int i = 0; i < ROZMIAR; i++){
        wyraz[i] = tab[i];}
}

double Wektor::operator [] (int index) const {

    if(index < 0 || index > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indexu" << std::endl; 
    }

    return wyraz[index];
}

double &Wektor::operator [] (int index) {

    if(index < 0 || index > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indexu" << std::endl; 
    }

    return wyraz[index];
}


Wektor Wektor::operator + (Wektor &wek){

    Wektor wynik;

    for (int i = 0; i < ROZMIAR; i++){
        wynik[i] = wyraz[i] + wek[i];}

    return wynik;
}

Wektor Wektor::operator - (Wektor &wek){

    Wektor wynik;

    for (int i = 0; i < ROZMIAR; i++){
        wynik[i] = wyraz[i] - wek[i];}

    return wynik;
}

Wektor Wektor::operator * (double &tmp){

    Wektor wynik;

    for (int i = 0; i < ROZMIAR; i++){
        wynik[i] = tmp * wyraz[i];
    }

    return wynik;
}

Wektor Wektor::operator / (double &tmp){

    Wektor wynik;

    for (int i = 0; i < ROZMIAR; i++){
        wynik[i] = 1/tmp * wyraz[i];
    }

    return wynik;
}

std::istream &operator>> (std::istream &input, Wektor &wek){

    for (int i = 0; i < ROZMIAR; ++i){
        input >> wek[i];
    }

    return input;   
}
std::ostream &operator<< (std::ostream &output, Wektor const &wek){

    for (int i = 0; i < ROZMIAR; ++i){
        output << wek[i] << " ";
    }
    output << std::endl;

    return output;    
}