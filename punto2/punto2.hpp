#ifndef PUNTO2_HPP
#define PUNTO2_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

/**
 * @class Estudiante
 * @brief Representa a un estudiante con nombre, legajo y notas
 */
class Estudiante {
    private:
        string nombre;
        string legajo;
        vector<int> notas;
    
    public:
        /**
         * @brief Constructor de Estudiante
         * @param nombre Nombre del estudiante
         * @param legajo Legajo del estudiante
         */
        Estudiante(string nombre, string legajo);
    
        /**
         * @brief Calcula el promedio de notas del estudiante
         * @return Promedio de las notas o 0.0 si no tiene notas
         */
        double obtenerPromedio() const;
    
        /**
         * @brief Agrega una nueva nota al estudiante
         * @param nota Nota a agregar
         */
        void agregarNota(int nota);
    
        /**
         * @return Legajo del estudiante
         */
        string obtenerLegajo() const;
    
        /**
         * @return Nombre del estudiante
         */
        string obtenerNombre() const;
    
        /**
         * @brief Muestra la informacion del estudiante
         */
        void mostrarInformacion() const;
    };
    
    /**
     * @class Curso
     * @brief Representa un curso que contiene objetos tipo estudiante
     */
    class Curso {
    private:
        vector<Estudiante*> estudiantes;
    
    public:
        /// Destructor, solo borra obj curso 
        ~Curso();
    
        /**
         * @brief inscribe un estudiante al curso
         * @param estudianteNuevo puntero al nuevo estudiante
         * @throws runtime_error si el estudiante ya esta inscripto
         */
        void inscribirEstudiante(Estudiante* estudianteNuevo);
    
        /**
         * @brief Desinscribe un estudiante del curso. Arroja error si no existe
         * @param legajoBorrar Legajo del estudiante a borrar
         */
        void desinscribirEstudiante(string legajoBorrar);
    
        /**
         * @brief Verifica si un estudiante esta inscripto
         * @param legajo Legajo del estudiante a verificar
         * @return true si esta inscripto, false si no
         */
        bool estaInscripto(string legajo);
    
        /**
         * @brief Verifica si el curso esta completo (20 estudiantes)
         * @return true si esta completo, false si no
         */
        bool estaCompleto();
    
        /**
         * @brief Imprime los estudiantes ordenados alfabeticamente por nombre
         */
        void imprimirAlfabetico();
    
        /**
         * @brief Crea una copia superficial del curso
         * @return Copia del curso
         */
        Curso copiarCurso();
    };
    
    /**
     * @brief Muestra el menu de opciones para el curso
     */
    void mostrarMenu();
    
    #endif
    