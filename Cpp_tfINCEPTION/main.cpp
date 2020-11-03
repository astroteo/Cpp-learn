#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <vector>
#include <list>
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>

using namespace::std;

class S{
public:
  vector<int> &v;

  /*referenced object is not controlled by the class,
   but can change externally.
   If the reference is not const, then the class
   can change the state of an object that lives outside of it.*/
   
  S(vector<int> &v_c):v(v_c){}
  void printS(void){

    for(auto v_el: v){

      cout << v_el<<endl;
    }
  }
};

int main(int argc, char* argv[]){

  vector<int> v_c;
  v_c.push_back(1);
  v_c.push_back(2);
  v_c.push_back(33);
  S s(v_c);
  s.printS();




  cout << " THIS IS THE END -> MY LONELY FRIEND, THE EEEND!! "<<endl;



}
