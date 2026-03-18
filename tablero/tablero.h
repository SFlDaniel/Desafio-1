#ifndef TABLERO_H
#define TABLERO_H

class Tablero
{

private:

    unsigned char* datos;

    int ancho;
    int alto;

    int bytesPorFila;

public:

    Tablero(int ancho, int alto);
    ~Tablero();

    void limpiar();

    int getAncho() const;
    int getAlto() const;

    int getBit(int x, int y) const;
    void setBit(int x, int y, int valor);

    int hayColision(
        unsigned char* forma,
        int anchoPieza,
        int altoPieza,
        int posX,
        int posY
        ) const;

    void fijarPieza(
        unsigned char* forma,
        int anchoPieza,
        int altoPieza,
        int posX,
        int posY
        );

    void eliminarFilas();

    int filaLlena(int y) const;

};

#endif