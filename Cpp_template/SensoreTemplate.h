#ifndef SensoreTemplate_h
#define SensoreTemplate_h
#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <vector>
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
using std::string;

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

#endif /* SensoreTemplate_h */
