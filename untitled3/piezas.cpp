#include <iostream>
#include "pieza.h"

using namespace std;

Pieza::Pieza(int tipo)
{
    //PIEZA I Raya//
    if(tipo == 0)
    {
        ancho = 4;
        alto = 1;
        forma = new unsigned char[alto];
        forma[0] = 0b00001111;
    }

    //PIEZA [] Cuadrado//
    else if(tipo == 1)
    {
        ancho = 2;
        alto = 2;
        forma = new unsigned char[alto];
        forma[0] = 0b00000011;
        forma[1] = 0b00000011;
    }

    // PIEZA T //
    else if(tipo == 2)
    {
        ancho = 3;
        alto = 2;
        forma = new unsigned char[alto];
        forma[0] = 0b00000010;
        forma[1] = 0b00000111;
    }

    //PIEZA S//
    else if(tipo == 3)
    {
        ancho = 4;
        alto = 2;
        forma = new unsigned char[alto];
        forma[0] = 0b00000110;
        forma[1] = 0b00000011;
    }

    //PEZA Z//
    else if(tipo == 4)
    {
        ancho = 4;
        alto = 2;
        forma = new unsigned char[alto];
        forma[0] = 0b00000011;
        forma[1] = 0b00000110;
    }

    //PIEZA L//
    else if(tipo == 5)
    {
        ancho = 2;
        alto = 3;
        forma = new unsigned char[alto];
        forma[0] = 0b00000001;
        forma[1] = 0b00000001;
        forma[2] = 0b00000011;
    }

    //PEZA J Acostda//
    else if(tipo == 6)
    {
        ancho = 3;
        alto = 2;
        forma = new unsigned char[alto];
        forma[0] = 0b00000111;
        forma[1] = 0b00000001;
    }
}

Pieza::~Pieza()
{
    delete[] forma;
}

void Pieza::imprimir()
{
    for(int i = 0; i < alto; i++)
    {
        for(int j = 0; j < ancho; j++)
        {
            unsigned char mask = 1 << (ancho - 1 - j);

            if(forma[i] & mask)
                cout << "[]";
            else
                cout << "  ";
        }
        cout << endl;
    }
}