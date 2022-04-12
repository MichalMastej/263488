#ifndef WYRAZENIEZESPOLONE_HH
#define WYRAZENIEZESPOLONE_HH

#include "LZespolona.hh"

enum Operator {op_dodaj, op_odejmij, op_mnoz, op_dziel};

class WyrazenieZespolone
{
public:
  
  LZespolona arg1;
  Operator op;
  LZespolona arg2;
  
  void zadaj_pytanie();
  LZespolona oblicz();
  
};

std::ostream& operator << (std::ostream &input, const WyrazenieZespolone &wyr_1);
std::istream& operator >> (std::istream &output, Operator &op_1);
std::istream& operator >> (std::istream &output, WyrazenieZespolone &wyr_1);

#endif