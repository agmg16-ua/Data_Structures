#include <iostream>
#include "tabbcom.h"
#include <queue>

using namespace std;

//---------------------------TABBCOM-----------------------------

//----PRIVATE----

void TABBCom::InordenAux(TVectorCom &vector, int &posicion) {
    if(this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {

        vector[posicion] = this->Raiz();
    
    } else if (this->nodo->iz.EsVacio()) {

        vector[posicion] = this->Raiz();
        posicion++;
        this->nodo->de.InordenAux(vector, posicion);

    } else if (this->nodo->de.EsVacio()) {

        this->nodo->iz.InordenAux(vector, posicion);
        posicion++;
        vector[posicion] = this->Raiz();

    } else {

        this->nodo->iz.InordenAux(vector, posicion);
        posicion++;
        vector[posicion] = this->Raiz();
        posicion++;
        this->nodo->de.InordenAux(vector, posicion);

    }
}

void TABBCom::PreordenAux(TVectorCom &vector, int &posicion) {
    if(this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {

        vector[posicion] = this->Raiz();
    
    } else if (this->nodo->iz.EsVacio()) {

        vector[posicion] = this->Raiz();
        posicion++;
        this->nodo->de.InordenAux(vector, posicion);

    } else if (this->nodo->de.EsVacio()) {

        vector[posicion] = this->Raiz();
        posicion++;
        this->nodo->iz.InordenAux(vector, posicion);
        
    } else {

        vector[posicion] = this->Raiz();
        posicion++;
        this->nodo->iz.InordenAux(vector, posicion);
        posicion++;
        this->nodo->de.InordenAux(vector, posicion);

    }
}

void TABBCom::PostordenAux(TVectorCom &vector, int &posicion) {
    if(this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {

        vector[posicion] = this->Raiz();
    
    } else if (this->nodo->iz.EsVacio()) {

        this->nodo->de.InordenAux(vector, posicion);
        posicion++;
        vector[posicion] = this->Raiz();

    } else if (this->nodo->de.EsVacio()) {

        this->nodo->iz.InordenAux(vector, posicion);
        posicion++;
        vector[posicion] = this->Raiz();
        
    } else {

        this->nodo->iz.InordenAux(vector, posicion);
        posicion++;
        this->nodo->de.InordenAux(vector, posicion);
        posicion++;
        vector[posicion] = this->Raiz();

    }
}

//----PUBLIC----
TABBCom::TABBCom() {
    nodo = NULL;
}

TABBCom::TABBCom(TABBCom &abbCom) {
    if(abbCom.EsVacio()) {
        this->nodo = NULL;
    } else {
        nodo = new TNodoABB(*abbCom.nodo);
    }
}

TABBCom::~TABBCom() {
    nodo = NULL;
}

TABBCom &TABBCom::operator=(TABBCom &abbCom) {
    if(this != &abbCom) {
        (*this).~TABBCom();
        this->nodo = new TNodoABB(*abbCom.nodo);
    }

    return (*this);
}

bool TABBCom::operator==(TABBCom &abbCom) {
    TVectorCom thisOrder = this->Preorden();
    TVectorCom abbComOrder = abbCom.Preorden();

    if(thisOrder.Tamano() == abbComOrder.Tamano()) {
        for(int i=1; i<thisOrder.Tamano(); i++) {
            if(!this->Buscar(abbComOrder[i])) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}

bool TABBCom::EsVacio() const{
    if(this->nodo == NULL) {
        cout << "Vacio" << endl;
        return true;
    }
    cout << "Vacio" << endl;
    return false;
}

bool TABBCom::Insertar(TComplejo &complejo) {
    if(this->Buscar(complejo)) {
        return false;
    }
    
    if(this->EsVacio()) {
        nodo = new TNodoABB();
        nodo->item = complejo;
        return true;
    }

    if(this->Raiz().Mod() > complejo.Mod() || 
        (this->Raiz().Mod() == complejo.Mod() && this->Raiz().Re() > complejo.Re()) || 
        (this->Raiz().Mod() == complejo.Mod() && this->Raiz().Re() == complejo.Re() && this->Raiz().Im() > complejo.Im())) {
        return this->nodo->iz.Insertar(complejo);
    } else {
        return this->nodo->de.Insertar(complejo);
    }

} 

bool TABBCom::Borrar(TComplejo &complejo) {
    return true;
} 

bool TABBCom::Buscar(TComplejo &complejo) {
    TVectorCom arbolb = this->Preorden();
    for(int i=1; i<arbolb.Tamano(); i++) {
        if(complejo == arbolb[i]) {
            return true;
        }
    }

    return false;
} 

TComplejo TABBCom::Raiz() const{
    if(this->EsVacio()) {
        return TComplejo();
    }

    return this->nodo->item;
}

int TABBCom::Altura() const{
    if(this->EsVacio()) {
        return 0;
    }

    return max(this->nodo->iz.Altura(), this->nodo->de.Altura()) + 1;

}

int TABBCom::Nodos() const{
    if(this->EsVacio()) {
        return 0;
    }

    return 1 + this->nodo->iz.Nodos() + this->nodo->de.Nodos();

}

int TABBCom::NodosHoja() const{
    if(this->EsVacio()) {
        return 0;
    }

    if(this->nodo->iz.EsVacio() && this->nodo->iz.EsVacio()) {
        return 1;
    } else {
        return this->nodo->iz.NodosHoja() + this->nodo->de.NodosHoja();
    }

}

TVectorCom TABBCom::Inorden() {
    int posicion = 1;
    TVectorCom vectorCom(this->Nodos());
    this->InordenAux(vectorCom, posicion);
    return vectorCom;
}

TVectorCom TABBCom::Preorden() {
    int posicion = 1;
    TVectorCom vectorCom(this->Nodos());
    this->PreordenAux(vectorCom, posicion);
    return vectorCom;
} 

TVectorCom TABBCom::Postorden() {
    int posicion = 1;
    TVectorCom vectorCom(this->Nodos());
    this->PreordenAux(vectorCom, posicion);
    return vectorCom;
}

TVectorCom TABBCom::Niveles() {
    return TVectorCom();
}

ostream & operator<<(ostream &os, TABBCom &abbCom) {
    return os;
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

    return (*this);
}
