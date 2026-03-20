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