#include <iostream>

using namespace std;

#include "tlistacom.h"

//*************************Clase TListaNodo*************************
TListaNodo::TListaNodo():e() {
    this->anterior = NULL;
    this->siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &listaNodo):e(listaNodo.e) {
    this->anterior = listaNodo.anterior;
    this->siguiente = listaNodo.siguiente;
}

TListaNodo::~TListaNodo() {
    this->e.~TComplejo();
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo& TListaNodo::operator=(const TListaNodo &listaNodo) {
    if(this != &listaNodo) {
        (*this).~TListaNodo();

        this->e = listaNodo.e;
        this->anterior = listaNodo.anterior;
        this->siguiente = listaNodo.siguiente;
        
    }

    return (*this);
}




//**************************Clase TListaPos*************************
TListaPos::TListaPos() {
    this->pos = NULL;
}

TListaPos::TListaPos(const TListaPos &listaPos) {
    this->pos = listaPos.pos;
} 

TListaPos::~TListaPos() {
    this->pos = NULL;
}

TListaPos& TListaPos::operator=(const TListaPos &listaPos) {
    if(this != &listaPos) {
        this->~TListaPos();
        this->pos = listaPos.pos;
    }

    return (*this);
}

bool TListaPos::operator==(const TListaPos &listaPos) const {
    if(pos == NULL || listaPos.pos == NULL){
        return false;
    }
    if(pos->e == listaPos.pos->e && pos->anterior == listaPos.pos->anterior && pos->siguiente == listaPos.pos->siguiente){
        return true;
    }
    else{
        return false;
    }
}

bool TListaPos::operator!=(const TListaPos &listaPos) const {
    return !(*this == listaPos);
}

TListaPos TListaPos::Anterior() const {
    TListaPos aux;
    
    if(pos == NULL){
        return aux;
    }

    if(pos->anterior == NULL){
        return aux;
    }
    else{
        aux.pos = pos->anterior;
        return aux;
    }
}

TListaPos TListaPos::Siguiente() const {
    TListaPos aux;
    if(pos == NULL){
        return aux;
    }

    if(pos->siguiente == NULL){
        return aux;
    }
    else{
        aux.pos = pos->siguiente;
        return aux;
    }
}

bool TListaPos::EsVacia() const {
    if(this->pos == NULL) {
        return true;
    }

    return false;
}


 

//**************************Clase TListaCom*************************
TListaCom::TListaCom() {
    this->primero = NULL;
    this->ultimo = NULL;
}

TListaCom::TListaCom(const TListaCom &listaCom) {
    primero = NULL;
    ultimo = NULL;
    TListaPos aux = listaCom.Ultima();

    while(aux.EsVacia() == false){
        this->InsCabeza(aux.pos->e);
        aux = aux.Anterior();
    }
}

TListaCom::~TListaCom() {
    TListaNodo *aux;

    while (this->primero != NULL){
        aux = this->primero->siguiente;
        this->primero->~TListaNodo();
        this->primero = aux;
    }
}

TListaCom& TListaCom::operator=(const TListaCom &listaCom) {
    if(this != &listaCom) {
        (*this).~TListaCom();

        //Se recorre desde el final la lista del parametro y se añaden en la cabeza de this, para que queden en el mismo orden
        for(TListaPos i = listaCom.Ultima(); !i.EsVacia() ; i = i.Anterior()) {
            this->InsCabeza(i.pos->e);
        }
    }

    return *this;
}

bool TListaCom::operator==(const TListaCom &listaCom) const {
    TListaPos posic = this->Primera();
    TListaPos posicParam = listaCom.Primera();

    if(this->Longitud() == listaCom.Longitud()) {
        while(posic.pos != NULL) {
            if(posic.pos != posicParam.pos) {
                return false;
            }
            posic = posic.Siguiente();
            posicParam = posicParam.Siguiente();
        }

        return true;

    } else {
        return false;
    }
}

bool TListaCom::operator!=(TListaCom &listaCom) {
    TListaPos posic = this->Primera();
    TListaPos posicParam = listaCom.Primera();

    if(this->Longitud() == listaCom.Longitud()) {
        while(posic.pos != NULL) {
            if(posic.pos != posicParam.pos) {
                return true;
            }
            posic = posic.Siguiente();
            posicParam = posicParam.Siguiente();
        }

        return false;

    } else {
        return true;
    }
}

TListaCom TListaCom::operator+(const TListaCom &listaCom) {
    TListaCom listaAux;
    
    for(TListaPos i = listaCom.Ultima(); !i.EsVacia(); i = i.Anterior()) {
        listaAux.InsCabeza(i.pos->e);
    }

    for(TListaPos i = this->Ultima(); !i.EsVacia(); i = i.Anterior()) {
        listaAux.InsCabeza(i.pos->e);
    }

    return listaAux;
}

TListaCom TListaCom::operator-(const TListaCom &listaCom) {
    TListaCom listaAux;

    for(TListaPos i = this->Ultima(); !i.EsVacia(); i = i.Anterior()) {
        listaAux.InsCabeza(i.pos->e);
    }
    
    for(TListaPos i = listaCom.Primera(); !i.EsVacia(); i = i.Siguiente()) {
        listaAux.BorrarTodos(i.pos->e);
    }

    return listaAux;
}

bool TListaCom::EsVacia() const{
    if(this->primero == NULL) {
        return true;
    }

    return false;
}

bool TListaCom::InsCabeza(const TComplejo &complejo) {
    TListaNodo *aux = new TListaNodo;

    aux->e = complejo;

    if(aux == NULL) {
        return false;
    }

    if(this->primero == NULL) {
        primero = aux;
        ultimo = aux;
        return true;
    } else if(this->primero->siguiente == NULL){
        this->primero = aux;
        this->primero->siguiente = ultimo;
        this->ultimo->anterior = primero;
        return true;
    } else {
        TListaPos *posicion = new TListaPos(this->Primera());
        this->primero = aux;
        this->primero->siguiente = posicion->pos;
        posicion->pos->anterior = this->primero;
        return true;
    }
}

bool TListaCom::InsertarI(const TComplejo &complejo, const TListaPos &listaPos) {
    TListaNodo *aux = new TListaNodo;
    aux->e = complejo;
    if(aux == NULL || listaPos.EsVacia()) {
        return false;
    }

    if(this->primero == listaPos.pos) {
        InsCabeza(complejo);
        return true;
    }
    else {
        for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente()) {
            if(i.Siguiente() == listaPos) {
                return InsertarD(complejo, i); //CAMBIADO i.SIGUIENTE() por i
            }
        } 
    }

    return false;
}

