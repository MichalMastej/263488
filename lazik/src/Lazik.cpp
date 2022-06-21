#include <iostream>
#include <fstream>
#include <unistd.h>
#include <math.h>
#include <thread>
#include "Lazik.hh"
#include "lacze_do_gnuplota.hh"

using namespace std;

TypKolizji Lazik::czy_kolizja(const std::shared_ptr<ObiektGeom> &wsk_obiekt) const{

    if (
        (this->obrys.wierz_gorny_prawy[0] > wsk_obiekt->obrys.wierz_dolny_lewy[0]) &&
        (wsk_obiekt->obrys.wierz_gorny_prawy[0] > this->obrys.wierz_dolny_lewy[0]) &&
        (this->obrys.wierz_gorny_prawy[1] > wsk_obiekt->obrys.wierz_dolny_lewy[1]) &&
        (wsk_obiekt->obrys.wierz_gorny_prawy[1] > this->obrys.wierz_dolny_lewy[1])
        ){

        std::cout << std::endl << "Nastapila Kolizja: " << this->WezNazweObiektu() << std::endl;
        return tk_kolizja;
    }
    else {return tk_brak_kolizji;}

}

Lazik::Lazik(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double x, double y, double z, 
            double angle, double angle_tmp, double distance, double velocity):
ObiektGeom(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, x, y, z){

    kat_obrotu = angle;
    kat_polozenia = angle_tmp;
    odleglosc_do_przejechania = distance;
    predkosc = velocity;

    double tmp[3] = {20, 20, 10};
    skala = tmp;
}

void Lazik::przesuniecie(PzG::LaczeDoGNUPlota  &Lacze, std::list<std::shared_ptr<ObiektGeom>> wsk_obiekt, std::shared_ptr<Lazik> aktywny_lazik){

    std::shared_ptr<ObiektGeom> jd1;
    Wektor3D tmp;
    double x = 0, v = 0;
    bool zezwolenie_jazdy = true;

    cout << "Podaj odleglosc na ktora ma przejechac lazik oraz predkosc jego jazdy()    " << endl;
    cout << "Odleglosc oraz predkosc: ";
    cin >> x; cin >> v;

    this->set_odleglosc_do_przejechania(x);
    this->set_szybkosc(v);

    double odleglosc_dp = odleglosc_do_przejechania/10;
    tmp[0] = odleglosc_dp;
    tmp = macierz_rotacji * tmp;

    for(int i = 0; i < 10; i++){

        polozenie = polozenie + tmp;
        Przelicz_i_Zapisz_Wierzcholki1();
        for(const std::shared_ptr<ObiektGeom> &elem : wsk_obiekt){
            if(elem != aktywny_lazik){
                if(elem->czy_kolizja(aktywny_lazik) == tk_kolizja){
                    zezwolenie_jazdy = false;
                    break;}
            }
        }
        // if (zezwolenie_jazdy == false){
        //     break;
        // }
        Lacze.Rysuj();
        this_thread::sleep_for(240ms);
    }

    odleglosc_do_przejechania = 0;
    predkosc = 0;

}

void Lazik::obrot_o_kat(PzG::LaczeDoGNUPlota  &Lacze){

    int x = 0;

    cout << "Podaj kat o jaki chcesz obrocic lazik: ";
    cin >> kat_obrotu;

    x = kat_obrotu/10;

    for(int i =0; i < 10; i++){
        
        kat_polozenia += x;
        double tmp_mac[3][3] = {{cos(kat_polozenia*M_PI/180), -sin(kat_polozenia*M_PI/180), 0}, {sin(kat_polozenia*M_PI/180), cos(kat_polozenia*M_PI/180), 0}, {0, 0, 1}};
        macierz_rotacji = tmp_mac;
        Przelicz_i_Zapisz_Wierzcholki1();
        Lacze.Rysuj();
        this_thread::sleep_for(240ms);
    }

    std::cout << obrys.wierz_gorny_prawy << " " << obrys.wierz_dolny_lewy << std::endl;
}