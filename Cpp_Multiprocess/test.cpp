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
template<typename U>
class B: public A<U>{
public:
  U c;               // !! TEMPLATE ALSO  THE CONSTRUCTOR  == B( T vc, string kc, T cc):: A<T>:: A(vc,kc){...}
  B( U vc, string kc, U cc): A<U>(vc,kc){
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
void func_ref(int &a){

  a++;
}

void func_point(int *a){

  *a = *a +1;

}

void funcA_ref(A<int> &a){
  a.v++;
}

void funcA_point(A<int> *a){
  a->v++;
}

int main(){
  fflush(stdout); // needed to do not buffer the stdout,
  /*
  */
  int a = 10;

  cout << " prima a = "<< a<<endl;
  func_ref(a);

  cout << "dopo a = "<<a<<endl;

  func_point(&a);
  cout << " dopo dopo a = "<<a<<endl;

  A<int> a_obj( 12,"ciao");
  cout << " prima a_obj.v = "<< a_obj.v << endl;

  funcA_ref(a_obj);

  cout << " dopo a_obj.v = "<< a_obj.v << endl;

  funcA_point(&a_obj);

  cout << "dopo dopo a_obj.v = "<< a_obj.v << endl;


  B<int> b_obj(a_obj.v,a_obj.k,12);

  b_obj.printInfo();









  /*
  cout << "this is my pid: "<< getpid() << " => this is my father's pid: "<< getppid()<<endl;

  pid_t parent_pid = getpid();

  pid_t child_pid = fork();

  if(getpid() == parent_pid){

    cout << "I'm the parent"<<endl;
  }
  else{
    cout << "I'm the child"<<endl;
    if ( child_pid == 0){
      cout << "assertion correct: I'm the child, my id is: "<<getpid()<<endl;
    }
  }


  cout <<" executed by partent and child"<<endl;
  */


}
