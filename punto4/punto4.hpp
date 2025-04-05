#ifndef CUENTAS_HPP
#define CUENTAS_HPP

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
/**
 * @brief Clase abstracta base que representa una cuenta de banco
 */
class cuentaBanco {
private:
    double balance = 0.0; //Balance (dinero) de la cuenta

    /*
     * @brief Muestra la informacion de la cuenta
     */
    virtual void mostrarInfo() const = 0;

protected:
    string titularCuenta; // Nombre del titular de la cuenta

public:
    /**
     * @brief Constructor
     * @param titular Nombre del titular
     * @param balanceInicial Balance inicial de la cuenta
     */
    cuentaBanco(string titular, double balanceInicial = 0.0);

    /**
     * @brief Deposita dinero en cuenta
     * @param cantidad Monto a ingresar
     */
    virtual void depositar(double cantidad);

    /**
     * @brief Retira dinero de la cuenta. Chequea que sea posible
     * @param cantidad Monto a retirar
     * @throws runtime_error Si no hay fondos suficientes
     */
    virtual void retirar(double cantidad) = 0;

    /**
     * @brief Destructor VIRTUAL
     */
    virtual ~cuentaBanco();

    friend class CuentaCorriente;
    friend class CajaDeAhorro;
};

/**
 * @brief Clase que representa una caja de ahorro
 */
class CajaDeAhorro : public cuentaBanco {
private:
    int vecesMostrado = 0; // Cantidad de veces que se mostro la informacion. Util para cobrar si se excede de 2 requerimentos

public:
    /**
     * @brief Constructor de CajaDeAhorro
     * @param titular Nombre del titular
     * @param balanceInicial Balance inicial
     */
    CajaDeAhorro(string titular, double balanceInicial = 0.0);

    /**
     * @brief Deposita una cantidad en la cuenta.
     * @param cantidad Monto a depositar.
     */
    void depositar(double cantidad) override;

    /**
     * @brief Retira dinero de la cuenta.
     * @param cantidad Monto a retirar.
     * @throws runtime_error Si el retiro supera el balance.
     */
    void retirar(double cantidad) override;

    /**
     * @brief Muestra la informacion de la cuenta.
     *Cobra $20 del balance si el usuario solicita mostrar mas de 2 veces.
     */
    void mostrarInfo() const override;
};

/**
 * @brief Clase que representa una cuenta corriente vinculada a una caja de ahorro.
 */
class CuentaCorriente : public cuentaBanco {
private:
    CajaDeAhorro* cajaAhorro; /// PUNTERO a la caja de ahorro vinculada.

public:
    /**
     * @brief Constructor de CuentaCorriente
     * @param titular Nombre del titular
     * @param balanceInicial Balance inicial
     * @param vinculada Puntero a la CajaDeAhorro vinculada
     */
    CuentaCorriente(string titular, double balanceInicial, CajaDeAhorro* vinculada);

    /**
     * @brief Deposita dinero en la cuenta
     * @param cantidad Monto a depositar
     */
    void depositar(double cantidad) override;

    /**
     * @brief Retira dinero de la cuenta
     * Si no hay suficiente en cuenta corriente, retira de caja de ahorro
     * @param cantidad Monto a retirar
     */
    void retirar(double cantidad) override;

    /**
     * @brief Muestra la informacion de la cuenta
     */
    void mostrarInfo() const override;
};

#endif 
