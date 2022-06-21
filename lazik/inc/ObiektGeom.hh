#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include <memory>
#include "Wektor3D.hh"
#include "Macierz3D.hh"
#include "ObrysXY.hh"
#include "TypKolizji.hh"
#include "Kolory.hh"


#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA    "pliki_do_rysowania"

class ObiektGeom {
    std::string   _NazwaPliku_BrylaWzorcowa;
    std::string   _NazwaPliku_BrylaRysowana;
    std::string   _NazwaObiektu;
    int           _KolorID;

  protected:

    const char* NazwaChar = _NazwaObiektu.c_str();
    Wektor3D polozenie;
    Wektor3D skala;
    Macierz3D macierz_rotacji;

  public:

    ObrysXY obrys;

    ObiektGeom(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double x, double y, double z);
    virtual ~ObiektGeom(){};

    int WezKolorID() const { return _KolorID; }
    const std::string & WezNazweObiektu() const { return _NazwaObiektu; }
    const std::string & WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }
    Wektor3D get_polozenie() const {return polozenie;}
    const char* wez_nazwe_char() const {return NazwaChar;}
    void show_macierz(){std::cout << macierz_rotacji;}
    void set_skala(Wektor3D &skal);
    void set_polozenie(Wektor3D &pol);
    void set_KolorID(const Kolory &kolor);

    bool Przelicz_i_Zapisz_Wierzcholki1();

    virtual TypKolizji czy_kolizja(const std::shared_ptr<ObiektGeom> &wsk_obiekt) const = 0;
    virtual int TypObiektu() {return 0;}

};


#endif

