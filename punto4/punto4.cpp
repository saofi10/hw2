#include "punto4.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

// ======================= cuentaBanco ========================
cuentaBanco::cuentaBanco(string titular, double balanceInicial)
    : titularCuenta(titular), balance(balanceInicial) {}

void cuentaBanco::depositar(double cantidad) {
    balance += cantidad;
}

cuentaBanco::~cuentaBanco() {}

// ===================== CajaDeAhorro ========================
CajaDeAhorro::CajaDeAhorro(string titular, double balanceInicial)
    : cuentaBanco(titular, balanceInicial) {}

void CajaDeAhorro::depositar(double cantidad) {
    balance += cantidad;
}

void CajaDeAhorro::retirar(double cantidad) {
    if (cantidad > balance) {
        throw runtime_error("Error: No puede retirar mas dinero del que hay en cuenta");
    }
    balance -= cantidad;
}

void CajaDeAhorro::mostrarInfo() const {
    const_cast<CajaDeAhorro*>(this)->vecesMostrado++;

    cout << "Nombre: " << titularCuenta << endl;
    cout << "Balance: " << balance << endl;

    if (vecesMostrado > 2) {
        cout << "Se descuentan $20 por mostrar la informacion mas de 2 veces" << endl;
        const_cast<CajaDeAhorro*>(this)->balance -= 20;
    }
}

// ===================== CuentaCorriente ========================
CuentaCorriente::CuentaCorriente(string titular, double balanceInicial, CajaDeAhorro* vinculada)
    : cuentaBanco(titular, balanceInicial), cajaAhorro(vinculada) {}

void CuentaCorriente::depositar(double cantidad) {
    balance += cantidad;
}

void CuentaCorriente::retirar(double cantidad) {
    if (cantidad > balance) {
        if (cajaAhorro && cantidad <= cajaAhorro->balance) {
            cout << "Fondos insuficientes en cuenta corriente. Se esta retirando desde la caja de ahorro" << endl;
            cajaAhorro->balance -= cantidad;
        } else {
            cout << "Error: No hay fondos suficientes ni en la cuenta corriente ni en la caja de ahorro" << endl;
        }
    } else {
        balance -= cantidad;
    }
}

void CuentaCorriente::mostrarInfo() const {
    cout << "Nombre: " << titularCuenta << endl;
    cout << "Balance: " << balance << endl;
}

