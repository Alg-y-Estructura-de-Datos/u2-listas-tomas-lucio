/*
 Implementar una función que recibe una lista de números enteros y un número
 entero “n” y que modifique la lista borrando todos los elementos de la lista
 que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado
 a la función para mostrar que la lista original cambió.
 ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe pasar con
 la función a 1->2->4->5->7->8.

 */
#include <iostream>
#include "Lista/Lista.h"
using namespace std;

int main() {
    Lista<int> lista;
    int n,d,t,i=0;
    cout<<"Ingrese el tamaño de la Lista: ";
    cin>>t;

    for (int i = 0; i < t; i++) {
        cout<<"Ingrese el valor de la lista en la posicion: "<<i<<endl;
        cin>>d;
        lista.insertarUltimo(d);
    }
    
    cout<<"Ingrese el numero a eliminar de la Lista: "<<endl;
    cin>>n;

    while (i<lista.getTamanio())
    {
        if (lista.getDato(i)==n)
        {
            lista.remover(i);
        }
        else{
            i++;
        }
    }
    

    lista.print();
    
    
    return 0;
}
