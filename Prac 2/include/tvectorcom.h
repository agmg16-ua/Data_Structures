#ifndef _TVECTORCOM_H_
#define _TVECTORCOM_H_

#include <iostream>

using namespace std;

#include "tcomplejo.h"

class TVectorCom{

    //Funciones amigas
    friend ostream& operator<<(ostream &, TVectorCom &);

    private:
        //Objetos de tipo TComplejo
        TComplejo *c;
        
        //Tamanyo del vector
        int tamano;

        //Variable error
        TComplejo error;
    
    public:
        //Constructores
        TVectorCom();
        TVectorCom(int);
        TVectorCom(const TVectorCom &);
        ~TVectorCom();

        //Operadores
        TVectorCom & operator=(const TVectorCom &);
        bool operator==(const TVectorCom &);
        bool operator!=(const TVectorCom &);
        TComplejo & operator[](int);
        TComplejo operator[](int) const;

        //Otros metodos
        int Tamano();
        int Ocupadas();
        bool ExisteCom(const TComplejo &);
        void MostrarComplejos(double);
        bool Redimensionar(int);
};
#endif