#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <deque>
#include <set>
#include<unordered_set>


using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::pair;
using std::deque;
using std::set;
using std::unordered_set;


class classCase{


public:
  int a;
  int b;

public:
  classCase(int a_var, int b_var){
    a = a_var;
    b = b_var;
  }

public:
   void classCaseSum(int x, int y){
    cout << "the sum of input numbers is:" << x+y << endl;
  };
};

template <class T>
void fill_vect(vector<T>  &vect, int n ){

  for(int i=0; i< n; i++){

    vect.push_back(i);
  }

};

class Persona{
public:
  string nome;
  int eta;

public:
  Persona(string n, int e){
    nome = n;
    eta = e;
  }
  void printPersona() {
    cout << " nome: "<< nome << " , eta: "<< eta <<endl;
  }
  /*  type function(arg1, arg2,...) const{ ... }

the usage of const after the function:
A "const function", denoted with the keyword const after a function declaration,
makes it a compiler error for this class function to change a member variable of
the class.
B-T-W: here we are obliged to write it HERE since we are overriding a function
belonging to the STL library and it's simply defined like this; but it make sense
that 'operator <' will not make any modification to members of class Persona.
Class c{

void do_something() const;
}

method do_something() when implemented has to recall 'const':
void c :: do_something() const {

}

http://duramecho.com/ComputerInformation/WhyHowCppConst.html
https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration */
  bool operator<(const Persona &p_guess) const{

    if( eta < p_guess.eta){
      return true;
    }

    else if ( eta == p_guess.eta){
       bool  ret;

      if(nome < p_guess.nome){

        ret = true;
      }
      else{
          ret = false;
        }
        return ret;
      }


    else {
      return false;}
}
/* ALTERNATIVE OVERRIDE FOR operator <(...):
friend bool operator< (const Persona &p1 , const Persona &p2);*/




 friend bool operator == (const Persona &p1, const Persona &p2);
 /*ALTERNATIVE OVERRIDE FOR operator ==  (...) INSIDE CLASS:
  bool operator == (const Persona &p_guess)const{
      return nome == p_guess.nome && eta == p_guess.eta;
  }
  */
};

  /* ALTERNATIVE OVERRIDE IMPLEMENTATION FOR operator <(...):
  bool Persona::operator< (const Persona &p1 , const Persona &p2){
   return p1.eta > p2.eta;
};*/

bool operator == (const Persona &p1, const Persona &p2){

  return p1.nome == p2.nome && p1.eta == p2.eta;
}



// see Cpp_namespace to a full coomprehension of namespace..
/* it's essentially saying that belonging to  namespace std there's a struct
    hash<Persona>{...}

that implements operator().
this struct it's what objects belonging to the std namespace
(
std:: vector, std::set,etc...
)
needs to have whenever calling the iterator  &/or unordered_set constructor.
namespace N {
    template<class T> class X { ...}; // primary template
    template<> class X<int> { ... }; // specialization in same namespace
}
*/
namespace std
{
    template<>
    struct hash<Persona>
    {
      size_t operator()(const Persona & p) const
      {
        return hash<int>()(p.eta);
      }
    };
}



