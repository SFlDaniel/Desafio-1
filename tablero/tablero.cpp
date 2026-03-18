#include "tablero.h"
#include <stdlib.h>
#include <string.h>

Tablero::Tablero(int ancho_, int alto_)
{
    ancho = ancho_;
    alto = alto_;

    bytesPorFila = ancho / 8;

    datos = new unsigned char[alto * bytesPorFila];

    limpiar();
}
Tablero::~Tablero()
{
    delete[] datos;
}

void Tablero::limpiar()
{
    int total = alto * bytesPorFila;

    for (int i = 0; i < total; i++)
        datos[i] = 0;
}

int Tablero::getAncho() const
{
    return ancho;
}

int Tablero::getAlto() const
{
    return alto;
}

int Tablero::getBit(int x, int y) const
{
    int byte = x / 8;
    int bit = x % 8;

    unsigned char b =
        datos[y * bytesPorFila + byte];

    return (b >> bit) & 1;
}

void Tablero::setBit(int x, int y, int valor)
{
    int byte = x / 8;
    int bit = x % 8;

    unsigned char& b =
        datos[y * bytesPorFila + byte];

    if (valor)
        b |= (1 << bit);
    else
        b &= ~(1 << bit);
}

int Tablero::filaLlena(int y) const
{
    for (int i = 0; i < bytesPorFila; i++)
    {
        if (datos[y * bytesPorFila + i] != 255)
            return 0;
    }

    return 1;
}

void Tablero::eliminarFilas()
{
    for (int y = alto - 1; y >= 0; y--)
    {

        if (filaLlena(y))
        {

            for (int k = y; k > 0; k--)
            {
                for (int b = 0; b < bytesPorFila; b++)
                {
                    datos[k * bytesPorFila + b] =
                        datos[(k - 1) * bytesPorFila + b];
                }
            }

            for (int b = 0; b < bytesPorFila; b++)
                datos[b] = 0;

            y++;
        }
    }
}

int Tablero::hayColision(unsigned char* forma,
    int anchoPieza,
    int altoPieza,
    int posX,
    int posY
    ) const
{

    for (int y = 0; y < altoPieza; y++)
    {

        for (int x = 0; x < anchoPieza; x++)
        {

            int bitPieza =
                (forma[y] >> x) & 1;

            if (bitPieza)
            {

                int tx = posX + x;
                int ty = posY + y;

                if (tx < 0 || tx >= ancho ||
                    ty < 0 || ty >= alto)
                    return 1;

                if (getBit(tx, ty))
                    return 1;
            }
        }
    }

    return 0;
}

void Tablero::fijarPieza(
    unsigned char* forma,
    int anchoPieza,
    int altoPieza,
    int posX,
    int posY
    )
{

    for (int y = 0; y < altoPieza; y++)
    {
        for (int x = 0; x < anchoPieza; x++)
        {

            int bit =
                (forma[y] >> x) & 1;

            if (bit)
            {
                setBit(
                    posX + x,
                    posY + y,
                    1
                    );
            }
        }
    }

}