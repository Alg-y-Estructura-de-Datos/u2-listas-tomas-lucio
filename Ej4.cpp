/*
 Escribir un programa que pida al usuario una palabra o frase y la almacene en
 una Lista separando letra por letra, luego pedirá al usuario una vocal que
 desee contar y, por último, se debe imprimir por pantalla la lista y el número
 de veces que aparece la vocal en la palabra o frase.
 Validar que la Lista no esté vacía y que la letra a contar que introduzca
 el usuario sea una vocal.

 */

#include <iostream>
#include <cctype>
#include "Lista/Lista.h"
using namespace std;

bool esVocal(char vocal){
    vocal = tolower(vocal);
    return vocal == 'a' || vocal == 'e' || vocal == 'i' || vocal == 'o' || vocal == 'u';
}

int contarVocal(Lista<char>& lista,char vocal){
    int contador = 0;
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        if (tolower(lista.getDato(i)) == tolower(vocal))
        {
            contador++;
        }
    }
    return contador;
}

int main(){
    Lista<char> lista;
    string frase;
    char vocal;

    cout << "Ingrese una palabra o frase: ";
    getline(cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        lista.insertarUltimo(frase[i]);
    }
    
    cout << "Ingrese una vocal para contar en la frase: ";
    cin >> vocal;

    if (!esVocal(vocal)) {
        cout << "El carácter ingresado no es una vocal." << endl;
        return 0;
    }

    cout << "Lista: ";
    lista.print();

    int cantidad = contarVocal(lista, vocal);

    cout << "La vocal '" << vocal << "' aparece " << cantidad << " veces en la lista." << endl;
}