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
  //PRUEBA DEL EJEMPLO DEL ENUNCIADO DEL EXAMEN
  TABBCom a;
  TComplejo c8(8,8),c6(6,6),c1(1,1),c2(2,2),c3(3,3),c5(5,5),c7(7,7), c10(10, 10), c9(9,9), c25(25, 25);
  TVectorCom v1(4);
  
  a.Insertar(c6);
  a.Insertar(c3);
  a.Insertar(c8);
  a.Insertar(c1);
  a.Insertar(c5);
  a.Insertar(c7);
  a.Insertar(c10);

  v1[0] = c1;
  v1[1] = c6;
  v1[2] = c25;
  v1[3] = c8;

  TListaCom resultado1 = a.BuscaVecABB(v1);

  cout << "RESULTADO EJEMPLO = " << resultado1 << endl;

  //PRUEBA CON ARBOL VACIO Y VECTOR VACIO
  TABBCom b; //arbol vacio
  TVectorCom v2; //vector vacio

  TListaCom resultado2 = b.BuscaVecABB(v2);

  cout << "RESULTADO TODO VACIO = " << resultado2 << endl;


  //PRUEBA SOLO ARBOL VACIO
  TListaCom resultado3 = b.BuscaVecABB(v1);

  cout << "RESULTADO SOLO ARBOL VACIO = " << resultado3 << endl;

  //PRUEBA SOLO VECTOR VACIO  
  
  TListaCom resultado4 = a.BuscaVecABB(v2);

  cout << "RESULTADO SOLO VECTOR VACIO = " << resultado4 << endl;


  //PRUEBA CON UN ARBOL Y VECTOR PROPIOS

  TABBCom arbol;
  TComplejo com1(1,1), com5(5,5), com15(15,15), com20(20,20), com30(30,30), com35(35,35), com40(40,40), com50(50,50), com55(55,55), com60(60,60), com65(65,65), com68(68,68), com70(70,70), com73(73,73), com75(75,75), com80(80,80), com85(85,85), com90(90,90), com100(100,100);
  TVectorCom vector(6);

  arbol.Insertar(com50);  
  arbol.Insertar(com30); 
  arbol.Insertar(com70); 
  arbol.Insertar(com15); 
  arbol.Insertar(com40); 
  arbol.Insertar(com60); 
  arbol.Insertar(com80); 
  arbol.Insertar(com5); 
  arbol.Insertar(com20); 
  arbol.Insertar(com35); 
  arbol.Insertar(com55); 
  arbol.Insertar(com65); 
  arbol.Insertar(com75); 
  arbol.Insertar(com90); 
  arbol.Insertar(com1); 
  arbol.Insertar(com68); 
  arbol.Insertar(com73);
  arbol.Insertar(com85);

  vector[0] = com20;
  vector[1] = com40;
  vector[2] = com100;
  vector[3] = com55;
  vector[4] = com1;
  vector[5] = com75;

  TListaCom lista = arbol.BuscaVecABB(vector);

  cout << "RESULTADO DE MI PRUEBA = " << lista << endl;



  return 0;
}
