#include "tablero.h"
#include <iostream>

//Checkeo para no mover piezas fuera de lt ablero
bool DentroTablero(int f, int c)
{
	bool dentro = false;

	if (f >= 0 && f < FILAS && c >= 0 && c < COLUMNAS)
		dentro = true;

	return dentro;
}

//Checkeo para saber que piezas son de cada color en concreto
bool EsBlanca(char p)
{
	bool blanca = false;

	if (p == 'P' || p == 'R' || p == 'N' ||
		p == 'B' || p == 'Q' || p == 'K')
		blanca = true;

	return blanca;
}
bool EsNegra(char p)
{
	bool negra = false;

	if (p == 'p' || p == 'r' || p == 'n' ||
		p == 'b' || p == 'q' || p == 'k')
		negra = true;

	return negra;
}

//Delcaracion del enunciado de la funcion para usarla más abajo
bool CaminoLibre(int f1, int c1, int f2, int c2);
//Funcion importante dle juego que controla los movimientos
bool MovimientoValido(int f1, int c1, int f2, int c2)
{
	bool valido = false;

	if (DentroTablero(f1, c1) && DentroTablero(f2, c2))
	{
		char p = tablero[f1][c1];
		char d = tablero[f2][c2];

		if (p != '*')
		{
			if (!(EsBlanca(p) && EsBlanca(d)) &&
				!(EsNegra(p) && EsNegra(d)))
			{
				int df = f2 - f1;
				int dc = c2 - c1;

				//Una vez dentro del switch, ya cada pieza se mueve exactamente como debería en la vida real, aplicando comportamiento y checkeando mediante el bucle
				//Y el condicional del switch
				switch (p)
				{
				case 'P':
					if ((dc == 0 && df == -1 && d == '*' && CaminoLibre(f1, c1, f2, c2)) || ((dc == 1 || dc == -1) && df == -1 && d != '*'))
						valido = true;
					break;

				case 'p':
					if ((dc == 0 && df == 1 && d == '*' && CaminoLibre(f1, c1, f2, c2)) || ((dc == 1 || dc == -1) && df == 1 && d != '*'))
						valido = true;
					break;

				case 'R': case 'r':
					if ((df == 0 || dc == 0) && CaminoLibre(f1, c1, f2, c2))
						valido = true;
					break;

				case 'N': case 'n':
					if ((df == 2 || df == -2) && (dc == 1 || dc == -1))
						valido = true;
					if ((df == 1 || df == -1) && (dc == 2 || dc == -2))
						valido = true;
					break;

				case 'B': case 'b':
					if ((df == dc || df == -dc) && CaminoLibre(f1, c1, f2, c2))
						valido = true;
					break;

				case 'Q': case 'q':
					if ((df == 0 || dc == 0 || df == dc || df == -dc) && CaminoLibre(f1, c1, f2, c2))
						valido = true;
					break;

				case 'K': case 'k':
					if (df >= -1 && df <= 1 && dc >= -1 && dc <= 1)
						valido = true;
					break;
				}
			}
		}
	}

	return valido;
}

//Pequeño checkeo con coronacion, de peon a reina
bool MoverPieza(int f1, int c1, int f2, int c2)
{
	bool movido = false;

	if (MovimientoValido(f1, c1, f2, c2))
	{
		tablero[f2][c2] = tablero[f1][c1];
		tablero[f1][c1] = '*';

		// Coronación
		if (tablero[f2][c2] == 'P' && f2 == 0)
			tablero[f2][c2] = 'Q';

		if (tablero[f2][c2] == 'p' && f2 == 7)
			tablero[f2][c2] = 'q';

		movido = true;
	}

	return movido;
}

//Pequeño checkeo del rey
bool HayRey(char rey)
{
	bool encontrado = false;

	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			if (tablero[i][j] == rey)
				encontrado = true;
		}
	}

	return encontrado;
}

//Checkeo que se encarga de comprobar que el camino de las piezas esta bien, 
//para no rebasar / atravesar las piezas que nos vayamos encontrado
bool CaminoLibre(int f1, int c1, int f2, int c2)
{
	int df = f2 - f1;
	int dc = c2 - c1;

	int pasoF = (df == 0) ? 0 : (df > 0 ? 1 : -1);
	int pasoC = (dc == 0) ? 0 : (dc > 0 ? 1 : -1);

	int f = f1 + pasoF;
	int c = c1 + pasoC;

	while (f != f2 || c != c2)
	{
		if (tablero[f][c] != '*')
			return false;

		f += pasoF;
		c += pasoC;
	}

	return true;
}
