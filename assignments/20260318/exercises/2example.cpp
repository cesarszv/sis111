/*
SECUENCIA:
    - 60, 1, 58, 3, 56, 5, 54, 7, 52, 9, 50, 11, ...

*/

#include <iostream>

// definir funciones
int pedirLongitud()
{
    int longitud;
    std::cout << "introduce la longitud de la serie: ";
    std::cin >> longitud;

    while (longitud <= 0)
    {
        std::cout << "la longitud debe ser mayor a 0\n";
        std::cout << "introduce la longitud de la serie: ";
        std::cin >> longitud;
    }

    return longitud;
}

int pedirNumeroPar()
{
    int numeroPar;

    std::cout << "introduce un numero entero que sea par: ";
    std::cin >> numeroPar;

    while (numeroPar % 2 != 0)
    {
        std::cout << "el numero introducido no es par\n";
        std::cout << "introduce un numero entero que sea par: ";
        std::cin >> numeroPar;
    }

    return numeroPar;
}

int pedirNumeroImpar()
{
    int numeroImpar;

    std::cout << "introduce un numero entero que sea impar: ";
    std::cin >> numeroImpar;

    while (numeroImpar % 2 == 0)
    {
        std::cout << "el numero introducido no es impar\n";
        std::cout << "introduce un numero entero que sea impar: ";
        std::cin >> numeroImpar;
    }

    return numeroImpar;
}

void mostrarSeparador(int posicion)
{
    if (posicion > 1)
    {
        std::cout << ", ";
    }
}

int calcularTermino(int posicion, int numeroPar, int numeroImpar)
{
    if (posicion % 2 != 0)
    {
        return numeroPar;
    }

    return numeroImpar;
}

void mostrarSerie(int longitud, int numeroPar, int numeroImpar)
{
    for (int posicion = 1; posicion <= longitud; posicion++)
    {
        mostrarSeparador(posicion);
        std::cout << calcularTermino(posicion, numeroPar, numeroImpar);

        if (posicion % 2 != 0)
        {
            numeroPar -= 2;
        }
        else
        {
            numeroImpar += 2;
        }
    }
}

int main()
{
    int longitud = pedirLongitud();
    int numeroPar = pedirNumeroPar();
    int numeroImpar = pedirNumeroImpar();

    mostrarSerie(longitud, numeroPar, numeroImpar);
    std::cout << "\n";

    return 0;
}
