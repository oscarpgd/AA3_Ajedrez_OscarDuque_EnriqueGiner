#include <iostream>
#include "board.h"
#include "GamePlay.h"
void main()
{
	//Tablero
	char board[size][size];
	//Flags del gameloop
	bool gameOver = false;
	bool isWhiteTurn = true;
	//Obligatorias al inicio
	InitBoard(board);
	FillBoard(board);
	//Variables temporales de piezas
	int srow = 0; int scol = 0; int erow = 0; int ecol = 0;
	//Bucle de juego
	while (!gameOver)
	{
		PrintBoard(board);
		AskPlayer(isWhiteTurn, srow, scol, erow, ecol, board);
		std::cout << "\n" << srow << " " << scol;
		break;
	}
}