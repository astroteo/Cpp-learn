#ifndef Persona_h
#define Persona_h

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
class Persona{

protected:
    string nome;
    int eta;

public:
    Persona(string n, int e);
    Persona();

public:
    void setNome(string n);
    void setEta(int e);
    string getNome();
    int getEta();

    virtual ~Persona() {}; //destructor (virtual function to make Persona polymorphic)

};

#endif /* Persona_h */
