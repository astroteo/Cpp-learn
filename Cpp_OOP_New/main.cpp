

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

#include "Persona.h"
#include "Studente.h"


int main(int argc, const char * argv[]) {



Persona p1("gigi",32);
Persona* point_p1 = &p1;

cout<< "persona p1:\n "<<endl;
cout <<"nome: " << p1.getNome()<<endl;
cout <<"eta: " << p1.getEta()<<endl;

cout<< "persona p1:\n "<<endl;
cout<< "point_p1 -> nome,   nome:" << point_p1 -> getNome() <<endl;
cout<< "point_p1 -> eta,   eta:" << point_p1 -> getEta() <<endl;


Studente s1("matteo",32,"chimica");

cout<< "studente s1:\n "<<endl;
cout <<"nome: " << s1.getNome()<<endl;
cout <<"eta: " << s1.getEta()<<endl;
cout <<"cdl: " << s1.cdl <<endl;

// vediamo se è possibile fare un array misto di persone e studenti:
Studente s2("mario",32,"chimica");
Studente s3("maria",32,"fisica");

cout<< "studente s2:\n "<<endl;
s2.printCdl();

cout<< "studente s3:\n "<<endl;
s3.printCdl();

Persona *p_array_dyn = new Persona[3];// works fine
Persona p_array[3];

p_array[0] = p1;
p_array[1] = s2;
p_array[2] = s3;

for(int i=0; i<3; i++){

  Persona p = p_array[i];

  cout<< "persona #-"<< i <<endl;
  cout <<"nome: " << p.getNome()<<endl;
  cout <<"eta: " << p.getEta()<<endl;

  // this is the equivalent of  'instanceof()' in Java
  Persona *point_p = &p;

  Studente *point_s = (Studente*) point_p; // Unsafe Upcasting, always cast the class

  Studente *point_s_safe = dynamic_cast <Studente*> (point_p);// safe Upcas

  if(point_s_safe){//return 0x0 if casting fails, even if array elements belongst to Studente

    cout << "corso di laurea: " << "UHM AHAHAHA"<<endl;

  }

  try{
    point_s->printCdl();
    point_s->cdl = "cdl smarrito nel downcasting creando Persona p_array[N]";
    cout << point_s->cdl<<endl;
  }
  catch(int e){
    cout << "Impossible fare upcasting persona => studente "<<endl;
  }

}

//delete[] p_array_dyn;


cout <<"GoodBye world" << endl;

}
// to launch this script have to tell to compiler that a class has to be taken:
//    $g++ -o exec Persona.cpp main.cpp
