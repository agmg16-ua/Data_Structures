#include <iostream>
#include <math.h>

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

TComplejo& TComplejo::operator=(const TComplejo& complejo) {
    if(this != &complejo) {
        (*this).~TComplejo();
        im = complejo.im;
        re = complejo.re;
    }

    return *this;
}

TComplejo TComplejo::operator+(const TComplejo& complejo) {
    TComplejo aux;
    aux.re = re + complejo.re;
    aux.im = im + complejo.im;

    return aux;
}

TComplejo TComplejo::operator-(const TComplejo& complejo) {
    TComplejo aux;
    aux.re = re - complejo.re;
    aux.im = im - complejo.im;

    return aux;
}

TComplejo TComplejo::operator*(const TComplejo& complejo) {
    TComplejo aux;
    aux.re = re * complejo.re;
    aux.im = im * complejo.im;

    return aux;
}
 
TComplejo TComplejo::operator+(double real) {
    TComplejo aux;
    aux.re = re + real;
    aux.im = im;

    return aux;
}

TComplejo TComplejo::operator-(double real) {
    TComplejo aux;
    aux.re = re - real;
    aux.im = im;

    return aux;
}

TComplejo TComplejo::operator*(double real) {
    TComplejo aux;
    aux.re = re * real;
    aux.im = im * real;

    return aux;
}

TComplejo operator+(double real, const TComplejo &complejo) {
    TComplejo numero(real);

    return numero + complejo;
}

TComplejo operator-(double real, const TComplejo &complejo) {
    TComplejo numero(real);

    return numero - complejo;
}

TComplejo operator*(double real, const TComplejo &complejo) {
    TComplejo numero(real);
    numero.im = real;

    return numero * complejo;
}

bool TComplejo::operator==(const TComplejo& complejo) {
    if(re==complejo.re && im==complejo.im) {
        return true;
    }

    return false;
}

bool TComplejo::operator!=(const TComplejo& complejo) {
    if(re==complejo.re && im==complejo.im) {
        return false;
    }

    return true;
}

double TComplejo::Arg(void) {
    double arg = atan2(im, re); 
    return arg;
}

double TComplejo::Mod(void) {
    double mod = sqrt(pow(re,2) + pow(im,2));
    return mod;
}

ostream& operator<<(ostream &o, const TComplejo& obj) {
    o << "(" << obj.re << " " << obj.im << ")";
    return o;
}
