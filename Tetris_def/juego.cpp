#include "juego.h"
#include <iostream>
using namespace std;

void dibujar(Tablero* t, Pieza &p, int x, int y)
{
    for(int i = 0; i < t->alto; i++)
    {
        for(int j = 0; j < t->ancho; j++)
        {
            int ocupado = LeerBit(t, j, i);

            int enPieza = 0;
            int px = j - x;
            int py = i - y;

            if(px >= 0 && px < p.ancho && py >= 0 && py < p.alto)
                enPieza = (p.forma[py] >> px) & 1;

            if(ocupado || enPieza)
                cout << "[]";
            else
                cout << " .";
        }
        cout << endl;
    }
}

int gameOver(Tablero* t, Pieza &p, int x, int y)
{
    return hayColision(t, p.forma, p.ancho, p.alto, x, y);
}

char leerAccion()
{
    char c;
    cout << "a: izq | d: der | s: bajar | w: rotar ";
    cin >> c;
    return c;
}

void bucleJuego(Tablero* t)
{
    Pieza p;
    int x, y;
    crearPieza(p, piezaAleatoria());
    inicializarPosicionCentro(t, p, &x, &y);
    if(gameOver(t, p, x, y))
    {
        cout << "GAME OVER" << endl;
        return;
    }

    while(true)
    {
        dibujar(t, p, x, y);
        char accion = leerAccion();
        if(accion == 'w')
        {
            rotarSeguro(t, p, x, y);
        }
        else
        {
            int oldY = y;
            moverSeguro(t, p, &x, &y, accion);

            if(accion == 's' && y == oldY)
            {
                fijarPieza(t, p.forma, p.ancho, p.alto, x, y);
                eliminarFilas(t);
                liberarPieza(p);
                crearPieza(p, piezaAleatoria());
                inicializarPosicionCentro(t, p, &x, &y);

                if(gameOver(t, p, x, y))
                {
                    cout << "GAME OVER" << endl;
                    break;
                }
            }
        }
    }
    liberarPieza(p);
}
void iniciarJuego()
{
    int ancho = 8;
    int alto = 10;

    Tablero* t = crearTablero(ancho, alto);

    bucleJuego(t);

    destruirTablero(t);
}