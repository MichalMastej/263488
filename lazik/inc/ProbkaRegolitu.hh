#ifndef PROBKAREGOLITU_HH
#define PROBKAREGOLITU_HH

#include <iostream>
#include <string>
#include "Lazik.hh"
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"

class ObiektGeom;
class ProbkaRegolitu :public ObiektGeom{

    public:
    ProbkaRegolitu(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double x, double y, double z);

    virtual TypKolizji czy_kolizja(const std::shared_ptr<ObiektGeom> &wsk_obiekt) const override;
    virtual int TypObiektu() override {return 2;}

};

#endif