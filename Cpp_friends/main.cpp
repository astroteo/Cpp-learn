#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <deque>
#include <set>

using namespace::std;

/*ABOUT KEYWORDS:
template<typedef T>
typename ~>

template<class T>
class ~>

friend ~> enhance an external function/class to access members of the father class


*/

// !!! WTF !!!

template<class T>
class A;

template<class T>
A<T> foo(A<T>& a);

/*
declearing such headerS the issues disappears ==>


*/

// !!! WTF !!!



template<class T>
class A{

public:
  A (T a =0):m_a(a){}

  friend A foo<T>(A& a);

private:
   T m_a;
};

template <class T>
A<T> foo(A<T>& a){

  return a;

}

// !! W.T.F AGAIN=> let's declear the headerS !!
template< class T>
class Person;

template< class T >
void  smartOlderOne(Person<T>& person_to_make_older);



template<class T>
class Person{

  string name;
  T age;

public:
  Person(string n, T a){
    age = a;
    name = n;
  }

  void printInfo(){
    cout << "person => name: "<< name <<" => age: "<< age <<endl;
  }

  friend void olderOne(Person<T> &person_to_make_older);
  /// key-line key-line key-line key-line key-line key-line key-line key-line
  friend  void smartOlderOne<T>(Person<T> &person_to_make_older);
  /// key-line key-line key-line key-line key-line key-line key-line key-line
  friend class PersonInspector;

};


void olderOne( Person<int> &person_to_make_older){
  person_to_make_older.age++;
}

void olderOne( Person<float> &person_to_make_older){
  person_to_make_older.age++;
} // !! Big issue: it needs to implement a new olderOne method for all types !!


template<class T>
void smartOlderOne(Person<T> &person_to_make_older){
person_to_make_older.age++;
}

class PersonInspector{
public:
  void inspectPerson(Person<int> p_ti){
    cout << "Inspecting person from inspector class: "<<endl;
    p_ti.printInfo();
  }

  PersonInspector(){};

};


int main(int argc, const char * argv[]){

  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n 'friend' usage in class Person "<<endl;

  Person<int> p1("mario", 11);
  cout << "BEFORE application of order1 function:"<<endl;
  p1.printInfo();

  olderOne(p1);
  cout << "AFTER application of order1 function:"<<endl;
  p1.printInfo();

  PersonInspector pI;
  pI.inspectPerson(p1);

  Person<float> p1f("mario", 12.45);
  cout << "BEFORE application of order1 function: ON FLOAT Person"<<endl;
  p1f.printInfo();
  olderOne(p1f);
  cout << "AFTER application of order1 function: ON FLOAT Person"<<endl;
  p1f.printInfo();
  smartOlderOne(p1f);
  cout << "AFTER SMART application of order1 function: ON FLOAT Person"<<endl;
  p1f.printInfo();

  A<float> a(5);
  foo(a);










  return 0;

}
