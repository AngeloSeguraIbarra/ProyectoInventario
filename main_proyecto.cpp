/*
 * Proyecto Inventario
 * Angelo Segura Ibarra
 * A01711723
 *
 *Este es un proyecto de inventario para la clase TC1030 Programación Orientado 
 *a Objetos.Es un programa que nos permite crear diferente tipos de herramientas
 * y agregarlas a un inventario que tiene diferentes funciones como calcular 
 * precios,buscar herramientas,agregar herramientas y eliminarlas.
 */

#include <iostream>
#include "herramientas.h"
#include "inventario2.h"

int main() 
{
    Inventario miInventario;

    // Crear ejemplos de herramientas usando punteros
    Herramienta* dado1 = new Dado(59989, "MarcaA", 10, 15.99,
     "Grande", "Estandar");
    Herramienta* herramienta1 = new Electrica("Taladro",595959, "MarcaB", 7,
     99.99, 1200);

    // Agregar herramientas al inventario
    miInventario.agregar_herramienta(dado1);
    miInventario.agregar_herramienta(herramienta1);

    // Ciclo principal para tener un interacción con el usuario
    while (true) {
        int opcion;
        std::cout<<"\nIngresar los datos como se indica en sus descripciones\n";
        std::cout << "\nMenu:\n";
        std::cout << "1. Ver inventario\n";
        std::cout << "2. Buscar herramienta\n";
        std::cout << "3. Eliminar herramienta\n";
        std::cout << "4. Agregar herramientas\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opcion(digitar el numero): ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "\nInventario actual:\n";
                miInventario.imprimir_inventario();
                break;
            case 2: {
                int id;
                std::cout << "Ingrese el ID de la herramienta: ";
                std::cin >> id;
                miInventario.buscar_herramienta(id);
                break;
            }
            case 3: {
                int id;
                std::cout << "Ingrese el ID de la herramienta a eliminar: ";
                std::cin >> id;
                miInventario.eliminar_herramienta(id);
                break;
            }
            case 4: {
                int num_herramientas;
                std::cout 
                << "Cuantas herramientas de diferente tipo desea agregar?: ";
                std::cin >> num_herramientas;

                for (int i = 0; i < num_herramientas; i++) {
                    int cantidad,id;
                    double precio;
                    std::string type, marca;
                    std::cout <<"\n"
                    << "Tipo de herramienta (Dado/Llave/Electrica): ";
                    std::cin >> type;
                    std::cout << "ID de la herramienta: ";
                    std::cin >> id;
                    std::cout << "Marca de la herramienta: ";
                    std::cin >> marca;
                    std::cout << "Cantidad: ";
                    std::cin >> cantidad;
                    std::cout << "Precio por unidad: ";
                    std::cin >> precio;

                    if (type == "Dado") {
                        std::string tamano, tipo_dado;
                        std::cout 
                        << "Tipo de dado (Estandar/Especial): ";
                        std::cin >> tipo_dado;
                        std::cout << "Tamano del dado: ";
                        std::cin >> tamano;
                        Herramienta* nueva = new Dado(id, marca, cantidad,
                         precio, tamano, tipo_dado);
                        miInventario.agregar_herramienta(nueva);
                    } else if (type == "Llave") {
                        std::string tamano, tipo_llave;
                        std::cout 
                        << "Tipo de llave (Estandar/Torque): ";
                        std::cin >> tipo_llave;
                        std::cout << "Tamano de la llave: ";
                        std::cin >> tamano;
                        Herramienta* nueva = new Llave(id, marca, cantidad, 
                        precio, tamano, tipo_llave);
                        miInventario.agregar_herramienta(nueva);
                    } else if (type == "Electrica") {
                        int potencia;
                        std::string name;                        
                        std::cout << "Nombre de la Herramienta: ";
                        std::cin >> name;
                        std::cout << "Potencia de la herramienta electrica: ";
                        std::cin >> potencia;
                        Herramienta* nueva = new Electrica(name,id, marca,cantidad,
                         precio, potencia);
                        miInventario.agregar_herramienta(nueva);
                    } else {
                        std::cout 
                        << "Tipo de herramienta no valido" << std::endl;
                    }
                }
                break;
            }
            case 5:
                return 0;    
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    }
    return 0;
}
