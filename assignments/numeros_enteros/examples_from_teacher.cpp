#include <iostream>
using namespace std;

/*
    Ejemplos guia para el practico de numeros enteros.

    Idea principal:
    - Para leer un numero por digitos se usa:
        digito = numero % 10;
        numero = numero / 10;

    - Para formar un numero de izquierda a derecha se usa:
        nuevoNumero = nuevoNumero * 10 + digito;

    - Para mantener el orden original cuando se lee de derecha a izquierda:
        nuevoNumero = nuevoNumero + digito * 10^posicion;
*/

int potencia10(int exponente) {
    int resultado = 1;

    for (int posicion = 1; posicion <= exponente; posicion++) {
        resultado = resultado * 10;
    }

    return resultado;
}

bool esPrimo(int numero) {
    int cantidadDivisores = 0;

    for (int divisor = 1; divisor <= numero; divisor++) {
        if (numero % divisor == 0) {
            cantidadDivisores++;
        }
    }

    return cantidadDivisores == 2;
}

// Serie: 1, 2, 4, 3, 6, 5, 8, 7, 9, 11, 10, 13, ...
void mostrarSerieNoPrimoPrimo(int cantidadTerminos) {
    int numeroPrimo = 1;
    int numeroNoPrimo = 1;
    int terminosMostrados = 0;

    while (terminosMostrados < cantidadTerminos) {
        if (terminosMostrados % 2 == 0) {
            while (esPrimo(numeroNoPrimo)) {
                numeroNoPrimo++;
            }

            cout << numeroNoPrimo << " , ";
            numeroNoPrimo++;
        } else {
            while (!esPrimo(numeroPrimo)) {
                numeroPrimo++;
            }

            cout << numeroPrimo << " , ";
            numeroPrimo++;
        }

        terminosMostrados++;
    }
}

int contarDigitos(int numero) {
    int copiaNumero = numero;
    int cantidadDigitos = 0;

    while (copiaNumero > 0) {
        copiaNumero = copiaNumero / 10;
        cantidadDigitos++;
    }

    return cantidadDigitos;
}

int contarDigitosPares(int numero) {
    int copiaNumero = numero;
    int cantidadPares = 0;

    while (copiaNumero > 0) {
        int digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (digito % 2 == 0) {
            cantidadPares++;
        }
    }

    return cantidadPares;
}

int contarDigitosImpares(int numero) {
    int copiaNumero = numero;
    int cantidadImpares = 0;

    while (copiaNumero > 0) {
        int digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (digito % 2 == 1) {
            cantidadImpares++;
        }
    }

    return cantidadImpares;
}

int frecuenciaDigito(int numero, int digitoBuscado) {
    int copiaNumero = numero;
    int frecuencia = 0;

    while (copiaNumero > 0) {
        int digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (digito == digitoBuscado) {
            frecuencia++;
        }
    }

    return frecuencia;
}

int digitoMasFrecuente(int numero) {
    int copiaNumero = numero;
    int digitoActual = 0;
    int digitoMayorFrecuencia = copiaNumero % 10;
    int mayorFrecuencia = frecuenciaDigito(copiaNumero, digitoMayorFrecuencia);

    while (copiaNumero > 0) {
        digitoActual = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (frecuenciaDigito(numero, digitoActual) > mayorFrecuencia) {
            mayorFrecuencia = frecuenciaDigito(numero, digitoActual);
            digitoMayorFrecuencia = digitoActual;
        }
    }

    return digitoMayorFrecuencia;
}

bool existeDigitoPar(int numero) {
    int copiaNumero = numero;
    bool encontrado = false;

    while (copiaNumero > 0 && encontrado == false) {
        int digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (digito % 2 == 0) {
            encontrado = true;
        }
    }

    return encontrado;
}

bool todosSonDigitosPares(int numero) {
    int copiaNumero = numero;
    bool todosSonPares = true;

    while (copiaNumero > 0 && todosSonPares == true) {
        int digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (digito % 2 == 1) {
            todosSonPares = false;
        }
    }

    return todosSonPares;
}

bool todosSonDigitosIguales(int numero) {
    int copiaNumero = numero;
    int digitoReferencia = copiaNumero % 10;
    bool todosSonIguales = true;

    while (copiaNumero > 0 && todosSonIguales == true) {
        int digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (digitoReferencia != digito) {
            todosSonIguales = false;
        }
    }

    return todosSonIguales;
}

// n = 45645442, digitoAEliminar = 4 => n = 5652
void eliminarDigitos(int& numero, int digitoAEliminar) {
    int nuevoNumero = 0;
    int posicion = 0;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito != digitoAEliminar) {
            nuevoNumero = nuevoNumero + digito * potencia10(posicion);
            posicion++;
        }
    }

    numero = nuevoNumero;
}

