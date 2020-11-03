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

for(int i=0; i<5; i++){
  cout <<"counter on external process: #-"<<i<<endl;
  sleep(1);
}


cout <<sizeof(int)<<endl;
cout <<sizeof(float)<<endl;
cout<< sizeof(double)<<endl;
}
