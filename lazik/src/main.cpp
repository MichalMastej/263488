#include <iostream>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "Lazik.hh"
#include "Scena.hh"


using namespace std;

void pokaz_menu(){

  cout << "j - Jazda na wprost" << endl 
  << "o - Obrot o kat" << endl 
  << "w - wybor lazika" << endl 
  << "m - wyswietl menu" << endl
  << "l - lista probek na scenie" << endl << endl 
  << "k - koniec dzialania programu" << endl << endl;
}

int main()
{  
  Scena scena1;
  char choice;
  Wektor3D tmp1;

  scena1.inicjalizuj_lacze();

  if (!Inicjalizuj_PowierzchnieMarsa(scena1.Lacze)) return 1;

  cout << endl << "Start programu gnuplot" << endl << endl;

  while(choice != 'k'){
  cout << endl << "Aktywny lazik" << endl;
  cout << "Nazwa: " << scena1.aktywny_lazik->WezNazweObiektu() << endl;
  cout << "Polozenie: " << scena1.aktywny_lazik->get_polozenie() <<  "Kąt: " <<  scena1.aktywny_lazik->get_kat() << endl;

  tmp1.wypisz_info();

  cout << "j - Jazda na wprost" << endl << "o - Obrot o kat" << endl << "w - wybor lazika" << endl << "l - lista probek na scenie" << endl << "m - wyswietl menu" << endl << endl << "k - koniec dzialania programu" << endl << endl;
  cout << "Twoj wybor: ";
  cin >> choice;
  cout << endl;

  switch (choice){
  
  case 'j':
    scena1.go();
    break;
  
  case 'o':
    scena1.rotate();
    break; 

  case 'w':
    scena1.wybierz_lazik();
    break;

  case 'm':
    pokaz_menu();
    break;

  case 'l':
    scena1.wyswietl_liste_probek();
    break;

  case 'k':
    break;

  default:
    break;
  }}
}