#ifndef STATYSTYKATESTU_HH
#define STATYSTYKATESTU_HH

class StatystykaTestu
{
  
  int odp_poprawne;
  int ilosc_pytan;

  public:

  StatystykaTestu();

  void increment_value(int tmp);
  void decrement_value(int tmp);

  void summary();
};

#endif