#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <unistd.h>
#include <vector>
using namespace::std;
int main (int argc, const char * argv[]){
  int cnt =1;
  while(true){

    int* p = new int[100000*cnt];
    delete[] p;
    cnt ++;

    cout <<cnt<<endl;

  }
}
