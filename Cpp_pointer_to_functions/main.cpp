#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <signal.h> // signal handling by O.S. => love for this machine.


using namespace::std;


int sum(int a, int b){

  return a+b;
}

/* function meant to be called by another function*/
void function_to_be_called(string message)
{
  cout << "ftbc => message: " + message <<endl;
}

void another_function_to_be_called(string message)
{
  cout << "another ftbc => message: " + message <<endl;
}


void caller_function(string message, void (*ptr_func_to_call) (std::string m))
{
  ptr_func_to_call(message);
}



/* define the type: pointer to function that takes a string and returns a void */
typedef void (*P_call)(string m);

void function_calling(P_call p, string message){

  cout << "what calling function says ??"<<endl;

  p(message);

}

//_____________________________________________________________________
class Person{

public:
  string name;
  int id;

public:
  Person(int id_, string n_)
  {
    this->id = id_;
    this->name = n_;
  }

  void recap(){

    cout << " id: "<< id << " => name: " << name <<endl;

  }


};

class DogPerson : public Person{

public:
  string dog_name;
  DogPerson(int id_, string n_, string dn_) : Person(id_, n_){

    dog_name = dn_;
  }
};

class SpecialPerson:public Person {

private:
  static  int private_id;

  public:
     int& age;
     int id;
     string name;
     SpecialPerson(int id_, string n_, int& age_, int pid_): age(age_), Person(id_, n_){

       id = id_;
       name = n_;

       private_id++;

     }

     //override
     void recap(){

       cout << "private id: "<< private_id << " => name: " << name << " age: "  << age << endl;

     }

     void set_private_id(int pid_){
       this-> private_id = pid_;
     }

};

int SpecialPerson::private_id = -1;


int main(){


  cout<< "____DEALING WITH A SIMPLE POINTER TO FUNCTION____"<<endl;

  int (*pt)(int x, int y); //define the pointer to the function
  /* mantra: ' puntatore ad una funzione che ritorna un intero e che prende in input due interi.'*/

  int(*pt1) (int x , int y);

  pt = sum; // assign the pointer to the function => ! synthactic sugar !

  pt1 = &sum;// coherent way to make the pointer point the function



  int c = pt(13,14);
  int c1 = pt1(13,14);

  cout <<"pt = sum =>  c = pt(13,14) = "<< c  <<endl;
  cout <<"pt1 = &sum =>  c1 = pt(13,14) = "<< c1  <<endl;


  cout<< "___ TYPEDEF USAGE FOR A CLEARER WAY ____"<<endl;
  /*typedef return_type (*pointer_name)(par1, par2,...)*/
  typedef int (*Pt2)(int x,int y);  // MANTRA: ' definisco un nuovo tipo:
                                   //PUNTATORE A FUNZIONE CHE RICEVE IN INPUT 2 INTERI
                                  // E RITORNA 1 INTERO:

  Pt2 pt2;     // dichiaro poi una variabile di tale tipo!!
  pt2 = sum;  // gli assegno effettivamente la funzione!!
  int c2 =0;
  c2 = pt2(13,14);// uso il puntatore a funzione

  cout << "typedef returnType (*pointer_name) (parameters)\n typedef int (*pt2)(int x,int y); => pt2 = "<< c2 <<endl;

  cout<< "____CALLBACKS ____"<<endl;// ? what is a callback ?

  P_call p;
  p = function_to_be_called;

  function_calling(p,"HELLO");


  cout << "REVIEW ----------------------------------------------------"<<std::endl;
  //pointer to function_calling

  void (*pf_call) (string s); // output (*pointer_name) (input) !! preserve type!!
  pf_call = function_to_be_called;
  pf_call(" !! NOW CALLING FROM POINTER!!");

  void (*pf_call_) (string s);
  caller_function("!! NOW CALLING FROM A FUNCTION  HAVING A POINTER TO FUNCTION AS INPUT !!",pf_call);

  //using the typedef one can avoid the hustle of defining every time the pointer
  P_call p_typedef = another_function_to_be_called;
  caller_function("THIS TIME THE POINTER IS TO \' another_function_to_be_called\' AND HAS BEEN DEFINED WITH A TYPEDEF",
                  p_typedef);

  cout << "CLASSES REVIEW ----------------------------------------------------"<<std::endl;

  Person prs1(1,"marius");
  prs1.recap();
  DogPerson dprs1(1,"gigius","fuffi");
  dprs1.recap();

  int special_person_age = 32;
  SpecialPerson sprs1(1,"matheus",special_person_age, 0);
  sprs1.recap();
  SpecialPerson sprs2(1,"matheus-hide",special_person_age, 0);

  special_person_age = 33;
  sprs2.recap();
  sprs1.recap();

  try {
    sprs2.set_private_id(0);
    throw 22;
  }
  catch (int e){
    cout << "static attribute ! exception nr:" << e << std::endl;

  }
  sprs2.set_private_id(0);
  sprs2.recap();






















  return 0;
}
