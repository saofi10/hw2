#include "punto3.hpp"
class Numero {
    public:
        //metodos puros a colocar tambien en derivadas
        virtual Numero* sumar(const Numero& otro) const = 0;
        virtual Numero* restar(const Numero& otro) const = 0;
        virtual Numero* multiplicar(const Numero& otro) const = 0;
        virtual Numero* dividir(const Numero& otro) const = 0;
        virtual string toString() const = 0;
    
        //operadores sobrecargados, lo comentado en el hpp
        Numero* operator+(const Numero& otro) const { return sumar(otro); }
        Numero* operator-(const Numero& otro) const { return restar(otro); }
        Numero* operator*(const Numero& otro) const { return multiplicar(otro); }
        Numero* operator/(const Numero& otro) const { return dividir(otro); }

        //destructor virtual
        virtual ~Numero() {}
    };
    
    // Clase Entero
class Entero : public Numero {
    private:
        int valor;
    
    public://constructor
        Entero(int valor) : valor(valor) {}
    
        //metodos concretos
        Numero* sumar(const Numero& otro) const override {
            const Entero& o = dynamic_cast<const Entero&>(otro);
            return new Entero(valor + o.valor);
        }
    
        Numero* restar(const Numero& otro) const override {
            const Entero& o = dynamic_cast<const Entero&>(otro);
            return new Entero(valor - o.valor);
        }
    
        Numero* multiplicar(const Numero& otro) const override {
            const Entero& o = dynamic_cast<const Entero&>(otro);
            return new Entero(valor * o.valor);
        }
    
        Numero* dividir(const Numero& otro) const override {
            const Entero& o = dynamic_cast<const Entero&>(otro);
            if (o.valor == 0) throw runtime_error("Error: Division por cero");
            return new Entero(valor / o.valor);
        }
    
        string toString() const override {
            return to_string(valor);
        }
    };

    class Real : public Numero {
        private:
            double valor;
        
        public://constructor
            Real(double valor) : valor(valor) {}
        
            //metodos concretos
            Numero* sumar(const Numero& otro) const override {
                const Real& o = dynamic_cast<const Real&>(otro);
                return new Real(valor + o.valor);
            }
        
            Numero* restar(const Numero& otro) const override {
                const Real& o = dynamic_cast<const Real&>(otro);
                return new Real(valor - o.valor);
            }
        
            Numero* multiplicar(const Numero& otro) const override {
                const Real& o = dynamic_cast<const Real&>(otro);
                return new Real(valor * o.valor);
            }
        
            Numero* dividir(const Numero& otro) const override {
                const Real& o = dynamic_cast<const Real&>(otro);
                if (o.valor == 0) throw runtime_error("Error: Division por cero");
                return new Real(valor / o.valor);
            }
        
            string toString() const override {
                return to_string(valor);
            }
        };

class Complejo : public Numero {
    private:
        double parteReal;
        float parteImaginaria;
    
    public://constructor
        Complejo(double parteReal,float parteImaginaria) : parteReal(parteReal),parteImaginaria(parteImaginaria) {}
    
        //metodos concretos
        Numero* sumar(const Numero& otro) const override {
            const  Complejo& o = dynamic_cast<const Complejo&>(otro);
            return new Complejo(parteReal + o.parteReal, parteImaginaria + o.parteImaginaria);
        }

         //metodos concretos
        Numero* restar(const Numero& otro) const override {
            const Complejo& o = dynamic_cast<const Complejo&>(otro);
            return new Complejo(parteReal - o.parteReal, parteImaginaria - o.parteImaginaria);
        }
    
        Numero* multiplicar(const Numero& otro) const override { //z1.z2= (ac-bd)+(ad+bc)i ,,,si z1= a+bi z2= c+di
            const Complejo& o = dynamic_cast<const Complejo&>(otro);
            double nuevoReal = parteReal * o.parteReal - parteImaginaria * o.parteImaginaria;
            double nuevoImaginario = parteReal * o.parteImaginaria + parteImaginaria * o.parteReal;
            return new Complejo(nuevoReal, nuevoImaginario);
        }

        Numero* dividir(const Numero& otro) const override {//z1/z2= z1.conjz2)/|z2|^2
            const Complejo& o = dynamic_cast<const Complejo&>(otro);
            double denominador = o.parteReal * o.parteReal + o.parteImaginaria * o.parteImaginaria;
            if (denominador == 0) throw runtime_error("Error: division por cero");
    
            double nuevoReal = (parteReal * o.parteReal + parteImaginaria * o.parteImaginaria) / denominador;
            double nuevoImaginario = (parteImaginaria * o.parteReal - parteReal * o.parteImaginaria) / denominador;
            return new Complejo(nuevoReal, nuevoImaginario);
        }
        string toString() const override {
            ostringstream os;
            os << parteReal << " + " << parteImaginaria << "i";
            return os.str();
        }
    };
