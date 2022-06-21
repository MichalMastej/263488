#ifndef SWEKTOR_HH
#define SWEKTOR_HH

#include <iostream>

template<typename Typ, int Wymiar>
class SWektor{

    Typ wyraz[Wymiar];
    static int count_all_wektorow3d;
    static int count_active_wektorow3d;

    public:

    SWektor();
    // SWektor(const SWektor<Typ, Wymiar> &wek){++count_active_wektorow3d;
    // ++count_all_wektorow3d; (*this) = wek;};
    SWektor(Typ tmp[Wymiar]);
    SWektor(double x, double y, double z){wyraz[0] = x; wyraz[1] = y; wyraz[2] = z;}
    SWektor(double x, double y){wyraz[0] = x; wyraz[1] = y;}
    // SWektor(){for(int i = 0; i < Wymiar; i++){wyraz[i] = 0;};}
    // SWektor(Typ tmp[Wymiar]){ for(int i = 0; i < Wymiar; i++){wyraz[i] = tmp[i];};}
    ~SWektor();

    Typ operator[] (int index) const {return wyraz[index];}
    Typ &operator[] (int index) {return wyraz[index];}

    SWektor<Typ, Wymiar> operator+ (SWektor <Typ, Wymiar> &wek) const;
    SWektor<Typ, Wymiar> operator- (SWektor <Typ, Wymiar> &wek) const;
    SWektor<Typ, Wymiar> operator* (SWektor <Typ, Wymiar> &wek) const;
    SWektor<Typ, Wymiar> operator* (double &tmp) const;
    SWektor<Typ, Wymiar> operator/ (Typ &tmp) const;

    void wypisz_info();
};

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar>::SWektor(){
    for(int i = 0; i < Wymiar; i++){
        wyraz[i] = 0;
    }

    ++count_active_wektorow3d;
    ++count_all_wektorow3d;
}

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar>::SWektor(Typ tmp[Wymiar]){
    for(int i = 0; i < Wymiar; i++){
        wyraz[i] = tmp[i];
    }

    ++count_active_wektorow3d;
    ++count_all_wektorow3d;
}

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar>::~SWektor(){
    
    --count_active_wektorow3d;
}

template<typename Typ, int Wymiar>
void SWektor<Typ, Wymiar>::wypisz_info(){

    std::cout<< std::endl << "Ilosc aktywnych wektorow: " << count_active_wektorow3d << std::endl;
    std::cout << "Ilosc wszystkich wektorow: " << count_all_wektorow3d << std::endl << std::endl;
}

template<typename Typ, int Wymiar>
int SWektor<Typ, Wymiar>::count_active_wektorow3d = 0;

template<typename Typ, int Wymiar>
int SWektor<Typ, Wymiar>::count_all_wektorow3d = 0;

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar> SWektor<Typ, Wymiar>::operator+ (SWektor<Typ, Wymiar> &wek) const{

    SWektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] + wek[i];
    }

    return wynik;    
}

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar> SWektor<Typ, Wymiar>::operator- (SWektor<Typ, Wymiar> &wek) const{

    SWektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] - wek[i];
    }

    return wynik;
}

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar> SWektor<Typ, Wymiar>::operator* (SWektor<Typ, Wymiar> &wek) const{

    SWektor<Typ, Wymiar> wynik;

    for(int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i]*wek[i];
    }

    return wynik;
}

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar> SWektor<Typ, Wymiar>::operator* (double &tmp) const{

    SWektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] * tmp;
    }

    return wynik;
}

template<typename Typ, int Wymiar>
SWektor<Typ, Wymiar> SWektor<Typ, Wymiar>::operator/ (Typ &tmp) const{

    SWektor<Typ, Wymiar> wynik;

    for (int i = 0; i < Wymiar; ++i){
        wynik[i] = wyraz[i] / tmp;
    }

    return wynik;
}

template<typename Typ, int Wymiar>
std::ostream& operator<< (std::ostream& output, const SWektor <Typ, Wymiar> &wek){

    for (int i = 0; i < Wymiar; ++i)    {
        output << wek[i] << " ";
    }

    output << std::endl;
    
    return output;
}

template<typename Typ, int Wymiar>
std::istream& operator>> (std::istream& input,  SWektor <Typ, Wymiar> &wek){

    for (int i = 0; i < Wymiar; ++i)    {
        input >> wek[i];
    }
    
    return input;
}

#endif