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

//-----------------------------------------METODO EXAMEN-------------------------------------------------

//Metodo auxiliar para buscar el complejo
void TABBCom::BuscaVecABBAux(TComplejo complejo, TListaCom &listacom) {
    if(this->Raiz() == complejo) { //Si es la raiz...
        if(listacom.EsVacia()) { //Si esta vacia la lista, se inserta en cabeza. Si no, a la derecha del ultimo
            listacom.InsCabeza(complejo);
        }
        else {
            listacom.InsertarD(complejo, listacom.Ultima());
        }
    }
    else {
        if(complejo > this->Raiz()) { //Si el complejo es mayor que la raiz...
            this->nodo->de.BuscaVecABBAux(complejo, listacom); //Llamada recursiva para buscar a la derecha del arbol el complejo
            listacom.InsertarD(this->Raiz(), listacom.Ultima()); //Se inserta a la derecha el elemento actual
        }
        else {
            this->nodo->iz.BuscaVecABBAux(complejo, listacom); //Llamada recursiva para buscar a la izquierda del arbol el complejo
            listacom.InsertarD(this->Raiz(), listacom.Ultima()); //Se inserta a la derecha el elemento actual
        }
    }

}


/*
Cuando se van a insertar elementos en la lista, se realiza primero la llamada recursiva hasta encontrar
el complejo, y despues se inserta el elemento. De esta manera se inserta la el complejo y cuando vuelve de 
las llamadas recursivas se va insertando el camino de manera inversa
*/
TListaCom TABBCom::BuscaVecABB(TVectorCom &vectorcom) {
    TListaCom listacom;
    if(vectorcom.Tamano() == 0) { //Si el tamaño del vector es 0, esta vacio y se devuelve la lista vacia
        return listacom;
    }

    if(this->EsVacio()) { //Si el arbol esta vacio, se devuelve la lista vacia
        return listacom;
    }

<<<<<<< HEAD:EXAMEN JUNIO/lib/tabbcom.cpp
    for(int i=1; i<=vectorcom.Tamano(); i++) {
        TComplejo complejo = vectorcom[i];
        if(this->Buscar(complejo)) {
            if(this->Raiz() == complejo) {
                if(listacom.EsVacia()) {
=======
    for(int i=1; i<=vectorcom.Tamano(); i++) { //Se recorre el vector
        TComplejo complejo = vectorcom[i]; //Se guarda el complejo del vector en una variable por comodidad
        if(this->Buscar(complejo)) { //Si existe el complejo en el arbol...
            if(this->Raiz() == complejo) { //Si la raiz es el complejo...
                if(listacom.EsVacia()) { //Si la lista esta vacia, se inserta en cabeza, si no se inserta a la derecha del ultimo
>>>>>>> cb6f317e5c1ae9e9bb00e4ff4e9bda7573564de0:Examenes/Junio 2023/EXAMEN/lib/tabbcom.cpp
                    listacom.InsCabeza(complejo);
                }
                else {
                    listacom.InsertarD(complejo, listacom.Ultima());
                }
            }
            else if(complejo > this->Raiz()) { //Si el complejo es mayor que la raiz...
                this->nodo->de.BuscaVecABBAux(complejo, listacom); //Metodo auxiliar para buscar el complejo a la derecha del arbol
                listacom.InsertarD(this->Raiz(), listacom.Ultima()); //Se inserta la raiz
            }
            else {
                this->nodo->iz.BuscaVecABBAux(complejo, listacom); //Metodo auxiliar para biscar el complejo a la izquierda del arbol
                listacom.InsertarD(this->Raiz(), listacom.Ultima()); //Se inserta la raiz
            }
        }
    }

    return listacom; //Se devuelve la lista

}


//-------------------------------------------------------------------------------------------------------

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