#include "punto2.hpp"

//===== Clase Estudiante ======================================================================

Estudiante::Estudiante(string nombre, string legajo) : nombre(nombre), legajo(legajo) {}

double Estudiante::obtenerPromedio() const {
    double sumaAux = 0.0;
    for (int nota : notas) {
        sumaAux += nota;
    }
    return notas.empty() ? 0.0 : sumaAux / notas.size();
}

void Estudiante::agregarNota(int nota) {
    notas.push_back(nota);
}

string Estudiante::obtenerLegajo() const {
    return legajo;
}

string Estudiante::obtenerNombre() const {
    return nombre;
}

void Estudiante::mostrarInformacion() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Legajo: " << legajo << endl;
    cout << "Promedio General: " << obtenerPromedio() << endl;
}

//===== Clase Curso =======================================================================================

Curso::~Curso() {
    // No borra los estudiantes al borrar curso porque no es owner de ellos (agregacion)
}

void Curso::inscribirEstudiante(Estudiante* estudianteNuevo) {
    string legajo = estudianteNuevo->obtenerLegajo();
    if (estaInscripto(legajo))
        throw runtime_error("Error: Este estudiante ya pertenece al curso");
    estudiantes.push_back(estudianteNuevo);
}

void Curso::desinscribirEstudiante(string legajoBorrar) {
    if (!estaInscripto(legajoBorrar))
        throw invalid_argument("El estudiante que se intenta borrar no está en el curso.");

    auto it = estudiantes.begin();
    while (it != estudiantes.end()) {
        if ((*it)->obtenerLegajo() == legajoBorrar) {
            it = estudiantes.erase(it);
            return;
        } else {
            ++it;
        }
    }
}

bool Curso::estaInscripto(string legajo) {
    for (Estudiante* estudiante : estudiantes) {
        if (estudiante->obtenerLegajo() == legajo) {
            return true;
        }
    }
    return false;
}

bool Curso::estaCompleto() {
    return estudiantes.size() >= 20;
}

void Curso::imprimirAlfabetico() {
    vector<Estudiante*> estudiantesCopia = estudiantes;
    sort(estudiantesCopia.begin(), estudiantesCopia.end(), [](Estudiante* a, Estudiante* b) {
        return a->obtenerNombre() < b->obtenerNombre();
    });
    for (Estudiante* estudiante : estudiantesCopia) {
        estudiante->mostrarInformacion();
        cout << endl;
    }
    
    }


Curso Curso::copiarCurso() {
    Curso cursoCopia;
    for (Estudiante* estudiante : estudiantes) {
        cursoCopia.inscribirEstudiante(estudiante); // Copia superficial
    }
    return cursoCopia;
}

//===== menu ===========================================================================

void mostrarMenu() {
    cout << "\nOpciones del Curso:" << endl;
    cout << "1. Inscribir estudiante" << endl;
    cout << "2. Desinscribir estudiante" << endl;
    cout << "3. Ver si un estudiante esta inscrito" << endl;
    cout << "4. Indicar si el curso esta completo" << endl;
    cout << "5. Imprimir lista de estudiantes en orden alfabetico" << endl;
    cout << "6. Copiar curso" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}
