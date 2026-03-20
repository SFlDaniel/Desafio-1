#ifndef TABLERO_H
#define TABLERO_H

struct Tablero
{
    unsigned char* datos; // memoria dinámica de bits
    int ancho;            // ancho en celdas
    int alto;             // alto en celdas
    int bytesPorFila;     // ancho / 8
};

// Constructor / Destructor
Tablero* crearTablero(int ancho, int alto);
void destruirTablero(Tablero* t);

// Limpieza
void limpiarTablero(Tablero* t);

// Lectura / Escritura de bits
int LeerBit(const Tablero* t, int x, int y);
void EscribirBit(Tablero* t, int x, int y, int valor);

// Filas
int filaLlena(const Tablero* t, int y);
void eliminarFilas(Tablero* t);

// Colisiones y fijar pieza
int hayColision(const Tablero* t, unsigned char* forma, int anchoPieza, int altoPieza, int posX, int posY);
void fijarPieza(Tablero* t, unsigned char* forma, int anchoPieza, int altoPieza, int posX, int posY);

#endif