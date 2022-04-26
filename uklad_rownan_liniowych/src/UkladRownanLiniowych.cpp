#include "UkladRownanLiniowych.hh"

Macierz UkladRownanLiniowych::get_value_mac(){

    return A;
}

Wektor UkladRownanLiniowych::get_value_wek(){

    return b;
}

Wektor UkladRownanLiniowych::oblicz(UkladRownanLiniowych &url){

    double ratio;

    for(int k = 0; k < ROZMIAR - 1; ++k){
        if (url.A[k][k] != 1){
                double tmp_1 = url.A[k][k];
                url.A[k] = url.A[k] / tmp_1;
                url.b[k] = url.b[k] / tmp_1;}

        for (int i = k + 1; i < ROZMIAR; ++i){
            
            ratio = url.A[i][k]/url.A[k][k];
            for (int j = 0; j < ROZMIAR; ++j){
                url.A[i][j] = url.A[i][j] - ratio * url.A[k][j];
            }
            url.b[i] = url.b[i] - ratio * url.b[k];

            std::cout << "Odjecie od wiersza: " << i+1 << " wiersz: " << k+1 << std::endl;
            std::cout << "Przy kazdej iteracji sprawdzane jest, czy wyraz macierzy znajdujacy sie na przekatnej jest rowny 1, jezeli nie jest takze wykonywana operacja dzielenia wiersza przes wartosc tego wyrazu" << std::endl;
            std::cout << std::endl << url.A << std::endl; 
    }}

    double tmp_2 = url.A[ROZMIAR-1][ROZMIAR-1];
    url.A[ROZMIAR-1] = url.A[ROZMIAR-1] / tmp_2;
    url.b[ROZMIAR-1] = url.b[ROZMIAR-1] / tmp_2;

    std::cout << std::endl << "Podzielenie wiersza " << ROZMIAR << " przez wartosc wyrazu [" << ROZMIAR << "][" << ROZMIAR << "] macierzy" << std::endl;
    std::cout << std::endl << url.A << std::endl;  

    for(int k = ROZMIAR-1; k > -1; --k){
        if (url.A[k][k] != 1){
                double tmp_1 = url.A[k][k];
                url.A[k] = url.A[k] / tmp_1;
                url.b[k] = url.b[k] / tmp_1;}

        for (int i = k - 1; i > -1; --i){
            
            ratio = url.A[i][k]/url.A[k][k];
            for (int j = ROZMIAR-1; j > -1; --j){
                url.A[i][j] = url.A[i][j] - ratio * url.A[k][j];
            }
            url.b[i] = url.b[i] - ratio * url.b[k];

            std::cout << "Odjecie od wiersza: " << i+1 << " wiersz: " << k+1 << std::endl;
            std::cout << "Przy kazdej iteracji sprawdzane jest, czy wyraz macierzy znajdujacy sie na przekatnej jest rowny 1, jezeli nie jest takze wykonywana operacja dzielenia wiersza przes wartosc tego wyrazu" << std::endl;
            std::cout << std::endl << url.A << std::endl;  
    }}

    
    return url.b;
}

std::ostream &operator<< (std::ostream &output, UkladRownanLiniowych &url){

    output << url.A;

    output << url.b;

    return output;
}

std::istream &operator>> (std::istream &input, UkladRownanLiniowych &url){

    input >> url.A;

    input >> url.b;

    return input;
}

Wektor oblicz_wektor_bledu(UkladRownanLiniowych url, Wektor x){

    Wektor wynik;

    wynik = url.A * x - url.b;

    return wynik;
}