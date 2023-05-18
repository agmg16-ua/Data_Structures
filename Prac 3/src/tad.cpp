/* Prueba:
      =, !=
*/

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
using namespace std;

int
main(void)
{

  TVectorCom vec(5);
  TComplejo c1(1), c2(2), c8(8);

  vec[1] = c1;
  vec[2] = c2;
  vec[3] = c8;

  for(int i=1; i<=vec.Tamano(); i++) {
    cout << vec[i] << endl;
  }

  cout << vec << endl;

  return 0;
}
