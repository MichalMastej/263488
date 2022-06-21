#include <iostream>
#include <fstream>
#include <unistd.h>
#include <math.h>
#include <thread>
#include "ObrysXY.hh"

ObrysXY::ObrysXY(){

    wierz_dolny_lewy[0] = 0;
    wierz_dolny_lewy[1] = 0;
    wierz_gorny_prawy[0] = 0;
    wierz_gorny_prawy[1] = 0;
}