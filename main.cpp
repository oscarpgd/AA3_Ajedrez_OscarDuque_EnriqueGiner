#include <iostream>
#include "board.h"
#include "GamePlay.h"

void main()
{
	// Tablero
	char board[size][size];

	bool gameOver = false;
	bool isWhiteTurn = true; 
	// Inicialización 
	InitBoard(board);
	FillBoard(board);

	// Variables para coordenadas
	int srow = 0, scol = 0, erow = 0, ecol = 0;

	// Bucle de juego 
	while (!gameOver)
	{
		PrintBoard(board);

		// movimiento 
		AskPlayer(isWhiteTurn, srow, scol, erow, ecol, board);

		system("cls");

		// Comprobar si el rey ha muerto 
		if (!IsKingAlive(board, !isWhiteTurn))
		{
			PrintBoard(board);
			std::cout << "Ganan las " << (isWhiteTurn ? "blancas" : "negras") << " por jaque mate." << std::endl; 
			gameOver = true;
		}
		else
		{
			// Cambiar turno 
			isWhiteTurn = !isWhiteTurn;
		}
	}
}