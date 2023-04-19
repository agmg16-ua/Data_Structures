#include <iostream>
#include "tabbcom.h"

using namespace std;

//---------------------------TABBCOM-----------------------------

//----PRIVATE----

//----PUBLIC----
TABBCom::TABBCom() {
    nodo = NULL;
}

TABBCom::TABBCom(TABBCom &abbCom) {
    nodo = new TNodoABB(*abbCom.nodo);
}

TABBCom::~TABBCom() {
    delete[] nodo;
}

TABBCom &TABBCom::operator=(TABBCom &abbCom) {
    if(this != &abbCom) {
        (*this).~TABBCom();
        this->nodo = new TNodoABB(*abbCom.nodo);
    }
}

bool TABBCom::operator==(TABBCom &abbCom) {
    if()
}


//---------------------------TNODOABB----------------------------

TNodoABB::TNodoABB():item(),iz(),de() {}

TNodoABB::TNodoABB(TNodoABB &nodoAbb):item(nodoAbb.item),iz(nodoAbb.iz),de(nodoAbb.de) {}

TNodoABB::~TNodoABB() {
    item.~TComplejo();
    iz.~TABBCom();
    de.~TABBCom();
}

TNodoABB &TNodoABB::operator=(TNodoABB &nodoAbb) {
    this->item = nodoAbb.item;
    this->de = nodoAbb.de;
    this->iz = nodoAbb.iz;
}
