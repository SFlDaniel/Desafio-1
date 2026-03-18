#include <iostream>
#include "piezas.h"

using namespace std;

void crearPieza(Pieza &p, int tipo)
{
    switch(tipo)
    {
    case 0: // Pieza Raya//
        p.ancho = 4;
        p.alto = 1;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b11110000;
        break;

    case 1: // Piza Cuadrado//
        p.ancho = 2;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b11000000;
        p.forma[1] = 0b11000000;
        break;

    case 2: // Pieza T//
        p.ancho = 3;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b01000000;
        p.forma[1] = 0b11100000;
        break;

    case 3: // Pieza S//
        p.ancho = 3;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b01100000;
        p.forma[1] = 0b11000000;
        break;

    case 4: // pieza Z//
        p.ancho = 3;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b11000000;
        p.forma[1] = 0b01100000;
        break;

    case 5: // Pieza L//
        p.ancho = 2;
        p.alto = 3;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b10000000;
        p.forma[1] = 0b10000000;
        p.forma[2] = 0b11000000;
        break;

    case 6: // J de lado//
        p.ancho = 3;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b11100000;
        p.forma[1] = 0b00100000;
        break;
    }
}

void imprimirPieza(Pieza &p)
{
    for(int i = 0; i < p.alto; i++)
    {
        unsigned char mascara = 0x80;

        for(int j = 0; j < p.ancho; j++)
        {
            if(p.forma[i] & mascara)
                cout << "[]";
            else
                cout << "  ";

            mascara >>= 1;
        }
        cout << endl;
    }
}

void liberarPieza(Pieza &p)
{
    delete[] p.forma;
}