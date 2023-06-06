/* Prueba:
     - INSERCION y preorden
*/

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"
using namespace std;

int
main(void)
{
  TAVLCom a;
  TComplejo c4(4,4),c6(6,6),c1(1,1),c2(2,2),c3(3,3),c5(5,5),c7(7,7),c8(8,8);
  TListaCom l1;

  //Lista [(8,8),(7,7),(1,1),(4,4)]
  l1.InsCabeza(c4);
  l1.InsCabeza(c1);
  l1.InsCabeza(c7);
  l1.InsCabeza(c8);
  
  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  a.Insertar(c4);
  a.Insertar(c5);
  a.Insertar(c6);
  a.Insertar(c7);


  cout<<"preorden="<<a.Preorden()<<endl;

  //El metodo BuscarAVL debe devolver [0,2,1,3]
  int* resultado = a.BuscaAVL(l1);

  cout << "Salida del metodo de 2015 = [";

  for(int i=0; i<l1.Longitud(); i++) {
    if(i>0) {
      cout << ','; 
    }

    cout << resultado[i];
    
  }

  cout << ']' << endl;

  
  return 0;
}
