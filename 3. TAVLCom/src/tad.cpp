/* Prueba:
     - Borrar
*/

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
using namespace std;
int
main(void)
{
  TComplejo d1(1, 1), d2(2, 2), d3(3, 3), d4(4, 4),d5(5,5),d6(6,6),d7(7,7),d8(8,8);
  TAVLCom a;

  a.Insertar(d1);
  a.Insertar(d2);
  a.Insertar(d3);
  a.Insertar(d4);
  a.Insertar(d5);
  a.Insertar(d6);
  a.Insertar(d7);
  a.Insertar(d8);

  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d1);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d2);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d3);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d4);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d5);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d6);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d7);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  a.Borrar(d8);
  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  cout<<"--------------------------------------------------------------------"<<endl;
  

  cout<<a.Inorden()<<endl;
  cout<<a.Preorden()<<endl;
  cout<<a.Postorden()<<endl;
  
}
