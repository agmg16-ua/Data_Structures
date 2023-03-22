#include <iostream>

using namespace std;

#include "tvectorcom.h"
#include "tcomplejo.h"
#include "tlistacom.h"

int
main(void)
{
  TVectorCom a(2);
  TVectorCom b(4);
  TVectorCom c(6);

  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;

{
  TComplejo a;
  TComplejo b(a);
  TComplejo c;
  c = a;
  
  if(a == b)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a == c)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;


}


