#ifndef _TVECTORCOM_H_
#define _TVECTORCOM_H_

#include <iostream>

using namespace std;

#include "tcomplejo.h"

class TVectorCom{

    private:
        TComplejo c;
        int tamano;
    
    public:
        TVectorCom();
        TVectorCom(int);
        TVectorCom(const TVectorCom &);
        ~TVectorCom();
        TVectorCom & operator=(const TVectorCom &);

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