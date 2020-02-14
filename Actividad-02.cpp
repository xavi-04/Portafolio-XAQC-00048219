#include <iostream>

using namespace std;

//Prototipo de las funciones
void pedirDatos();
int **punteroMatriz1, **punteroMatriz2;
int nFilas;
int nCol;
void mostrarMatrizResultado(int **punteroMatriz1, int nFilas, int nCol);
void sumarMatrices(int **punteroMatriz1, int **punteroMatriz2, int nFilas, int nCol);

int main()
{

    pedirDatos();
    sumarMatrices(punteroMatriz1, punteroMatriz2, nFilas, nCol);
    mostrarMatrizResultado(punteroMatriz1, nFilas, nCol);

    return 0;
}

//Definicion de funcion
void pedirDatos()
{
    cout << "Ingrese el número de filas: ";
    cin >> nFilas;
    cout << "Ingrese el número de columnas: ";
    cin >> nCol;

    //Resereva de memoria para la primera matriz
    punteroMatriz1 = new int *[nFilas];
    for (int i = 0; i < nFilas; i++)
    {
        punteroMatriz1[i] = new int[nCol];
    }

    cout << "Digite los elementos de la primera matriz: " << endl;
    for (int i = 0; i < nFilas; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            cout << "Digite un numero[" << i << "][" << j << "]: " << endl;
            cin >> *(*(punteroMatriz1 + i) + j); //punteroMatriz1[i][j]
        }
    }

    //Reservar memoria para la segunda matriz
    punteroMatriz2 = new int *[nFilas];
    for (int i = 0; i < nFilas; i++)
    {
        punteroMatriz2[i] = new int[nCol];
    }

    cout << "Digite los elementos de la segunda matriz: " << endl;
    for (int i = 0; i < nFilas; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            cout << "Digite un numero[" << i << "][" << j << "]: " << endl;
            cin >> *(*(punteroMatriz2 + i) + j); //punteroMatriz2 [i][j]
        }
    }
}

//Definicion de funcion de suma
void sumarMatrices(int **punteroMatriz1, int **punteroMatriz2, int nFilas, int nCol)
{
    for (int i = 0; i < nFilas; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            *(*(punteroMatriz1 + i) + j) += *(*(punteroMatriz2 + i) + j);
        }
    }
}

//Definicion de funcion de mostrar el resultado
void mostrarMatrizResultado(int **punteroMatriz1, int nFila, int nCol)
{
    cout << "La suma de las dos matrices es: " << endl;

    for (int i = 0; i < nFilas; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            cout << *(*(punteroMatriz1 + i) + j) << " | "; //puntero_matriz[i][j]
        }
        cout << endl;
    }
}