#include <iostream>

using namespace std;

#include "tlistacom.h"

//*************************Clase TListaNodo*************************
TListaNodo::TListaNodo() {

}

TListaNodo::TListaNodo(const TListaNodo &listaNodo) {

}

TListaNodo::~TListaNodo() {

}

TListaNodo& TListaNodo::operator=(const TListaNodo listaNodo) {

}




//**************************Clase TListaPos*************************
TListaPos::TListaPos() {

}

TListaPos::TListaPos(const TListaPos &listaPos) {

} 

TListaPos::~TListaPos() {

}

TListaPos& TListaPos::operator=(const TListaPos &listaPos) {

}

bool TListaPos::operator==(const TListaPos &listaPos) {

}

bool TListaPos::operator!=(const TListaPos &listaPos) {

}

TListaPos TListaPos::Anterior() {

}

TListaPos TListaPos::Siguiente() {

}

bool TListaPos::EsVacia() {

}




//**************************Clase TListaCom*************************
TListaCom::TListaCom() {

}

TListaCom::TListaCom(const TListaCom &listaCom) {

}

TListaCom::~TListaCom() {

}

TListaCom& TListaCom::operator=(const TListaCom &) {
    
}

bool TListaCom::operator==(const TListaCom &listCom) {

}

bool TListaCom::operator!=(const TListaCom &listaCom) {

}

TListaCom TListaCom::operator+(const TListaCom &listaCom) {

}

TListaCom TListaCom::operator-(const TListaCom &listaCom) {

}

bool TListaCom::EsVacia() {

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

bool TListaCom::Borrar(const TListaPos &complejo) {


}

TComplejo TListaCom::Obtener(const TListaPos &complejo) {

}

bool TListaCom::Buscar(const TComplejo &complejo) {

}

int TListaCom::Longitud() {

}

TListaPos TListaCom::Primera() {

}

TListaPos TListaCom::Ultima() {

}


