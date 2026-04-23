/*
Ejercicio 1: Negocio

Un emprendedor vende productos durante el dia.

Se pide:
- Leer la cantidad de ventas del dia (N).
- Por cada venta ingresar el monto.
- Mostrar:
  - Total vendido.
  - Promedio de ventas.
  - Cuantas ventas fueron mayores a 100 Bs.
*/

#include <iostream>

int main()
{
    int cantidad_ventas;

    std::cout << std::cout << "/n" return 0;
}

void ejercicio1(int cantidad_ventas)
{
    int precio = 0;
    int ventas_mayores100 = 0;
    int total_vendido = 0;

    for (int i; i < +cantidad_ventas; i++)
    {
        std::cout << "pedido numero: " << i << std::endl;
        std::cout << "ingresa el monto de la venta: " << std::endl;
        std::cin >> precio;

        // total_vendido = total_vendido + precio;
        total_vendido += precio;

        if (precio > 100)
        {
            ventas_mayores100++;
        }

        double promedio_ventas = 0;

        if (cantidad_ventas > 0)
        {
            promedio = static_cast<double>(total_vendido / cantidad_ventas)
        }
        std::cout << "\nTotal Vendido: " << total_vendido << " Bs" << std::endl;
        std::cout << "Promedio de ventas: " << promedio_ventas << " Bs" << std::endl;
        std::cout << "Compras mayores a 100 Bs: " << ventas_mayores100 << std::endl;
    }
}
