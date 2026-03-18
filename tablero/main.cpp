#include <iostream>
#include "tablero.h"

using namespace std;

int main() //prueba
{
    Tablero t(16, 10);

    t.setBit(1, 1, 1);
    t.setBit(2, 1, 1);
    t.setBit(3, 1, 1);

    for (int y = 0; y < t.getAlto(); y++)
    {
        for (int x = 0; x < t.getAncho(); x++)
        {
            if (t.getBit(x, y))
                cout << "#";
            else
                cout << ".";
        }

        cout << endl;
    }

    return 0;
}