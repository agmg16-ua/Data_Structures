#include <iostream>
#include "tavlcom.h"
#include <queue>

using namespace std;

//---------------------------TAAVLCOM-----------------------------

//----PRIVATE----

void TAVLCom::InordenAux(TVectorCom &vector, int &posicion) {
    if(posicion <= vector.Tamano()) {
        if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()) {

            vector[posicion] = this->Raiz();
        
        } else if (this->raiz->iz.EsVacio()) {

            vector[posicion] = this->Raiz();
            posicion++;
            this->raiz->de.InordenAux(vector, posicion);

        } else if (this->raiz->de.EsVacio()) {

            this->raiz->iz.InordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();

        } else {

            this->raiz->iz.InordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();
            posicion++;
            this->raiz->de.InordenAux(vector, posicion);

        }
    }
}

void TAVLCom::PreordenAux(TVectorCom &vector, int &posicion) {
    if(posicion <= vector.Tamano()) {
        if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()) {

            vector[posicion] = this->Raiz();
        
        } else if (this->raiz->iz.EsVacio()) {

            vector[posicion] = this->Raiz();
            posicion++;
            this->raiz->de.PreordenAux(vector, posicion);

        } else if (this->raiz->de.EsVacio()) {

            vector[posicion] = this->Raiz();
            posicion++;
            this->raiz->iz.PreordenAux(vector, posicion);
            
        } else {

            vector[posicion] = this->Raiz();
            posicion++;
            this->raiz->iz.PreordenAux(vector, posicion);
            posicion++;
            this->raiz->de.PreordenAux(vector, posicion);

        }
    }
}

void TAVLCom::PostordenAux(TVectorCom &vector, int &posicion) {
    if(posicion <= vector.Tamano()) {
        if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()) {

            vector[posicion] = this->Raiz();
        
        } else if (this->raiz->iz.EsVacio()) {

            this->raiz->de.PostordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();

        } else if (this->raiz->de.EsVacio()) {

            this->raiz->iz.PostordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();
            
        } else {

            this->raiz->iz.PostordenAux(vector, posicion);
            posicion++;
            this->raiz->de.PostordenAux(vector, posicion);
            posicion++;
            vector[posicion] = this->Raiz();

        }
    }
}

bool TAVLCom::InsertarAux(const TComplejo &complejo, bool &crece) {
    bool insertado = false;
    bool creceDer = false;
    bool creceIzq = false;

    if(this->EsVacio()) {
        this->raiz = new TNodoAVL();
        this->raiz->item = complejo;
        crece = true;
        return true;
    }

    if(this->raiz->item == complejo) {
        crece = false;
        return false;
    }

    if(this->raiz->item > complejo) {
        //cout << "entra insertar izquierda" << endl; 
        insertado = this->raiz->iz.InsertarAux(complejo, creceIzq);
    } else {
        //cout << "entra insertar derecha" << endl;
        insertado = this->raiz->de.InsertarAux(complejo, creceDer);
    }

    if(creceIzq == false && creceDer == false) { //No se añade nuevo nivel

        crece = false;

    } else if(creceIzq == true) { //Se ha añadido un nuevo nivel a la izquierda

        this->raiz->fe--;

        if(this->raiz->fe == 0) {

            crece = false;

        } else if (this->raiz->fe == -1) {

            crece = true;

        } else { //Caso de que sea -2 y por tanto hay que hacer rotacion 

            crece = false;

            if(this->raiz->iz.raiz->fe == -1) {
                //cout << "Error IzqIzq" << endl;
                this->IzqRotaIzq();
            } else {
                //cout << "Error IzqDer" << endl;
                this->IzqRotaDer();
            }

        }

    } else { //Se ha añadido un nuevo nivel a la derecha

        this->raiz->fe++;

        if(this->raiz->fe == 0) {
            crece = false;
        } else if(this->raiz->fe == 1) {
            crece = true;
        } else { //Caso de que sea 2 hay que rotar

            crece = false;

            if(this->raiz->de.raiz->fe == 1) {
                //cout << "Error DerDer" << endl;
                this->DerRotaDer();
            } else {
                //cout << "Error DerIzq" << endl;
                this->DerRotaIzq();
            }
        }
    }

    return insertado;
}

