#include <iostream>
#include <string>
using namespace std;

struct pais
{
    string nombre, capital;
    int habitantes;
};
typedef struct pais paises;

struct continente
{
    string nombreContinente;

    int poblacion = 0;

    paises paisxCon[5];
};

typedef struct continente continentes;

int main()
{
    string mayorCapital;
    string nombreContinentePoblacion;
    continentes continente;

    cout << "Ingrese los datos: " << endl << endl;

    cout << "Ingrese el nombre del continente " << ": " << endl;
    cin >> continente.nombreContinente;
    cout << endl;

    cout << "Introduzca la informacion de los paises del continente: " << endl;

    for (int j = 0; j <= 4; j++)
    {
        cout << "Nombre del país " << j + 1 << ": " << endl;
        cin >> continente.paisxCon[j].nombre;
        cout << "Nombre de la Capital: " << endl;
        cin >> continente.paisxCon[j].capital;
        cout << "Cantidad de habitantes: " << endl;
        cin >> continente.paisxCon[j].habitantes;
        cout << endl;
        continente.poblacion = continente.poblacion + continente.paisxCon[j].habitantes;
    }

    cout << "Los datos ingresados son: " << endl << endl;

    int numMayor = 0;
    cout << "Continente " << ": " << continente.nombreContinente << endl;

    for (int j = 0; j <= 4; j++)
    {
        cout << "País: " << j + 1 << ": " << continente.paisxCon[j].nombre << endl;
        cout << "Capital: " << continente.paisxCon[j].capital << endl;
        cout << "Habitantes: " << continente.paisxCon[j].habitantes << endl;
        if (continente.paisxCon[j].habitantes > numMayor)
        {
            numMayor = continente.paisxCon[j].habitantes;
            mayorCapital = continente.paisxCon[j].capital;
        }
    }
    cout << "La capital con mayor poblacion es: " << mayorCapital << endl;

    cout << endl
         << endl
         << endl;

    
    return 0;
}
