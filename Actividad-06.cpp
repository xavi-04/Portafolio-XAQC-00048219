#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct celular
{
    string Marca;
    string Color;
    string Estilo;
};
typedef struct celular Celular;

int main()
{
    stack<Celular> pilaDeCelulares;

    bool continuar = true;
    do
    {
        char opcion = 's';
        cout << "\nCantidad de celulares actuales: " << pilaDeCelulares.size();
        cout << "\nDesea apilar otro celular? (s/n): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S')
        {
            Celular unCelular;
            cout << "Marca: ";
            getline(cin, unCelular.Marca);
            cout << "Color: ";
            getline(cin, unCelular.Color);
            cout << "Estilo: ";
            getline(cin, unCelular.Estilo);
            pilaDeCelulares.push(unCelular);
        }
        else if (opcion == 'n' || opcion == 'N')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    } while (continuar);

    cout << "\nDesapilando celulares..." << endl;
    while (!pilaDeCelulares.empty())
    {

        Celular CelularDeEncima = pilaDeCelulares.top();
        cout << "Celular [" << CelularDeEncima.Marca;
        cout << ", " << CelularDeEncima.Color;
        cout << ", " << CelularDeEncima.Estilo << "]\n";

        pilaDeCelulares.pop();
    }
    cout << "Pila de platos vacia." << endl;

    return 0;
}
