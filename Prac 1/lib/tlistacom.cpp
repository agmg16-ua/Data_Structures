#include <iostream>

using namespace std;

#include "tlistacom.h"

//*************************Clase TListaNodo*************************
TListaNodo::TListaNodo():e() {
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &listaNodo):e() {
    e = listaNodo.e;
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo::~TListaNodo() {
    e = NULL;
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo& TListaNodo::operator=(const TListaNodo listaNodo) {
    if(this != &listaNodo) {
        (*this).~TListaNodo();

        this->e = listaNodo.e;
        this->anterior = listaNodo.anterior;
        this->siguiente = listaNodo.siguiente;
        
    }
}




//**************************Clase TListaPos*************************
TListaPos::TListaPos() {
    pos = NULL;
}

TListaPos::TListaPos(const TListaPos &listaPos) {
    (*this).pos = listaPos.pos;
} 

TListaPos::~TListaPos() {
    pos = NULL;
}

TListaPos& TListaPos::operator=(const TListaPos &listaPos) {
    if(this != &listaPos) {
        (*this).~TListaPos();

        (*this).pos = listaPos.pos;
    }

    return (*this);
}

bool TListaPos::operator==(const TListaPos &listaPos) {
    if(this->pos == listaPos.pos) {
        return true;
    }

    return false;
}

bool TListaPos::operator!=(const TListaPos &listaPos) {
    if(this->pos == listaPos.pos) {
        return false;
    }

    return true;
}

TListaPos TListaPos::Anterior() {
    TListaPos aux;

    aux.pos = this->pos->anterior;

    return aux;
}

TListaPos TListaPos::Siguiente() {
    TListaPos aux;

    aux.pos = this->pos->siguiente;

    return aux;
}

bool TListaPos::EsVacia() {
    if(pos==NULL) {
        return true;
    }

    return false;
}


 

//**************************Clase TListaCom*************************
TListaCom::TListaCom() {
    primero = NULL;
    ultimo = NULL;
}

TListaCom::TListaCom(const TListaCom &listCom) {
    this->primero = listCom.primero;
    this->ultimo = listCom.ultimo;
}

TListaCom::~TListaCom() {
    primero = NULL;
    ultimo = NULL;
}

TListaCom& TListaCom::operator=(const TListaCom &listCom) {
    if(this != &listCom) {
        (*this).~TListaCom();

        this->primero = listCom.primero;
        this->ultimo = listCom.ultimo;
    }

    return (*this);
}

bool TListaCom::operator==(const TListaCom &listCom) {
    if(this->primero == listCom.primero && this->ultimo == listCom.ultimo) {
        return true;
    }

    return false;
}

bool TListaCom::operator!=(const TListaCom &listCom) {
    if(this->primero == listCom.primero && this->ultimo == listCom.ultimo) {
        return false;
    }

    return true;
}

TListaCom TListaCom::operator+(const TListaCom &listaCom) {
    TListaCom aux;
    
    aux.primero = this->primero;
    aux.ultimo = listaCom.ultimo;

    return aux;
}

TListaCom TListaCom::operator-(const TListaCom &listaCom) {

}

bool TListaCom::EsVacia() {
    if(this->primero == NULL) {
        return true;
    }

    return false;
}

bool TListaCom::InsCabeza(const TComplejo &complejo) {

}

bool TListaCom::InsertarI(const TComplejo &complejo, const TListaPos &listaPos) {

}

bool TListaCom::InsertarD(const TComplejo &complejo, const TListaPos &listaPos) {

}

bool TListaCom::Borrar(const TComplejo &complejo) {

}

bool TListaCom::BorrarTodos(const TComplejo &complejo) {

}

bool TListaCom::Borrar(const TListaPos &listaPos) {

}

TComplejo TListaCom::Obtener(const TListaPos &listaPos) {

}

bool TListaCom::Buscar(const TComplejo &complejo) {

}

int TListaCom::Longitud() {
    int longitud = 0;
    for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente()) {
        longitud++;
    }

    return longitud;

}

TListaPos TListaCom::Primera() {
    TListaPos aux;

    if(!this->EsVacia()) {
        aux.pos = primero;
    }

    return aux;
}

TListaPos TListaCom::Ultima() {
    TListaPos aux;

    if(!this->EsVacia()) {
        aux.pos = ultimo;
    }

    return aux;
}