bool TAVLCom::BorrarAux(const TComplejo &complejo, bool &decrece) {
    bool borrado = false;
    bool decreceIzq = false;
    bool decreceDer = false;
    TComplejo mayor;
    TNodoAVL *nodo;
    TNodoAVL *aux;

    if(this->EsVacio()) {
        decrece = false;
        return false;
    }

    if(this->raiz->item == complejo) {
        if(this->raiz->iz.raiz == NULL && this->raiz->de.raiz == NULL) {
            delete this->raiz;
            this->raiz = NULL;
            decrece = true;
            return true;
        }

        if(this->raiz->iz.raiz == NULL) {
            nodo = this->raiz;
            this->raiz = this->raiz->de.raiz;
            nodo->de.raiz = NULL;
            delete nodo;
            decrece = true;
            return true;
        }

        //Tanto si hay izquierdo como si hay ambos, hay que sustituir la raiz por el mayor de la izquierda

        TVectorCom buscarMayor = this->raiz->iz.Inorden();

        mayor = buscarMayor[1];

        for(int i=1; i<=buscarMayor.Tamano(); i++) {
            if(buscarMayor[i] > mayor) {
                mayor = buscarMayor[i];
            }
        }

        aux = this->raiz;
        borrado = this->BorrarAux(mayor, decrece);
        aux->item = mayor;

    } else {
        if(this->raiz->item > complejo) {
            borrado = this->raiz->iz.BorrarAux(complejo, decreceIzq);
        } else {
            borrado = this->raiz->de.BorrarAux(complejo, decreceDer);
        }

        if(borrado == true) {
            if(decreceIzq == false && decreceDer == false) {
                decrece = false;
            } else {
                if(decreceIzq == true) {
                    this->raiz->fe++;

                    if(this->raiz->fe == 0) {

                        decrece = true;

                    } else if(this->raiz->fe == 1) {

                        decrece = false;

                    } else {
                        
                        if(this->raiz->de.raiz->fe == 0) {
                            this->DerRotaDer();
                            decrece = false;
                        } else if(this->raiz->de.raiz->fe == 1) {
                            this->DerRotaDer();
                            decrece = true;
                        } else {
                            this->DerRotaIzq();
                            decrece = true;
                        }

                    }

                } else {
                    this->raiz->fe--;

                    if(this->raiz->fe == 0) {

                        decrece = false;

                    } else if(this->raiz->fe == -1) {

                        decrece = true;

                    } else {

                        if(this->raiz->iz.raiz->fe == 0) {
                            this->IzqRotaIzq();
                            decrece = false;
                        } else if(this->raiz->iz.raiz->fe == 1) {
                            this->IzqRotaDer();
                            decrece = true;
                        } else {
                            this->IzqRotaIzq();
                            decrece = true;
                        }

                    }

                }
            }
        }

    }

    return borrado;
}

void TAVLCom::IzqRotaIzq() {
    TNodoAVL *derNuevaRaiz = this->raiz;
    TNodoAVL *nuevaRaiz = derNuevaRaiz->iz.raiz;
    TNodoAVL *izqDerNuevaRaiz = derNuevaRaiz->de.raiz;

    this->raiz = nuevaRaiz;
    nuevaRaiz->de.raiz = derNuevaRaiz;
    derNuevaRaiz->iz.raiz = izqDerNuevaRaiz;

    if(nuevaRaiz->fe == 0) {
        nuevaRaiz->fe = 1;
        derNuevaRaiz->fe = -1;
    } else if(nuevaRaiz->fe == -1){
        nuevaRaiz->fe = 0;
        derNuevaRaiz->fe = 0;
    }
}

