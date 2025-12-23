#pragma once

#include <iostream>

const int FILAS = 8;
const int COLUMNAS = 8;

extern char tablero[FILAS][COLUMNAS];

void InicializarTablero();
void MostrarTablero();

bool DentroTablero(int f, int c);
bool EsBlanca(char p);
bool EsNegra(char p);

bool MovimientoValido(int f1, int c1, int f2, int c2);
bool MoverPieza(int f1, int c1, int f2, int c2);

bool HayRey(char rey);


