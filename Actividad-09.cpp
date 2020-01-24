//Agenda 
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct schedule{
    string Title;
    string Hour;
    int Minutes;
};

typedef struct schedule Schedule;

struct activities{
    queue<schedule> colaActividades;
    string ActividadesRealizadas;
    int MinutosOcupados;
};

typedef struct activities Activities;

Activities Agenda2020;

void agregar();
void consular();
void borrar();
void reiniciar ();

int main(){    
    Agenda2020.ActividadesRealizadas = 0;
    Agenda2020.MinutosOcupados = 0;

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\n1) Agregar actividad\n ";
        cout << "2) Consultar actividades actuales\n ";
        cout << "3) Borrar actividades\n ";
        cout << "4) Borrar todo\n ";
        cout << "5) Salir ";
        cin >> opcion; cin.ignore();

        switch (opcion)
        {
        case 1:
            break;
        
        }
    }
    return 0;
}

    cout << "Ingrese el título de la actividad: ";
    cin >> Activities.Title;
    cout << "Inicio de la Actividad: ";
    cin >> Activities.Hour;
    cout << "Duración de la Actividad: ";
    cin >> Activities.Minutes;
    return 0;