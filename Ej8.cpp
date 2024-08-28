#include <iostream>
#include <string>
#include "Lista/CircList.h"

using namespace std;

void MostrarFrases(CircList<string>& lista,int tamanio);

int main()
{
    CircList<string> lista;
    int op=1, pos, tamanio = 0;
    string frase;
    string aEliminar;
    while(op=!0){
        cout << "Ingrese que accion desea realizar"<<endl;
        cin>>op;
        cin.ignore();
        switch(op)
        {
            case 1:
                getline(cin,frase);
                lista.insertarUltimo(frase);
                tamanio++;
            break;

            case 2:
                cin>>pos;
                aEliminar = lista.getDato(pos);
                lista.eliminarPorValor(aEliminar);
                tamanio--;
                break;
            case 3:
                MostrarFrases(lista,tamanio);
            break;
        }

    }
    /*
    lista.insertarUltimo("Gran venta de fin de temporada!");
    lista.insertarUltimo("50% de descuento en toda la tienda.");
    lista.insertarUltimo("Compra uno y llevate el segundo a mitad de precio.");
    lista.insertarUltimo("Visitanos hoy y obten un regalo sorpresa.");

    MostrarFrases(lista , 4);
    */
}

void MostrarFrases(CircList<string>& lista,int tamanio)
{
    while (true)
    {
    
        for (int i = 0; i < tamanio; i++)
        {
            string texto = lista.getDato(i);
            cout << texto <<endl;
        }   
    }
}