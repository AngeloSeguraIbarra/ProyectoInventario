#ifndef PROYECTO_H_
#define PROYECTO_H_

#include <string>
#include <sstream>



class Herramienta
{
    private:
        std::string nombre;
        std::string marca;
        int cantidad;
        double precio;

    public:
    //sobrecarga
    Herramienta(std::string name,std::string marc,int cant,double prec);
    Herramienta(std::string name,int cant,double prec);

    int get_cant(void);

    void set_cant(int cant);

    std::string get_name(void);

    std::string get_marc(void);
    double get_precio(void);

    //sobreescritura
    virtual double calcular_precio(void);
    virtual void descripcion_herramienta();
};
//metodos de herramienta
Herramienta::Herramienta(std::string name, std::string marc, int cant, double prec)
    : nombre(name), marca(marc), cantidad(cant), precio(prec)
{
}

Herramienta::Herramienta(std::string name, int cant, double prec)
    : nombre(name), cantidad(cant), precio(prec)
{
}

int Herramienta::get_cant(void)
{
    return cantidad;
}

void Herramienta::set_cant(int cant)
{
    cantidad = cant;
}

std::string Herramienta::get_name(void)
{
    return nombre;
}

std::string Herramienta::get_marc(void)
{
    return marca;
}

double Herramienta::get_precio(void)
{
    return precio;
}

double Herramienta::calcular_precio(void)
{
    return cantidad * precio;
}

void Herramienta::descripcion_herramienta()
{
    std::cout << "\t Herramienta:" << nombre << "\t Marca: " << marca << "\t Precio: " << precio << std::endl;
}

//herencia
class Dado : public Herramienta
{
    private:
        std::string tamano;
        std::string tipo;
        double impuesto;

    public:
        //sobrecarga  cosntructores
        Dado(std::string name,std::string marc,int cant,double prec,std::string size,std::string type);
        Dado(std::string name,int cant,double prec,std::string size,std::string type);

        //sobreescritura
        double calcular_precio(void) override;
        void descripcion_herramienta(void) override;

};
// metodos de dado
Dado:: Dado(std::string name,std::string marc,int cant,double prec,std::string size,std::string type):tamano(size),tipo(type),Herramienta(name,marc,cant,prec){}
Dado:: Dado(std::string name,int cant,double prec,std::string size,std::string type):tamano(size),tipo(type),Herramienta(name,cant,prec){}

double Dado::calcular_precio(void) 
        {
            double precio=get_precio();
        if (tipo == "Estandar") 
        {
            precio += 50.99; // Costo adicional para llaves estandares
        }
        if (tipo == "Especial") 
        {
            precio+= 100.99; // Costo adicional para llaves especiales
        }
        return precio* get_cant();
        
        }

void Dado:: descripcion_herramienta(void)
        {        
            std::cout << "Nombre: " << get_name()<< "\n"
                    << "Marca: " << get_marc() << "\n"   // en caso de no tener el dato de marca como hago la otra funcion 
                    << "medida: " << tamano << "\n"
                    << "Tipo: " << tipo << "\n"
                    << "Cantidad: " << get_cant() << "\n"
                    << "Precio: " << calcular_precio()<< std::endl;
        }

//herencia
class Llave : public Herramienta
{
    private:
        std::string  tamano;
        std::string tipo;

    public:
        //sobrecarga  constructores
        Llave(std::string name,std::string marc,int cant,double prec,std::string size,std::string type);
        Llave(std::string name,int cant,double prec,std::string size,std::string type);

        //sobreescritura
        double calcular_precio(void) override;
        void descripcion_herramienta(void) override;

};
//metodos llave
Llave :: Llave(std::string name,std::string marc,int cant,double prec,std::string size,std::string type):tamano(size),tipo(type), Herramienta(name,marc,cant,prec){}
Llave::Llave(std::string name,int cant,double prec,std::string size,std::string type):tamano(size),tipo(type),Herramienta(name,cant,prec){}
double Llave::calcular_precio(void) 
        {
            double precio=get_precio();
            if (tipo == "Estandar") 
            {
                precio += 150.99; // Costo adicional para dados estandares
            }
            if (tipo == "Torque") 
            {
                precio+= 200.99; // Costo adicional para dados de torque(de diferente dureza y uso)
            }
            return precio* get_cant();
        }
void Llave::descripcion_herramienta(void)
        {        
            std::cout << "Nombre: " << get_name()<< "\n"
                    << "Marca: " << get_marc() << "\n"   // en caso de no tener el dato de marca como hago la otra funcion 
                    << "tamaño: " << tamano << "\n"
                    << "Tipo: " << tipo << "\n"
                    << "Cantidad: " << get_cant() << "\n"
                    << "Precio: " << calcular_precio()<< std::endl;
        }

//herencia 
class Electrica : public Herramienta
{
    private:
        int potencia;  
    public:
        //sobrecarga constructores
        Electrica(std::string name,std::string marc,int cant,double prec,int poten);
        Electrica(std::string name,int cant,double prec,int poten);
        
        //sobreescritura
        double calcular_precio() override;
        void descripcion_herramienta(void) override;
};

//metodos de electrica
Electrica:: Electrica(std::string name,std::string marc,int cant,double prec,int poten):potencia(poten),Herramienta(name,marc,cant,prec){}
Electrica:: Electrica(std::string name,int cant,double prec,int poten):potencia(poten), Herramienta(name,cant,prec){}
double  Electrica::calcular_precio() 
        {
            double precio=get_precio();
            if (potencia > 1000) 
            {
                precio += 750.99; // Costo adicional por alta potencia
            }
            return precio* get_cant();
        }
void  Electrica::descripcion_herramienta(void)
        {        
            std::cout << "Nombre: " << get_name()<< "\n"
                    << "Marca: " << get_marc() << "\n"   // en caso de no tener el dato de marca como hago la otra funcion
                    << "Potencia: " << potencia << "\n"
                    << "Cantidad: " << get_cant() << "\n"
                    << "Precio: " << calcular_precio()<< std::endl;
        }



#endif