
#ifndef PIEZA_H
#define PIEZA_H

class Pieza
{
private:
    unsigned char* forma;
    int ancho;
    int alto;

public:
    Pieza(int tipo);
    ~Pieza();

    void imprimir();
};

#endif
