/* Prueba:
     - INSERCION y preorden
*/

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
using namespace std;

int
main(void)
{
  TAVLCom a, b;
  TComplejo c23(23,4),c25(25,6),c42(42,1),c26(26,2),c50(50,3),c74(74,5),c68(68,7),c75(75,8),c83(83,1),c70(70,8),c51(51,8);
  TVectorCom ejemplo1(9), ejemplo2(4), ejemplo3(3);
  
  //ARBOL DEL EJEMPLO
  a.Insertar(c50);
  a.Insertar(c25);
  a.Insertar(c74);
  a.Insertar(c23);
  a.Insertar(c42);
  a.Insertar(c68);
  a.Insertar(c75);
  a.Insertar(c26);
  a.Insertar(c83);

  //VECTOR ENTRADA EJEMPLO 1
  ejemplo1[0] = c50;
  ejemplo1[1] = c23;
  ejemplo1[2] = c75;
  ejemplo1[3] = c42;
  ejemplo1[4] = c25;
  ejemplo1[5] = c68;
  ejemplo1[6] = c74;
  ejemplo1[7] = c83;
  ejemplo1[8] = c26;

  //VECTOR ENTRADA EJEMPLO 2
  ejemplo2[0] = c50;
  ejemplo2[1] = c25;
  ejemplo2[2] = c74;
  ejemplo2[3] = c70;
  
  //VECTOR ENTRADA EJEMPLO 3
  ejemplo3[0] = c51;
  ejemplo3[1] = c42;
  ejemplo3[2] = c70;


  cout<<"preorden="<<a.Preorden()<<endl;

  TListaCom lista = a.Caminos_AVL(ejemplo1);

  cout << "Salida del ejemplo 1: " << lista << endl;

  lista = a.Caminos_AVL(ejemplo2);

  cout << "Salida del ejemplo 2: " << lista << endl;

  lista = a.Caminos_AVL(ejemplo3);

  cout << "Salida de ejemplo 3: " << lista << endl;
  
  return 0;
}
