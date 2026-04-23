/*
SECUENCIA: 
    - 60, 1, 58, 3, 56, 5, 54, 7, 52, 9, 50, 11, ... 

*/

#include <iostream>

int main(){
    // definir longitud de la serie
    int longitud;
    std::cout << "introduce la longitud de la serie: ";
    std::cin >> longitud;

    while(longitud <= 2){
    std::cout << "la longitud debe ser mas de 2 terminos \n";
    std::cout << "introduce la longitud de la serie: ";
    std::cin >> longitud;
    }

    // definimos las variables
    int numero_par;
    std::cout << "introduce un numero entero que sea par: ";
    std::cin >> numero_par;
    
    while(numero_par % 2 != 0){
        std::cout << "el numero entero introducido no es par\n";
        std::cout << "introduce un numero entero que sea par: ";
        std::cin >> numero_par;
    }

    int numero_impar;
    std::cout << "introduce un numero entero que sea impar: ";
    std::cin >> numero_impar;

    while(numero_impar % 2 == 0){
        std::cout << "el numero que introduciste es par\n";
        std::cout << "introduce un numero entero que sea impar: ";
        std::cin >> numero_impar;
    }


    return 0;
}
