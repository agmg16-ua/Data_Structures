#ifndef _TVECTORCOM_H_
#define _TVECTORCOM_H_

#include <iostream>

using namespace std;

#include "tcomplejo.h"

class TVectorCom{

    friend ostream& operator<<(ostream &, TVectorCom &);

    private:
        //Objetos de tipo TComplejo
        TComplejo *c;
        
        //Tamanyo del vector
        int tamano;
    
    public:
        TVectorCom();
        TVectorCom(int);
        TVectorCom(const TVectorCom &);
        ~TVectorCom();
        TVectorCom & operator=(const TVectorCom &);

        //Operadores
        bool operator==(const TVectorCom &);
        bool operator!=(const TVectorCom &);
        TComplejo & operator[](int);
        TComplejo operator[](int) const;

        int Tamano();
        int Ocupadas();
        bool ExisteCom(const TComplejo &);
        void MostrarComplejos(double);
        bool Redimensionar(int);
};
#endif