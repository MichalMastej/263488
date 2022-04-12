#include <iostream>
#include <fstream>

#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

int main(){

    UkladRownanLiniowych ur1;
    Wektor wynik;
    fstream file;

    file.open("macierz.txt");
    file >> ur1;

    cout << endl << "Start programu" << endl << endl;
    cout << endl << "Macierz A^T:" << endl << endl;

    cout << ur1.A << endl;

    cout << endl << "Wektor wyrazow wolnych" << endl << endl;

    cout << ur1.b << endl;

    ur1.A.zamien(1,2);
    
    cout << endl << ur1.A << endl;

    wynik = ur1.oblicz(ur1);

    cout << endl << "Rozwiazanie x = (x1, x2, x3): " << endl;
    cout << wynik;

    cout << endl << ur1.A << endl;
    cout << endl << ur1.b << endl;
}