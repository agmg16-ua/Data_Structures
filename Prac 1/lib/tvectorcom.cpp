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
    this->tamano = vecCom.tamano;
    for(int i=0; i<tamano; i++) {
        c[i] = vecCom[i];
    }
}

TVectorCom::~TVectorCom() {
    //delete[] c;
    //c = NULL;
    for(int i=0; i<tamano; i++) {
        c[i].~TComplejo();
    }
    tamano = 0;
}


TVectorCom & TVectorCom::operator=(const TVectorCom &vecCom) {
    TVectorCom aux[vecCom.tamano];

    for(int i=0; i<this->tamano; i++) {
        (*aux).c[i]= vecCom.c[i];
    }

    return (*aux);
}


bool TVectorCom::operator==(const TVectorCom &vecCom) {

}

bool TVectorCom::operator!=(const TVectorCom &vecCom) {

}

TComplejo & TVectorCom::operator[](int pos) {

}

TComplejo TVectorCom::operator[](int pos) const {

}


int TVectorCom::Tamano() {
    return tamano;
}

int TVectorCom::Ocupadas() {

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