#include "Persona.h"

#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi

using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;

Persona :: Persona(){
//cout << "chiamato costruttore semplice"<<endl;
}

Persona :: Persona(string n, int e){

  //cout << "chiamato costruttore overloaded"<<endl;
  
  eta = e;
  nome = n;
}

void Persona :: setNome(string n ){
nome = n;
}
string Persona :: getNome(){

  return nome;

}

void Persona :: setEta(int e ){

  eta = e;

}
int Persona :: getEta(){

  return eta;

}