void TAVLCom::IzqRotaDer() {
    TNodoAVL *derNuevaRaiz = this->raiz;
    TNodoAVL *izqNuevaRaiz = this->raiz->iz.raiz;
    TNodoAVL *nuevaRaiz = this->raiz->iz.raiz->de.raiz;
    TNodoAVL *derIzqNuevaRaiz = this->raiz->iz.raiz->de.raiz->iz.raiz;
    TNodoAVL *izqDerNuevaRaiz = this->raiz->iz.raiz->de.raiz->de.raiz;

    this->raiz = nuevaRaiz;
    nuevaRaiz->de.raiz = derNuevaRaiz;
    nuevaRaiz->iz.raiz = izqNuevaRaiz;
    izqNuevaRaiz->de.raiz = derIzqNuevaRaiz;
    derNuevaRaiz->iz.raiz = izqDerNuevaRaiz;

    if(nuevaRaiz->fe == 0) {
        nuevaRaiz->fe = 0;
        izqNuevaRaiz->fe = 0;
        derNuevaRaiz->fe = 0;
    } else if(nuevaRaiz->fe == 1) {
        nuevaRaiz->fe = 0;
        izqNuevaRaiz->fe = -1;
        derNuevaRaiz->fe= 0;
    } else if(nuevaRaiz->fe == -1) {
        nuevaRaiz->fe = 0;
        izqNuevaRaiz->fe = 0;
        derNuevaRaiz->fe = 1;
    }
}

void TAVLCom::DerRotaIzq() {
    TNodoAVL *izqNuevaRaiz = this->raiz;
    TNodoAVL *derNuevaRaiz = this->raiz->de.raiz;
    TNodoAVL *nuevaRaiz = this->raiz->de.raiz->iz.raiz;
    TNodoAVL *derIzqNuevaRaiz = this->raiz->de.raiz->iz.raiz->iz.raiz;
    TNodoAVL *izqDerNuevaRaiz = this->raiz->de.raiz->iz.raiz->de.raiz;

    raiz = nuevaRaiz;
    nuevaRaiz->de.raiz = derNuevaRaiz;
    nuevaRaiz->iz.raiz = izqNuevaRaiz;
    derNuevaRaiz->iz.raiz = izqDerNuevaRaiz;
    izqNuevaRaiz->de.raiz = derIzqNuevaRaiz;

    if(nuevaRaiz->fe == 0) {
        nuevaRaiz->fe = 0;
        derNuevaRaiz->fe = 0;
        izqNuevaRaiz->fe = 0;
    } else if(nuevaRaiz->fe == 1) {
        nuevaRaiz->fe = 0;
        derNuevaRaiz->fe = 0;
        izqNuevaRaiz->fe = -1;
    } else if(nuevaRaiz->fe == -1) {
        nuevaRaiz->fe = 0;
        derNuevaRaiz->fe = 1;
        izqNuevaRaiz->fe = 0;
    }

}

void TAVLCom::DerRotaDer() {
    TNodoAVL *laRaiz = this->raiz;
    TNodoAVL *derRaiz = this->raiz->de.raiz;
    TNodoAVL *izqDerRaiz = this->raiz->de.raiz->iz.raiz;

    this->raiz = derRaiz;
    derRaiz->iz.raiz = laRaiz;
    laRaiz->de.raiz = izqDerRaiz;

    if(derRaiz->fe == 0) {
        derRaiz->fe = -1;
        laRaiz->fe = 1;
    } else if(derRaiz->fe = 1) {
        derRaiz->fe = 0;
        laRaiz->fe = 0;
    }
}

//----PUBLIC----
TAVLCom::TAVLCom() {
    raiz = NULL;
}

TAVLCom::TAVLCom(TAVLCom &avlCom) {
    if(avlCom.EsVacio()) {
        this->raiz = NULL;
    } else {
        raiz = new TNodoAVL(*avlCom.raiz);
    }
}

