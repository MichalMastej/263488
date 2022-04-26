#include <iostream>
#include <fstream>
#include <cmath>

#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main(){

    UkladRownanLiniowych ur1 ,ur_tmp;
    Wektor wynik, blad;
    Macierz tmp;
    fstream file;
    double d_wek_bledu;

    file.open("macierz.txt");
    file >> ur1;

    ur_tmp = ur1;

    cout << endl << "Start programu" << endl << endl;
    cout << endl << "Macierz A^T:" << endl << endl;

    tmp = ur1.get_value_mac();
    cout << tmp << endl;

    cout << endl << "Wektor wyrazow wolnych" << endl << endl;

    tmp = ur1.get_value_mac();
    cout << tmp << endl;

    ur1.get_value_mac().transponuj();

    wynik = ur1.oblicz(ur1);

    cout << endl << "Rozwiazanie x = (x1, x2, x3): " << endl;
    cout << wynik;

    tmp = ur1.get_value_mac();
    cout << endl << tmp << endl;
    cout << endl << ur1.get_value_wek() << endl;

    ur_tmp.get_value_mac().transponuj();
    blad = oblicz_wektor_bledu(ur_tmp, wynik);

    cout << endl << "Wektor bledu: Ax - b = " << blad << endl;

    d_wek_bledu = blad.iloczyn_skalarny(blad);

    cout << endl << "Dlugosc wektora bledu: ||Ax - b|| = " << sqrt(d_wek_bledu) << endl;
}