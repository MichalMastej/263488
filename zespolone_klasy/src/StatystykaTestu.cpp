#include <iostream>
#include "StatystykaTestu.hh"

StatystykaTestu::StatystykaTestu(){

  odp_poprawne = 0;
  ilosc_pytan = 0;
}

void StatystykaTestu::increment_value(int tmp){

  if (tmp == 0){

    odp_poprawne++;
  }
  else {

    ilosc_pytan++;
  }
}

void StatystykaTestu::decrement_value(int tmp){

  if (tmp == 0){

    odp_poprawne--;
  }
  else {

    ilosc_pytan--;
  }
}

void StatystykaTestu::summary()
{
  float percentage = (float) this->odp_poprawne/this->ilosc_pytan;
  std::cout << std::endl << "Ilosc dobrych odpowiedzi: " << this->odp_poprawne << std::endl;
  std::cout << "Ilosc blednych odpowiedzi: " << this->ilosc_pytan - this->odp_poprawne << std::endl;
  std::cout << "Wynik procentowy poprawnych opdowiedzi: " << percentage*100 << "%" << std::endl;
}