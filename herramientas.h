/*
 * Proyecto Inventario
 * Angelo Segura Ibarra
 * A01711723
 * Esta clase esta define un objeto de tipo Producto, que es una clase base
 * abstracta.Esta clase nos permite deobtener y establecer atributos como
 * marca,id,cantidad,precio.
 * Contiene las clases heredadas Dado,Llave y Electrica
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_
#include <string>
#include <iostream>

// Clase Herramienta que es declarada como Abstracta 
class Herramienta {
// Atributos
private:
    std::string marca;
    int cantidad,id;
    double precio;

// Metodos 
public:
    // Sobrecarga de constructores
    Herramienta(int iD, std::string marc, int cant, double prec);
    Herramienta(int iD, int cant, double prec);

    // Getters y setters
    int get_cant(void);
    void set_cant(int cant);
    int get_name(void);
    std::string get_marc(void);
    double get_precio(void);

    // Métodos virtuales
    virtual double calcular_precio(void)=0; 
    virtual void descripcion_herramienta()=0; // Metodo abstracto
};

// Métodos de Herramienta
Herramienta::Herramienta(int iD, std::string marc, int cant, double prec)
    : id(iD), marca(marc), cantidad(cant), precio(prec) {}

Herramienta::Herramienta(int iD, int cant, double prec)
    : id(iD), cantidad(cant), precio(prec) {}

int Herramienta::get_cant(void) { return cantidad; }

void Herramienta::set_cant(int cant) { cantidad = cant; }

int Herramienta::get_name(void) { return id; }

std::string Herramienta::get_marc(void) { return marca; }

double Herramienta::get_precio(void) { return precio; }

// Metodos que seran sobreecritos 
double Herramienta::calcular_precio(void) { return cantidad * precio; }

void Herramienta::descripcion_herramienta() {
    std::cout << "\t Herramienta(id): " << id << "\t Marca: " << marca 
    << "\t Precio: " << precio << std::endl;
}

// Clase Dado heredada de Herramienta
class Dado : public Herramienta {
// Atributos
private:
    std::string tamano;
    std::string tipo;

// Metodos
public:
    // Sobrecarga de constructores
    Dado(int iD, std::string marc, int cant, double prec, std::string size,
     std::string type);
    Dado(int iD, int cant, double prec, std::string size, std::string type);

// Poliformismo: Sobrescritura de la función, implementando polimorfismo  
    double calcular_precio(void) ;  
    void descripcion_herramienta(void) ;
};

// Métodos de la clase  Dado
Dado::Dado(int iD, std::string marc, int cant, double prec, std::string size,
 std::string type)
    : Herramienta(iD, marc, cant, prec), tamano(size), tipo(type) {}

Dado::Dado(int iD, int cant, double prec, std::string size, std::string type)
    : Herramienta(iD, cant, prec), tamano(size), tipo(type) {}

/*Sobreescritura de los metodos calcular_precio y descripcion_herramienta,
* ya que en calcular precio este dependera del tipo del dado y en el caso de 
* descripcion esste tiene un diferente modo de imprimir la descripcion de la 
* herramienta
*/
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
    std::cout <<"Herramienta: Dado\n"
              << "ID: " << get_name() << "\n"
              << "Marca: " << get_marc() << "\n"
              << "Medida: " << tamano << "\n"
              << "Tipo: " << tipo << "\n"
              << "Cantidad: " << get_cant() << "\n"
              << "Precio: " << calcular_precio()<< "\n" << std::endl;
}

// Clase Llave heredada de Herramienta
class Llave : public Herramienta {
//Atributos
private:
    std::string tamano;
    std::string tipo;

// Metodos
public:
    // Sobrecarga de constructores
    Llave(int iD, std::string marc, int cant, double prec, std::string size,
     std::string type);
    Llave(int iD, int cant, double prec, std::string size, std::string type);

//Poliformismo: Sobrescritura de la función virtual, implementando polimorfismo
    double calcular_precio(void);
    void descripcion_herramienta(void);
};

// Métodos de la clase Llave
Llave::Llave(int iD, std::string marc, int cant, double prec, std::string size,
 std::string type)
    : Herramienta(iD, marc, cant, prec), tamano(size), tipo(type) {}

Llave::Llave(int iD, int cant, double prec, std::string size, std::string type)
    : Herramienta(iD, cant, prec), tamano(size), tipo(type) {}


//Sobreescritura de los metodos calcular_precio y descripcion_herramienta
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
    std::cout <<"Herramienta: Llave"
              << "ID: " << get_name() << "\n"
              << "Marca: " << get_marc() << "\n"
              << "Tamano: " << tamano << "\n"
              << "Tipo: " << tipo << "\n"
              << "Cantidad: " << get_cant() << "\n"
              << "Precio(total por todas las unidades): " << calcular_precio()
              << "\n" << std::endl;
}

// Clase Electrica heredada de Herramienta
class Electrica : public Herramienta {
// Atributos
private:
    int potencia;
    std:: string nombre;

public:
    // Sobrecarga de constructores
    Electrica(std:: string name,int iD, std::string marc, int cant,double prec,
    int poten);
    Electrica(std:: string name,int iD, int cant, double prec, int poten);

//Poliformismo: Sobrescritura de la función virtual, implementando polimorfismo
    double calcular_precio(void);
    void descripcion_herramienta(void);
    std::string get_name1(void);
};

// Métodos de Electrica
Electrica::Electrica(std::string name,int iD, std::string marc, int cant,
 double prec, int poten)
    : Herramienta(iD, marc, cant, prec), potencia(poten), nombre(name) {}

Electrica::Electrica(std::string name, int iD, int cant, double prec,int poten)
    : Herramienta(iD, cant, prec), potencia(poten),nombre(name) {}

/*Sobreescritura de los metodos calcular_precio debido a que se calcula de 
 *una manera diferente y descripcion_herramienta tiene un diferente modo de 
 * imprimir la descripcio  de la herramienta.
*/
double Electrica::calcular_precio(void) {
    double precio = get_precio();
    if (potencia > 1000) {
        precio += 750.99;
    }
    return precio * get_cant();
}

std::string Electrica::get_name1(void) { return nombre; }

void Electrica::descripcion_herramienta(void) {
    std::cout << "Herramienta: " << get_name1() << "\n"
              << "ID: " << get_name() << "\n"
              << "Marca: " << get_marc() << "\n"
              << "Potencia: " << potencia << "\n"
              << "Cantidad: " << get_cant() << "\n"
              << "Precio(total por todas las unidades): " << calcular_precio()
              << "\n" << std::endl;
}

#endif
