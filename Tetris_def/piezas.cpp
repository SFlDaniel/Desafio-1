#include "piezas.h"
#include <cstdlib>
#include <iostream>
#include "tablero.h"
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

    case 4: // L
        p.ancho = 2;
        p.alto = 3;
        p.forma = new unsigned char[p.alto];
        p.forma[0] = 0b00000001;
        p.forma[1] = 0b00000001;
        p.forma[2] = 0b00000011;
        break;
    }
}

void liberarPieza(Pieza &p)
{
    delete[] p.forma;
    p.forma = nullptr;
}

int piezaAleatoria()
{
    return rand() % 5;
}

void rotarSeguro(Tablero* t, Pieza &p, int x, int y)
{
    unsigned char* nuevaForma = new unsigned char[p.ancho];

    for(int i = 0; i < p.ancho; i++)
        nuevaForma[i] = 0;

    for(int i = 0; i < p.alto; i++)
    {
        for(int j = 0; j < p.ancho; j++)
        {
            int bit = (p.forma[i] >> j) & 1;

            if(bit)
                nuevaForma[j] |= (1 << (p.alto - 1 - i));
        }
    }

    int nuevoAncho = p.alto;
    int nuevoAlto = p.ancho;

    if(!hayColision(t, nuevaForma, nuevoAncho, nuevoAlto, x, y))
    {
        delete[] p.forma;
        p.forma = nuevaForma;
        p.ancho = nuevoAncho;
        p.alto = nuevoAlto;
    }
    else
    {
        delete[] nuevaForma;
    }
}

void moverSeguro(Tablero* t, Pieza &p, int *x, int *y, char direccion)
{
    int nuevoX = *x;
    int nuevoY = *y;

    switch(direccion)
    {
    case 'a':
        nuevoX--;
        break;

    case 'd':
        nuevoX++;
        break;

    case 's':
        nuevoY++;
        break;

    default:
        return;
    }

    if (!hayColision(t, p.forma, p.ancho, p.alto, nuevoX, nuevoY))
    {
        *x = nuevoX;
        *y = nuevoY;
    }
}

void inicializarPosicionCentro(Tablero* t, Pieza &p, int *x, int *y)
{
    *x = (t->ancho - p.ancho) / 2;
    *y = 0;
}