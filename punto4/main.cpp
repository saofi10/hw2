#include "punto4.hpp"
int main() {
    try {
        CajaDeAhorro miCajaDeAhorro("Pedro Fernandez", 500.0);
        CuentaCorriente miCuentaCorriente("Pedro Fernandez", 200.0, &miCajaDeAhorro); 

        cout << "Mostrar informacion de la Caja de Ahorro:" << endl;
        miCajaDeAhorro.mostrarInfo();
        miCajaDeAhorro.depositar(100.0);
        miCajaDeAhorro.retirar(50.0);
        miCajaDeAhorro.mostrarInfo();
        miCajaDeAhorro.mostrarInfo();  // desde aca debe descontar $20

        cout << "\nMostrar estado final de la Cuenta Corriente:" << endl;
        miCuentaCorriente.mostrarInfo();
        miCuentaCorriente.retirar(300.0); // retira desde caja de ahorro
        miCuentaCorriente.mostrarInfo();

        cout << "\nMostrar estado final de la Caja de Ahorro:" << endl;
        miCajaDeAhorro.mostrarInfo();  // se pide de nuevo,vuelve a descontar $20

    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