// n = 546452, digitoAEliminar = 4 => n = 54652
void eliminarPrimerDigito(int& numero, int digitoAEliminar) {
    int nuevoNumero = 0;
    int posicion = 0;
    bool encontrado = false;

    while (numero > 0 && encontrado == false) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito == digitoAEliminar) {
            encontrado = true;
        } else {
            nuevoNumero = nuevoNumero + digito * potencia10(posicion);
            posicion++;
        }
    }

    numero = numero * potencia10(posicion) + nuevoNumero;
}

// n = 1234 => n = 4321
void invertirNumero(int& numero) {
    int nuevoNumero = 0;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;

        nuevoNumero = nuevoNumero * 10 + digito;
    }

    numero = nuevoNumero;
}

// n = 44564544, numeroAEliminar = 44 => n = 5645
void eliminarNumeroPorBloques(int& numero, int numeroAEliminar) {
    int nuevoNumero = 0;
    int posicion = 0;
    int cantidadDigitosBloque = contarDigitos(numeroAEliminar);
    int divisor = potencia10(cantidadDigitosBloque);

    while (numero > 0) {
        int bloque = numero % divisor;
        numero = numero / divisor;

        if (bloque != numeroAEliminar) {
            nuevoNumero = nuevoNumero + bloque * potencia10(posicion);
            posicion = posicion + cantidadDigitosBloque;
        }
    }

    numero = nuevoNumero;
}

// n = 4454644544, numeroAEliminar = 44 => n = 5465
void eliminarNumero(int& numero, int numeroAEliminar) {
    int nuevoNumero = 0;
    int posicion = 0;
    int cantidadDigitosBloque = contarDigitos(numeroAEliminar);
    int divisor = potencia10(cantidadDigitosBloque);

    while (numero > 0) {
        int bloque = numero % divisor;

        if (bloque == numeroAEliminar) {
            numero = numero / divisor;
        } else {
            numero = numero / 10;
            nuevoNumero = nuevoNumero + (bloque % 10) * potencia10(posicion);
            posicion++;
        }
    }

    numero = nuevoNumero;
}

// n = 564370211 => n = 11234567
void ordenarAscendente(int& numero) {
    int numeroOrdenado = 0;
    int copiaOriginal = numero;

    for (int digitoBuscado = 1; digitoBuscado <= 9; digitoBuscado++) {
        numero = copiaOriginal;

        while (numero > 0) {
            int digito = numero % 10;
            numero = numero / 10;

            if (digitoBuscado == digito) {
                numeroOrdenado = numeroOrdenado * 10 + digito;
            }
        }
    }

    numero = numeroOrdenado;
}

// n = 112345 => n = 543211
void ordenarDescendente(int& numero) {
    int numeroOrdenado = 0;
    int copiaOriginal = numero;

    for (int digitoBuscado = 9; digitoBuscado >= 0; digitoBuscado--) {
        numero = copiaOriginal;

        while (numero > 0) {
            int digito = numero % 10;
            numero = numero / 10;

            if (digitoBuscado == digito) {
                numeroOrdenado = numeroOrdenado * 10 + digito;
            }
        }
    }

    numero = numeroOrdenado;
}

int digitoMenor(int numero) {
    int copiaNumero = numero;
    int menorDigito = copiaNumero % 10;

    while (copiaNumero > 0) {
        int digito = copiaNumero % 10;
        copiaNumero = copiaNumero / 10;

        if (digito < menorDigito) {
            menorDigito = digito;
        }
    }

    return menorDigito;
}

void ordenarAscendenteV2(int& numero) {
    int numeroOrdenado = 0;

    while (numero > 0) {
        int menorDigito = digitoMenor(numero);
        eliminarPrimerDigito(numero, menorDigito);
        numeroOrdenado = numeroOrdenado * 10 + menorDigito;
    }

    numero = numeroOrdenado;
}

/*
    Segmenta el numero en pares ASC e impares ASC.
    n = 12345678 => n = 24681357
    n = 81723645 => n = 24681357
*/
void segmentarParesImpares(int& numero) {
    int numeroSegmentado = 0;

    ordenarDescendente(numero);
    int copiaOrdenada = numero;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito % 2 == 0) {
            numeroSegmentado = numeroSegmentado * 10 + digito;
        }
    }

    numero = copiaOrdenada;

    while (numero > 0) {
        int digito = numero % 10;
        numero = numero / 10;

        if (digito % 2 == 1) {
            numeroSegmentado = numeroSegmentado * 10 + digito;
        }
    }

    numero = numeroSegmentado;
}

int main() {
    int numero;

    cout << "Ingresar n: ";
    cin >> numero;

    segmentarParesImpares(numero);

    cout << "Resultado: " << numero << endl;

    return 0;
}
