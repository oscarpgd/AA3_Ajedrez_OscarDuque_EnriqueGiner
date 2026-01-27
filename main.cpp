#include <iostream>
#include "board.h"
#include "GamePlay.h"

void main()
{
	// Tablero
	char board[size][size];

	// Flags del gameloop
	bool gameOver = false;
	bool isWhiteTurn = true; // Empiezan las blancas

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

		
		//int sR = srow - 1;
		//int sC = scol - 1;
		//int eR = erow - 1;
		//int eC = ecol - 1;

		// Ejecutar el movimiento en la matriz
		MovePiece(board, sR, sC, eR, eC);

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