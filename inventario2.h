/*
 * Proyecto Inventario
 * Angelo Segura Ibarra
 * A01711723
 * Esta clase define un objeto de tipo Inventario que contiene todas las
 * operaciones como agregar herramientas,imprimir el inventario,eliminar
 * herramientas del inventario, busacar herramientas por su ID. Esta clase
 * utiliza polimorfismo para manejar productos de diferentes tipos.Es parte
 * del proyecto Inventario.
 */

#ifndef INVENTARIO2_H_
#define INVENTARIO2_H_
#include <string>
#include <iostream>
// Biblioteca con los objetos que se usan.
#include "herramientas.h"

// Declaracion de la clase Inventario
class Inventario {
// Atributos
private:
    Herramienta* inven[100];
    int num_herramientas;
// Metodos
public:
    Inventario() : num_herramientas(0) {}
    void agregar_herramienta(Herramienta* nueva);
    void imprimir_inventario();
    void eliminar_herramienta(const int& iD);
    void buscar_herramienta(const int& iD);
};

// Implementación de los métodos de Inventario

/*
 * El metodo agregar herramienta recibe un objeto de tipo puntero que
 * posteriormente se agrega al obejeto inventario, guardandolo en su indice
 * correspondiente
 */

void Inventario::agregar_herramienta(Herramienta* nueva) {
    if (num_herramientas < 100) {
        inven[num_herramientas++] = nueva;
    } else {
        std::cout << "Inventario lleno\n" << std::endl;
    }
}

/*
 * El metodo imprimir inventario muestra una lista dando la descripcion
 * correspondiente de cada objeto creado
 */

void Inventario::imprimir_inventario() {
    for (int i = 0; i < num_herramientas; ++i) {
        inven[i]->descripcion_herramienta();
    }
}

/*
 * El metodo eliminar herramienta una vez que recibio el ID de la herramienta
 * que se busca eliminar busca en el inventario este articulo para eliminarlo
*/

void Inventario::eliminar_herramienta(const int& id) {
    for (int i = 0; i < num_herramientas; ++i) {
        if (inven[i]->get_name() == id) {
            delete inven[i];
            for (int j = i; j < num_herramientas - 1; ++j) {
                inven[j] = inven[j + 1];
            }
            --num_herramientas;
            std::cout << "Herramienta " << id << " eliminada del inventario.\n" 
            << std::endl;
            return;
        }
    }
    std::cout << "Herramienta " << id << " no encontrada en el inventario.\n" 
    << std::endl;
}

/*
 * El metodo buscar herramienta una vez que el usuario ingresa el ID de la 
 * Herramienta lo busaca en el inventario e imprime su descripcion.
*/

void Inventario::buscar_herramienta(const int& id) {
    for (int i = 0; i < num_herramientas; ++i) {
        if (inven[i]->get_name() == id) {
            std::cout << "Herramienta encontrada: \n" << std::endl;
            inven[i]->descripcion_herramienta();
            return;
        }
    }
    std::cout << "Herramienta " << id << " no encontrada en el inventario.\n"
    << std::endl;
}

#endif
