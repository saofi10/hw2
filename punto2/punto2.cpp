#include "punto2.hpp"

class Curso;
class Estudiante {
private:
    string nombre, legajo;
    vector<int> notas;

public:
    Estudiante(string nombre, string legajo) : nombre(nombre), legajo(legajo) {}
    
    double obtenerPromedio() const {
        double sumaAux = 0.0;
        for (int nota : notas) {
            sumaAux += nota;
        }
        return notas.empty() ? 0.0 : sumaAux/notas.size();
    }

    void agregarNota(int nota) {
        notas.push_back(nota);
    }

    string obtenerLegajo() const {
        return legajo;
    }

    string obtenerNombre() const {
        return nombre;
    }

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Legajo: " << legajo << endl;
        cout << "Promedio General: " << obtenerPromedio() << endl;
    }
};

class Curso {
private:
    vector<Estudiante*> estudiantes;

public:
    ~Curso() {}//borra el vector pero estrudiantes siguen existineod porque entiendo que no es owner de ellos
    

    void inscribirEstudiante(Estudiante* estudianteNuevo) {
        string legajo = estudianteNuevo->obtenerLegajo();
        if (estaInscripto(legajo)) throw runtime_error("Error: Este estudiante ya pertenece al curso");
        else estudiantes.push_back(estudianteNuevo);
    }

    void desinscribirEstudiante(string legajoBorrar) {
        if (!estaInscripto(legajoBorrar)) throw invalid_argument ("El estudiante que se intena borrar no esta en el sistema.");
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

    bool estaInscripto(string legajo) {
        for (Estudiante* estudiante : estudiantes) {
            if (estudiante->obtenerLegajo() == legajo) {
                return true;
            }
        }
        return false;
    }

    bool estaCompleto() {
        return estudiantes.size() >= 20;
    }

    void imprimirAlfabetico() {
        vector<Estudiante*> estudiantesCopia = estudiantes;
        sort(estudiantesCopia.begin(), estudiantesCopia.end(), [](Estudiante* a, Estudiante* b) {
            return a->obtenerNombre() < b->obtenerNombre();
        });
        for (Estudiante* estudiante : estudiantesCopia) {
            cout << *estudiante << endl; //esto llama al operador<<
        }
        
        cout << endl;
    }

    Curso copiarCurso() {
        Curso cursoCopia;
        for (Estudiante* estudiante : estudiantes) { 
            cursoCopia.inscribirEstudiante(estudiante); // shallow copy, copia los punteros entonces desde el curso puedo modificar a los estudiantes y no va a haber 2 duplicados
        }
        return cursoCopia;
    }
    /*
    Hago una copia superficial del curso, como muchos cursos comparten estudiantes poruqe solo copia los punteros, evita duplicar objetos, y conviene porque
    una modificación a un estudiante en un curso tambien ocurre en el otro. Eso sirve porque el estudiante de un curso no tiene que ser distinto al de otro 
    d) Me parece que es una agregacion, porque el curso seria el whole y has estudiantes. Puedo borrar curso sin borrar estudiantes.
*/
    
};

ostream& operator<<(ostream& os, const Estudiante& e) { //sobrecarga de operador << 
    os << e.obtenerNombre() << " - Legajo: " << e.obtenerLegajo()
       << " - Promedio: " << e.obtenerPromedio();
    return os;
}
//este va afuera porque no tiene que ver con el curso.
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
