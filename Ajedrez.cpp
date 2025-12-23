#include "tablero.h"
#include <iostream>

char tablero[FILAS][COLUMNAS];

void InicializarTablero()
{
<<<<<<<< HEAD:AA3_Aejdrez/Tablero.cpp
    // Piezas negras
========

    char tablero[FILAS][COLUMNAS];

    //Piezas negras  

>>>>>>>> b382480b383c23f378f5591bf74e9457eb7ed7f8:Ajedrez.cpp
    tablero[0][0] = 'r'; tablero[0][1] = 'n'; tablero[0][2] = 'b'; tablero[0][3] = 'q';
    tablero[0][4] = 'k'; tablero[0][5] = 'b'; tablero[0][6] = 'n'; tablero[0][7] = 'r';

    for (int j = 0; j < COLUMNAS; j++)
        tablero[1][j] = 'p';

    // Casillas vacías
    for (int i = 2; i < 6; i++)
        for (int j = 0; j < COLUMNAS; j++)
            tablero[i][j] = '*';

<<<<<<<< HEAD:AA3_Aejdrez/Tablero.cpp
    // Piezas blancas
    for (int j = 0; j < COLUMNAS; j++)
        tablero[6][j] = 'P';
========
    //Piezas blancas

    for (int j = 0; j < COLUMNAS; j++) tablero[6][j] = 'P';
>>>>>>>> b382480b383c23f378f5591bf74e9457eb7ed7f8:Ajedrez.cpp

    tablero[7][0] = 'R'; tablero[7][1] = 'N'; tablero[7][2] = 'B'; tablero[7][3] = 'Q';
    tablero[7][4] = 'K'; tablero[7][5] = 'B'; tablero[7][6] = 'N'; tablero[7][7] = 'R';
}

void MostrarTablero()
{
    std::cout << "\n  ";
    for (int j = 0; j < COLUMNAS; j++)
        std::cout << j << " ";
    std::cout << "\n";

    for (int i = 0; i < FILAS; i++)
    {
        std::cout << i << " ";
        for (int j = 0; j < COLUMNAS; j++)
            std::cout << tablero[i][j] << " ";
        std::cout << "\n";
    }
}
