#include <iostream>
#include <string>
#include "LZespolona.hh"

/*!                                                                             
 * Realizuje dodanie dwoch liczb zespolonych.                                   
 * Argumenty:                                                                   
 *    obj_1 - pierwszy skladnik dodawania,                                       
 *    obj_1 - drugi skladnik dodawania.                                          
 * Zwraca:                                                                      
 *    Sume dwoch skladnikow przekazanych jako parametry.                        
 */
LZespolona LZespolona::operator + (LZespolona obj_2){

    LZespolona wynik;

    wynik.rl = this->rl + obj_2.rl;
    wynik.im = this->im + obj_2.im;

    return wynik;
}

/*!                                                                             
 * Realizuje odejmowanie dwoch liczb zespolonych.                                   
 * Argumenty:                                                                   
 *    obj_1 - pierwszy skladnik odejmowania,                                       
 *    obj_2 - drugi skladnik odejmowania.                                          
 * Zwraca:                                                                      
 *    Roznice dwoch skladnikow przekazanych jako parametry.                        
 */

LZespolona LZespolona::operator - (LZespolona obj_2){

    LZespolona wynik;

    wynik.rl = this->rl - obj_2.rl;
    wynik.im = this->im - obj_2.im;

    return wynik;
}

/*!                                                                             
 * Realizuje iloczyn dwoch liczb zespolonych.                                   
 * Argumenty:                                                                   
 *    obj_1 - pierwszy skladnik mnozenia,                                       
 *    obj_2 - drugi skladnik mnozenia.                                          
 * Zwraca:                                                                      
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.                        
 */

LZespolona LZespolona::operator * (LZespolona obj_2){

    LZespolona wynik;

    wynik.rl = this->rl * obj_2.rl - this->im * obj_2.im;
    wynik.im = this->rl * obj_2.im + obj_2.rl * this->im;

    return wynik;
}

/*!                                                                             
 * Realizuje iloraz liczby zespolonej przez liczbe rzeczywista.                                   
 * Argumenty:                                                                   
 *    obj_1 - pierwszy skladnik dzielenia,                                       
 *    obj_2 - drugi skladnik dzielenia.                                          
 * Zwraca:                                                                      
 *    Iloraz dwoch skladnikow przekazanych jako parametry.                     
 */

LZespolona LZespolona::operator / (double obj_2){

    LZespolona wynik;

    wynik.rl = this->rl/obj_2;
    wynik.im = this->im/obj_2;

    return wynik;
}

/*!                                                                             
 * Realizuje iloraz dwoch liczb zespolonych.                                   
 * Argumenty:                                                                   
 *    obj_1 - pierwszy skladnik dzielenia,                                       
 *    obj_2 - drugi skladnik dzielenia.                                          
 * Zwraca:                                                                      
 *    Iloraz dwoch skladnikow przekazanych jako parametry.                        
 */

LZespolona LZespolona::operator / (LZespolona obj_2){

    LZespolona wynik, licznik;
    double mianownik;

        licznik.rl = this->rl * obj_2.rl - this->im * (-obj_2.im);
        licznik.im = this->rl * (-obj_2.im) + this->im * obj_2.rl;

        mianownik = (obj_2.rl*obj_2.rl)+(obj_2.im*obj_2.im);

        wynik = licznik/mianownik;


    return wynik;
}

/*!                                                                             
 * Realizuje porownanie dwoch liczb zespolonych.                                   
 * Argumenty:                                                                   
 *    obj_1 - pierwszy skladnik porownania,                                       
 *    obj_2 - drugi skladnik porownania.                                          
 * Zwraca:                                                                      
 *    Wartosc true lub false.                        
 */

bool LZespolona::operator == (LZespolona obj_2){

    if(this->rl == obj_2.rl && this->im == obj_2.im){
        return true;
    }
    
    return false;
}

/*!                                                                             
 * Realizuje wypisanie liczby zespolonej na standardowe wyjscie                                  
 * Argumenty:                                                                   
 *    input - adress standardowego wyjscia, na ktore ma zostac wypisana liczba,               
 *    obj_1 - liczba zespolona ktora ma zostac wypisana na wyjscie                  
 * Zwraca:                                                                      
 *    Adress standardowego wyjscia, na ktore ma zostac wypisana liczba.                       
 */

std::ostream& operator << (std::ostream &input, const LZespolona &obj_2){

    input << "(" << obj_2.rl;
    if (obj_2.im < 0){
        input << obj_2.im << "i)";
    }
    else {
        input << "+" << obj_2.im << "i)";
    }

    return input;
}

/*!                                                                             
 * Realizuje wpisanie liczby zespolonej do standardowego wejscia do zmiennej                                  
 * Argumenty:                                                                   
 *    input - adress standardowego wejscia, do ktorego ma zostac wypisana liczba,               
 *    obj_1 - liczba zespolona ktora ma zostac wypisana na wyjscie                  
 * Zwraca:                                                                      
 *    Adress standardowego wejscia, dzieki ktoremu liczba zostaje wpisana do zmiennej                       
 */

std::istream& operator >> (std::istream &output, LZespolona &obj_2){

    std::string temp;
    char a, b;

    output >> a;
    if (a != '('){
        output.setstate(std::ios::failbit);
        return output;
    }

    if ((output >> obj_2.rl).fail()){
        output.setstate(std::ios::failbit);
        return output;
    }

    output >> b;
    if (b != '+' && b != '-'){
        output.setstate(std::ios::failbit);
        return output;
    }
    output.putback(b);

    if ((output >> obj_2.im).fail()){
        output.setstate(std::ios::failbit);
        return output;
    }

    output >> a;
    if (a != 'i'){
        output.setstate(std::ios::failbit);
        return output;
    }

    output >> a;
    if (a != ')'){
        output.setstate(std::ios::failbit);
        return output;
    }

    return output;
}