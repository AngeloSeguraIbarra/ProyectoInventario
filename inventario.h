#ifndef INVENTARIO_H_
#define INVENTARIO_H_

#include <string>
#include <iostream>
#include <sstream>
#include "proyecto.h"

class Inventario
{
    private:
        Herramienta* inven[100];
        int num_herramientas;

    public:
        Inventario():num_herramientas(0){}

        void imprimir_inventario()
        {
            for(int i=0;i<num_herramientas;i++)
            {
                inven[i]->descripcion_herramienta();
            }
        }

        void agregar_herramienta(Herramienta* nueva)
        {
            if (num_herramientas<100)
            {
                inven[num_herramientas++]=nueva;
            }
            else
            {
                std::cout << "Inventario lleno" << std::endl;
            }
        }

        void eliminar_herramienta(std::string nombre)
        {
            for (int i = 0; i < num_herramientas; i++)
            {
                if (inven[i]->get_name() == nombre)
                {
                    for (int j = i; j < num_herramientas - 1; j++)
                    {
                        inven[j] = inven[j + 1];
                    }
                    num_herramientas--;
                    std::cout << "Herramienta " << nombre << " eliminada del inventario." << std::endl;
                    return;
                }
            }
            std::cout << "Herramienta " << nombre << " no encontrada en el inventario." << std::endl;
        }

        void buscar_herramienta(std::string nombre)
        {
            for (int i = 0; i < num_herramientas; i++)
            {
                if (inven[i]->get_name() == nombre)
                {
                    std::cout << "Herramienta encontrada: " << std::endl;
                    inven[i]->descripcion_herramienta();
                    return;
                }
            }
            std::cout << "Herramienta " << nombre << " no encontrada en el inventario." << std::endl;
        }
};

#endif
