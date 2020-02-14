#include <iostream>
#include <string>
using namespace std;

struct Pedido
{
    string Apellido;
    int Mesa;
    int Burritos;
    int Alitas;
    int Tacos;
    int Hamburguesas;
    int HotDogs;
    int Pizza;
    int Ensalada;
    int Tiempo;
    
};

typedef Pedido T;
const T noValido = {{""}, -1, -1, -1, -1, -1, -1, -1, -1, -1};

struct Nodo
{
    T elemento;
    struct Nodo *siguiente;
};

struct Cola
{
    Nodo *frente;
    Nodo *final;
};

void initialize(Cola *q);
bool empty(Cola *q);
T front(Cola *q);
T back(Cola *q);
void enqueue(Cola *q, T x);
T dequeue(Cola *q);
int size(Cola *q);

struct Restaurant
{
    Cola colaPedidos;
    int ComidaHecha;
};

Restaurant MixRestaurant;
void agregar();
void consultar();
void servir();
void vertodos();

int main()
{

    cout << "\nBienvenidos a Mix Restaurant ";
    initialize(&MixRestaurant.colaPedidos);
    MixRestaurant.ComidaHecha = 0;

    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "\n\t1) Agregar orden";
        cout << "\n\t2) Consultar ordenes";
        cout << "\n\t3) Despachar ordenes";
        cout << "\n\t4) Ver todas las ordenes";
        cout << "\n\t5) Salir";
        cout << "\n\t   Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            agregar();
            break;
        case 2:
            consultar();
            break;
        case 3:
            servir();
            break;
        case 4:
            vertodos();
            break;
        case 5:
            continuar = false;
            break;
        default:
            cout << "Opción inválida!\n";
            break;
        }

    } while (continuar);

    return 0;
}

void initialize(Cola *q)
{
    q->frente = NULL;
    q->final = NULL;
}

bool empty(Cola *q)
{
    return (q->frente == NULL) ? true : false;
}

T front(Cola *q)
{
    if (empty(q))
    {
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->frente)->elemento;
}

T back(Cola *q)
{
    if (empty(q))
    {
        cout << "Underflow!" << endl;
        return noValido;
    }
    return (q->final)->elemento;
}

void enqueue(Cola *q, T x)
{
    Nodo *unNodo = new Nodo;
    unNodo->elemento = x;
    unNodo->siguiente = NULL;

    if (q->final == NULL)
        q->frente = unNodo;
    else
        (q->final)->siguiente = unNodo;

    q->final = unNodo;
}

T dequeue(Cola *q)
{
    if (empty(q))
    {
        cout << "Underflow!" << endl;
        return noValido;
    }
    Nodo *unNodo = q->frente;
    T x = unNodo->elemento;
    q->frente = unNodo->siguiente;
    if (q->frente == NULL)
        q->final = NULL;
    delete (unNodo);
    return x;
}

int size(Cola *q)
{
    Cola colaTemporal;
    initialize(&colaTemporal);

    int contador = 0;
    while (!empty(q))
    {
        T elemento = dequeue(q);
        enqueue(&colaTemporal, elemento);
        contador++;
    }
    while (!empty(&colaTemporal))
    {
        T elemento = dequeue(&colaTemporal);
        enqueue(q, elemento);
    }
    return contador;
}

void agregar()
{
    Pedido unPedido;
    cout << "Digite su apellido: ";
    getline(cin, unPedido.Apellido);
    cout << "Número de la mesa: ";
    cin >> unPedido.Mesa;
    cin.ignore();
    cout << "Cantidad de ordenes de alitas: ";
    cin >> unPedido.Alitas;
    cin.ignore();
    cout << "Cantidad de ordenes de burritos: ";
    cin >> unPedido.Burritos;
    cin.ignore();
    cout << "Cantidad de ordenes de ensalada: ";
    cin >> unPedido.Ensalada;
    cin.ignore();
    cout << "Cantidad de ordenes de hamburguesa: ";
    cin >> unPedido.Hamburguesas;
    cin.ignore();
    cout << "Cantidad de ordenes de Hot Dogs: ";
    cin >> unPedido.HotDogs;
    cin.ignore();
    cout << "Cantidad de ordenes de pizza: ";
    cin >> unPedido.Pizza;
    cin.ignore();
    cout << "Cantidad de ordenes de tacos: ";
    cin >> unPedido.Tacos;
    cin.ignore();
    unPedido.Tiempo = (unPedido.Alitas + unPedido.Burritos + unPedido.Ensalada + unPedido.Hamburguesas + unPedido.HotDogs + unPedido.Pizza + unPedido.Tacos) * 600;

    enqueue(&MixRestaurant.colaPedidos, unPedido);

    MixRestaurant.ComidaHecha += (unPedido.Alitas + unPedido.Burritos + unPedido.Ensalada + unPedido.Hamburguesas + unPedido.HotDogs + unPedido.Pizza + unPedido.Tacos);
}

void consultar()
{
    cout << "Pedidos en espera: " << size(&MixRestaurant.colaPedidos) << endl;
    cout << "Total de ordenes hechas: " << MixRestaurant.ComidaHecha << endl;
}

void servir()
{
    Pedido pedidoDespachado = dequeue(&MixRestaurant.colaPedidos);
    cout << "Familia " << pedidoDespachado.Apellido << " su pedido esta listo\n";
    cout << "Se encuentran en la mesa " << pedidoDespachado.Mesa << endl;
}
void vertodos()
{
    Cola colaTemporal;
    initialize(&colaTemporal);

    while (!empty(&MixRestaurant.colaPedidos))
    {
        Pedido unPedido = dequeue(&MixRestaurant.colaPedidos);
        enqueue(&colaTemporal, unPedido);

        cout << "Información del pedido: " << unPedido.Apellido << ", ";
        cout << "Alitas: " << unPedido.Alitas << ", ";
        cout << "Burritos: " << unPedido.Burritos << ", ";
        cout << "Ensalada: " << unPedido.Ensalada << ", ";
        cout << "Hamburguesa: " << unPedido.Hamburguesas << ", ";
        cout << "Hot Dogs: " << unPedido.HotDogs << ", ";
        cout << "Pizza: " << unPedido.Pizza << ", ";
        cout << "Tacos: " << unPedido.Tacos << "\n\n";
    }

    while (!empty(&colaTemporal))
    {
        T elemento = dequeue(&colaTemporal);
        enqueue(&MixRestaurant.colaPedidos, elemento);
    }
}