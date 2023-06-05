#ifndef _TLISTACOM_H_
#define _TLISTACOM_H_

#include <iostream>

using namespace std;

#include "tcomplejo.h"
#include "tvectorcom.h"

class TListaNodo {
    friend class TListaPos;
    friend class TListaCom;

    private:
        //Elemento del nodo
        TComplejo e;

        //El nodo anterior
        TListaNodo *anterior;

        //El nodo siguiente
        TListaNodo *siguiente;
    
    public:
        //Constructores
        TListaNodo();
        TListaNodo(const TListaNodo &);
        ~TListaNodo();

        //Operadores
        TListaNodo & operator=(const TListaNodo&);
};

class TListaPos {

    friend class TListaNodo;
    friend class TListaCom;

    private:
        //Puntero a un nodo de la lista
        TListaNodo *pos;
    
    public:
        //Constructores
        TListaPos();
        TListaPos(const TListaPos &);
        ~TListaPos();

        //Operadores
        TListaPos& operator=(const TListaPos &);
        bool operator==(const TListaPos &) const;
        bool operator!=(const TListaPos &) const;

        //Otros metodos
        TListaPos Anterior() const;
        TListaPos Siguiente() const;
        bool EsVacia() const;
};

class TListaCom {

    friend class TListaPos;
    friend class TListaNodo;

    friend ostream & operator<<(ostream &, const TListaCom &); 

    private:
        //Primer elemento de la lista
        TListaNodo *primero;

        //Ultimo elemento de la lista
        TListaNodo *ultimo;
    
    public:
        //Constructores
        TListaCom();
        TListaCom(const TListaCom &);
        ~TListaCom();

        //Operadores
        TListaCom &operator=(const TListaCom &);
        bool operator==(const TListaCom &) const;
        bool operator!=(TListaCom &);
        TListaCom operator+(const TListaCom &);
        TListaCom operator-(TListaCom &);

        //Otros metodos
        bool EsVacia() const;
        bool InsCabeza(const TComplejo &);
        bool InsertarI(const TComplejo &, const TListaPos &);
        bool InsertarD(const TComplejo &, const TListaPos &);
        bool Borrar(const TComplejo &);
        bool BorrarTodos(const TComplejo &);
        bool Borrar(const TListaPos &);
        TComplejo Obtener(const TListaPos &) const;
        bool Buscar(const TComplejo &) const;
        int Longitud() const;
        TListaPos Primera() const;
        TListaPos Ultima() const;
};
#endif