//
//  main.cpp
//  Cpp_learn
//
//  Created by teo baiguera on 19/04/18.
//  Copyright © 2018 teo baiguera. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi

using namespace std;
using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::getline;

string input_key;
string input_value;
int value_int;
int c = 0;

//////////////////////////////////////////////////////////////
// creating an object: this is dictionary-like
struct DictionaryObject{
    string Key;
    int Value;
};

// creating empty array of DictionaryObjects:
DictionaryObject* dictionariesArray = NULL;

//////////////////////////////////////////////////////////////
// creating a class:

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
//private members of a class are accessible only from within other members of the same class (or from their "friends").
//protected members are accessible from other members of the same class (or from their "friends" ==> classes tha inheritates from that one), but also from members of their derived classes.
//public members are accessible from anywhere where the object is visible.

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

class Rectangle{
    int length,width;
public:
    void set_values(int,int);//constructor:
    int get_perimeter();
    int area(){
        return length*width;
    } // this is a generic method of class rectangle
    } rect;;// immidiatly instantiate an object !! you need the constructor to instantiate like this => void constructor_name()

void Rectangle::set_values (int x, int y) {
    width = x;
    length = y;
} // this is the setter declaration
//  !! scope operator "::" !!  definition of functions to definea member of a class outside the class itself.
int Rectangle::get_perimeter(){
    
    return 2*width+2*length;
    }
//  !! scope operator "::" !! can use all attributes of the class


class Circle{
    
    double radius;
    
public:
    
    Circle(double r): radius(r) {}; // "smarter" constuctor alternative is doing a setter method void Circle::set_circle(int r){ radius = r;}
    double area(){return 3.14 * radius;}
};

class Cylinder{
    Circle circle;
    double heigth;
    
public:
    Cylinder(double h,Circle c) : heigth(h),circle(c) {};
    double volume(){return circle.area() * heigth;}
};

class Parallepiped{
    
    Rectangle base;
    double heigth;
    
public:
    void set_parallelepiped(Rectangle,double);
    double volume(){
    
        double base_area = base.area();
        return base_area * heigth;
    }
} parall;

void Parallepiped :: set_parallelepiped(Rectangle r, double h){
    base = r;
    heigth = h;
}

struct CrazyStruct{
    
    Parallepiped parall;
    Rectangle rect;
}; // allow Parallelepiped object together with Rectangle BUT NOT Parallelepiped with Cylinder. Maybe because they mixes classes ??


//

//

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ** * * * * * * * * * * //


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, coglione \n Let's play with array of indefinite size \n";
    cout << "Here we create an home-made dictionary: \n";
    
while(input_key != "stop"){
    
    DictionaryObject current_dic;
    
    cout << "Give me the key \n";
        getline(cin,input_key);
        
        if ( input_key !="stop"){
    cout << "Give me the value \n";
        getline(cin,input_value);
            
        const char * value_char = input_value.c_str();
            
            try{
                
        value_int = atoi(value_char);// atoi works only with char arrays.
                throw 20;// "id" for the exception
            
                }
            catch(int exception){
                
                cout << "Exception Nr "<< exception<<"\n";
              
            }
            
        }
        else
        {
            value_int =0;
        }
    
    
    current_dic.Key = input_key;
    current_dic.Value = value_int;
        
        if (dictionariesArray == NULL){
            
            dictionariesArray = new  DictionaryObject[1]; // new array of length 1 (!! dictionariesArray originally intialized NULL !! while now is of length 1)
            dictionariesArray[0] = current_dic;
            
        }
        else{
            
            DictionaryObject* temp = dictionariesArray; // storint dictionariesArray into temp variable
            dictionariesArray = new  DictionaryObject[c]; // new array of length c
            
            for (int i =0; i<c; ++i){
                
                dictionariesArray[i] = temp[i]; // filling the newly created dictionariesArray
                
                }
            
            dictionariesArray[c] = current_dic;
            delete [] temp;
        }
    
    c++;
    
    }
    
    for (int j=0 ; j<c; ++j){
        
         cout << "step" << j << " given key--> " << dictionariesArray[j].Key <<" given value --> " << dictionariesArray[j].Value <<"\n";
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Hello, coglione \n Let's play with classes\n";
    
    // instantiating a class:
    Rectangle rect; // instance declaration
    rect.set_values(11,2);//crating an instance
    
    cout << "Area of the rectangle: "<< rect.area()<< "\n";
    cout << "Perimeter of the rectangle: "<< rect.get_perimeter()<< "\n";
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Hello, coglione \n Let's play with CROSSED classes\n";
    
    Circle circ(2.0); // altenative, to setter method
    cout << "Circle area is " << circ.area()<< "\n";
    
    Cylinder cyl(12.0,circ);
    cout << "Cylinder area is " << cyl.volume()<< "\n";
    
    
    
    Rectangle parall_base;
    parall_base.set_values(20, 20);
    
    parall.set_parallelepiped(parall_base, 12.0);
    
    CrazyStruct crzy;
    
    crzy.parall= parall;
    crzy.rect = parall_base;
    
    return 0;
    
}
