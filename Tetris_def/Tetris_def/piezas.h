#ifndef PIEZA_H
#define PIEZA_H

struct Pieza
{
    unsigned char* forma;
    int ancho;
    int alto;
};

void crearPieza(Pieza &p, int tipo);
void imprimirPieza(Pieza &p);
void liberarPieza(Pieza &p);

#endif
