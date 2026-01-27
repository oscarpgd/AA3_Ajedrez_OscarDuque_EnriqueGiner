#include "GamePlay.h"
void AskPlayer(bool isWhiteTurn, int srow, int scol, int erow, int ecol, char board[][size])
{
	//Codigo para printear de quien es el turno
	std::string tempText;
	tempText = isWhiteTurn ? "\nTurno de las Blancas\n" : "Turno de las negras\n";
	std::cout << tempText;
	//Bucle para escoger la pieza que mover
	//Bucle para comprobar que en la posicion que elija el player, hay pieza valida
	while (true)
	{
		//Bucle de pregunta para la pieza a mover, y comprobar si esta dentro de los límites
		while (true) {
			std::cout << "Que pieza quieres mover (X): ";
			std::cin >> srow;
			if (srow >= 1 && srow < 9)
				break;
		}
		while (true) {
			std::cout << "Que pieza quieres mover (Y): ";
			std::cin >> scol;
			if (scol >= 1 && scol < 9)
				break;
		}
		//Comprobación de si en esa posicion hay una pieza del color correspondiente
		bool validPiece = isAValidPiece(isWhiteTurn, board, srow, scol);
		if (validPiece) break;
		else
			std::cout << "Debes elegir una posicion donde haya una pieza de tu color\n";
	}
	//Bucle para comprobar si la posicion donde quiere mover es una posicion valida
	while (true)
	{
		//Bucle de pregunta para la pieza a mover, y comprobar si esta dentro de los límites
		while (true) {
			std::cout << "A que posicion la quieres mover (X): ";
			std::cin >> erow;
			if (erow >= 1 && erow < 9)
				break;
		}
		while (true) {
			std::cout << "A que posicion la quiere mover (Y): ";
			std::cin >> ecol;
			if (ecol >= 1 && ecol < 9)
				break;
		}
		//Comprobación de si en esa posicion hay una pieza del color correspondiente
		bool validPosition = isAValidPiece(isWhiteTurn, board, srow, scol);
		if (validPosition) break;
		else
			std::cout << "Debes elegir una posicion válida\n";
	}
	std::cout << srow << " " << scol;
	//para la pieza que hemos escogido, es una posición válida
}
bool isAValidPiece(bool isWhiteTurn, char board[][size], int srow, int scol)
{
	int row = srow - 1;
	int col = scol - 1;
	//aqui restamos 1 para que cuadre con el tablero, ya que preguntamos del 1 al 8, pero el tablero es del 0 al 7
	if (isWhiteTurn)
	{
		if (board[row][col] == wpawn || board[row][col] == wtower || board[row][col] == whorse ||
			board[row][col] == wbishop || board[row][col] == wking || board[row][col] == wqueen)
		{
			return true;
		}
		else return false;
	}
	else {
		if (board[row][col] == bpawn || board[row][col] == btower || board[row][col] == bhorse ||
			board[row][col] == bbishop || board[row][col] == bking || board[row][col] == bqueen)
		{
			return true;
		}
		else return false;
	}
}
bool isAValidSpot(bool isWhiteTurn, char board[][size], int srow, int scol, int erow, int ecol)
{
	//Start
	int sRow = srow - 1;
	int sCol = scol - 1;
	//End
	int eRow = erow - 1;
	int eCol = ecol - 1;
	//Para no mover a la misma casilla
	if (sRow == eRow && sCol == eCol) return false;
	char piece = board[sRow][sCol];
	if (piece == empty) return false;
	bool isWhitePiece = IsMayus(piece);
	if (isWhiteTurn != isWhitePiece) return false;
	//Llamada a una comprobación particular pieza por pieza
	if (piece == 'B' || piece == 'b') {
		return IsValidBishopMove(isWhiteTurn, board, sRow, sCol, eRow, eCol);
	}
	if (piece == 'H' || piece == 'h') {
		return IsValidHorseMove(isWhiteTurn, board, sRow, sCol, eRow, eCol);
	}
	if (piece == 'Q' || piece == 'q') {
		return IsValidQueenMove(isWhiteTurn, board, sRow, sCol, eRow, eCol);
	}
}
bool IsEnemy(bool isWhiteTurn, char target)
{
	if (target == empty) return false;
	bool esPiezaBlanca = IsMayus(target);
	return isWhiteTurn ? !esPiezaBlanca : esPiezaBlanca;
}
bool IsPathClear(const char board[][size], int sRow, int sCol, int eRow, int eCol)
{
	//Distance row & distance col
	int dr = eRow - sRow;
	int dc = eCol - sCol;
	//Determinar la dirección
	int stepRow = 0;
	if (dr > 0) stepRow = 1;
	else if (dr < 0) stepRow = -1;
	int stepCol = 0;
	if (dc > 0) stepCol = 1;
	else if (dc < 0) stepCol = -1;
	//distancia, la mayor de las dos
	int distance;
	if (dr < 0)
		dr = -dr;
	if (dc < 0)
		dc = -dc;
	if (dr > dc)
		distance = dr;
	else
		distance = dc;
	//Avanzamos paso a paso comprobando los huecos
	int r = sRow + stepRow;
	int c = sCol + stepCol;
	for (int i = 1; i < distance; i++) {
		if (board[r][c] != empty) return false;
		r += stepRow;
		c += stepCol;
	}
}
bool IsMayus(char piece)
{
	if (piece == 'K' || piece == 'Q' || piece == 'T' || piece == 'H' || piece == 'P' || piece == 'B')
		return true;
	else
		return false;
}
//Piezas, particularmente
bool IsValidBishopMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol)
{
	int dr = eRow - sRow;
	int dc = eCol - sCol;
	// Convertimos diferencias a positivas para comparar
	int absDr = (dr < 0) ? -dr : dr;
	int absDc = (dc < 0) ? -dc : dc;
	// Debe ser movimiento diagonal (misma distancia en fila y columna, y no cero)
	if (absDr == 0 || absDc == 0 || absDr != absDc) {
		return false;
	}
	// Camino libre (no chequeamos destino, solo intermedios)
	if (!IsPathClear(board, sRow, sCol, eRow, eCol)) {
		return false;
	}
	// Destino válido: vacío o enemigo
	char target = board[eRow][eCol];
	return (target == empty || IsEnemy(isWhiteTurn, target));
}
bool IsValidHorseMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol)
{
	int dr = eRow - sRow;
	int dc = eCol - sCol;
	// Convertimos a positivo para comparar
	int absDr = (dr < 0) ? -dr : dr;
	int absDc = (dc < 0) ? -dc : dc;
	// Patrón L del caballo: (2 en una dirección y 1 en perpendicular)
	bool esPatronL = (absDr == 2 && absDc == 1) || (absDr == 1 && absDc == 2);
	if (!esPatronL) {
		return false;
	}
	// Solo destino válido: vacío o enemigo
	char target = board[eRow][eCol];
	return (target == empty || IsEnemy(isWhiteTurn, target));
}
bool IsValidQueenMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol)
{
	int dr = eRow - sRow;
	int dc = eCol - sCol;
	int absDr = (dr < 0) ? -dr : dr;
	int absDc = (dc < 0) ? -dc : dc;
	// Reina mueve como torre O como alfil
	bool esHorizontalVertical = (dr == 0 || dc == 0) && (absDr + absDc > 0);
	bool esDiagonal = (absDr == absDc) && (absDr > 0);
	if (!esHorizontalVertical && !esDiagonal) {
		return false;
	}
	// Camino libre (vale para ambas direcciones)
	if (!IsPathClear(board, sRow, sCol, eRow, eCol)) {
		return false;
	}
	// Destino válido
	char target = board[eRow][eCol];
	return (target == empty || IsEnemy(isWhiteTurn, target));
}
bool IsKingAlive(char board[][size], bool isWhite)
{
	//Buscamos al rey que queremos
	char targetKing = isWhite ? wking : bking;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == targetKing)
			{
				return true; // Rey Encontrado
			}
		}
	}
	return false; //Rey Muerto
}
void MovePiece(char board[][size], int sRow, int sCol, int eRow, int eCol) {
	
	board[eRow][eCol] = board[sRow][sCol];

	// 2. Vaciamos la casilla de origen
	board[sRow][sCol] = empty;
}