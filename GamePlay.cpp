#include "GamePlay.h"
void AskPlayer(bool isWhiteTurn, int srow, int scol, int erow, int ecol, char board[][size])
{
	std::string tempText = isWhiteTurn ? "\nTurno de las Blancas\n" : "Turno de las negras\n";
	std::cout << tempText;

	bool movimientoFinalizado = false;

	while (!movimientoFinalizado)
	{
		// Seleccionar pieza de ORIGEN
		std::cout << " SELECCION DE PIEZA " << std::endl;
		std::cout << "Fila (X): "; std::cin >> srow;
		std::cout << "Columna (Y): "; std::cin >> scol;

		// Validar pieza
		if (srow < 1 || srow > 8 || scol < 1 || scol > 8 || !isAValidPiece(isWhiteTurn, board, srow, scol)) {
			std::cout << "Error: Seleccion invalida o no es una pieza tuya." << std::endl;
			continue; 
		}

		// Donde se mueve la ficha
		std::cout << "Mover a Fila (X): "; std::cin >> erow;
		if (erow == 0) continue; 
		std::cout << "Mover a Columna (Y): "; std::cin >> ecol;
		if (ecol == 0) continue;

		// Validar si el movimiento cumple las reglas de la pieza
		if (erow >= 1 && erow <= 8 && ecol >= 1 && ecol <= 8) {
			if (isAValidSpot(isWhiteTurn, board, srow, scol, erow, ecol)) {
				
				MovePiece(board, srow - 1, scol - 1, erow - 1, ecol - 1);
				CheckPawnPromotion(board, erow - 1, ecol - 1);
				movimientoFinalizado = true; 
			else {
				std::cout << "Esta pieza no puede mover asi o hay algo en el camino." << std::endl;
				
			}
		}
		else {
			std::cout << "Esa Casilla no existe!!" << std::endl;
		}
	}
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

bool isAValidSpot(bool isWhiteTurn, char board[][size], int srow, int scol, int erow, int ecol) {
	int sR = srow - 1;
	int sC = scol - 1;
	int eR = erow - 1;
	int eC = ecol - 1;
	char piece = board[sR][sC];

	if (piece == 'P' || piece == 'p') return IsValidPawnMove(isWhiteTurn, board, sR, sC, eR, eC);
	if (piece == 'T' || piece == 't') return IsValidTowerMove(isWhiteTurn, board, sR, sC, eR, eC);
	if (piece == 'K' || piece == 'k') return IsValidKingMove(isWhiteTurn, board, sR, sC, eR, eC);
	if (piece == 'B' || piece == 'b') return IsValidBishopMove(isWhiteTurn, board, sR, sC, eR, eC);
	if (piece == 'H' || piece == 'h') return IsValidHorseMove(isWhiteTurn, board, sR, sC, eR, eC);
	if (piece == 'Q' || piece == 'q') return IsValidQueenMove(isWhiteTurn, board, sR, sC, eR, eC);

	return false;
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
	//Miramos si nada por en medio
	int r = sRow + stepRow;
	int c = sCol + stepCol;
	for (int i = 1; i < distance; i++) {
		if (board[r][c] != empty) return false;
		r += stepRow;
		c += stepCol;
	}
	return true;
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
// Movimiento de la Torre 
bool IsValidTowerMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol) {
	if (sRow != eRow && sCol != eCol) return false; 
	if (!IsPathClear(board, sRow, sCol, eRow, eCol)) return false; 
	return board[eRow][eCol] == empty || IsEnemy(isWhiteTurn, board[eRow][eCol]);
}

// Movimiento del Rey 
bool IsValidKingMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol) {
	int dr = abs(eRow - sRow);
	int dc = abs(eCol - sCol);
	if (dr <= 1 && dc <= 1) {
		return board[eRow][eCol] == empty || IsEnemy(isWhiteTurn, board[eRow][eCol]);
	}
	return false;
}

// Movimiento del Peon 
bool IsValidPawnMove(bool isWhiteTurn, const char board[][size], int sRow, int sCol, int eRow, int eCol) {
	int direction = isWhiteTurn ? -1 : 1; 
	int dr = eRow - sRow;
	int dc = eCol - sCol;

	// Avance simple
	if (dc == 0 && dr == direction && board[eRow][eCol] == empty) return true;
	// Captura diagonal
	if (abs(dc) == 1 && dr == direction && IsEnemy(isWhiteTurn, board[eRow][eCol])) return true;

	return false;
}

// Coronacion
void CheckPawnPromotion(char board[][size], int row, int col) {
	if (board[row][col] == wpawn && row == 0) board[row][col] = wqueen;
	if (board[row][col] == bpawn && row == 7) board[row][col] = bqueen;
}
void MovePiece(char board[][size], int sRow, int sCol, int eRow, int eCol) {
	
	board[eRow][eCol] = board[sRow][sCol];

	//Vaciamos la casilla de origen
	board[sRow][sCol] = empty;
}