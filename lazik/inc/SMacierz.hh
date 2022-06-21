#ifndef SMACIERZ_HH
#define SMACIERZ_HH

#include <iostream>
#include "SWektor.hh"

template <typename Typ, int Wymiar>
class SMacierz{

    SWektor<Typ, Wymiar> wiersz[Wymiar];

    public:

    SMacierz();
    SMacierz(Typ tmp[Wymiar]){ for(int i = 0; i < Wymiar; i++){wiersz[i] = tmp[i];};}
    SMacierz(double tab[Wymiar][Wymiar]);

    const SWektor<Typ, Wymiar> &operator [] (int wie) const {return wiersz[wie];}
    SWektor<Typ, Wymiar> &operator [] (int wie) {return wiersz[wie];}

    SMacierz<Typ, Wymiar> operator+ (const SMacierz <Typ, Wymiar> mac) const;
    SWektor<Typ, Wymiar> operator* (SWektor<Typ, Wymiar> wek) const;

    void zamien(int ktory, int z_ktorym);
    void transponuj();
};

template <typename Typ, int Wymiar>
SMacierz<Typ, Wymiar>::SMacierz(){

    for (int i = 0; i < Wymiar; ++i){
        for (int j = 0; j < Wymiar; ++j){
            wiersz[i][j] = 0;
    }}

    wiersz[0][0] = 1;
    wiersz[1][1] = 1;
    wiersz[2][2] = 1;
}

template <typename Typ, int Wymiar>
SMacierz<Typ, Wymiar>::SMacierz(double tab[Wymiar][Wymiar]){

    for (int i = 0; i < Wymiar; ++i){
        for (int j = 0; j < Wymiar; ++j){
            wiersz[i][j] = tab[i][j];
    }}
}

template<typename Typ,int Wymiar>
SMacierz<Typ, Wymiar> SMacierz<Typ, Wymiar>::operator+ (const SMacierz<Typ, Wymiar> mac) const {

    SMacierz<Typ, Wymiar> wynik;

    for (int ind = 0; ind < Wymiar; ++ind){
        wynik[ind] = wiersz[ind] + mac[ind];
    }

    return wynik;
}

template<typename Typ,int Wymiar>
SWektor<Typ, Wymiar> SMacierz<Typ, Wymiar>::operator* (SWektor<Typ, Wymiar> wek) const{

    SWektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        for (int j = 0; j < Wymiar; ++j){
            wynik[i] = wynik[i] + (wiersz[i][j] * wek[j]);
    }}

    return wynik;
}

template<typename Typ,int Wymiar>
void SMacierz<Typ, Wymiar>::transponuj(){

    SMacierz tmp;

    for (int i = 0; i < Wymiar; ++i){
        for (int j = 0; j < Wymiar; j++)
        {
            tmp[i][j] = wiersz[i][j];
        }
    }

    for (int i = 0; i < Wymiar; ++i){
        for (int j = 0; j < Wymiar; j++)
        {
            wiersz[i][j] = tmp[j][i];
        }
    }
}

template<typename Typ, int Wymiar>
std::ostream& operator<< (std::ostream& output, const SMacierz <Typ, Wymiar> &mac){ 
    
    for (int i = 0; i < Wymiar; ++i){
        output << mac[i];
    }
    
    return output;
}

template<typename Typ, int Wymiar>
std::istream& operator>> (std::istream& input, SMacierz <Typ, Wymiar> &mac){ 
    
    for (int i = 0; i < Wymiar; ++i){
        input >> mac[i];
    }

    return input;
}

#endif