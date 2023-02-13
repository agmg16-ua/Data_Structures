#include <iostream>

#include "tcomplejo.h"

using namespace std;

TComplejo::TComplejo() {
    re = 0;
    im = 0;
} 

TComplejo::TComplejo(double real) {
    this->re = real;
    im = 0;
}

TComplejo::TComplejo(double real, double imaginaria) {
    this->re = real;
    this->im = imaginaria;
}

TComplejo::TComplejo(const TComplejo& complejo) {
    this->re = complejo.re;
    this->im = complejo.im;
}

TComplejo::~TComplejo() {
    this->re = 0;
    this->im = 0;
}

double TComplejo::Re() {
    return this->re;
}

double TComplejo::Im() {
    return this->im;
}

void TComplejo::Re(double real) {
    this->re = real;
}

void TComplejo::Im(double imaginaria) {
    this->im = imaginaria;
}

//otros metodos

TComplejo& TComplejo::operator=(const TComplejo& complejo) {
    if(this != &complejo) {
        (*this).~TComplejo();
        im = complejo.im;
        re = complejo.re;
    }

    return *this;
}

TComplejo TComplejo::operator+(const TComplejo& complejo) {

}

TComplejo TComplejo::operator-(const TComplejo& complejo) {

}

TComplejo TComplejo::operator*(const TComplejo& complejo) {

}

TComplejo TComplejo::operator+(double real) {

}

TComplejo TComplejo::operator-(double real) {

}

TComplejo TComplejo::operator*(double real) {

}

bool TComplejo::operator==(const TComplejo& complejo) {

}

bool TComplejo::operator!=(const TComplejo& complejo) {

}

double TComplejo::Re() {
    return this->re;
}

double TComplejo::Im() {
    return this->im;
}

void TComplejo::Re(double real) {

}

void TComplejo::Im(double imaginaria) {

}

double TComplejo::Arg() {

}

double TComplejo::Mod() {

}

ostream& operator<<(ostream &s, const TComplejo &obj) {

}
