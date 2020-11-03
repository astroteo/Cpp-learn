#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <pthread.h>
#include<sys/types.h>// ~> first library supporting multiprocessing
#include<unistd.h>// ~> second library supporting multiprocessing

using namespace::std;

template<typename T>
class A;
template<typename T>
class B;


template<typename T>
class A {
public:
  string k;
  T v;
public:
  A(T vc, string kc){
    v = vc;
    k = kc;

  }

};
template<typename T>
class B: public A<T>{
public:
  T c;               // !! TEMPLATE ALSO  THE CONSTRUCTOR  == B( T vc, string kc, T cc):: A<T>:: A(vc,kc){...}
  B( T vc, string kc, T cc): A<T>(vc,kc){
    c = cc;
  }
 void printInfo();

};


// defining an external function w.r.t a template class
template<typename T>
void B<T>::printInfo(){
  cout <<"hello <3"<<endl;
  // IN GENERAL: this-> makes clear that we are referring to class member
  cout << " key: "<< this->k << " val1: "<< this->v <<" val3: "<< this->c<<endl;

}


int main(){

  cout << "Dealing with the 'this', and 'this->' concept"<<endl;
}
