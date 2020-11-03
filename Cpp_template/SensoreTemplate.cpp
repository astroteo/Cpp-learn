#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <vector>
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>

using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
//https://en.cppreference.com/w/cpp/language/template_parameters
template <class T>
class SensoreTemplate{
  T val; // in questo modo posso inserire interi, float, double ,etc...
  int id;

public:
  string measure;

public:
  SensoreTemplate(string mis,int idn){
   measure = mis;
   id = idn;
   }
  void setVal(T val);

  T getVal();
  int getId();
};

template <class T>
 T SensoreTemplate<T> :: getVal(){
      return val;
    }

template <class T>
int  SensoreTemplate<T> :: getId(){
        return id;
      }

template <class T>
void SensoreTemplate<T> :: setVal(T f){
    val = f;
  }
