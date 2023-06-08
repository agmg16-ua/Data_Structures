#include <iostream>
#include "tabbcom.h"
#include <queue>

using namespace std;

//---------------------------TABBCOM-----------------------------

//----PRIVATE----

void TABBCom::InordenAux(TVectorCom &vector, int &posicion) {
    if(posicion <= vector.Tamano()) {
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
}

void TABBCom::PreordenAux(TVectorCom &vector, int &posicion) {
    if(posicion <= vector.Tamano()) {
        if(this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {

            vector[posicion] = this->Raiz();
        
        } else if (this->nodo->iz.EsVacio()) {

            vector[posicion] = this->Raiz();
            posicion++;
            this->nodo->de.PreordenAux(vector, posicion);

        } else if (this->nodo->de.EsVacio()) {

            vector[posicion] = this->Raiz();
            posicion++;
            this->nodo->iz.PreordenAux(vector, posicion);
            
        } else {

            vector[posicion] = this->Raiz();
            posicion++;
            this->nodo->iz.PreordenAux(vector, posicion);
            posicion++;
            this->nodo->de.PreordenAux(vector, posicion);

        }
    }
}

void TABBCom::PostordenAux(TVectorCom &vector, int &posicion) {
    if(posicion <= vector.Tamano()) {
        if(this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {

            vector[posicion] = this->Raiz();
        
        } else if (this->nodo->iz.EsVacio()) {

            this->nodo->de.PostordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();

        } else if (this->nodo->de.EsVacio()) {

            this->nodo->iz.PostordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();
            
        } else {

            this->nodo->iz.PostordenAux(vector, posicion);
            posicion++;
            this->nodo->de.PostordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();

        }
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
    if(nodo != NULL) {
        delete nodo;
        nodo = NULL;
    }
}

TABBCom &TABBCom::operator=(TABBCom &abbCom) {
    if(this != &abbCom) {
        (*this).~TABBCom();

        if(abbCom.EsVacio()) {
            this->nodo = NULL;
        } else {
            this->nodo = new TNodoABB(*abbCom.nodo);
        }
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
        return true;
    }
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
    TNodoABB *arbolBorrar;

    if(this->EsVacio()) {
        return false;
    }

    if(!this->Buscar(complejo)) {
        return false;
    }

    if(this->Raiz() == complejo) {   
        if(this->nodo->iz.EsVacio() && this->nodo->de.EsVacio()) {
            this->~TABBCom();
            return true;
        }

        if(this->nodo->iz.EsVacio()) {
            arbolBorrar = this->nodo;
            this->nodo = this->nodo->de.nodo;
            arbolBorrar->de.nodo = NULL;
            return true;
        }

        if(this->nodo->de.EsVacio()) {
            arbolBorrar = this->nodo;
            this->nodo = this->nodo->iz.nodo;
            arbolBorrar->iz.nodo = NULL;
            return true;
        }

        TVectorCom vectorIz = this->nodo->iz.Inorden();
        
        TComplejo mayor = vectorIz[1];

        for(int i=1; i<=vectorIz.Tamano(); i++) {
            if(vectorIz[i].Mod() > mayor.Mod()) {
                mayor = vectorIz[i];
            }
        }

        this->nodo->item = mayor;

        return this->nodo->iz.Borrar(mayor);

    } else {
        return (this->nodo->iz.Borrar(complejo) || this->nodo->de.Borrar(complejo));
    }

} 

bool TABBCom::Buscar(const TComplejo &complejo) {
    TVectorCom arbolb = this->Preorden();

    return arbolb.ExisteCom(complejo);
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
    if(vectorCom.Tamano() > 0) {
        this->InordenAux(vectorCom, posicion);
    }
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
    TVectorCom niveles(this->Nodos());
    queue<TNodoABB *> cola;

    int contadorPos = 1;

    cola.push(this->nodo);


    while(contadorPos <= this->Nodos()) {
        TNodoABB *actual = cola.front();
        cola.pop();

        niveles[contadorPos] = actual->item;

        if(!actual->iz.EsVacio()) {
            cola.push(actual->iz.nodo);
        }

        if(!actual->de.EsVacio()) {
            cola.push(actual->de.nodo);
        }

        contadorPos++;
    }

    return niveles;
}

//-------------------------------------------------------------------------------------------------------------------------

int TABBCom::MulticaminoAux(TComplejo com1, TComplejo com2) {
    if(com1 == com2) {
        return 1;
    }

    if(this->Raiz() == com1) {
        if(com2 > com1) {
            if(this->nodo->de.Buscar(com2)) {
                return this->nodo->de.MulticaminoAux(this->nodo->de.Raiz(), com2);
            }
            else {
                return 0;
            }
        }
        else {
            if(this->nodo->iz.Buscar(com2)) {
                return this->nodo->iz.MulticaminoAux(this->nodo->iz.Raiz(), com2);
            }
            else {
                return 0;
            }
        }
    } 
    else {
        if(com1 > this->Raiz()) {
            return this->nodo->de.MulticaminoAux(com1, com2);
        }
        else {
            return this->nodo->iz.MulticaminoAux(com1, com2);
        }
    }
}

int* TABBCom::Multicamino(TListaCom &lista1, TListaCom &lista2) {
    int* arrayEnteros;
    int tam = 0;
    if(lista1.EsVacia() && lista2.EsVacia()) {
        arrayEnteros = NULL;
        return arrayEnteros;
    } 
    else if(lista1.EsVacia()) {
        arrayEnteros = new int[lista2.Longitud()];
        tam = lista2.Longitud();
    } 
    else if(lista2.EsVacia()) {
        arrayEnteros = new int[lista1.Longitud()];
        tam = lista1.Longitud();
    }
    else {
        if(lista1.Longitud() > lista2.Longitud()) {
            arrayEnteros = new int[lista1.Longitud()];
            tam = lista1.Longitud();
        }
        else {
            arrayEnteros = new int[lista2.Longitud()];
            tam = lista2.Longitud();
        }
    }

    TListaPos pos1 = lista1.Primera();
    TListaPos pos2 = lista2.Primera();

    for(int i=0; i<tam; i++) {
        TComplejo com1;
        TComplejo com2;
        bool tiene1 = false, tiene2 = false;
        if(!pos1.EsVacia()) {
            com1 = lista1.Obtener(pos1);
            pos1 = pos1.Siguiente();
            tiene1 = true;
        }

        if(!pos2.EsVacia()) {
            com2 = lista2.Obtener(pos2);
            pos2 = pos2.Siguiente();
            tiene2 = true;
        }

        if(tiene1 && tiene2) {
            if(this->Buscar(com1)) {
                arrayEnteros[i] = this->MulticaminoAux(com1, com2);
            }
            else {
                arrayEnteros[i] = 0;
            }
        }
        else {
            arrayEnteros[i] = 0;
        }

    }

    return arrayEnteros;

}

//--------------------------------------------------------------------------------------------------------------------------

ostream & operator<<(ostream &os, TABBCom &abbCom) {
    os << abbCom.Niveles();
    return os;
}


//---------------------------TNODOABB----------------------------

TNodoABB::TNodoABB():item(),iz(),de() {}

TNodoABB::TNodoABB(TNodoABB &nodoAbb):item(nodoAbb.item),iz(nodoAbb.iz),de(nodoAbb.de) {}

TNodoABB::~TNodoABB() {
    /*item.~TComplejo();
    iz.~TABBCom();
    de.~TABBCom();*/
}

TNodoABB &TNodoABB::operator=(TNodoABB &nodoAbb) {
    this->item = nodoAbb.item;
    this->de = nodoAbb.de;
    this->iz = nodoAbb.iz;

    return (*this);
}