#pragma once
#include <iostream>
#include "board.h"
//Funcion para preguntar al jugador donde mover
//srow y erow para star y end, respectivamente, lo mismo con las cols
void AskPlayer(bool isWhiteTurn, int srow, int scol, int erow, int ecol, char board[][size]);
//Funcion para comprobar si la pieza seleccionada para mover, es una pieza válida
bool isAValidPiece(bool isWhiteTurn, char board[][size], int srow, int scol);
//Funcion para escoger si el movimiento escogido es válido
bool isAValidSpot(bool isWhiteTurn, char board[][size], int srow, int scol, int erow, int ecol);
//Funcion para comprobar si las piezas que nos vamos encontrando son rivales o no
bool IsEnemy(bool isWhiteTurn, char target);
//Funcion para comprobar si el camino está vacio y no atravesar piezas
bool IsPathClear(const char board[][size], int sRow, int sCol, int eRow, int eCol);
//Funcion auxiliar para distinguir entre blancas y negras
bool IsMayus(char piece);
//Funcion particular para cada pieza, 6 en total
bool IsValidBishopMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol);
bool IsValidHorseMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol);
bool IsValidQueenMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol);