#include <iostream>

using namespace std;

#include "tvectorcom.h"

TVectorCom::TVectorCom() {

}

TVectorCom::TVectorCom(int tam) {

}

TVectorCom::TVectorCom(const TVectorCom &vecCom) {

}

TVectorCom::~TVectorCom() {

}

TVectorCom & TVectorCom::operator=(const TVectorCom &vecCom) {

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

}

int TVectorCom::Ocupadas() {

}

bool TVectorCom::ExisteCom(const TComplejo &complejo) {

}

void TVectorCom::MostrarComplejos(double real) {

}

bool TVectorCom::Redimensionar(int tam) {

}
