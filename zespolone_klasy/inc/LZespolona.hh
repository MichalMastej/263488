#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

class LZespolona;

class LZespolona
{

public:
  
  double rl;
  double im;
  
  LZespolona operator + (LZespolona obj_2);
  LZespolona operator - (LZespolona obj_2);
  LZespolona operator * (LZespolona obj_2);
  LZespolona operator / (double obj_2);
  LZespolona operator / (LZespolona obj_2);
  bool operator == (LZespolona obj_2);

};

std::ostream& operator << (std::ostream &stream, const LZespolona &obj_2); 
std::istream& operator >> (std::istream &stream, LZespolona &obj_2);

#endif
