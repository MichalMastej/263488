#include "UkladRownanLiniowych.hh"

Wektor UkladRownanLiniowych::oblicz(UkladRownanLiniowych &url){

    for (int i = 0; i < ROZMIAR; ++i)
    {
        for (int j = 0; j < ROZMIAR; ++j)
        {
            /* code */
        }
        
    }

    return url.b;
}

std::ostream &operator<< (std::ostream &output, UkladRownanLiniowych &url){

    output << url.A;

    output << url.b;

    return output;
}

std::istream &operator>> (std::istream &input, UkladRownanLiniowych &url){

    input >> url.A;

    input >> url.b;

    return input;
}