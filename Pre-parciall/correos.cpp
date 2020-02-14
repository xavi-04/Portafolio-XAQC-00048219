#include <iostream>
#include <string>
using namespace std;

struct Correo
{
    string Remitente;
    string Destinatario;
    char Type;
    float Weigth;
    char Modalidad;
};
void printInfo(Correo printPedido);

int main(void)
{
   
    cout << "Pedidos ilimitados por cliente" << endl;
    int size = 0;
    char TipoPedido;
    char ModalidadPedido;

    Correo Pedido1[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Número del pedido: " << i + 1 << endl;

        cout << "Remitente: ";
        getline(cin, Pedido1[i].Remitente);

        cout << "Destinatario: ";
        getline(cin, Pedido1[i].Destinatario);

        cout << "Tipo del pedido (C-carta / P-paquete): ";
        cin >> Pedido1[i].Type;
        cin.ignore();

        cout << "Peso del pedido (g): ";
        cin >> Pedido1[i].Weigth;
        cin.ignore();

        cout << "Escriba la modalidad del pedido (U-urgente / N-nacional / I-internacional): ";
        cin >> Pedido1[i].Modalidad;
        cout << endl;
    }
    printInfo(Pedido1[5]);

    return 0;
}

void printInfo(Correo printPedido)
{
    cout << " Nombre del remitente: " << printPedido.Remitente << endl;
    cout << " Nombre del destinatario: " << printPedido.Destinatario << endl;
    cout << " Tipo del paquete: " << printPedido.Type << endl;
    cout << " Peso del paquete: " << printPedido.Weigth << endl;
    cout << " Modalidad del paquete: " << printPedido.Modalidad << endl;
    cout << endl;
}
