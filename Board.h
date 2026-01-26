#pragma once
#pragma once
#include <iostream>
//Fichas blancas
#define wpawn 'P'
#define wbishop 'B'
#define wtower 'T'
#define whorse 'H'
#define wqueen 'Q'
#define wking 'K'
//Fichas negras
#define bpawn 'p'
#define bbishop 'b'
#define btower 't'
#define bhorse 'h'
#define bqueen 'q'
#define bking 'k'
//defines generales
#define empty '*'
#define size 8
//Funcion de única llamada al incio, rellena el tablero con '*'
void InitBoard(char board[][size]);
//Funcion de única llamada al incio, rellena el tablero con las fichas
void FillBoard(char board[][size]);
//Funcion llamada en el bucle del juego para printear el tablero
void PrintBoard(char board[][size]);
//Funcion auxiliar para printear las columnas, se integra con PrintBoard
void PrintCols();
