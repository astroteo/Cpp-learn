
#ifndef Pila_h
#define Pila_h

#include <cstring>
#include <cstdlib> // standard C library!!
#include <iostream>
#include <cstring>
#include <cstdlib> // standard C library!!
#include <iostream>

using std::cout;
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;

using std::string;


class Pila{

  private:
    struct nodo{

      int val;
      nodo *successivo;


    };

    nodo *top;
    nodo *temp; // da utilizzare solo per il problema del return

  public:
    Pila();
    void push(int n);
    int pop();
};

  #endif /* Persona_h */
