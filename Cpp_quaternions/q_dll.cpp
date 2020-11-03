#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>

#include "q_dll.h"

using namespace::std;

void CppQuatDescrition(void){

  cout << "This DLL deals with quaternions"<<endl;

}


Quat::Quat(vector<double> q){

  q1 = q[1];
  q2 = q[2];
  q3 = q[3];
  q4 = q[4];

}

void Quat::printQuat(void){

  for(int i=0; i< 4; i++){

    cout << " q"<< i+1 << " = "  << q[i];

  }
}
