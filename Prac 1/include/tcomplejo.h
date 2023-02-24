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
        //Constructores
        TComplejo();
        TComplejo(double);
        TComplejo(double, double);
        TComplejo(const TComplejo&);
        ~TComplejo();

        //Operadores
        TComplejo& operator= (const TComplejo&);
        TComplejo operator+ (const TComplejo&);
        TComplejo operator- (const TComplejo&);
        TComplejo operator* (const TComplejo&);
        TComplejo operator+ (double);
        TComplejo operator- (double);
        TComplejo operator* (double);
        bool operator== (const TComplejo&);
        bool operator!= (const TComplejo&);
        
        //Otros metodos
        double Re();
        double Im();
        void Re(double);
        void Im(double);
        double Arg(void);
        double Mod(void);
};
#endif