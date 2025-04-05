#include "punto1.hpp";
class Time {
private:
    int h, m, s;
    string periodo; // "a.m." o "p.m."

    void validarTiempo(int h, int m, int s) {
        if (h < 0 || h > 12) throw invalid_argument("La hora debe estar entre 1 y 12.");
        if (m < 0 || m >= 60) throw invalid_argument("Los minutos deben estar entre 0 y 59.");
        if (s < 0 || s >= 60) throw invalid_argument("Los segundos deben estar entre 0 y 59.");
    }

    void validarPeriodo(const string& p) { /// Lo tuve que hacer apartre pq  no en t odo meto pm am
        if (p != "a.m." && p != "p.m.") throw invalid_argument("El periodo debe ser 'a.m.' o 'p.m.'.");
    }

public:
    Time() : h(0), m(0), s(0), periodo("a.m.") {} //Constructor1, en los siguientes constructores va siendo con cada vez mas parametros, como pide consigna
    Time(int h) : m(0), s(0), periodo("a.m.") {
        if (h == 0) this->h = 12;
        else this->h = h;
        validarTiempo(this->h, m, s);
    }
    Time(int h, int m) : s(0), periodo("a.m.") {
        if (h == 0) this->h = 12;
        else this->h = h;
        this->m = m;
        validarTiempo(this->h, this->m, s);
    }
    Time(int h, int m, int s) : periodo("a.m.") {
        if (h == 0) this->h = 12;
        else this->h = h;
        this->m = m;
        this->s = s;
        validarTiempo(this->h, this->m, this->s);
    }
    Time(int h, int m, int s, const string& p) {
        if (h == 0) this->h = 12;
        else this->h = h;
        this->m = m;
        this->s = s;
        validarPeriodo(p);
        validarTiempo(this->h, this->m, this->s);
        this->periodo = p;
    }
//Ahora laas funciones que pide, las de modificar cada cosa individualmente y despues las de get
    void ponerHora(int h) {
        if (h == 0) h = 12;
        validarTiempo(h, m, s);
        this->h = h;
    }
    void ponerMin(int m) {
        validarTiempo(h, m, s);
        this->m = m;
    }
    void ponerSeg(int s) {
        validarTiempo(h, m, s);
        this->s = s;
    }
    void ponerPeriodo(const string& p) {
         validarPeriodo(p);
         this->periodo = p;
    }

    int getHora() const { return h; } //Declaro const porque no van a ser metodos que modigican solo informan 
    int getMinutos() const { return m; }
    int getSegundos() const { return s; }
    string getPeriodo() const { return periodo; }

    void mostrarTiempo() const {
        cout << setfill('0') << setw(2) << h << "h, "
             << setw(2) << m << "m, "
             << setw(2) << s << "s " << periodo << endl;
    }

    void mostrar24() const {
        int h24 = h % 12;
        if (periodo == "p.m.") h24 += 12;
        if (periodo == "a.m." && h == 12) h24 = 0;

        cout << setfill('0') << setw(2) << h24 << ":"
             << setw(2) << m << ":"
             << setw(2) << s << endl;
    }
};


