#include <iostream>

using namespace std;

#include "tvectorcom.h"

TVectorCom::TVectorCom() {
    c = NULL;
    tamano = 0;
}

TVectorCom::TVectorCom(int tam) {
    if(tam<0) {
        TVectorCom();
    } else {
        TComplejo complejo;
        tamano = tam;
        c = new TComplejo[tamano];
        for(int i=0; i<tamano; i++) {
            c[i] = complejo;
        }
    }
}

TVectorCom::TVectorCom(const TVectorCom &vecCom) {
    c = new TComplejo[vecCom.tamano];
    tamano = vecCom.tamano;
    c = new TComplejo[tamano];
    for(int i=0; i<tamano; i++) {
        c[i] = vecCom.c[i];
    }
}

TVectorCom::~TVectorCom() {
    delete[] c;
    c = NULL;
    tamano = 0;
}


TVectorCom & TVectorCom::operator=(const TVectorCom &vecCom) {

    if(this != &vecCom) {
        (*this).~TVectorCom();

        c = new TComplejo[vecCom.tamano];
        tamano = vecCom.tamano;

        for(int i=0; i<tamano; i++) {
            c[i] = vecCom.c[i];
        }
    }

    return (*this);
}


bool TVectorCom::operator==(const TVectorCom &vecCom) {
    if(tamano != vecCom.tamano) {
        return false;
    }

    for(int i=0; i<tamano; i++) {
        if(c[i] != vecCom.c[i]) {
            return false;
        }
    }
    return true;
}

bool TVectorCom::operator!=(const TVectorCom &vecCom) {
    if(tamano != vecCom.tamano) {
        return true;
    }

    for(int i=0; i<tamano; i++) {
        if(c[i] != vecCom.c[i]) {
            return true;
        }
    }
    return false;
}

TComplejo &TVectorCom::operator[](int pos) {

    if(pos<=tamano && pos>0) {
        return c[pos-1];
    }

    return error;
    
}

TComplejo TVectorCom::operator[](int pos) const {
    TComplejo complejo;

    if(pos<=tamano && pos>0) {
        return c[pos-1];
    }

    return complejo;
}


int TVectorCom::Tamano() {
    return tamano;
}

int TVectorCom::Ocupadas() {
    int contador = 0;

    TComplejo vacio;

    for(int i=0; i<tamano; i++) {
        if(c[i]==vacio) {
            contador++;
        }
    }

    return contador;
    
}

bool TVectorCom::ExisteCom(const TComplejo &complejo) {
    bool existe = false;

    for(int i=0; i<this->tamano; i++) {
        if(c[i]==complejo) {
            existe = true;
        }
    }

    return existe;
}

void TVectorCom::MostrarComplejos(double real) {
    bool coma = false; //Control para no poner la coma en el primer elemento

    cout << '[';
    for(int i=0; i<this->tamano; i++ ) {
        if(c[i].Re()==real) {
            if(coma==true) {
                cout << ", ";
            }

            cout << c[i]; 
            coma = true;
        }
    }
    cout << ']';
}

bool TVectorCom::Redimensionar(int tam) {
    if(tam<=0) {
        return false;
    }

    if(tam==tamano) {
        return false;
    }

    if(tam < tamano) {
        TVectorCom aux(tam);

        for(int i=0; i<tam; i++) {
            aux.c[i] = c[i];
        }
        
        delete[] c;

        tamano = tam;
        c = aux.c;

        aux.~TVectorCom();

        return true;
    }

    if(tam > tamano) {
        TVectorCom aux(tam);
        TComplejo complejo;
        
        for(int i=0; i<tamano; i++) {
            aux.c[i] = c[i];
        }

        delete[] c;

        for(int i=tamano; i<tam; i++) {
            aux.c[i] = complejo;
        }

        tamano = tam;

        c[tamano];

        for(int i=0; i<tamano; i++) {
            c[i] = aux.c[i];
        }

        aux.~TVectorCom();


        return true;
    }

    return false;

}

ostream& operator<<(ostream &o, TVectorCom& obj) {
    bool coma = false; //controlas coma para evitar el primer elemento

    o << '[';
    for(int i=0; i<obj.tamano; i++) {
        if(coma==true) {
            o << ", ";
        }
        o << '(' << i+1 << ") " << obj.c[i];
        coma = true;
    }
    o << ']';

    return o;
}