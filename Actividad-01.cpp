#include<iostream>
using namespace std;

float mediana(int a[], int tamano){
	int mediana;
	int b = 0;
	int c = 0;
	b = tamano/2;
	c = b+1;
	mediana = (a[b-1] + a[c-1]) / 2; 
	return mediana;
	
}

int main(){
	int numero;
	int tamano = 0;
	int a[tamano] ;
	cout << "Ingrese el tamaño: "; cin >> tamano;

	for(int i = 0; i < tamano; i++){
		cout << "Numero " << i + 1 << ": ";
		cin >> numero;
	}

	int med = mediana(a, tamano);
	cout << "La mediana es: " << med;
	return 0;
}