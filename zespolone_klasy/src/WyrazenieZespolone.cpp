#include <iostream>
#include "WyrazenieZespolone.hh"

using namespace std;

void WyrazenieZespolone::zadaj_pytanie()
{
  cout << endl << "Podaj wynik operacji: ";
  cout << *this;
  cout << "=" << endl;
  cout << "Twoja odpowiedz: ";
}

std::ostream& operator << (std::ostream& input, const WyrazenieZespolone &wyr_1){

  if ((input << wyr_1.arg1).fail()) return input;
    
    switch (wyr_1.op)
    {
    case 0:
        
        input << " + ";
        break;

    case 1:
        
        input << " - ";
        break;

    case 2:
        
        input << " * ";
        break;

    case 3:
        
        input << " / ";
        break;
    
    default:
        break;
    }

    if ((input << wyr_1.arg2).fail()) return input;

    return input;
}

std::istream& operator >> (std::istream& output, Operator &op_1){

    char a;

    output >> a;

    switch (a)
    {
    case '+':

        op_1 = op_dodaj;
        break;

    case '-':

        op_1 = op_odejmij;
        break;
        
    case '*':

        op_1 = op_mnoz;
        break;

    case '/':

        op_1 = op_dziel;
        break;

    default:
        
        output.setstate(std::ios::failbit);
        break;
    }

    return output;
}

std::istream& operator >> (std::istream& output, WyrazenieZespolone &wyr_1){

    output >> wyr_1.arg1;

    output >> wyr_1.op;

    output >> wyr_1.arg2;

    return output;
}

LZespolona WyrazenieZespolone::oblicz(){

    LZespolona wynik;

        switch (this->op)
    {
    case 0:
        
        wynik = this->arg1 + this->arg2;
        break;

    case 1:
        
        wynik = this->arg1 - this->arg2;
        break;

    case 2:
        
        wynik = this->arg1 * this->arg2;
        break;

    case 3:
        
        wynik = this->arg1 / this->arg2;
        break;
    
    default:
        break;
    }

    return wynik;
}