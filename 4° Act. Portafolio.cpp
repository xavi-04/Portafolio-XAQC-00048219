/*#include <iostream>
using namespace std;

int addNumbers(int limit, int aux);

int main(void){
    int n; 
    cout << "Escriba el numero: " << endl;
    cin >> n;
   
}

int addNumbers(int limit, int aux){
    if(aux == limit){
        return aux;
    }
    else{
        return aux + addNumbers(limit, aux + 1);
    }
}*/


#include <iostream>
using namespace std;

int addNumbers(int limit, int aux);

int main(void){
    cout << addNumbers(10, 1) << endl;
}

int addNumbers(int limit, int aux){
    if(aux == limit){
        return aux;
    }
    else{
        return aux + addNumbers(limit, aux + 1);
    }
}