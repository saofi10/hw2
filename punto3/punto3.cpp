#include "punto3.hpp"
// Clase Entero
Entero::Entero(int valor) : valor(valor) {}

// metodos concretos
Numero* Entero::sumar(const Numero& otro) const {
    const Entero& o = dynamic_cast<const Entero&>(otro);
    return new Entero(valor + o.valor);
}

Numero* Entero::restar(const Numero& otro) const {
    const Entero& o = dynamic_cast<const Entero&>(otro);
    return new Entero(valor - o.valor);
}

Numero* Entero::multiplicar(const Numero& otro) const {
    const Entero& o = dynamic_cast<const Entero&>(otro);
    return new Entero(valor * o.valor);
}

Numero* Entero::dividir(const Numero& otro) const {
    const Entero& o = dynamic_cast<const Entero&>(otro);
    if (o.valor == 0) throw runtime_error("Error: Division por cero");
    return new Entero(valor / o.valor);
}

string Entero::toString() const {
    return to_string(valor);
}

// Clase Real
Real::Real(double valor) : valor(valor) {}

// metodos concretos
Numero* Real::sumar(const Numero& otro) const {
    const Real& o = dynamic_cast<const Real&>(otro);
    return new Real(valor + o.valor);
}

Numero* Real::restar(const Numero& otro) const {
    const Real& o = dynamic_cast<const Real&>(otro);
    return new Real(valor - o.valor);
}

Numero* Real::multiplicar(const Numero& otro) const {
    const Real& o = dynamic_cast<const Real&>(otro);
    return new Real(valor * o.valor);
}

Numero* Real::dividir(const Numero& otro) const {
    const Real& o = dynamic_cast<const Real&>(otro);
    if (o.valor == 0) throw runtime_error("Error: Division por cero");
    return new Real(valor / o.valor);
}

string Real::toString() const {
    return to_string(valor);
}

// Clase Complejo
Complejo::Complejo(double parteReal, double parteImaginaria) 
    : parteReal(parteReal), parteImaginaria(parteImaginaria) {}

// metodos concretos
Numero* Complejo::sumar(const Numero& otro) const {
    const  Complejo& o = dynamic_cast<const Complejo&>(otro);
    return new Complejo(parteReal + o.parteReal, parteImaginaria + o.parteImaginaria);
}

// metodos concretos
Numero* Complejo::restar(const Numero& otro) const {
    const Complejo& o = dynamic_cast<const Complejo&>(otro);
    return new Complejo(parteReal - o.parteReal, parteImaginaria - o.parteImaginaria);
}

Numero* Complejo::multiplicar(const Numero& otro) const { 
    // z1.z2 = (ac - bd) + (ad + bc)i , si z1 = a+bi y z2 = c+di
    const Complejo& o = dynamic_cast<const Complejo&>(otro);
    double nuevoReal = parteReal * o.parteReal - parteImaginaria * o.parteImaginaria;
    double nuevoImaginario = parteReal * o.parteImaginaria + parteImaginaria * o.parteReal;
    return new Complejo(nuevoReal, nuevoImaginario);
}

Numero* Complejo::dividir(const Numero& otro) const {
    // z1/z2 = (z1 * conj(z2)) / |z2|^2
    const Complejo& o = dynamic_cast<const Complejo&>(otro);
    double denominador = o.parteReal * o.parteReal + o.parteImaginaria * o.parteImaginaria;
    if (denominador == 0) throw runtime_error("Error: division por cero");

    double nuevoReal = (parteReal * o.parteReal + parteImaginaria * o.parteImaginaria) / denominador;
    double nuevoImaginario = (parteImaginaria * o.parteReal - parteReal * o.parteImaginaria) / denominador;
    return new Complejo(nuevoReal, nuevoImaginario);
}

string Complejo::toString() const {
    ostringstream os;
    os << parteReal << " + " << parteImaginaria << "i";
    return os.str();
}

//operador para impresion
ostream& operator<<(ostream& os, const Numero& num) {
    os << num.toString();
    return os;
}
