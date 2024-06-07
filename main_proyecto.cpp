
#include <iostream>
#include "herramientas.h"
#include "inventario2.h"   

int main() {
    // Crear el inventario
    Inventario miInventario;

    // Crear ejemplos de herramientas usando punteros
    Herramienta* dado1 = new Dado("Dado1", "MarcaA", 10, 15.99, "Grande", "Estandar");
    Herramienta* dado2 = new Dado("Dado2", 5, 20.99, "Pequeno", "Especial");
    Herramienta* herramienta1 = new Electrica("Taladro", "MarcaB", 7, 99.99, 1200);

    // Agregar herramientas al inventario
    miInventario.agregar_herramienta(dado1);
    miInventario.agregar_herramienta(dado2);
    miInventario.agregar_herramienta(herramienta1);

    // Imprimir el inventario
    std::cout << "Inventario inicial:" << std::endl;
    miInventario.imprimir_inventario();

    // Buscar una herramienta
    std::cout << "\nBuscando 'Dado1':" << std::endl;
    miInventario.buscar_herramienta("Dado1");

    // Eliminar una herramienta
    std::cout << "\nEliminando 'Dado1':" << std::endl;
    miInventario.eliminar_herramienta("Dado1");

    // Imprimir el inventario después de la eliminación
    std::cout << "\nInventario despues de eliminar 'Dado1':" << std::endl;
    miInventario.imprimir_inventario();

    return 0;
}
