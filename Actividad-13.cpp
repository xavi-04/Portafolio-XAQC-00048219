#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <random>
#include <time.h>
#include <stack>
using namespace std;

// Referente a Carta
enum Palos{Corazones, Diamantes, Treboles, Picas};
struct Carta{
    Palos palo;
    int numero;
};
void mostrarCarta(Carta unaCarta);

// Referente a bajara
list<Carta> baraja;
void agregarCarta(int n, Palos p);
void quitarCarta(int n, Palos p);
void barajear();

int main(){
    // Poblar baraja
    for(int i = 2; i <= 14; i++) agregarCarta(i, Corazones);
    for(int i = 2; i <= 14; i++) agregarCarta(i, Diamantes);
    for(int i = 2; i <= 14; i++) agregarCarta(i, Treboles);
    for(int i = 2; i <= 14; i++) agregarCarta(i, Picas);
    
    // Mostrar baraja
    for(Carta c : baraja) mostrarCarta(c);
    
    // Barajear
    srand( time(NULL) );//Configurar semilla solo se hace una vez
    barajear();
    
    // Mostrar baraja
    for(Carta c : baraja) mostrarCarta(c);
    
    // Cada jugador tomara 5 cartas de manera alternada
    stack<Carta> mazoJugador1, mazoJugador2;
    for (int i = 0; i < 10; i++) {
        Carta unaCarta = baraja.front();//Obtener carta de encima
        baraja.erase(baraja.begin());//Quitar carta de encima
        
        if(i%2 == 0)
            mazoJugador1.push(unaCarta);//Poner carta en pila
        else
            mazoJugador2.push(unaCarta);//Poner carta en pila
    }
    
    // Declarar contadores
    int contador1 = 0, contador2 = 0;
    
    // Comienza el juego
    cout << "\nComienza el juego:\n\n";
    for (int i = 0; i < 5; i++) {
        // Jugador 1 toma una carta
        Carta cartaJug1 = mazoJugador1.top();
        mazoJugador1.pop();
        // Jugador 2 toma una carta
        Carta cartaJug2 = mazoJugador2.top();
        mazoJugador2.pop();
        
        // Mostrar cartas
        cout << "Jugador 1: "; mostrarCarta(cartaJug1);
        cout << "Jugador 2: "; mostrarCarta(cartaJug2);
        if(cartaJug1.numero > cartaJug2.numero){
            cout << "\nEsta ronda la gana el Jugador 1!\n\n"; contador1++;

        }else if(cartaJug1.numero ==  cartaJug2.numero){
            cout << "Queda empate esta ronda!!!\n\n";
        }
        else{
            cout << "Esta ronda la gana el Jugador 2!\n\n"; contador2++;
        }
        

        
    }
    
    // Declarar ganador
    if(contador1 > contador2)
        cout << "Gana el Jugador #1!!!" << endl;
    else
        cout << "Gana el Jugador #2!!!" << endl;

    return 0;
}

void mostrarCarta(Carta unaCarta){
    if (unaCarta.numero > 1 && unaCarta.numero <= 10)
        cout << unaCarta.numero;
    else
        switch (unaCarta.numero){
            case 11: cout << "Jota"; break;
            case 12: cout << "Reína"; break;
            case 13: cout << "Rey"; break;
            case 14: cout << "As"; break;
        }
    cout << " de ";
    switch (unaCarta.palo){
        case Corazones: cout << "corazones"; break;
        case Diamantes: cout << "diamantes"; break;
        case Treboles: cout << "tréboles"; break;
        case Picas: cout << "picas"; break;
    }
    cout << " color ";
    switch (unaCarta.palo){
        case Corazones: cout << "rojo"; break;
        case Diamantes: cout << "rojo"; break;
        case Treboles: cout << "negro"; break;
        case Picas: cout << "negro"; break;
    }
    cout << endl;
}

void agregarCarta(int n, Palos p){
    Carta unaCarta;
    unaCarta.numero = n;
    unaCarta.palo = p;
    
    baraja.insert(baraja.end(), unaCarta);
}

void quitarCarta(int n, Palos p){
    for(auto iter = baraja.begin(); iter != baraja.end(); ++iter){
        if(iter->numero == n && iter->palo == p){
            iter = baraja.erase(iter);
            break;
        }
    }
}

void barajear(){
    cout << "\nBarajeando................\n\n";
    for(int i=0; i<100; i++) {
        int nAle = rand() % 13 + 1;
        int p = rand() % 4 + 1;
        Palos pAle = (p==1) ? Corazones : (p==2) ? Diamantes : (p==3) ? Treboles : Picas;
        
        quitarCarta(nAle, pAle);
        agregarCarta(nAle, pAle);
    }
}

