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
using std::vector;

template <class T>
class MyPair {
    T a, b;
  public:
    MyPair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};

template <class T>
T MyPair<T>::getmax ()
{
  T retval;
  if( a > b){
    retval = a;
  }
  else{
    retval = b;
  }
  return retval;
}
