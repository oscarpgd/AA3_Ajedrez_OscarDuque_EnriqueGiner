#include <iostream> 

const int FILAS = 8;
const int COLUMNAS = 8;

void InicializarTablero()

{

    char tablero[FILAS][COLUMNAS];

 //Piezas negras  

    tablero[0][0] = 'r'; tablero[0][1] = 'n'; tablero[0][2] = 'b'; tablero[0][3] = 'q';
    tablero[0][4] = 'k'; tablero[0][5] = 'b'; tablero[0][6] = 'n'; tablero[0][7] = 'r';

    for (int j = 0; j < COLUMNAS; j++) tablero[1][j] = 'p';



 

    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            tablero[i][j] = '*';
        }
    }

//Piezas blancas

    for (int j = 0; j < COLUMNAS; j++) tablero[6][j] = 'P';

    tablero[7][0] = 'R'; tablero[7][1] = 'N'; tablero[7][2] = 'B'; tablero[7][3] = 'Q';
    tablero[7][4] = 'K'; tablero[7][5] = 'B'; tablero[7][6] = 'N'; tablero[7][7] = 'R';



    // Mostrar columnas 

    std::cout << "  ";

    for (int j = 0; j < COLUMNAS; j++)
    {
        std::cout << j << " ";
    }
    std::cout << std::endl;

    // Mostrar tablero con número de fila 

    for (int i = 0; i < FILAS; i++) {

        std::cout << i << " ";

        for (int j = 0; j < COLUMNAS; j++) {

            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void main()

{

    InicializarTablero();

}

