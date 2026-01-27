#include "board.h"
void InitBoard(char board[][size])
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = empty;
		}
	}
}
void FillBoard(char board[][size])
{
	//Fill de negras
	board[0][0] = btower;
	board[0][1] = bhorse;
	board[0][2] = bbishop;
	board[0][4] = bking;
	board[0][3] = bqueen;
	board[0][5] = bbishop;
	board[0][6] = bhorse;
	board[0][7] = btower;
	for (int i = 0; i < size; i++)
	{
		board[1][i] = bpawn;
	}
	//Fill de Blancas
	board[7][0] = wtower;
	board[7][1] = whorse;
	board[7][2] = wbishop;
	board[7][3] = wqueen;
	board[7][4] = wking;
	board[7][5] = wbishop;
	board[7][6] = whorse;
	board[7][7] = wtower;
	for (int i = 0; i < size; i++)
	{
		board[6][i] = wpawn;
	}
}
void PrintBoard(char board[][size])
{
	PrintCols();
	//Aqui se añade un toque especial para printear filas
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << " ";
		for (int j = 0; j < size; j++)
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
void PrintCols()
{
	for (int i = 0; i < size + 1; i++) {
		if (i == 0)
			std::cout << "  ";
		else
			std::cout << i << " ";
	}
	std::cout << std::endl;
}