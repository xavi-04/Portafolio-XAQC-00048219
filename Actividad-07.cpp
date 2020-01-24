#include <iostream>
#include <string>
using namespace std;

struct celular
{
    string Marca;
    string Color;
    string Estilo;
};
typedef struct celular Celular;

struct nodo
{
    Celular elemento;
    struct nodo *siguiente;
};
typedef struct nodo *Pila;

void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Celular e);
Celular pop(Pila *s);
Celular top(Pila *s);

int main()
{

    Pila pilaDeCelulares;
    initialize(&pilaDeCelulares);

    bool continuar = true;
    do
    {
        char opcion = 's';

        cout << "\nDesea apilar otro Celular? (s/n): ";
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
            push(&pilaDeCelulares, unCelular);
        }
        else if (opcion == 'n' || opcion == 'N')
            continuar = false;
        else
            cout << "Opcion no valida!" << endl;
    } while (continuar);

    cout << "\nDesapilando Celulares..." << endl;
    while (!empty(&pilaDeCelulares))
    {

        Celular platoDeEncima = top(&pilaDeCelulares);
        cout << "Celular [" << platoDeEncima.Marca;
        cout << ", " << platoDeEncima.Color;
        cout << ", " << platoDeEncima.Estilo << "]\n";

        pop(&pilaDeCelulares);
    }
    cout << "Pila de platos vacia." << endl;

    return 0;
}

void initialize(Pila *s)
{
    *s = NULL;
}

bool empty(Pila *s)
{
    return *s == NULL;
}

void push(Pila *s, Celular e)
{
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;

    *s = unNodo;
}

Celular pop(Pila *s)
{
    if (!empty(s))
    {
        struct nodo *unNodo = *s;
        Celular e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete (unNodo);
        return e;
    }
    else
        return {{" "}, {" "}, {" "}};
}

Celular top(Pila *s)
{
    if (!empty(s))
        return (*s)->elemento;
    else
        return {{" "}, {" "}, {" "}};
}