TAVLCom::~TAVLCom() {
    if(raiz != NULL) {
        delete raiz;
        raiz = NULL;
    }
}

TAVLCom &TAVLCom::operator=(TAVLCom &avlCom) {
    if(this != &avlCom) {
        (*this).~TAVLCom();

        if(avlCom.EsVacio()) {
            this->raiz = NULL;
        } else {
            this->raiz = new TNodoAVL(*avlCom.raiz);
        }
    }

    return (*this);
}

bool TAVLCom::operator==(TAVLCom &avlCom) {
    TVectorCom thisOrder = this->Preorden();
    TVectorCom avlComOrder = avlCom.Preorden();

    if(thisOrder.Tamano() == avlComOrder.Tamano()) {
        for(int i=1; i<thisOrder.Tamano(); i++) {
            if(!this->Buscar(avlComOrder[i])) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}

bool TAVLCom::operator!=(TAVLCom &avlCom) {
    return !(*this == avlCom);
}

bool TAVLCom::EsVacio() const{
    if(this->raiz == NULL) {
        return true;
    }

    return false;
}

bool TAVLCom::Insertar(const TComplejo &complejo) {
    bool crece = false;

    return this->InsertarAux(complejo, crece);
}

bool TAVLCom::Borrar(TComplejo &complejo) {
    bool decrece = false;
    
    return this->BorrarAux(complejo, decrece);
}

bool TAVLCom::Buscar(const TComplejo &complejo) {
    TVectorCom arbolavl = this->Postorden();

    return arbolavl.ExisteCom(complejo);
}

TComplejo TAVLCom::Raiz() const{
    if(this->EsVacio()) {
        return TComplejo();
    }

    return this->raiz->item;
}

int TAVLCom::Altura() const{
    if(this->EsVacio()) {
        return 0;
    }

    return max(this->raiz->iz.Altura(), this->raiz->de.Altura()) + 1;
}

int TAVLCom::Nodos() const{
    if(this->EsVacio()) {
        return 0;
    }

    return 1 + this->raiz->iz.Nodos() + this->raiz->de.Nodos();
}

int TAVLCom::NodosHoja() const{
    if(this->EsVacio()) {
        return 0;
    }

    if(this->raiz->iz.EsVacio() && this->raiz->de.EsVacio()) {
        return 1;
    }

    return this->raiz->iz.NodosHoja() + this->raiz->de.NodosHoja();
}

TVectorCom TAVLCom::Inorden() {
    int position = 1;
    TVectorCom vectorCom(this->Nodos());
    if(vectorCom.Tamano() > 0) {
        this->InordenAux(vectorCom, position);
    }

    return vectorCom;
}

TVectorCom TAVLCom::Preorden() {
    int position = 1;
    TVectorCom vectorCom(this->Nodos());
    if(vectorCom.Tamano() > 0) {
        this->PreordenAux(vectorCom, position);
    }

    return vectorCom;
}

TVectorCom TAVLCom::Postorden() {
    int position = 1;
    TVectorCom vectorCom(this->Nodos());
    if(vectorCom.Tamano() > 0) {
        this->PostordenAux(vectorCom, position);
    }

    return vectorCom;
}

ostream & operator<<(ostream &os, TAVLCom &avlCom) {
    os << avlCom.Inorden();
    return os;
}


//---------------------------TNODOAVL----------------------------

TNodoAVL::TNodoAVL():item(),iz(),de(),fe() {}

TNodoAVL::TNodoAVL(TNodoAVL &nodoAvl):item(nodoAvl.item),iz(nodoAvl.iz),de(nodoAvl.de),fe(nodoAvl.fe) {}

TNodoAVL::~TNodoAVL(){}

TNodoAVL &TNodoAVL::operator=(TNodoAVL &nodoAvl) {
    this->item = nodoAvl.item;
    this->iz = nodoAvl.iz;
    this->de = nodoAvl.de;
    this->fe = nodoAvl.fe;

    return (*this);
}



