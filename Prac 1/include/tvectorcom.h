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
        TVectorCom(TVectorCom &);
        ~TVectorCom();
        TVectorCom & operator=(TVectorCom &);

        bool operator==(TVectorCom &);
        bool operator!=(TVectorCom &);
};
#endif