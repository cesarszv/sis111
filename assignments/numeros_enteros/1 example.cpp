#include <iostream>
using namespace std;

/*
    Ejercicio 1:
    Contar bloques diferentes de a nd digitos.

    Ejemplo:
    N = 22112211, nd = 2

    Como nd = 2, no trabajamos con digitos sueltos, sino con bloques:
    22 11 22 11

    Los bloques diferentes son: 22 y 11.
    Resultado = 2
*/

int potencia10(int exponente) {
    int resultado = 1;

    for (int posicion = 1; posicion <= exponente; posicion++) {
        resultado = resultado * 10;
    }

    return resultado;
}

bool existeBloque(int bloquesRevisados, int cantidadBloquesRevisados, int bloqueBuscado, int nd) {
    int divisor = potencia10(nd);
    bool encontrado = false;

    while (cantidadBloquesRevisados > 0 && encontrado == false) {
        int bloqueActual = bloquesRevisados % divisor;
        bloquesRevisados = bloquesRevisados / divisor;

        if (bloqueActual == bloqueBuscado) {
            encontrado = true;
        }

        cantidadBloquesRevisados--;
    }

    return encontrado;
}

int contarBloquesDiferentes(int numero, int nd) {
    int divisor = potencia10(nd);
    int bloquesRevisados = 0;
    int cantidadBloquesRevisados = 0;
    int cantidadDiferentes = 0;
    int posicion = 0;

    while (numero > 0) {
        int bloque = numero % divisor;
        numero = numero / divisor;

        if (existeBloque(bloquesRevisados, cantidadBloquesRevisados, bloque, nd) == false) {
            cantidadDiferentes++;
        }

        bloquesRevisados = bloquesRevisados + bloque * potencia10(posicion);
        cantidadBloquesRevisados++;
        posicion = posicion + nd;
    }

    return cantidadDiferentes;
}

int main() {
    int numero;
    int nd;

    cout << "Ingresar N: ";
    cin >> numero;

    cout << "Ingresar nd: ";
    cin >> nd;

    cout << "Resultado: " << contarBloquesDiferentes(numero, nd) << endl;

    return 0;
}
