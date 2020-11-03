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
#include "Coda.h"

Coda :: Coda(){

  head = NULL;
  tail = NULL;

}

void Coda :: push(int n){


  elem = new nodo;

  elem -> val = n;
  elem -> successivo = NULL;

  if(tail != NULL){
  tail -> successivo = elem;
}

  tail = elem;


  if(head == NULL)// se è il primo elemento inserito:
  {

    head = tail;
  }


}

int Coda :: pop(){


  int val_to_return;

  if(head != NULL){

    val_to_return = head -> val;

    elem = head -> successivo;
    delete head;

    head = elem;

    if (head == NULL){

      tail = head;
    }

  }

  return val_to_return;




}
