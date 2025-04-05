#include "punto3.hpp"
int main() {
    try {
        // oruebas con entero
        Numero* n1 = new Entero(10);
        Numero* n2 = new Entero(5);
        Numero* sumaEntero = n1->sumar(*n2);
        cout << "Suma de enteros: " << sumaEntero->toString() << endl;

        delete sumaEntero;

        // pruebas con real
        Numero* r1 = new Real(10.5);
        Numero* r2 = new Real(2.3);
        Numero* productoReal = r1->multiplicar(*r2);
        cout << "Producto de reales: " << productoReal->toString() << endl;

        delete productoReal;

        // Pruebas con complejo
        Numero* c1 = new Complejo(3, 4);
        Numero* c2 = new Complejo(1, -2);
        Numero* divisionComplejo = c1->dividir(*c2);
        cout << "Division de complejos: " << divisionComplejo->toString() << endl;

        delete divisionComplejo;

        // liberar memoria
        delete n1;
        delete n2;
        delete r1;
        delete r2;
        delete c1;
        delete c2;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}