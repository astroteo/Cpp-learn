#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <sstream>


using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::stringstream;
using std::strcat;

const char * someText(string s){

  string str = "Hello";
  int l_char = sizeof(str)/sizeof(str[0]) + sizeof(s)/sizeof(s[0]);
  char c[l_char];

  for(int i =0; i<l_char; i++){
    c[i] =str[i];
  }

  char* pc;
  pc = &c[0];
  return pc;
}
void Subroutine(int Parameter1){
  // this is "SUPER-WRONG": C++ makes a copy of Parameter1
  // that's no good if, in example,  this is a big_data_struct
  Parameter1= 10;
}

void Subroutine3(int &Parameter1)
{Parameter1=98;}

void Subroutine4 (int *Parameter1)
{*Parameter1 = 99;}

/* SEE Subroutine5 ( const int &Parameter1)
Don't want to modify Parameter1, but want to use it only !!
=> constant make it un-modifyble.
 Q: B-T-W, why not passing simply the value???
int Subroutine5(int Parameter1){...}
A: passing parameters as values makes a copy in the memory
=> that's a waste of memory !!
Let's assume: int Subroutine5(big_data_struct Parameter1){...}
in this case i'm wasting memory, better to pass value by dereference
with 'const' to modify this fucking function;
*/
 int* Subroutine5 ( const int &Parameter1)
{
  /* SUPER-IMPORTANT SUPER-IMPORTANT SUPER-IMPORTANT SUPER-IMPORTANT SUPER-IMPORTANT

   Second point to remember is that C++ does not advocate to return the address
   of a local variable to outside of the function so you would have to define
   the local variable as static variable.

   SUPER-IMPORTANT SUPER-IMPORTANT SUPER-IMPORTANT SUPER-IMPORTANT SUPER-IMPORTANT */
static int a[2];
 // static for a variable => salva in  maniera permanente, altrimenti a[2] vale il tempo dell'esecuzione
 //                       => SUPER-DRAWBACK: non posso deallocare a in questo caso
 a[0] =  Parameter1;
 a[1] =  Parameter1 + 1;



return &a[0];
}


int* returnArray( const int &Parameter1){


  int* vett_return = new int(2); // crea puntatore e alloca 8-bytes !!
  vett_return[0] = Parameter1;
  vett_return[1] = Parameter1 + 1;

  return vett_return;

}

class Class1
{
public:
  void Method1();
  int MemberVariable1;
  Class1(int mv1){
    MemberVariable1 = mv1;
  }
};

void Class1:: Method1(){
  MemberVariable1++;
}
/* putting const to Method1 in class 2 prevents the method to modify any memeber
of class2 (=> Method1() cannot modify MemberVariable1)

which will ban Method1 in Class2 from being anything which can attempt to alter
any member variables in the object.
*/

class Class2{

public:
  void Method1() const;
  int MemberVariable1;
  Class2(int mv1){
    MemberVariable1 = mv1;
  }};
/* rise to an error
  void Class2:: Method1() const{
    MemberVariable1++;
}
  */

void Class2:: Method1() const{
  // this method cannot modify members of Class2
  cout << "Class2, MemberVariable1 = "<< MemberVariable1;
}






int main(int argc, const char * argv[]){

  // a pointer to a const
  const int z = 10;
  const int * pz;
  pz = &z;

  //~ obviuos:  *pz =11; => this gives an error since it is a constant.
  // !! ERROR GIVEN @ COMPILE-TIME !!


  // function returning a pointer to a constant
  const char *pc = someText("babbaz");

  bool flag = false;
  while(*pc != 'z' && flag != true ){
  cout << *pc;
  if (*pc == 'z'){
    flag = true;
  }
  pc++;

}
  /*Even more useful is a pointer (constant or otherwise) to a ‘const’ value.
  This is useful for returning constant strings and arrays from functions which,
  because they are implemented as pointers, the program could otherwise try to
  alter and crash.
  Instead of a difficult to track down crash, the attempt to alter unalterable
  values will be detected during compilation.*/

  /*The addition of an ‘&’ to the parameter name in C++ (which was a very confusing choice of symbol
  because an ‘&’ in front of variables elsewhere in C generates pointers!)
  causes the actual variable itself, rather than a copy, to be used as the
  parameter in the subroutine and therefore can be written to thereby passing data back out the subroutine.*/
  cout << "\n ______________________________________________________\n " <<endl;
  cout << " 'const'... USED FOR PASSING A VARIABLE AS A REFERENCE  TO A FUNCTION... BUT IN READ-ONLY MODE"<<endl;
  int par = 10;
  cout <<endl<< "before value par = "<<par <<endl;
  Subroutine3(par);
  cout << "after Subroutine3 par = "<<par <<endl;
  Subroutine4(&par);
  cout << "after Subroutine4 par = "<<par <<endl;
  int* s5  =  Subroutine5(par);
  cout << " 'constant' usage in parameters of a function: type_out function(const type_in &par): "<<endl;
  cout<<"using Subroutine5: val1 = "<< *s5 <<" , val2 = "<< *(s5+1)<<endl;
  cout<<"SYNTACTIC-SUGAR: using Subroutine5: s5 [0]= "<< s5[0] <<" , s5[1] = "<<s5[1]<<endl;

  int*  s6  = returnArray(par);
  cout<<"SYNTACTIC-SUGAR: using returnArray(par): s6[0] = "<< s6[0] <<" , s6[1] = "<<s6[1]<<endl;
  delete[] s6;



  cout << "\n ______________________________________________________\n " <<endl;
  cout << " 'const'... USAGE IN OOP"<<endl;

  Class1 c1(13);
  c1.Method1();

  cout << "  Class1 c1(13); => called c1.Method1() => c1.MemberVariable1 = "<<c1.MemberVariable1<<endl;

  Class2 c2(13);
  c2.Method1();







  cout << "\n ______________________________________________________\n " <<endl;
    cout << "\n GoodBye World"<<endl;
}
