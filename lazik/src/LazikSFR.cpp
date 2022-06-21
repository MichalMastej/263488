#include "LazikSFR.hh"
#include "Kolory.hh"
#include <iostream>
#include <string>

LazikFSR::LazikFSR(const char* sNazwaPliku_BrylaWzorcowa, const char* sNazwaObiektu, int KolorID, double x, double y, double z, 
            double angle, double angle_tmp, double distance, double velocity) 
            :Lazik(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID, x, y, z, angle, angle_tmp, distance, velocity){}

void LazikFSR::wyswietl_liste_probek(){

  int iter = 0;
  int i = 1;
  std::string name;
  Wektor3D coordinates;

  std::cout << std::endl << "Lista probek na scenie:" << std::endl;
  for (std::shared_ptr<ProbkaRegolitu> &elem : lista_probek){
    iter = elem->TypObiektu();
    if(iter == 2){
      name = elem->WezNazweObiektu();
      coordinates = elem->get_polozenie();
      std::cout << i <<". " << name << "   " << "Polozenie: " << coordinates << std::endl;
      i++;
    }
  }
}

void LazikFSR::dodaj_probke(std::shared_ptr<ObiektGeom> probka){

    // lista_probek.push_back(std::shared_ptr<ProbkaRegolitu>("bryly_wzorcowe/szescian3.dat", probka->wez_nazwe_char(), Kolor_Zielony, 0, 0, 0));
}