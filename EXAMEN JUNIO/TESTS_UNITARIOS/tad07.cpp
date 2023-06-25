
#include <iostream>
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"

using namespace std;

/* PRUEBA: con ARBOL semi-degenerado, DCHA-IZQ  */
/* SALIDA : L1 = {(3 0) (5 0) (6 0) (10 0) (2 0) (1 0)} */

int
main(void)
{
  TABBCom a;
  TVectorCom v(1);
  TListaCom L1;
  
  TComplejo c1(1, 0);
  TComplejo c2(2, 0);
  TComplejo c3(3, 0);
  TComplejo c5(5, 0);
  TComplejo c6(6, 0);
  TComplejo c7(7, 0);
  TComplejo c8(8, 0);
  TComplejo c10(10, 0);
  TComplejo c25(25, 0);
 

  v[1] = c3;



  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c10);
  a.Insertar(c6);
  a.Insertar(c5);
  a.Insertar(c3);
 

  L1 = a.BuscaVecABB(v);

  cout << "L1 = "<< L1 << endl;

  return 1;
  
}


