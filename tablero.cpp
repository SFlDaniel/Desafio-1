#include <iostream>
#include "tablero.h"

using namespace std;

static unsigned char* tablero = nullptr;

static int anchoTablero = 0;
static int altoTablero = 0;
static int bytesPorFila = 0;

void imprimirTablero()
{
    cout << "+";
    for (int c = 0; c < anchoTablero; c++)
        cout << "--";
    cout << "+" << endl;

    for (int f = 0; f < altoTablero; f++)
    {
        cout << "|";

        for (int c = 0; c < anchoTablero; c++)
        {
            if (getBit(f, c))
                cout << "[]";
            else
                cout << "  ";
        }

        cout << "|" << endl;
    }
    cout << "+";
    for (int c = 0; c < anchoTablero; c++)
        cout << "--";
    cout << "+" << endl;
}
