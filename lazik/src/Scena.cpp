#include "Scena.hh"
#include <string>

Scena::Scena(){

  inicjalizuj_lacze();
  obiekty_sceny.push_back(std::make_shared<LazikFSR>("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski, 0, 0, 0, 0, 0, 0, 0));
  obiekty_sceny.push_back(std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony, 60, 60, 0, 0, 0, 0, 0));
  obiekty_sceny.push_back(std::make_shared<Lazik>("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony, -20, 70, 0, 0, 0, 0, 0));
  obiekty_sceny.push_back(std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian3.dat", "pomidor1", Kolor_Zielony, -60, 0, 0));
  obiekty_sceny.push_back(std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian3.dat", "pomidor2", Kolor_Zielony, 40, -60, 0));
  obiekty_sceny.push_back(std::make_shared<ProbkaRegolitu>("bryly_wzorcowe/szescian3.dat", "pomidor3", Kolor_Zielony, -90, 70, 0));
  for(std::shared_ptr<ObiektGeom> &elem : obiekty_sceny){ (*elem).Przelicz_i_Zapisz_Wierzcholki1();};
  for(std::shared_ptr<ObiektGeom> &elem : obiekty_sceny){dodaj_do_listy_rysowania(*elem);};

  aktywny_lazik = (*this)(0);

  it = -1;
}

void Scena::inicjalizuj_lacze()
{
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
  Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
  Lacze.UstawZakresZ(-0, 90);  
  Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok

  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
  Inicjalizuj_PowierzchnieMarsa(Lacze);
  przelicz_all();
  Lacze.Rysuj();
}



void Scena::dodaj_do_listy_rysowania(const ObiektGeom  &obj)
{
  PzG::InfoPlikuDoRysowania *wInfoPliku;
  
  wInfoPliku = &Lacze.DodajNazwePliku(obj.WezNazwePliku_BrylaRysowana());
  wInfoPliku->ZmienKolor(obj.WezKolorID());
}

void Scena::przelicz_all(){

    for(std::shared_ptr<ObiektGeom> &elem : obiekty_sceny){ (*elem).Przelicz_i_Zapisz_Wierzcholki1();}
}

std::shared_ptr<Lazik> Scena::operator() (unsigned int x){

  unsigned int j = 0;
  for (const std::shared_ptr<ObiektGeom> &Obiekt : obiekty_sceny){

    if(x==j){
      return std::dynamic_pointer_cast<Lazik> (Obiekt);
    }

    else j++;
  }

  throw std::logic_error("Nie ma lazikow");
}

void Scena::zmien_kolor(Kolory kolor){

  if (kolor == Kolor_Czerwony){

  }
}

void Scena::wybierz_lazik(){

  int choice = 0;

  std::cout << std::endl << "Wybierz lazik:" << std::endl;
  wyswietl_laziki();
  std::cout << "Twoj wybor: ";
  std::cin >> choice;

  int it = 1;
  for (const std::shared_ptr<ObiektGeom> &obiekt : obiekty_sceny){
    if(it == choice){
      aktywny_lazik->set_KolorID(Kolor_Czerwony);
      aktywny_lazik = std::static_pointer_cast<Lazik>(obiekt);
      aktywny_lazik->set_KolorID(Kolor_JasnoNiebieski);
    }
    ++it;
  }
}

void Scena::wyswietl_liste_probek(){

  int iter = 0;
  int i = 1;
  std::string name;
  Wektor3D coordinates;

  std::cout << std::endl << "Lista probek na scenie:" << std::endl;
  for (std::shared_ptr<ObiektGeom> &elem : obiekty_sceny){
    iter = elem->TypObiektu();
    if(iter == 2){
      name = elem->WezNazweObiektu();
      coordinates = elem->get_polozenie();
      std::cout << i <<". " << name << "   " << "Polozenie: " << coordinates << std::endl;
      i++;
    }
  }
}

void Scena::wyswietl_laziki(){

  int iter = 0;
  int i = 1;
  std::string name;
  Wektor3D coordinates;

  std::cout << std::endl << "Lista lazikow na scenie:" << std::endl;
  for (std::shared_ptr<ObiektGeom> &elem : obiekty_sceny){
    iter = elem->TypObiektu();
    if((iter == 1) || (iter == 3)){
      name = elem->WezNazweObiektu();
      coordinates = elem->get_polozenie();
      std::cout << i <<". " << name << "   " << "Polozenie: " << coordinates << std::endl;
      i++;
    }
  }
}

void Scena::podejmij_probke(){}