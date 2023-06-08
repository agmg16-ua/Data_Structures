/* Prueba:
     - INSERCION y preorden
*/

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"
#include "tabbcom.h"
using namespace std;

int
main(void)
{
  TABBCom a;
  TComplejo arbol1(1,1), arbol2(2,2), arbol3(3,3);
  TComplejo c50(50,50),c23(23,23),c75(75,75),c42(42,42),c25(25,25),c68(68,68),c74(74,74),c83(83,83),c26(26,26);
  TListaCom l1,l2,l3;
  
  a.Insertar(arbol1);
  a.Insertar(arbol2);
  a.Insertar(arbol3);

  l1.InsCabeza(c50);
  l1.InsertarD(c23, l1.Ultima());
  l1.InsertarD(c75, l1.Ultima());
  l1.InsertarD(c42, l1.Ultima());
  l1.InsertarD(c25, l1.Ultima());
  l1.InsertarD(c68, l1.Ultima());
  l1.InsertarD(c74, l1.Ultima());
  l1.InsertarD(c83, l1.Ultima());
  l1.InsertarD(c26, l1.Ultima());
  cout << "(los mensajes LISTA DE ENTRADA y ARRAY DE SALIDA no se deben mostrar, " << endl;
  cout << "son orientativos para saber si los pasos se realizan correctamente." << endl;
  cout << "lo unico que se debe mostrar es lo que hay entre LISTA DE ENTRADA y ARRAY DE SALIDA)" << endl;

  cout << endl << "LISTA DE ENTRADA: " << l1 << endl << endl;





  TComplejo* arrayDinamico = a.MostrarNiveles(l1);





  cout << endl << "ARRAY DE SALIDA: [";
  for(int i=0; i<l1.Longitud(); i++) {
    if(i != 0) {
      cout << ", ";
    }
    cout << arrayDinamico[i];
  }
  cout << ']' << endl;
  
  return 0;
}
