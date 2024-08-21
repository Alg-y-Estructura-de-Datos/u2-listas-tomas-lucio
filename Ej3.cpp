/*
 Implementar una función que intercambie los elementos entre 2 listas de números
 enteros que recibe como parámetros. Si los tamaños de las listas son distintos,
 igual debe cambiar los datos y cambiarían los tamaños de cada lista.
 Ejemplo sea lista1= 15->1->8->35->40->25->12 y lista2= 3->4->912->45->66
 al ejecutar la función quedarían lista1= 3->4->912->45->66 y
 lista2=15->1->8->35->40->25->12.
 */
#include <iostream>
#include "Lista/Lista.h"
using namespace std;


void intercambiarListas(Lista<int>& lista1,Lista<int>& lista2)
{
    Lista<int> temporal;
    for (int i = 0; i < lista2.getTamanio(); i++)
    {
        temporal.insertarUltimo(lista2.getDato(i));
    }
    for (int i = 0; i < lista1.getTamanio(); i++)
    {
        if (lista2.getTamanio()<=lista1.getTamanio())
        {
            lista2.reemplazar(i,lista1.getDato(i));
        }
        else{
            lista2.insertarUltimo(lista1.getDato(i));
        }
    }
    for (int i = 0; i < temporal.getTamanio(); i++)
    {
        if (lista1.getTamanio()<=temporal.getTamanio())
        {
            lista1.reemplazar(i,temporal.getDato(i));
        }
        {
            lista1.insertarUltimo(temporal.getDato(i));
        }
    }
}

int main() {

    Lista<int> lista1;
    Lista<int> lista2;

    lista1.insertarUltimo(15);
    lista1.insertarUltimo(1);
    lista1.insertarUltimo(8);
    lista1.insertarUltimo(35);
    lista1.insertarUltimo(40);
    lista1.insertarUltimo(25);
    lista1.insertarUltimo(12);

    // Insertar elementos en la segunda lista
    lista2.insertarUltimo(3);
    lista2.insertarUltimo(4);
    lista2.insertarUltimo(912);
    lista2.insertarUltimo(45);
    lista2.insertarUltimo(66);

    cout << "Lista 1 antes de intercambiar: ";
        lista1.print();

        cout << "Lista 2 antes de intercambiar: ";
        lista2.print();

        // Intercambiar los elementos de las listas
        intercambiarListas(lista1, lista2);

        cout << "Lista 1 después de intercambiar: ";
        lista1.print();

        cout << "Lista 2 después de intercambiar: ";
        lista2.print();
    return 0;
}
