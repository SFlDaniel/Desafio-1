#ifndef PIEZA_H
#define PIEZA_H

#include "tablero.h"

struct Pieza
{
    unsigned char* forma;
    int ancho;
    int alto;
};

void crearPieza(Pieza &p, int tipo);
void imprimirPieza(Pieza &p);
void liberarPieza(Pieza &p);


void inicializarPosicion(int *x, int *y);
void moverSeguro(Tablero* t, Pieza &p, int *x, int *y, char direccion);

void inicializarPosicionCentro(Tablero* t, Pieza &p, int *x, int *y);

#endif