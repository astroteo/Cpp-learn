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
#include "Pila.h"

Pila :: Pila(){

  top = NULL;// costruttore inizializza top a null
}


void Pila :: push(int n){


  nodo *elem = new nodo;

  elem -> val = n;
  elem -> successivo = top;

  top = elem;


}


int Pila :: pop(){

  int val_to_return;

  if (top !=NULL){


    val_to_return = top -> val;
    temp = top -> successivo;

    delete top;
    top = temp;


  }
  else{
    cout <<"empy stack" <<endl;
    val_to_return = -1;
  }


return val_to_return;
}

/* Funzionamento Stack => LIFO


### PUSH(int n)

#empty <--- (top non punta nulla)

#first push
_______________________ <--- first element (puntato da top)

#second push
_______________________ <--- second element (puntato da top)

_______________________ <--- fist element

#third push

_______________________ <--- third element (puntato da top)

_______________________ <-- second element

_______________________ <-- fist element



### POP()





*/
