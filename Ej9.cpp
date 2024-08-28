#include <iostream>
#include <string>
#include "Lista/ListaDoble.h"
using namespace std;

void mostrarHistorial(ListaDoble<string>& lista, int tamanio)
{
    for (int i = 0; i < tamanio; i++)
    {
        cout << i+1 <<"."<<lista.getDato(i)<<endl;
    }
}

int main()
{
    ListaDoble<string> lista;
    int op=1, pos=0, tamanio = 0;
    string url;
    while(op=!0){
        cout << "Menu:" << endl;
        cout << "1. Anadir pagina" << endl;
        cout << "2. Mostrar historial" << endl;
        cout << "3. Retroceder" << endl;
        cout << "4. Avanzar" << endl;
        cout << "5. Salir" << endl;
        cin>>op;
        cin.ignore();
        switch(op){
            case 1:
                getline(cin,url);
                lista.insertarUltimo(url);
                tamanio++;
                pos++;
                break;
            case 2:
                mostrarHistorial(lista,tamanio);
                break;
            case 3:
                pos--;
                cout<<"Pagina actual: "<<lista.getDato(pos)<<endl;
                break;
            case 4:
                if (pos<tamanio)
                {
                    pos++;
                }
                cout<<"pagina actual: "<<lista.getDato(pos)<<endl;
                break;
        }
    }
}