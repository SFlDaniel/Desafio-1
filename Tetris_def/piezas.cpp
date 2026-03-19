#include "piezas.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void crearPieza(Pieza &p, int tipo)
{
    switch(tipo)
    {
    case 0: // I
        p.ancho = 4;
        p.alto = 1;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00001111;
        break;

    case 1: // O
        p.ancho = 2;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00000011;
        p.forma[1] = 0b00000011;
        break;

    case 2: // T
        p.ancho = 3;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00000010;
        p.forma[1] = 0b00000111;
        break;

    case 3: // S
        p.ancho = 3;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00000110;
        p.forma[1] = 0b00000011;
        break;

    case 4: // Z
        p.ancho = 3;
        p.alto = 2;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00000011;
        p.forma[1] = 0b00000110;
        break;

    case 5: // L
        p.ancho = 2;
        p.alto = 3;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00000001;
        p.forma[1] = 0b00000001;
        p.forma[2] = 0b00000011;
        break;

    case 6: // J
        p.ancho = 2;
        p.alto = 3;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00000011;
        p.forma[1] = 0b00000001;
        p.forma[2] = 0b00000001;
        break;
    }
}

void imprimirPieza(Pieza &p)
{
    for(int i = 0; i < p.alto; i++)
    {
        unsigned char mascara = 1;

        for(int j = 0; j < p.ancho; j++)
        {
            if(p.forma[i] & mascara)
                cout << "[]";
            else
                cout << "  ";

            mascara <<= 1;
        }
        cout << endl;
    }
}

void liberarPieza(Pieza &p)
{
    delete[] p.forma;
    p.forma = nullptr;
}

int piezaAleatoria()
{
    return rand() % 7;
}

void rotarPieza(Pieza &p)
{
    unsigned char* nuevaForma = new unsigned char[p.ancho];
    // inicializar en 0
    for(int i = 0; i < p.ancho; i++)
        nuevaForma[i] = 0;

    for(int y = 0; y < p.alto; y++)
    {
        for(int x = 0; x < p.ancho; x++)
        {
            int bit = (p.forma[y] >> x) & 1;

            if(bit)
            {
                // rotación 90°: (x, y) -> (y, ancho-1-x)
                nuevaForma[x] |= (1 << (p.alto - 1 - y));
            }
        }
    }
    delete[] p.forma;

    int temp = p.ancho;
    p.ancho = p.alto;
    p.alto = temp;
    p.forma = nuevaForma;
}