int main(int argc, const char * argv[]){


  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n BASIC CONTAINER USAGE: set<...> VS vector<...> "<<endl;
  /*
 THE MAIN CONTAINERS IN C++ ARE:
 1 =>  vector;
 2=> deque;
 3 => list ;
 4 => queue;

  */

  vector<int> v;
  set <int> s;

  for(int i=0 ; i<10; i++){
    v.push_back(i);
    v.push_back(i+1);
    s.insert(i);
    s.insert(i+1);
  }

  int cnt =0;
  for (int s_el: s){

    cout << "set element #-"<< cnt <<"value: "<< s_el<<endl;
    cnt++;

  }
  cnt =0;

  for (int v_el: v){
    cout << "vector element #-"<< cnt <<"value: "<< v_el<<endl;
    cnt++;
  }

  classCase cc(1,2);

/*An Iterator is an object that can traverse (iterate over) a container class
  without the user having to know how the container is implemented.
  With many classes (particularly lists and the associative classes), iterators
  are the primary way elements of these classes are accessed.*/
/**************************************************************
*An iterator is best visualized as a pointer to a given element in the container,
*with a set of overloaded operators to provide a set of well-defined functions:
*   Operator* -- Dereferencing the iterator returns the element that the iterator is currently pointing at.
*   Operator++ -- Moves the iterator to the next element in the container. Most iterators also provide Operator-- to move to the previous element.
*   Operator== and Operator!= -- Basic comparison operators to determine if two iterators point to the same element. To compare the values that two iterators are pointing at, dereference the iterators first, and then use a comparison operator.
*   Operator= -- Assign the iterator to a new position (typically the start or end of the container’s elements). To assign the value of the element the iterator is point at, dereference the iterator first, then use the assign operator.
****************************************************************/

  /**************************************************************
  * Each container includes four basic member functions for use with Operator=:
  *   begin() returns an iterator representing the beginning of the elements in the container.
  *   end() returns an iterator representing the element just past the end of the elements.
  *   cbegin() returns a const (read-only) iterator representing the beginning of the elements in the container.
  *   cend() returns a const (read-only) iterator representing the element just past the end of the elements
  ***************************************************************/

/**************************************************************
  all containers provide (at least) two types of iterators:

  container::iterator provides a read/write iterator
  container::const_iterator provides a read-only iterator

  ***************************************************************/
  vector <int> vect;
  fill_vect(vect,12);


  // see Cpp_scope_resolution_operator for understanding this line
   vector<int>::const_iterator it; // declare a read-only iterator
   it = vect.begin(); // assign it to the start of the vector

   while (it != vect.end()) // while it hasn't reach the end
       {
       cout  << " from iterator:  "<< *it<<endl; // print the value of the element it points to
       ++it; // and iterate to the next element
       }
cout << "\n ______________________________________________________\n " <<endl;
cout <<"\n ITERATING OVER A CONTAINER OF OBJECTS "<<endl;

Persona p1("mario",12);
Persona p2("matteo",32);
Persona p3("lucia",12);

Persona p_array[] ={p1,p2,p3};

vector<Persona> vp;
vp.insert(vp.begin(),p_array,p_array+3);// good constructor for vector from array

vector<Persona>:: iterator it_persona;
it_persona = vp.begin();

while(it_persona != vp.end()){

  it_persona -> printPersona();
  // equivalent to:
  //cout<<"nome: " << (*it_persona).nome << ", eta: "<< (*it_persona).eta<<endl;
  // or :
  cout<<"nome: " << it_persona->nome << ", eta: "<< it_persona->eta<<endl;
  ++it_persona;
}

cout << "\n ______________________________________________________\n " <<endl;
cout <<"\n OVERRIDE OF A CONTAINER METHOD => \n !! C++ - set container cannot even allow insertion without overriding the 'operator <' !!"<<endl;

// the set issue:
cout << " ... set-container of non-primitices requires override of 'operator <': "<<endl;
set<Persona> sp;
Persona p4("matteo",12);
sp.insert(p4);
Persona p5("matteo",12);
sp.insert(p5);
for(auto p: vp){sp.insert(p);}
for(auto p:sp){ p.printPersona();}
          // as expected matteo,12 is printed only once <3


cout << " ... unordered_set-container REQUIRES ==> override of 'operator ==': "<<endl;
cout << "                                      ==> create special functions to make default std::hash<> & std::equals_to<"<<endl;
cout << "                                          to work with user defined class (class Persona here)"<<endl;
//http://thispointer.com/how-to-use-unordered_set-with-user-defined-classes-tutorial-example/

unordered_set<Persona> usp;
for(auto p: vp){usp.insert(p);}
usp.insert(p4);
usp.insert(p5);
// using an iterator here to iterate on the set:

unordered_set<Persona> :: const_iterator it_usp;
it_usp =usp.begin();

while(it_usp != usp.end()){
  cout <<"nome: "<<it_usp-> nome<<" , eta: "<< (*it_usp).eta<<endl;
  // don't know why it doesn't work with it_usp -> printPersona
  it_usp++;
}

cout << "GoodBye World!"<<endl;

}
