#include "tablero.h"

Tablero* crearTablero(int ancho, int alto)
{
    Tablero* t = new Tablero;
    t->ancho = ancho;
    t->alto = alto;
    t->bytesPorFila = ancho / 8;
    t->datos = new unsigned char[alto * t->bytesPorFila];

    limpiarTablero(t);

    return t;
}

void destruirTablero(Tablero* t)
{
    if (t)
    {
        delete[] t->datos;
        delete t;
    }
}

void limpiarTablero(Tablero* t)
{
    int total = t->alto * t->bytesPorFila;
    for (int i = 0; i < total; i++)
        t->datos[i] = 0;
}

int LeerBit(const Tablero* t, int x, int y)
{
    int byte = x / 8;
    int bit = x % 8;
    unsigned char b = t->datos[y * t->bytesPorFila + byte];
    return (b >> bit) & 1;
}

void EscribirBit(Tablero* t, int x, int y, int valor)
{
    int byte = x / 8;
    int bit = x % 8;
    unsigned char& b = t->datos[y * t->bytesPorFila + byte];

    if (valor)
        b |= (1 << bit);
    else
        b &= ~(1 << bit);
}

int filaLlena(const Tablero* t, int y)
{
    for (int i = 0; i < t->bytesPorFila; i++)
    {
        if (t->datos[y * t->bytesPorFila + i] != 255)
            return 0;
    }
    return 1;
}

void eliminarFilas(Tablero* t)
{
    for (int y = t->alto - 1; y >= 0; y--)
    {
        if (filaLlena(t, y))
        {
            // mover todo hacia abajo
            for (int k = y; k > 0; k--)
            {
                for (int b = 0; b < t->bytesPorFila; b++)
                    t->datos[k * t->bytesPorFila + b] = t->datos[(k - 1) * t->bytesPorFila + b];
            }
            // limpiar fila superior
            for (int b = 0; b < t->bytesPorFila; b++)
                t->datos[b] = 0;

            y++; // revisar fila actual nuevamente
        }
    }
}

int hayColision(const Tablero* t, unsigned char* forma, int anchoPieza, int altoPieza, int posX, int posY)
{
    for (int y = 0; y < altoPieza; y++)
    {
        for (int x = 0; x < anchoPieza; x++)
        {
            int bitPieza = (forma[y] >> x) & 1;
            if (bitPieza)
            {
                int tx = posX + x;
                int ty = posY + y;

                if (tx < 0 || tx >= t->ancho || ty < 0 || ty >= t->alto)
                    return 1;

                if (getBit(t, tx, ty))
                    return 1;
            }
        }
    }
    return 0;
}

void fijarPieza(Tablero* t, unsigned char* forma, int anchoPieza, int altoPieza, int posX, int posY)
{
    for (int y = 0; y < altoPieza; y++)
    {
        for (int x = 0; x < anchoPieza; x++)
        {
            int bit = (forma[y] >> x) & 1;
            if (bit)
                setBit(t, posX + x, posY + y, 1);
        }
    }
}