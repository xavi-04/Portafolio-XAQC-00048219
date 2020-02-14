//Ejercicio A
#include <iostream>
using namespace std;

int suma(int num);



int main(){
    int num = 0;
    cout << "Suma de n digitos " <<endl;
    cout << "Ingrese la cantdad de digitos a sumar: ";
    cin >>  num;
    int contador = suma(num);
    cout << "El resultado es: " << contador <<endl;

}

int suma(int num){
    int respuesta = 0;
   
    if(num == 1){
        cout << " Caso base: " << num  <<endl;
        respuesta = 1;
       
    }
    else{
        int a = num - 1;
        respuesta = num + suma(a);
    }
    return respuesta;
}

//Ejercicio B

/*#include <iostream>

using namespace std;

void imprimirArreglo(int *arreglo, int item) {

      if(item<=0) return;

      imprimirArreglo(arreglo, item-1);

      cout << ' ' << arreglo[item-1];

}

int main() {

      int arreglo[]={9, 24, 65 ,2, 19, 6, 17};

      imprimirArreglo(arreglo, 7);


      return 0;

}*/

//Ejercicio C

/*#include <iostream>
using namespace std;
void encontrar(int *i, int *f, int n){
	if(i < f){
		if(*i == n){
			cout<<*i<<" es igual al numero buscado\n";
			cout<<"\nSe encontro el numero\n";
		}else{
			cout<< *i <<" no es igual a " << n << endl;
			encontrar(i + 1, f, n);
		}
	}else{
		cout<<"\nNo se encontro el numero\n";
	}
}
int main() {
	int arr[10], numero;
	cout<<"Arreglo\n";
	for(int i = 0; i < 10; i++){
		cout<<"Ingrese el "<<i+1<<" valor: ";
		cin>>arr[i];
	} 
	cout<<"\nIngrese el numero a buscar: ";
	cin>>numero;
	encontrar(arr, arr + 10, numero);
	return 0;
}*/