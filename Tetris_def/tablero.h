#ifndef TABLERO_H
#define TABLERO_H

struct Tablero
{
    unsigned char* datos;
    int ancho;
    int alto;
    int bytesPorFila;
};

Tablero* crearTablero(int ancho, int alto);
void destruirTablero(Tablero* t);

void limpiarTablero(Tablero* t);

int LeerBit(const Tablero* t, int x, int y);
void EscribirBit(Tablero* t, int x, int y, int valor);

int filaLlena(const Tablero* t, int y);
void eliminarFilas(Tablero* t);

int hayColision(const Tablero* t, unsigned char* forma, int anchoPieza, int altoPieza, int posX, int posY);
void fijarPieza(Tablero* t, unsigned char* forma, int anchoPieza, int altoPieza, int posX, int posY);

#endif