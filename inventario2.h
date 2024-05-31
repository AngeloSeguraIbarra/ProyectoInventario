#ifndef INVENTARIO2_H_
#define INVENTARIO2_H_

#include <string>
#include <iostream>
#include "herramientas.h"

class Inventario {
private:
    Herramienta* inven[100];
    int num_herramientas;

public:
    Inventario() : num_herramientas(0) {}
    ~Inventario();

    void imprimir_inventario();
    void agregar_herramienta(Herramienta* nueva);
    void eliminar_herramienta(const std::string& nombre);
    void buscar_herramienta(const std::string& nombre);
};

// Implementación de los métodos de Inventario
Inventario::~Inventario() {
    for (int i = 0; i < num_herramientas; ++i) {
        delete inven[i];
    }
}

void Inventario::imprimir_inventario() {
    for (int i = 0; i < num_herramientas; ++i) {
        inven[i]->descripcion_herramienta();
    }
}

void Inventario::agregar_herramienta(Herramienta* nueva) {
    if (num_herramientas < 100) {
        inven[num_herramientas++] = nueva;
    } else {
        std::cout << "Inventario lleno" << std::endl;
    }
}

void Inventario::eliminar_herramienta(const std::string& nombre) {
    for (int i = 0; i < num_herramientas; ++i) {
        if (inven[i]->get_name() == nombre) {
            delete inven[i];
            for (int j = i; j < num_herramientas - 1; ++j) {
                inven[j] = inven[j + 1];
            }
            --num_herramientas;
            std::cout << "Herramienta " << nombre << " eliminada del inventario." << std::endl;
            return;
        }
    }
    std::cout << "Herramienta " << nombre << " no encontrada en el inventario." << std::endl;
}

void Inventario::buscar_herramienta(const std::string& nombre) {
    for (int i = 0; i < num_herramientas; ++i) {
        if (inven[i]->get_name() == nombre) {
            std::cout << "Herramienta encontrada: " << std::endl;
            inven[i]->descripcion_herramienta();
            return;
        }
    }
    std::cout << "Herramienta " << nombre << " no encontrada en el inventario." << std::endl;
}

#endif
