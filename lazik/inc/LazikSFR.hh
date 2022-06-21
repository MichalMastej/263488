#ifndef LAZIKFSR_HH
#define LAZIKFSR_HH

#include <iostream>
#include <string>
#include <memory>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"
#include "TypKolizji.hh"
#include "Lazik.hh"
#include "ProbkaRegolitu.hh"
#include "Scena.hh"
#include "LazikSFR.hh"

class LazikFSR :public Lazik{

    public:
    std::list<std::shared_ptr<ProbkaRegolitu>> lista_probek;

    LazikFSR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double x, double y, double z, 
            double angle, double angle_tmp, double distance, double velocity);
    void dodaj_probke(std::shared_ptr<ObiektGeom> Probka);
    void wyswietl_liste_probek();
    virtual int TypObiektu() override {return 3;}
};

#endif