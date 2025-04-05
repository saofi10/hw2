#include "punto1.hpp"
int main() {
    Time tiempo;
    while (true) {
        try {
            int opcion;
            cout << "\nSeleccione una opcion:\n"
                 << "1. Configurar hora\n"
                 << "2. Configurar minutos\n"
                 << "3. Configurar segundos\n"
                 << "4. Configurar periodo (a.m./p.m.)\n"
                 << "5. Configurar toda la hora de una vez\n"
                 << "6. Mostrar tiempo en formato 12 horas\n"
                 << "7. Mostrar tiempo en formato 24 horas\n"
                 << "8. Salir\n"
                 << "Ingrese su eleccion: ";
            cin >> opcion;
            if (opcion == 8) break;

            switch (opcion) {
                case 1: {
                    int h;
                    cout << "Ingrese la hora (1-12): ";
                    cin >> h;
                    tiempo.ponerHora(h);
                    break;
                }
                case 2: {
                    int m;
                    cout << "Ingrese los minutos (0-59): ";
                    cin >> m;
                    tiempo.ponerMin(m);
                    break;
                }
                case 3: {
                    int s;
                    cout << "Ingrese los segundos (0-59): ";
                    cin >> s;
                    tiempo.ponerSeg(s);
                    break;
                }
                case 4: {
                    string p;
                    cout << "Ingrese el periodo ('a.m.' o 'p.m.'): ";
                    cin >> p;
                    tiempo.ponerPeriodo(p);
                    break;
                }
                case 5: {
                    int h, m, s;
                    string p;
                    cout << "Ingrese la hora (1-12): "; cin >> h;
                    cout << "Ingrese minutos: "; cin >> m;
                    cout << "Ingrese segundos: "; cin >> s;
                    cout << "Ingrese periodo ('a.m.' o 'p.m.'): "; cin >> p;
                    tiempo = Time(h, m, s, p);
                    break;
                }
                case 6:
                    tiempo.mostrarTiempo();
                    break;
                case 7:
                    tiempo.mostrar24();
                    break;
                default:
                    cout << "Opcion invalida. Intente de nuevo.\n";
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << ". Intente de nuevo.\n";
        }
    }
    return 0;
}
