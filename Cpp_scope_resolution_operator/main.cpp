#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <deque>
#include <set>


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


const int x = 10;


class classCase{
public:
  int a;
  int b;

public:
  classCase(int a_var, int b_var){
    a = a_var;
    b = b_var;
  }

  int sumMembers();
};

int classCase:: sumMembers(){ return a+b;}

template <class T>
void fill_vect(vector<T>  &vect, int n ){

  for(int i=0; i< n; i++){

    vect.push_back(i);
  }

};

class Dummy {
  public:
    static int n;
    static int dummyFun();
    static void printDummyFun();
    int id;
    Dummy () { id =n;
              n++; };
};

int Dummy::n = 0;
int Dummy::dummyFun(){
  return Dummy :: n;

}
void Dummy::printDummyFun(){

  cout<< " FROM VOID FUNCTION =>  static counter n is n = "<< Dummy ::n<<endl;
  // LIKE IN JAVA: static function can only use static members:
  // E.g. This is impossible:     cout << "  id = "<<id <<endl;
}

class DummyWrapper{
public:
   class DummyInner{
   public:
     int id;
    static int cnt;
    DummyInner(){
    cout << "hello I'm DummyInner contructor"<<endl;
    id = cnt;
    cnt ++;
    }
  };
};

int DummyWrapper::DummyInner::cnt =0;







int main(int argc, const char * argv[]){


  // :: operator
  // USAGE-1: call global variables

  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n :: GLOBAL VS LOCAL VARIABLES "<<endl;

  int x =11;

  cout <<"x defined in main, x = " <<x<<endl;
  cout <<"x defined global (out of main), ::x = " <<::x<<endl;

  // USAGE-2: define a memeber out of a classes

  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n :: DEFINE FUNCTIONS/MEMEBERS OUT OF CLASS (NOT IN MAIN) "<<endl;

  classCase cc(11,12);
  cout << "create an instance of classCase: classCase cc(11,12)"<<endl;
  cout << " implemented method (out of main) outside the class  sumMembers(): cc.sumMembers() = "<< cc.sumMembers()<<endl;

   // USAGE-3: calling static members from a class
  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n :: RECALL STATIC MEMEBERS (FUNCTIONS/ATTRIBUTES)  "<<endl;

  cout  << " by calling in main: Dummy :: n = "<< Dummy :: n<<endl;

  Dummy d1;
  Dummy d2;

  cout << " Dummy d1;=> d1.n = " << d1.n <<" , => d1.id = "<<d1.id  <<endl;
  cout << " Dummy d2;=> d2.n = " << d2.n << " , => d2.id = "<<d2.id  <<endl;

  cout  << " In fact, by calling NOW  in main: Dummy :: n = "<< Dummy :: n<<endl;

  int n_static = Dummy :: n;

  cout << "int n_static = Dummy :: n; => n_static = "<< n_static << endl;

   int returned_from_static_fun = Dummy :: dummyFun();

   cout << " int returned_from_static_fun = Dummy :: dummyFun(); => returned_from_static_fun  = "<< returned_from_static_fun << endl;

   Dummy :: printDummyFun();

   cout << "\n ______________________________________________________\n " <<endl;
   cout <<"\n :: CALL A CLASS DEFINED INSIDE ANOTHER "<<endl;



   DummyWrapper::DummyInner di1;
   DummyWrapper::DummyInner di2;

   cout << " DummyWrapper::DummyInner di1;=> d1.n = " << di1.cnt<<" , => d1.id = "<<di1.id  <<endl;
   cout << " DummyWrapper::DummyInner di2;=> d2.n = " << di2.cnt << " , => d2.id = "<<di2.id  <<endl;

   cout <<"...That's exactly what happens wen calling the iterator on containers:"<<endl;
  vector <int> vect;
  fill_vect(vect,4);
  cout << "vector<int>::const_iterator it_rOnly;"<<endl;

  vector<int>::const_iterator it_rOnly;
  it_rOnly = vect.begin();

  while(it_rOnly != vect.end() ){

    cout << *it_rOnly<<"\t"<<endl;
    ++it_rOnly;
  }




  cout << "\n ______________________________________________________\n " <<endl;
  cout << "GoodBye World!"<<endl;
}
