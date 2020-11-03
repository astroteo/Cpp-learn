#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include<math.h>
using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::pair;

void augmentByRef(int & var){

var++;

}

void printArray(int (& arr)[3]){

  int length = sizeof(arr)/sizeof(arr[0]);

  for (int i =0; i < length; i++){
    cout << arr[i]<<endl;
  }
}
struct inner{

  int v;
  string k;
};
struct wrapper{
  string k;
  inner inner_struct;

};
int main(int argc, const char * argv[]){

  /* ra actually behaves like a pointer to a:
   this is equivalent to:

   int *pa;
   pa = &a;

   *pa = 5;
   cout << a= << a << *pa = << *pa <<endl;

   1) REFERENCES MUST BE INITIALIZED WHEN CREATED:

   int var = 4;
   int &r_var = var;

   ... when using constant is valid also:

   const int &ref = 5;

   2) REFERENCES CANNOT BE RE-ASSIGNED:

   int var2 = 5;
   r_var = var2;

   This will set: var =5 , r_var = 5;

   but if a do:
   ra = 6;

   This will set: a=6 , r_var = 6; BUT REFERENCE NOT LINIKING var2
                                    STILL: var2 =5 ;

    3)  REFERENCE AS FUNCTION PARAMETER:

    def: void function( type1 &par1,type2 &par2,... ){.....}
    call:  function(par1, par2, ..);

    This function will act directly on the varibles passed by reference

    It's dual with pointers is of course:

    def: function(type1 *p1, type2 *p2){* p1 => if you need to use the value of p1
                                        p1 => if you need the memory address of p1}
    call: function(& p1, &p2,..)



    4)  REFERENCE AS SHORTCUTS:

*/
cout <<"\n REFERENCE DEFINITION "<<endl;
//A reference is a type of C++ variable that acts as an alias to another object or value.
int a=4;
int &ra = a;// MUST be decleared with a variable;

cout <<" a = "<<a <<" &a =" << &a << "=> decleare int &ra = a; => &ra =" <<&ra << ", ra =" <<ra <<endl;

const int &ref_to_const = 5;
                // obviously this value cannit be re-assigned anymore <3;

cout << "valid for const: const int &ref_to_const = 5; => ref_to_const = " << ref_to_const <<endl<<endl;

ra = 5;

cout<< "after assignment: ra = 5; => " <<", a = "<<a <<", &a = " << &a << ", ra = " << ra <<", &ra = " <<&ra <<endl;

int b = 6;
ra = b;


cout<< "after reference re-assignment: int b = 6;  ra = b; => " <<", a = "<<a <<", b = " << b << ", ra = " << ra <<endl;

ra = 12;

cout<< "after  value  re-assignment to reference variable:  ra = 12; => " <<" a = "<<a <<", b = " << b << ", ra = " << ra <<endl;

cout << "\n ______________________________________________________\n " <<endl;
cout <<"\n REFERENCE AS FUNCTION PARAMETER "<<endl;

int var = 10;
cout << " var before function call: var = "<< var<<endl;

augmentByRef(var);

cout << "def : void function( &x ){...} , call: function( x );  \n after function call: var = "<< var<<endl;

cout << "\n ______________________________________________________\n " <<endl;
cout <<"\n REFERENCE PARAMETER FUNCTION FOR ARRAYS "<<endl;

int arr[3];

arr[0] =12;
arr[1] =13;
arr[2] =3;

printArray(arr);

cout << "\n ______________________________________________________\n " <<endl;
cout <<"\n REFERENCE AS SHORTCUT FOR NESTED STRUCTS"<<endl;

inner inner_struct;
inner_struct.v = 10;
inner_struct.k ="inner";

wrapper wrapper_struct;
wrapper_struct.k = "wrapper";
wrapper_struct.inner_struct = inner_struct;

// a good way to speed-up code is to define reference to the inner value (assuming i need it a lot of time in the code)
int & ref_to_inner_value =  wrapper_struct.inner_struct.v;
cout << " int ref_to_inner_value = & wrapper_struct.inner_struct.v => before re-assignment: ref_to_inner_value = " << ref_to_inner_value<<endl;
ref_to_inner_value +=1;
cout << " ref_to_inner_value +=1; => after re-assignment: ref_to_inner_value = " << ref_to_inner_value<<endl;
cout << "                         => wrapper_struct.inner_struct.v  = " << wrapper_struct.inner_struct.v <<endl;

cout << "\n ______________________________________________________\n " <<endl;
cout <<"GoodBye World"<<endl;
}
