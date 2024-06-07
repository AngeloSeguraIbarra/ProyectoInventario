/*
 *
 * Proyecto Inventario
 * Angelo Segura Ibarra
 * A01711723
 * 06/06/2024
 * Esta clase defina objeto de tipo Empleado que contiene las clases heredadas
 * de Dado,Llave, Electrica
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_

// Librerias 
#include <string>
#include <iostream>

// Clase que es declarada como Abstracta 
class Herramienta {
// Atributos
private:
    std::string nombre;
    std::string marca;
    int cantidad;
    double precio;

// Metodos 
public:
    // Sobrecarga de constructores
    Herramienta(std::string name, std::string marc, int cant, double prec);
    Herramienta(std::string name, int cant, double prec);

    // Getters y setters
    int get_cant(void);
    void set_cant(int cant);
    std::string get_name(void);
    std::string get_marc(void);
    double get_precio(void);

    // Métodos virtuales
    virtual double calcular_precio(void)=0; // Metodo abstracto
    virtual void descripcion_herramienta()=0; // Metodo abstracto
};

// Métodos de Herramienta
Herramienta::Herramienta(std::string name, std::string marc, int cant, double prec)
    : nombre(name), marca(marc), cantidad(cant), precio(prec) {}

Herramienta::Herramienta(std::string name, int cant, double prec)
    : nombre(name), cantidad(cant), precio(prec) {}

int Herramienta::get_cant(void) { return cantidad; }
void Herramienta::set_cant(int cant) { cantidad = cant; }
std::string Herramienta::get_name(void) { return nombre; }
std::string Herramienta::get_marc(void) { return marca; }
double Herramienta::get_precio(void) { return precio; }
double Herramienta::calcular_precio(void) { return cantidad * precio; }
void Herramienta::descripcion_herramienta() {
    std::cout << "\t Herramienta: " << nombre << "\t Marca: " << marca << "\t Precio: " << precio << std::endl;
}

// Clase Dado heredada de Herramienta
class Dado : public Herramienta {
private:
    std::string tamano;
    std::string tipo;

public:
    // Sobrecarga de constructores
    Dado(std::string name, std::string marc, int cant, double prec, std::string size, std::string type);
    Dado(std::string name, int cant, double prec, std::string size, std::string type);

    // Poliformismo: Sobrescritura de la función, implementando polimorfismo.  
    double calcular_precio(void) override;
    void descripcion_herramienta(void) override;
};

// Métodos de Dado
Dado::Dado(std::string name, std::string marc, int cant, double prec, std::string size, std::string type)
    : Herramienta(name, marc, cant, prec), tamano(size), tipo(type) {}

Dado::Dado(std::string name, int cant, double prec, std::string size, std::string type)
    : Herramienta(name, cant, prec), tamano(size), tipo(type) {}

double Dado::calcular_precio(void) {
    double precio = get_precio();
    if (tipo == "Estandar") {
        precio += 50.99;
    } else if (tipo == "Especial") {
        precio += 100.99;
    }
    return precio * get_cant();
}

void Dado::descripcion_herramienta(void) {
    std::cout << "Nombre: " << get_name() << "\n"
              << "Marca: " << get_marc() << "\n"
              << "Medida: " << tamano << "\n"
              << "Tipo: " << tipo << "\n"
              << "Cantidad: " << get_cant() << "\n"
              << "Precio: " << calcular_precio() << std::endl;
}

// Clase Llave heredada de Herramienta
class Llave : public Herramienta {
private:
    std::string tamano;
    std::string tipo;

public:
    // Sobrecarga de constructores
    Llave(std::string name, std::string marc, int cant, double prec, std::string size, std::string type);
    Llave(std::string name, int cant, double prec, std::string size, std::string type);

    // //Poliformismo: Sobrescritura de la función virtual, implementando polimorfismo.
    double calcular_precio(void) override;
    void descripcion_herramienta(void) override;
};

// Métodos de Llave
Llave::Llave(std::string name, std::string marc, int cant, double prec, std::string size, std::string type)
    : Herramienta(name, marc, cant, prec), tamano(size), tipo(type) {}

Llave::Llave(std::string name, int cant, double prec, std::string size, std::string type)
    : Herramienta(name, cant, prec), tamano(size), tipo(type) {}

double Llave::calcular_precio(void) {
    double precio = get_precio();
    if (tipo == "Estandar") {
        precio += 150.99;
    } else if (tipo == "Torque") {
        precio += 200.99;
    }
    return precio * get_cant();
}

void Llave::descripcion_herramienta(void) {
    std::cout << "Nombre: " << get_name() << "\n"
              << "Marca: " << get_marc() << "\n"
              << "Tamaño: " << tamano << "\n"
              << "Tipo: " << tipo << "\n"
              << "Cantidad: " << get_cant() << "\n"
              << "Precio: " << calcular_precio() << std::endl;
}

// Clase Electrica heredada de Herramienta
class Electrica : public Herramienta {
private:
    int potencia;

public:
    // Sobrecarga de constructores
    Electrica(std::string name, std::string marc, int cant, double prec, int poten);
    Electrica(std::string name, int cant, double prec, int poten);


    // //Poliformismo: Sobrescritura de la función virtual, implementando polimorfismo.
    double calcular_precio(void) override;
    void descripcion_herramienta(void) override;
};

// Métodos de Electrica
Electrica::Electrica(std::string name, std::string marc, int cant, double prec, int poten)
    : Herramienta(name, marc, cant, prec), potencia(poten) {}

Electrica::Electrica(std::string name, int cant, double prec, int poten)
    : Herramienta(name, cant, prec), potencia(poten) {}


double Electrica::calcular_precio(void) {
    double precio = get_precio();
    if (potencia > 1000) {
        precio += 750.99;
    }
    return precio * get_cant();
}

void Electrica::descripcion_herramienta(void) {
    std::cout << "Nombre: " << get_name() << "\n"
              << "Marca: " << get_marc() << "\n"
              << "Potencia: " << potencia << "\n"
              << "Cantidad: " << get_cant() << "\n"
              << "Precio: " << calcular_precio() << std::endl;
}

#endif
