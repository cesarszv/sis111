/*
SERIE NUMERICA = 4, 5, 9, 14, 23, 37, ...

Fibonacci
*/

#include <iostream>

int main() {
    // definir la longitud de la serie
    int longitud;
    std::cout << "introduce la longitud de tu serie: ";
    std::cin >> longitud;

    if(longitud <= 2) {
        std::cout << "la longitud debe ser mas de 2 digitos";
        return 1;
    }

    // definir variables con las que trabajaremos
    int primer_termino;
    std::cout << "introduce tu primer termino (el ejercicio usa el 4): ";
    std::cin >> primer_termino;


    int segundo_termino;
    std::cout << "introduce tu primer termino (el ejercicio usa el 5): ";
    std::cin >> segundo_termino;

    int siguiente;

    // primeros terminos
    std::cout << primer_termino << ", ";
    std::cout << segundo_termino;

    //
    for(int i = 2; i < longitud; i++){
        siguiente = primer_termino + segundo_termino;
        std::cout << "," << siguiente;

        primer_termino = segundo_termino;
        segundo_termino = siguiente;
    }

    return 0;
}
