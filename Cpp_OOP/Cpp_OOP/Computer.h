//
//  Computer.h
//  Cpp_OOP
//
//  Created by teo baiguera on 11/06/18.
//  Copyright © 2018 teo baiguera. All rights reserved.
//

#ifndef Computer_h
#define Computer_h

#include <cstring>
#include <cstdlib> // standard C library!!
#include <iostream>

using std::string;
 class Computer{
    
public:
    string marca;
    float prezzo;
    bool acceso = false;// è possibile inzializzarlo anche nel costruttore
    
public:
    Computer(string m, float p);
    Computer();
    Computer(bool a);
    void accendi();
    void spegni();
    
    void setMarca(string m);
    void setPrezzo(float p);
    string getMarca();
    float getPrezzo();
    
};

#endif /* Computer_h */
