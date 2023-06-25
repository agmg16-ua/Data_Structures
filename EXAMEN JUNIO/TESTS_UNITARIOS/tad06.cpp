
#include <iostream>
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
#include "tlistacom.h"

using namespace std;

/* PRUEBA: con ABB distribuido, hijos DCHA  */
/* SALIDA : L1 = {(5 0) (1 0) (6 0) (8 0) (7 0) (6 0)} */

int
main(void)
{
  TABBCom a;
  TVectorCom v(3);
  TListaCom L1;
  
  TComplejo c1(1, 0);
  TComplejo c3(3, 0);
  TComplejo c5(5, 0);
  TComplejo c6(6, 0);
  TComplejo c7(7, 0);
  TComplejo c8(8, 0);
  TComplejo c10(10, 0);
  TComplejo c25(25, 0);
 

  v[1] = c5;
  v[2] = c8;
  v[3] = c25;

  a.Insertar(c6);
  a.Insertar(c1);
  a.Insertar(c7);
  a.Insertar(c5);
  a.Insertar(c8);
  
  L1 = a.BuscaVecABB(v);

  cout << "L1 = "<< L1 << endl;

  return 1;
  
}


