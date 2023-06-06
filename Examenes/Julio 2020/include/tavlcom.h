#ifndef _TAVLCOM_H_
#define _TAVLCOM_H_

#include <iostream>
#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"

using namespace std;

class TNodoAVL;

class TAVLCom {

    friend class TNodoAVL;

    friend ostream & operator<<(ostream &, TAVLCom &);

    private:

        TNodoAVL *raiz;

        void InordenAux(TVectorCom &, int &);

        void PreordenAux(TVectorCom &, int &);

        void PostordenAux(TVectorCom &, int &);

        bool InsertarAux(const TComplejo &, bool &);

        bool BorrarAux(const TComplejo &, bool &);

        //El lado de la izquierda rota a la izquierda
        void IzqRotaIzq();

        //El lado de la izquierda rota a la derecha
        void IzqRotaDer();

        //El lado de la derecha rota a la izquierda
        void DerRotaIzq();

        //El lado de la derecha rota a la derecha
        void DerRotaDer();

        void PonerCaminoDer(TListaCom &);

        void PonerCaminoIzq(TListaCom &);

        void Caminos_AVLaux(TComplejo, TListaCom &);

    public:

        //Constructores
        TAVLCom();
        TAVLCom(TAVLCom &);
        ~TAVLCom();

        //Operadores
        TAVLCom & operator=(TAVLCom &);
        bool operator==(TAVLCom &);
        bool operator!=(TAVLCom &);

        //Otros metodos
        bool EsVacio() const;
        bool Insertar(const TComplejo &);
        bool Buscar(const TComplejo &);
        bool Borrar(TComplejo &);
        int Altura() const;
        TComplejo Raiz() const;
        int Nodos() const;
        int NodosHoja() const;
        TVectorCom Inorden();
        TVectorCom Preorden();
        TVectorCom Postorden();

        bool EsHoja();

        //Metodo examen Julio 2020
        TListaCom Caminos_AVL(TVectorCom &);
};

class TNodoAVL {

    friend class TAVLCom;

    private:
        TComplejo item;

        TAVLCom iz, de;

        int fe;

    public:

        TNodoAVL();

        TNodoAVL (TNodoAVL &);

        ~TNodoAVL();

        TNodoAVL &operator=(TNodoAVL &);
};

#endif