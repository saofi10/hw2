#ifndef NUMEROS_HPP
#define NUMEROS_HPP

#include <string>
#include <iostream>
#include <sstream> 

using namespace std;
    
/**
 * @class Numero
 * @brief Representa una clase abstracta Numero y define las operaciones que van a tener subclases
 */
class Numero {
public:
    virtual Numero* sumar(const Numero& otro) const = 0;
    virtual Numero* restar(const Numero& otro) const = 0; //no puse los briefs de cada funcion porque el nombre te dice 
    virtual Numero* multiplicar(const Numero& otro) const = 0;
    virtual Numero* dividir(const Numero& otro) const = 0;
    virtual string toString() const = 0;

    //Operadores sobrecargados, con esto le ensenias a c a como trabajr esos numeros, 
    //como que vos educas el uso de los signos, pues en principio no sabe un lenguaje como sumar clases o eso si vos las creaste
    Numero* operator+(const Numero& otro) const;
    Numero* operator-(const Numero& otro) const;
    Numero* operator*(const Numero& otro) const;
    Numero* operator/(const Numero& otro) const;

    virtual ~Numero() {}
};
    
/**
 * @class Entero derivada de Numero
 * @brief Representa un tipo de Numero Entero y define sus operaciones
 */
class Entero : public Numero {
private:
    int valor;

public:
    Entero(int valor);

    Numero* sumar(const Numero& otro) const override;
    Numero* restar(const Numero& otro) const override;
    Numero* multiplicar(const Numero& otro) const override;
    Numero* dividir(const Numero& otro) const override;
    string toString() const override;
};

class Real : public Numero {
private:
    double valor;

public:
    Real(double valor);

    Numero* sumar(const Numero& otro) const override;
    Numero* restar(const Numero& otro) const override;
    Numero* multiplicar(const Numero& otro) const override;
    Numero* dividir(const Numero& otro) const override;
    string toString() const override;
};
/**
 * @class Complejo derivada de Numero
 * @brief Representa un tipo de Numero Complejo y define sus operaciones
 */
class Complejo : public Numero {
private:
    double parteReal;
    double parteImaginaria;

public:
    Complejo(double parteReal, double parteImaginaria);

    Numero* sumar(const Numero& otro) const override;
    Numero* restar(const Numero& otro) const override;
    Numero* multiplicar(const Numero& otro) const override;
    Numero* dividir(const Numero& otro) const override;
    string toString() const override;
};

//operador impresion
ostream& operator<<(ostream& os, const Numero& num);

#endif 
