#include "Studente.h"

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
                                                      // this is equivalent to the Java super(nome,eta)
Studente :: Studente(string nome, int eta, string c): Persona(nome,eta){
  cdl = c;
}

void Studente :: printCdl(){
  // method MUST be written with getter() if the attributes {nome,eta} are set to private:
//cout <<" Lo studente di nome: "<< getNome() << " e di eta: " << getEta() << " studia: "<< cdl << endl;
cout <<" Lo studente di nome: "<< nome << " e di eta: " << eta << " studia: "<< cdl << endl;

}
