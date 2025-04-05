#include "punto4.hpp"

// Clase base abstracta
class cuentaBanco {
private:
    double balance = 0.0;  // a. 
    virtual void mostrarInfo() const = 0; // e. metodo virtual puro

protected:
    string titularCuenta; // b. 

public:
    cuentaBanco(string titular, double balanceInicial = 0.0)
        : titularCuenta(titular), balance(balanceInicial) {}

    // c.
    virtual void depositar(double cantidad) {
        balance += cantidad;
    }

    // d. 
    virtual void retirar(double cantidad) = 0;

    virtual ~cuentaBanco() {}

    // Friend para permitir acceso a balance desde cuentacorriente pero tambien desde cajadeahorro, por lo que dice al ultimo de la ultima consigna
    friend class CuentaCorriente;
    friend class CajaDeAhorro;
};

// Clase derivada CajaDeAhorro
class CajaDeAhorro : public cuentaBanco {
private:
    int vecesMostrado = 0;

public:
    CajaDeAhorro(string titular, double balanceInicial = 0.0)
        : cuentaBanco(titular, balanceInicial) {}

    void depositar(double cantidad) override {
        balance += cantidad;
    }

    void retirar(double cantidad) override {
        if (cantidad > balance) {
            throw runtime_error("Error: No puede retirar más dinero del que existe en la cuenta.");
        }
        balance -= cantidad;
    }

    void mostrarInfo() const override {
        const_cast<CajaDeAhorro*>(this)->vecesMostrado++;

        cout << "Nombre: " << titularCuenta << endl;
        cout << "Balance: " << balance << endl;

        if (vecesMostrado > 2) {
            cout << "Se descuentan $20 por mostrar la información más de 2 veces." << endl;
            const_cast<CajaDeAhorro*>(this)->balance -= 20;
        }
    }
};

class CuentaCorriente : public cuentaBanco {
private:
    CajaDeAhorro* cajaAhorro; // PUNTERO a caja de ahorro vinculada

public:
    CuentaCorriente(string titular, double balanceInicial, CajaDeAhorro* vinculada)
        : cuentaBanco(titular, balanceInicial), cajaAhorro(vinculada) {}

    void depositar(double cantidad) override {
        balance += cantidad;
    }

    void retirar(double cantidad) override {
        if (cantidad > balance) {
            if (cajaAhorro && cantidad <= cajaAhorro->balance) {
                cout << "Fondos insuficientes en cuenta corriente. Se está retirando desde la caja de ahorro." << endl;
                cajaAhorro->balance -= cantidad;
            } else {
                cout << "Error: No hay fondos suficientes ni en la cuenta corriente ni en la caja de ahorro." << endl;
            }
        } else {
            balance -= cantidad;
        }
    }

    void mostrarInfo() const override {
        cout << "Nombre: " << titularCuenta << endl;
        cout << "Balance: " << balance << endl;
    }
};

