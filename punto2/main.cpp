#include "punto2.hpp"
//aca se hace manejo de memoria librerando a todos los estudiantes que se crearon, porque como puse que la relacion sea agregacion al borrar el curso no libero memoria
int main() {
    Curso curso;
    int opcion;
    vector<Estudiante*> todosLosEstudiantes;

    do {
        mostrarMenu();
        /** void mostrarMenu() {
    cout << "\nOpciones del Curso:" << endl;
    cout << "1. Inscribir estudiante" << endl;
    cout << "2. Desinscribir estudiante" << endl;
    cout << "3. Ver si un estudiante esta inscrito" << endl;
    cout << "4. Indicar si el curso esta completo" << endl;
    cout << "5. Imprimir lista de estudiantes en orden alfabetico" << endl;
    cout << "6. Copiar curso" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}*/
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre, legajo;
                cout << "Ingrese el nombre y legajo del estudiante a inscribir: ";
                cin >> nombre >> legajo;
                Estudiante* nuevo = new Estudiante(nombre, legajo);
                try {
                    curso.inscribirEstudiante(nuevo);
                    todosLosEstudiantes.push_back(nuevo); // guardo para borrarlo al final, manejo de memmoria
                } catch (const runtime_error& e) {
                    delete nuevo; // si no se pudo inscribir evita  fuga
                    cerr << e.what() << endl;
                }
                break;
            }
            case 2: {
                string legajo;
                cout << "Ingrese el legajo del estudiante a desinscribir: ";
                cin >> legajo;
                curso.desinscribirEstudiante(legajo);
                break;
            }
            case 3: {
                string legajo;
                cout << "Ingrese el legajo del estudiante a chequear: ";
                cin >> legajo;
                cout << (curso.estaInscripto(legajo) ? "El estudiante esta inscripto." : "El estudiante no esta inscripto.") << endl;
                break;
            }
            case 4:
                cout << (curso.estaCompleto() ? "El curso esta completo." : "El curso no esta completo.") << endl;
                break;
            case 5:
                curso.imprimirAlfabetico();
                break;
            case 6: {
                Curso copia = curso.copiarCurso();
                cout << "Curso copiado. Todo ok!" << endl;
                break;
            }
            case 7:
                cout << "Adios!" << endl;
                break;
            default:
                cerr << "Opcion invalida. Intente de nuevo o salga del programa." << endl;
        }
    } while (opcion != 7);

    // Liberar la memoria de todos los estudiantes creados
    for (Estudiante* e : todosLosEstudiantes) {
        delete e;
    }

    return 0;
}
