#ifndef LAZIK_HH
#define LAZIK_HH

#include <iostream>
#include <string>
#include <memory>
#include "ObiektGeom.hh"
#include "lacze_do_gnuplota.hh"
#include "TypKolizji.hh"

class ObiektGeom;
class Lazik :public ObiektGeom{

    double kat_obrotu, kat_polozenia;
    double predkosc;
    double odleglosc_do_przejechania;

    public:

    Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double x, double y, double z, double angle, double angle_tmp, double distance, double velocity);

    void set_kat_obrotu(double kat){kat_obrotu = kat;}
    void set_szybkosc(double velocity){ predkosc = velocity;}
    void set_odleglosc_do_przejechania(double distance){odleglosc_do_przejechania = distance;}
    
    double get_kat(){return kat_polozenia;}

    void obrot_o_kat(PzG::LaczeDoGNUPlota  &Lacze);
    void przesuniecie(PzG::LaczeDoGNUPlota  &Lacze, std::list<std::shared_ptr<ObiektGeom>> wsk_obiekt, std::shared_ptr<Lazik> aktywny_lazik);
    void wybor_lazika();

    virtual TypKolizji czy_kolizja(const std::shared_ptr<ObiektGeom> &wsk_obiekt) const override;
    virtual int TypObiektu() override {return 1;};
};

#endif