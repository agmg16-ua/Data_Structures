#ifndef _TCOMPLEJO_H_
#define _TCOMPLEJO_H_

#include <iostream>

using namespace std;

class TComplejo{

    //funciones amigas
    friend ostream& operator<<(ostream &, TComplejo &);
    friend TComplejo operator+ (double , TComplejo&);
    friend TComplejo operator- (double , TComplejo&);
    friend TComplejo operator* (double , TComplejo&);

    private:
        //parte real
        double re;

        //parte imaginaria
        double im;
    
    public:
        //se inicializan las partes real e imaginaria a 0
        TComplejo();

        //se pasa el valor de la parte real
        TComplejo(double);

        //se pasan la parte real e imaginaria
        TComplejo(double, double);

        //constructor de copia
        TComplejo(const TComplejo&);

        //destructor
        ~TComplejo();

        //sobrecarga del operador de asignación
        TComplejo& operator= (const TComplejo&);

        //operadores
        TComplejo operator+ (const TComplejo&);
        TComplejo operator- (const TComplejo&);
        TComplejo operator* (const TComplejo&);
        TComplejo operator+ (double);
        TComplejo operator- (double);
        TComplejo operator* (double);

        bool operator== (const TComplejo&);
        bool operator!= (const TComplejo&);
        
        //devuelve la parte real/imaginaria;
        double Re();
        double Im();

        //modifica la parte real/imaginaria;
        void Re(double);
        void Im(double);

        //calcula el argumento(radianes)/Módulo
        double Arg(void);
        double Mod(void);
};
#endif