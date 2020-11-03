#ifndef Studente_h
#define Studente_h

#include "Persona.h"

class Studente: public Persona{

public:
  Studente(string n, int e, string cdl);


public:
    string cdl;

public:

    void printCdl ();


};


#endif /* Studente_h */
