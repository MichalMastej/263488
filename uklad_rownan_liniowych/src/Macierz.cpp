#include "Macierz.hh"

const Wektor &Macierz::operator[] (int wie) const {

    if(wie < 0 || wie > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indeksu" << std::endl;
    }

    return wiersz[wie];
}
Wektor &Macierz::operator[] (int wie) {

    if(wie < 0 || wie > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indeksu" << std::endl;
    }

    return wiersz[wie];
}

const double Macierz::operator() (int wie, int kol) const {

    if(wie < 0 || wie > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indeksu" << std::endl;
    }

    if(kol < 0 || kol > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indeksu" << std::endl;
    }

    return wiersz[wie][kol];
}

double& Macierz::operator() (int wie, int kol){

    if(wie < 0 || wie > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indeksu" << std::endl;
    }

    if(kol < 0 || kol > ROZMIAR){
        std::cerr << std::endl << "Brak takiego indeksu" << std::endl;
    }

    return wiersz[wie][kol];
}

Macierz::Macierz(){

    for (int i = 0; i < ROZMIAR; ++i){
        for (int j = 0; j < ROZMIAR; ++j){
            wiersz[i][j] = 0;
        }
    }
}

Macierz::Macierz(double tab[ROZMIAR][ROZMIAR]){

    for (int i = 0; i < ROZMIAR; ++i){
        for (int j = 0; j < ROZMIAR; ++j){
            wiersz[i][j] = tab[i][j];
        }
    }
}

Macierz Macierz::operator+ (Macierz mac) {

    Macierz wynik;

    for (int i = 0; i < ROZMIAR; ++i){
        for (int j = 0; j < ROZMIAR; ++j){
            wynik[i][j] = wiersz[i][j] + mac[i][j];
        }
    }

    return wynik;
}

//Wektor Macierz::operator* (Wektor wek){}

void Macierz::zamien(int ktory, int z_ktorym){

    Wektor tmp;

    tmp = wiersz[ktory];
    wiersz[ktory] = wiersz[z_ktorym];
    wiersz[z_ktorym] = tmp;
}

std::istream &operator>> (std::istream &input, Macierz &mac){

    for (int i = 0; i < ROZMIAR; ++i){
        input >> mac[i];
    }

    return input;
}

std::ostream &operator<< (std::ostream &output, Macierz &mac){

    for (int i = 0; i < ROZMIAR; ++i){
        output << mac[i];
    }

    return output;
} 