#include <iostream>
#include <fstream>
#include <cmath>
#include "ObiektGeom.hh"
#include "Kolory.hh"
#include "Wektor2D.hh"

using namespace std;

ObiektGeom::ObiektGeom( const char*  sNazwaPliku_BrylaWzorcowa, const char*  sNazwaObiektu, int KolorID, double x, double y, double z):
  _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";

  polozenie[0] = x;
  polozenie[1] = y;
  polozenie[2] = z;

  double tmp_mac[3][3] = {{cos(0), -sin(0), 0}, {sin(0), cos(0), 0}, {0, 0, 1}};
  macierz_rotacji = tmp_mac;

  Wektor2D tmp(0, 0);
  obrys.wierz_dolny_lewy = tmp;
  obrys.wierz_gorny_prawy = tmp;
}

bool ObiektGeom::Przelicz_i_Zapisz_Wierzcholki1(){

  ifstream  StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream  StrmWy(_NazwaPliku_BrylaRysowana);

  double tab_x[24];
  double tab_y[24];
  // double min_x = 0, min_y = 0, max_x = 0, max_y = 0;

  if (!(StrmWe.is_open() && StrmWy.is_open())) {
    cerr << endl << "Nie mozna otworzyc jednego z plikow:" << endl
	 << "    " << _NazwaPliku_BrylaWzorcowa << endl
	 << "    " << _NazwaPliku_BrylaRysowana << endl
	 << endl;
    return false;
  }

  Wektor3D wsp;
  Wektor2D tmp;
  int Indeks_Wiersza = 0;
  unsigned int i = 0;
  
  StrmWe >> wsp;

  if (StrmWe.fail())return false;
  
  do {
    wsp = macierz_rotacji*(wsp*skala) + polozenie;
    StrmWy << wsp;
    ++Indeks_Wiersza;
    
    if (Indeks_Wiersza >= 4) {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }
    
    tab_x[i] = wsp[0];
    tab_y[i] = wsp[1];
    StrmWe >> wsp;
    i++;
    
  } while (!StrmWe.fail());

  for(int j = 0; j < 24; j++){
    if(obrys.wierz_gorny_prawy[0] < tab_x[j]){
      obrys.wierz_gorny_prawy[0] = tab_x[j];
    }

    if(obrys.wierz_gorny_prawy[1] < tab_y[j]){
      obrys.wierz_gorny_prawy[1] = tab_y[j];
    }

    if(obrys.wierz_dolny_lewy[0] > tab_x[j]){
      obrys.wierz_dolny_lewy[0] = tab_x[j];
    }

    if(obrys.wierz_dolny_lewy[1] > tab_y[j]){
      obrys.wierz_dolny_lewy[1] = tab_y[j];
    }
  }
  // for (double &elem : tab_x){
  //   if(elem < min_x){
  //     min_x = elem;
  //   }

  //   else if(elem > max_x){
  //     max_x = elem;
  //   }
  // }

  // for (double &elem : tab_y){
  //   if(elem < min_y){
  //     min_y = elem;
  //   }

  //   else if(elem > max_y){
  //     max_y = elem;
  //   }
  // }
  // tmp[0] = max_x;
  // tmp[1] = max_y;
  // obrys.wierz_gorny_prawy = tmp;

  // tmp[0] = min_x;
  // tmp[1] = min_y;
  // obrys.wierz_dolny_lewy = tmp;

  // std::cout << obrys.wierz_gorny_prawy << " " << obrys.wierz_dolny_lewy << std::endl;

  if (!StrmWe.eof()) return false;
  
  return Indeks_Wiersza == 0 && !StrmWy.fail();
}


void ObiektGeom::set_KolorID(const Kolory &kolor){
  _KolorID = kolor;
}