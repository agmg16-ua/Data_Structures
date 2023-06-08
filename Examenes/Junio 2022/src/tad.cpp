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
  TComplejo c8(8,8),c6(6,6),c1(1,1),c2(2,2),c3(3,3),c5(5,5),c7(7,7), c10(10, 10), c9(9,9), c25(25, 25);
  TListaCom l1, l2;
  
  a.Insertar(c6);
  a.Insertar(c3);
  a.Insertar(c8);
  a.Insertar(c1);
  a.Insertar(c5);
  a.Insertar(c7);
  a.Insertar(c10);

  l1.InsCabeza(c3);

  l2.InsCabeza(c1);
  l2.InsertarD(c6, l2.Ultima()); 
  l2.InsertarD(c8, l2.Ultima()); 
  l2.InsertarD(c9, l2.Ultima()); 
  l2.InsertarD(c25, l2.Ultima()); 

  int* resultado = a.Multicamino(l1, l2);
  
  cout << "Salida primer ejemplo: [";
  for(int i=0; i<l2.Longitud(); i++) {
    if(i>0) {
      cout << ' ';
    }
    
    cout << resultado[i];
  }
  cout << "]" << endl;


  TListaCom l3, l4;

  l3.InsCabeza(c1);
  l3.InsertarD(c6, l3.Ultima()); 
  l3.InsertarD(c8, l3.Ultima()); 
  l3.InsertarD(c10, l3.Ultima()); 
  l3.InsertarD(c25, l3.Ultima()); 

  l4.InsCabeza(c1);
  l4.InsertarD(c5, l4.Ultima()); 
  l4.InsertarD(c7, l4.Ultima()); 
  l4.InsertarD(c8, l4.Ultima()); 
  l4.InsertarD(c10, l4.Ultima()); 

  int* resultado2 = a.Multicamino(l3, l4);
  
  cout << "Salida primer ejemplo: [";
  for(int i=0; i<l3.Longitud(); i++) {
    if(i>0) {
      cout << ' ';
    }
    
    cout << resultado2[i];
  }
  cout << "]" << endl;

  
  return 0;
}
