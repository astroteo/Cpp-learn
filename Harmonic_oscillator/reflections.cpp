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

#include <boost/numeric/odeint.hpp>

using boost::numeric::odeint::runge_kutta4; // -> it's a template
using boost::numeric::odeint::integrate_const; // -> it's a template
using boost::numeric::odeint::integrate;

struct myStruct{
  // memebers:
  string name;
  int val;

  // constructor(s):
  myStruct();
  myStruct(int v);
  myStruct(string n, int v);
  void printInfo(){
    cout<<"name: "<<name<<" value: "<<val<<endl;
  }

};

myStruct :: myStruct(){};//!! by default the empty construcor is created, but is called in main without the parenthesis
myStruct :: myStruct(int v){ val = v;}
myStruct :: myStruct(string n, int v){name = n; val = v; }


class DemoClass{
  /* INITIALISATION-LIST is used because the memeber is defined after consructor:
  here it is also syntactic sugar
  */
public:
  DemoClass(int &mval): val(mval) {}
public:
  int &val;

};


void swapByRef(int &a, int  &b ){

  cout << " function:  &a =  " << &a <<endl;
  cout << " function:  &b =  " << &b <<endl;

  int t = a;
  a = b;
  b = t;
}

  void swapByPointer(int *a ,int *b){

    int t = *a;
    *a = *b ;
    *b = t;
  }

  void swapByVal(int a, int  b ){

    int t = a;
    a = b;
    b = t;
  }

  int & return_ref( int &a){

    return a;
  }

  class A
{
public:
   A(int& thing) : m_thing(thing) {}
   void printit() { cout << " class memeber decleared as int &m_thing; => m_thing = "<< m_thing << endl;
                    cout << "                                          => &m_ting = " << &m_thing<<endl;
                  }

protected:
   const int& m_thing; //usually would be more complex object
};

int main(int argc, const char * argv[]){




   cout <<"\n R0-->reference variable and functions by reference" <<endl;

  /* it's alway pssible to define a member reference variable in C++*/

  int myint = 5;
   A myA(myint);
   myA.printit();

   // the swap function
  int x = 10;
  int y = 15;

  cout << "\n  def: function( int &a, int  &b){ ... } =>  call: function(a,b); "<<endl;
  cout << "before swapping [By Reference]  => x = " <<x << " &x = "<< &x <<", y = "<<y<<" &y = " << &y<<endl;
  // "chiamata tramite parametri puntatore (per indirizzo)"
  swapByRef(x,y);
  cout << "after swapping [By Reference] => x = " <<x << ", y = "<<y<<endl;

  int i =10;
  int j =15;

  cout << "\n  def: function( int *a, int  *b){ ... } =>  call: function(&a,&b); "<<endl;
  cout << "before swapping [By Pointer]  => i = " <<i << ", j = "<<j<<endl;
  // "chiamata tramite parametri puntatore (per indirizzo)"
  swapByPointer(&i, &j);
  cout << "before swapping [By Pointer]  => i = " <<i << ", j = "<<j<<endl;

  int f = 10;
  int g = 15;

  cout << "\n  def: function( int a, int  b){ ... } =>  call: function( a, b); "<<endl;
  cout << "before swapping [By Value]  => f = " <<f << ", g = "<<g<<endl;
  swapByVal(f,g);
  cout << "after swapping [By Value]  => f = " <<f << ", g = "<<g<<endl;
  cout << "OF COURSE LIKE THIS IT CANNOT WORK "<<endl;


  cout << " a Function can also return a  reference.\n def: int & function(int a, int b){...}"<<endl;
  cout << "call: return_ref(int f) = "<< return_ref(f);


  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n R1--> struct can have constructor(s),"<<endl;

  //using both construcors
  myStruct ms("matteo",0);

  myStruct ms1(12);
  myStruct *p_ms1 = &ms1;

  myStruct ms2(); // this is valid, but returns a warning because default constuctor can be used without parenthesis

  // struct memebers a public by default:
  p_ms1 -> name = "gigi";
  cout << " in struct, members are public by default: p_ms1-> name = "<< p_ms1-> name<<" , p_ms1-> val = " <<p_ms1-> val <<endl;
  p_ms1 -> printInfo();

  cout << "\n ______________________________________________________\n " <<endl;

  cout <<"\n R2-->special constructor: INITIALISATION LIST" <<endl;
  cout<<"STRICTLY NECESSARY WHENEVER A  MEMEBER CLASS IS A REFERENCE "<<endl;
                                                //https://en.cppreference.com/w/cpp/language/initializer_list
  int a=10;
  DemoClass dc(a);
  cout << " value stored inside demo-class: dc.val = "<< dc.val<<endl;



  /*
 You can be used for two purposes:
  1 -> Calling base class constructors
  2-> Initialising member variables before the body of the constructor executes.

  BUT OVERALL: THIS IS THE ONLY WAY IN WHICH YOU CAN INITIALIZE A CLASS MEMEBER
  E.g.:
  class DemoWrong{
   int &val_to_set;
   DemoWrong(int &val_for_setting){

   val_to_set = val_for_setting;
 }
}

class DemoGood{
int &val_to_set;
DemoGood(int &val_for_setting): val_to_set(val_for_setting){}
}
  */
  cout << "\n ______________________________________________________\n " <<endl;

  cout <<"\n R3--> creating a vector from another vector "<<endl;

  vector <float> vf(3);
  vf[0] =10;
  vf[1] =33;
  vf[2] =44;

  cout << "values inside original vector vf: "<< vf[0] << "\t"<< vf[1] <<"\t"<< vf[2]<<endl;

  vector <float> *p_vf;
  p_vf = & vf;

  vector<float> vf_new(vf);
  cout << "Using 'copy' constructor: vf_new(vf)\n values inside new vector: "<< vf_new[0] << "\t"<< vf_new[1] <<"\t"<< vf_new[2]<<endl;







  cout << "\n ______________________________________________________\n " <<endl;

  cout<< "Goodbye World"<<endl;
}
