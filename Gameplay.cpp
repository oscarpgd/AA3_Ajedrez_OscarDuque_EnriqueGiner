#include "tablero.h"

int main()
{
    InicializarTablero();
    bool turnoBlancas = true;

    while (true)
    {
        MostrarTablero();

        if (turnoBlancas)
        {
            std::cout << "\nTurno BLANCAS\n";
        }
        else
        {
            std::cout << "\nTurno NEGRAS\n";
        }

        int f1, c1, f2, c2;
        std::cout << "Fila origen Columna origen: ";
        std::cin >> f1 >> c1;
        std::cout << "Fila destino Columna destino: ";
        std::cin >> f2 >> c2;

        char pieza = tablero[f1][c1];

        if (turnoBlancas)
        {
            if (!EsBlanca(pieza))
            {
                std::cout << "Debes mover una pieza blanca\n";
                continue;
            }
        }
        else
        {
            if (!EsNegra(pieza))
            {
                std::cout << "Debes mover una pieza negra\n";
                continue;
            }
        }

        if (!MoverPieza(f1, c1, f2, c2))
        {
            std::cout << "Movimiento no valido\n";
            continue;
        }

        if (!HayRey('k'))
        {
            MostrarTablero();
            std::cout << "\nBLANCAS GANAN\n";
            break;
        }

        if (!HayRey('K'))
        {
            MostrarTablero();
            std::cout << "\nNEGRAS GANAN\n";
            break;
        }

        turnoBlancas = !turnoBlancas;
    }

    return 0;
}
