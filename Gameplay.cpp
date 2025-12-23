#include "tablero.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

int main()
{
    // Creacion del tabler
    // Uso de una variable para gestionar el bucle ingame
    // Uso de un vector para gestionar más facilmente el uso de los mensajitos cuando hagamos el systemCLS
    InicializarTablero();
    bool turnoBlancas = true;
    std::vector<std::string> historialErrores;

    while (true)
    {
        system("cls"); // limpia la pantalla, lo dicho
        MostrarTablero();

        // Mostrar historial de errores con el for este alternativo y que no se borren con la limpieza
        for (auto& mensaje : historialErrores)
            std::cout << mensaje << "\n";

        if (turnoBlancas)
            std::cout << "\nTurno BLANCAS\n";
        else
            std::cout << "\nTurno NEGRAS\n";

        int f1, c1, f2, c2;
        std::cout << "Fila origen Columna origen: ";
        std::cin >> f1 >> c1;
        std::cout << "Fila destino Columna destino: ";
        std::cin >> f2 >> c2;

        char pieza = tablero[f1][c1];
        //Entrda ya al bucle, la parte importante casi
        //Gestion del bucle ingame con uso de la variable
        if (turnoBlancas)
        {
            if (!EsBlanca(pieza))
            {
                historialErrores.push_back("Debes mover una pieza blanca");
                continue;
            }
        }
        else
        {
            if (!EsNegra(pieza))
            {
                historialErrores.push_back("Debes mover una pieza negra");
                continue;
            }
        }

        if (!MoverPieza(f1, c1, f2, c2))
        {
            historialErrores.push_back("Movimiento no valido");
            continue;
        }

        //Se usa esto para no solapar errores y que no la liemos tanto llenando la pantalla de mierda
        historialErrores.clear();

        if (!HayRey('k'))
        {
            system("cls");
            MostrarTablero();
            std::cout << "\nBLANCAS GANAN\n";
            break;
        }

        if (!HayRey('K'))
        {
            system("cls");
            MostrarTablero();
            std::cout << "\nNEGRAS GANAN\n";
            break;
        }

        turnoBlancas = !turnoBlancas;
    }

    return 0;
}
