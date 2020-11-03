//
//  Computer.cpp
//  Cpp_OOP
//
//  Created by teo baiguera on 11/06/18.
//  Copyright © 2018 teo baiguera. All rights reserved.
//

#include "Computer.h"
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

Computer:: Computer(){
    
}

Computer:: Computer(bool a){
    
    acceso = a;
}

Computer :: Computer(string m, float p){
    
    prezzo = p;
    marca = m;
    
} // Overload consentitissimo

void Computer :: accendi(){
    if(acceso){
        cout << "computer era gia acceso "<<endl;
    }
    else{
        acceso = true;
        cout << "computer acceso "<<endl;
        
    }
}

void Computer :: spegni(){
    if(acceso){
        acceso = false;
        cout << "computer spento "<<endl;
    }
    else{
        cout << "computer era gia spento "<<endl;
        
        
    }
}
void Computer::setMarca(string m){
    marca = m;
}

string Computer::getMarca(){
    return marca;
}

void Computer::setPrezzo(float p){
    
    prezzo = p;
}

float Computer::getPrezzo(){
    
    return prezzo;
}

