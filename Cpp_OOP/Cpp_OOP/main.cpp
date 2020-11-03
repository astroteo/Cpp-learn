//
//  main.cpp
//  Cpp_OOP
//
//  Created by teo baiguera on 11/06/18.
//  Copyright © 2018 teo baiguera. All rights reserved.
//

#include <iostream>

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

#include "Computer.h"



int main(int argc, const char * argv[]) {
    
    Computer c;
    
    c.accendi();
    c.accendi();
    
    c.setMarca("intel");
    c.setPrezzo(11.11);
    
    cout << "computer-marca: "<< c.getMarca()<<endl;
    cout << "computer-prezzo: " << c.getPrezzo()<<endl;
    
    c.spegni();
    
    
    Computer c1("apple",22.2);
    
    c1.accendi();
    cout << "computer1-marca: "<< c1.getMarca()<<endl;
    cout << "computer1-prezzo: " << c1.getPrezzo()<<endl;
    c1.spegni();
    c1.spegni();
    
    Computer *p_c = & c;
    cout<<"p_c => puntatore ad una istanza di Computer:\n per ottenere gli attributi: p_c -> prezzo: " <<p_c ->prezzo <<"\n p_c -> marca: " << p_c -> marca <<endl;
    
    
    Computer* p_c_array = new Computer[3];
    
    p_c_array[0] = c;
    p_c_array[1] = c1;
    Computer c2("winzoz",10.0);
    p_c_array[2] =c2 ;
    
    cout << "Array di computer"<< endl <<""<<endl;
    for(int i=0; i<3; i++){
        cout <<"computer #-"<<i<<endl;
        p_c_array[i].accendi();
        cout << p_c_array[i].getMarca()<<endl;
        cout << p_c_array[i].getPrezzo()<<endl<<" "<<endl;
        
    }
    
    delete[] p_c_array;
    
    
    
    
    
    std::cout << "GoodBye, World!\n";
    return 0;
}