bool TListaCom::InsertarD(const TComplejo &complejo, const TListaPos &listaPos) {
    TListaNodo *aux = new TListaNodo;
    aux->e = complejo;
    if(aux == NULL || listaPos.EsVacia()) {
        return false;
    }
    else {
        for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente()) {
            if(i == listaPos) {
                if(i.pos == this->ultimo) {
                    this->ultimo = aux;
                    i.pos->siguiente = aux;
                    aux->anterior = i.pos;

                    return true;
                } 
                else {
                    i.pos->siguiente->anterior = aux;
                    aux->siguiente = i.pos->siguiente;
                    aux->anterior = i.pos;
                    i.pos->siguiente = aux;

                    return true;
                }
            }
        }
    }

    return false;
}

bool TListaCom::Borrar(const TComplejo &complejo) {
    TListaNodo *aux = this->primero;
    TListaNodo *eliminar;

    while(aux != NULL) {
        if(this->primero->e == complejo) {
            eliminar = this->primero;
            this->primero = this->primero->siguiente;
            eliminar->~TListaNodo();
            this->primero->anterior = NULL;
            return true;
        } else {
            if(aux->siguiente != NULL && aux->siguiente->e == complejo) {
                eliminar = aux->siguiente;
                if(eliminar == this->ultimo) {
                    this->ultimo = aux;
                    aux->siguiente = NULL;
                } else {
                    aux->siguiente = aux->siguiente->siguiente;
                    aux->siguiente->anterior = aux;
                }
                eliminar->~TListaNodo();
                return true;
            }

            aux = aux->siguiente;
        }
    }

    return true;
}

bool TListaCom::BorrarTodos(const TComplejo &complejo) {
    bool elim = false;
    if(this->Buscar(complejo) == false){
        return elim;
    }
    else{
        TListaPos aux = this->Primera();
        while(aux.pos != NULL){
            if(aux.pos->e == complejo){
                if(this->Longitud() == 1){
                    primero = NULL;
                    ultimo = NULL;
                    return true;    //Porque no queda mas nada para borrar
                }
                else if(aux.pos == ultimo){
                    ultimo = aux.pos->anterior;
                    ultimo->siguiente = NULL;
                    return true;    //Porque si hace un siguiente se va a encontrar con un NULL
                }
                else if(aux.pos == primero){
                    primero = aux.pos->siguiente;
                    primero->anterior = NULL;
                }
                else{
                    aux.pos->siguiente->anterior = aux.pos->anterior;
                    aux.pos->anterior->siguiente = aux.pos->siguiente;
                }
                elim = true;
            }
            aux = aux.Siguiente();
        }
        return elim;
    }
}

bool TListaCom::Borrar(const TListaPos &listaPos) {
    if(listaPos.EsVacia()) {
        return false;
    }
    else {
        TComplejo aux = listaPos.pos->e;
        if(Borrar(aux)) {
            return true;
        }
        return false;

    }
}

TComplejo TListaCom::Obtener(const TListaPos &listaPos) const {
    for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente()) {
        if(i == listaPos){
            return i.pos->e;
        }
    }

    return TComplejo();
}

bool TListaCom::Buscar(const TComplejo &complejo) const {
    for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente()) {
        if(i.pos->e == complejo) {
            return true;
        }
    }

    return false;
}

int TListaCom::Longitud() const {
    int longitud = 0;
    
    if(this->EsVacia()) {
        return longitud;
    } else {
        for(TListaPos i = this->Primera(); !i.EsVacia(); i = i.Siguiente()) {
            longitud++;
        }
    }

    return longitud;
}

TListaPos TListaCom::Primera() const {
    TListaPos aux;

    if(!this->EsVacia()) {
        aux.pos = primero;
    }

    return aux;
}

TListaPos TListaCom::Ultima() const {
    TListaPos aux;

    if(!this->EsVacia()) {
        aux.pos = ultimo;
    }

    return aux;
}

ostream & operator<<(ostream& o, const TListaCom& obj) {
    o << "{";
    for(TListaPos i = obj.Primera(); !i.EsVacia(); i = i.Siguiente()) {
        o << obj.Obtener(i);

        if(i != obj.Ultima()) {
            o << " ";
        }
    }

    o << "}";

    return o;
}


