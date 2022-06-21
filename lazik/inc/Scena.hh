#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include <memory>
#include <chrono>
#include "Lazik.hh"
#include "lacze_do_gnuplota.hh"
#include "PowierzchniaMarsa.hh"
#include "Kolory.hh"
#include "ProbkaRegolitu.hh"
#include "ObiektGeom.hh"
#include "LazikSFR.hh"

class Scena{

    public:

    PzG::LaczeDoGNUPlota Lacze;
    std::shared_ptr<Lazik> aktywny_lazik;
    std::list<std::shared_ptr<ObiektGeom>> obiekty_sceny;
    int it;

    Scena();
    void inicjalizuj_lacze();
    void dodaj_do_listy_rysowania(const ObiektGeom &obj);
    void go(){aktywny_lazik->przesuniecie(Lacze, obiekty_sceny, aktywny_lazik);};
    void rotate(){aktywny_lazik->obrot_o_kat(Lacze);};
    void wybierz_lazik();
    void wyswietl_laziki();
    void wyswietl_liste_probek();
    void przelicz_all();    
    void zmien_kolor(Kolory kolor);
    void podejmij_probke();


    std::shared_ptr<Lazik> operator() (unsigned int x);
};

#endif