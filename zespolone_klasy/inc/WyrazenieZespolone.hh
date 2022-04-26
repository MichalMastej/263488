#ifndef WYRAZENIEZESPOLONE_HH
#define WYRAZENIEZESPOLONE_HH

#include "LZespolona.hh"

enum Operator {op_dodaj, op_odejmij, op_mnoz, op_dziel};

class WyrazenieZespolone
{  
  LZespolona arg1;
  Operator op;
  LZespolona arg2;
  
public:

  void set_value_arg1(LZespolona &zesp_tmp);
  void set_value_arg2(LZespolona &zesp_tmp);
  LZespolona get_value_arg(int number);

  void zadaj_pytanie();
  LZespolona oblicz();

  friend std::ostream& operator<< (std::ostream &input, const WyrazenieZespolone &wyr_1);
  friend std::istream& operator>> (std::istream &output, Operator &op_1);
  friend std::istream& operator>> (std::istream &output, WyrazenieZespolone &wyr_1);
  
};

std::ostream& operator<< (std::ostream &input, const WyrazenieZespolone &wyr_1);
std::istream& operator>> (std::istream &output, Operator &op_1);
std::istream& operator>> (std::istream &output, WyrazenieZespolone &wyr_1);

#endif