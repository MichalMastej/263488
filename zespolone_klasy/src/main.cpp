#include <iostream>
#include <fstream>
#include "WyrazenieZespolone.hh"
#include "StatystykaTestu.hh"

using namespace std;

void WykonajTest(istream &input)
{
    LZespolona odpowiedz, wynik;
    WyrazenieZespolone wyr_pytanie_testowe;
    StatystykaTestu stats_testu = {0, 0};

    int szanse = 3;

    while (!input.eof()){

        stats_testu.ilosc_pytan++;
        input.clear();
        input >> wyr_pytanie_testowe;

        if (input.fail() && !input.eof()){
        cout << endl << "Napotkano blad skladni pytania. Zostalo ono pominiete" << endl;
        input.clear();
        input.ignore(200000000, '\n');
        stats_testu.ilosc_pytan--;
        }

        else if (!input.fail()){

        while (szanse >= 0){

        if (wyr_pytanie_testowe.arg2.rl == 0 && wyr_pytanie_testowe.arg2.im == 0){
        cerr << endl << "Dzielenie przez zero. Pytanie pomieniete." << endl;
        stats_testu.ilosc_pytan--;
        break;}

        else{
        wynik = wyr_pytanie_testowe.oblicz();
        cout << endl << wynik << endl;
        wyr_pytanie_testowe.zadaj_pytanie();
        
        cin.clear();
        cin >> odpowiedz;

        if (wynik == odpowiedz){

            cout << "Odpowiedz poprawna" << endl;
            stats_testu.odp_poprawne++;
            break;
        }

        else if (cin.fail()){
        
            szanse--;

            if(szanse == 0){

            cout << endl << "Wykorzystales wszystkie 3 szanse na wpisanie poprawnej liczby" << endl;
            break;
            }

            else {

            cout << endl <<"Nieprawidlowe wprowadzona liczba, masz jeszcze: " << szanse << " szanse" << endl;
            cout << "Podaj ponownie odpowiedz: ";
            cin.clear();
            cin.ignore(2000000, '\n');
            }}

        else {

            cout << "Bledna odpowiedz. Prawidlowa odpowiedz to: " << wynik << endl;
            break;
        }}}}}
    stats_testu.ilosc_pytan--;
    stats_testu.summary();
}


int main(int argc, char **argv){

  if (argc < 2) {
    cerr << endl;
    cerr << " Brak nazwy testu." << endl;
    cerr << endl;
    return 1;
  }

  ifstream plik_testu(argv[1]);

  if(plik_testu.is_open() == false){

      cerr << endl;
      cerr << "Blad wczytywania pliku, nalezy otworzyc plik 'test-arytmetyka.txt'" << endl;
      cerr << endl;
      return 1;
  }

  cout << endl;
  cout << "Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WykonajTest(plik_testu);

  plik_testu.close();

  cout << endl;
  cout <<  "Koniec testu" << endl;
  cout << endl;
}