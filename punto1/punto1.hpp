#ifndef PUNTO1_HPP
#define PUNTO1_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

/**
 * @class Time
 * @brief Representa un momento del dia en formato de 12 horas con a.m./p.m.
 */
class Time {
private:
    int h, m, s;        // Hora (1-12), minutos (0-59), segundos (0-59). Con la hora se considera que siempre ingresas en formato 12 horas, despues si se puede llamar funcion para mostrar en formato 24hs.
    string periodo;     // "a.m." o "p.m."

    /**
     * @brief Valida que los valores de hora, minuto y segundo esten dentro de los rangos validos
     * @param h Hora (1-12)
     * @param m Minuto (0-59)
     * @param s Segundos (0-59)
     * @throws invalid_argument si algun valor esta fuera de rango
     */
    void validarTiempo(int h, int m, int s);

    /**
     * @brief Valida que el periodo sea "a.m." o "p.m."
     * @param p Periodo a validar
     * @throws invalid_argument si el valor no es "a.m." o "p.m."
     */
    void validarPeriodo(const string& p);

public:
    /// Constructor por defecto (00:00:00 a.m.)
    Time();

    /**
     * @brief Constructor con solo la hora
     * @param h Hora (1-12)
     */
    Time(int h);

    /**
     * @brief Constructor con hora y minutos
     * @param h Hora (1-12)
     * @param m Minutos (0-59)
     */
    Time(int h, int m);

    /**
     * @brief Constructor con hora, minutos y segundos
     * @param h Hora (1-12)
     * @param m Minutos (0-59)
     * @param s Segundos (0-59)
     */
    Time(int h, int m, int s);

    /**
     * @brief Constructor con todo
     * @param h Hora (1-12)
     * @param m Minutos (0-59)
     * @param s Segundos (0-59)
     * @param p Periodo ("a.m." o "p.m.")
     */
    Time(int h, int m, int s, const string& p);

    /// @brief Cambia la hora
    /// @param h Nueva hora (1-12)
    void ponerHora(int h);

    /// @brief Cambia los minutos
    /// @param m Nuevos minutos (0-59)
    void ponerMin(int m);

    /// @brief Cambia los segundos
    /// @param s Nuevos segundos (0-59)
    void ponerSeg(int s);

    /// @brief Cambia el periodo
    /// @param p Nuevo periodo ("a.m." o "p.m.")
    void ponerPeriodo(const string& p);

    /// @return La hora actual
    int getHora() const;

    /// @return Los minutos actuales
    int getMinutos() const;

    /// @return Los segundos actuales
    int getSegundos() const;

    /// @return El periodo actual ("a.m." o "p.m.")
    string getPeriodo() const;

    /// @brief Muestra el tiempo en formato 12h con a.m./p.m.
    void mostrarTiempo() const;

    /// @brief Muestra el tiempo en formato de 24 horas
    void mostrar24() const;
};

#endif
