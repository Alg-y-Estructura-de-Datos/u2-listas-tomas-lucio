#include <iostream>
#include <limits>
#include "Lista/Lista.h"
using namespace std;

Lista<int> encontrarRepetidos(Lista<int>& lista1) {
    Lista<int> repetidos;
    Lista<int> vistos;

    for (int i = 0; i < lista1.getTamanio(); i++) {
        int valor = lista1.getDato(i);
        bool yavisto = false;
        bool esrepe = false;

        for (int j = 0; j < vistos.getTamanio(); j++) {
            if (vistos.getDato(j) == valor) {
                yavisto = true;
                break;
            }
        }

        if (yavisto) {
            for (int j = 0; j < repetidos.getTamanio(); j++) {
                if (repetidos.getDato(j) == valor) {
                    esrepe = true;
                    break;
                }
            }

            if (!esrepe) {
                repetidos.insertarUltimo(valor);
            }
        } else {
            vistos.insertarUltimo(valor);
        }
    }

    return repetidos;
}

int main() {
    Lista<int> lista1;

    int num;
    cout << "Ingrese numeros enteros para la lista (ingrese 'q' para terminar):" << endl;
    while (true) {
        if (cin >> num) {
            lista1.insertarUltimo(num);
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }

    Lista<int> lista2 = encontrarRepetidos(lista1);

    cout << "Lista L1: ";
    lista1.print();

    if (lista2.esVacia()) {
        cout << "No hay elementos repetidos en lista1." << endl;
    } else {
        cout << "Lista lista2 (elementos repetidos): ";
        lista2.print();
    }

    return 0;
}
