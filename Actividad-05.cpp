#include <iostream>
using namespace std;

//Prototipos
int buscarArr(int arr[], int search, int high, int low);

//Inicio del programa
int main(){
    int size = 8, arr[size] = {1, 3, 4, 5, 17, 18, 31, 33}, numero, rspt;
    
    cout << "Introduzca un número por el cual buscar\n";
    cin >> numero;
    
    rspt = buscarArr(arr, numero, size - 1, 0);

    if(rspt == -1){
        cout << "El número no se encontro en el arreglo\n";
    }
    else{
        cout << "El número se encuentra en la posición " << rspt + 1 << "\n";
    }
    return 0;
}

int buscarArr(int arr[], int search, int high, int low){
    int mid = (low + high) / 2, elemento;

    if (low > high){
        return -1;
    }
    else if(arr[mid] == search){
        return mid;
    }
    else if(search < arr[mid]){
        elemento = buscarArr(arr, search, mid - 1, low);
        return elemento;
    }
    else if(search > arr[mid]){
        elemento = buscarArr(arr, search, high, mid + 1);
        return elemento;
    }
}