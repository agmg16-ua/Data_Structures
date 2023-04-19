#ifndef _TABBCOM_H_
#define _TABBCOM_H_

#include <iostream>
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;

class TNodoABB;

class TABBCom {

    friend ostream & operator<<(ostream &, TABBCom &);

    private:
        // Puntero al nodo 
        TNodoABB *nodo; 

        // AUXILIAR : Devuelve el recorrido en inorden 
        void InordenAux(TVectorCom &, int &); 

        // AUXILIAR : Devuelve el recorrido en preorden 
        void PreordenAux(TVectorCom &, int &); 

        // AUXILIAR : Devuelve el recorrido en postorden 
        void PostordenAux(TVectorCom &, int &); 
    
    public:
        //Constructores 
        TABBCom (); 
        TABBCom (TABBCom &);  
        ~TABBCom (); 

        //Operadores
        TABBCom & operator=( TABBCom &);
        bool operator==( TABBCom &); 

        //Otros metodos
        bool EsVacio(); 
        bool Insertar(TComplejo &); 
        bool Borrar(TComplejo &); 
        bool Buscar(TComplejo &); 
        TComplejo Raiz(); 
        int Altura();         
        int Nodos(); 
        int NodosHoja(); 
        TVectorCom Inorden(); 
        TVectorCom Preorden(); 
        TVectorCom Postorden(); 
        TVectorCom Niveles();

};

class TNodoABB {
    private:
        // El elemento del nodo 
        TComplejo item; 
        
        // Subárbol izquierdo y derecho 
        TABBCom iz, de; 
    
    public:
        //Constructores
        TNodoABB (); 
        TNodoABB (TNodoABB &); 
        ~TNodoABB (); 
        
        //Operador
        TNodoABB & operator=(TNodoABB &);
};

#endif