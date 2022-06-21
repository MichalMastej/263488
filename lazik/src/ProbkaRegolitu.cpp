#include <iostream>
#include <fstream>
#include <unistd.h>
#include <math.h>
#include <thread>
#include "Lazik.hh"
#include "lacze_do_gnuplota.hh"
#include "ProbkaRegolitu.hh"

ProbkaRegolitu::ProbkaRegolitu(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double x, double y, double z):
ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, x, y, z){

    double tmp[3] = {4, 4, 2};
    skala = tmp;
}

TypKolizji ProbkaRegolitu::czy_kolizja(const std::shared_ptr<ObiektGeom> &wsk_obiekt) const{

    if (
        (this->obrys.wierz_gorny_prawy[0] > wsk_obiekt->obrys.wierz_dolny_lewy[0]) &&
        (this->obrys.wierz_gorny_prawy[1] > wsk_obiekt->obrys.wierz_dolny_lewy[1]) &&
        (wsk_obiekt->obrys.wierz_gorny_prawy[0] > this->obrys.wierz_dolny_lewy[0]) &&
        (wsk_obiekt->obrys.wierz_gorny_prawy[1] > this->obrys.wierz_dolny_lewy[1])
    ){
        return tk_kolizja;
    }

    return tk_brak_kolizji;

}