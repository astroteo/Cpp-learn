#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <unistd.h>// library for time.sleep
#include <vector>
#include <typeinfo>

using namespace::std;

/*dealing with templates -> best practise for functions
=> GooGle uses snake notation for functions*/

template <typename T, typename S>
T sum_function(const T& var_t, const S& var_s){
  /* note that the type is T& var instead of T &var*/
  if(typeid(var_t) == typeid(var_s))
  {
    return var_t + (T) var_s;
  }
  else{

    return 0;
  }

}


/* dealing with templates -> best practise for classes
   => template <class T> instead of <typename T >*/

template<class T>
class Number{

private:
  string name;
  T value;


public:
  Number(string n, T v){
    name = n;
    value = v;

  };

  Number(){};

  void setName(string n){

    name = n;
  }

  const string getName(){

    return name;
  }

  void setValue(T v_new){
    value = v_new;
  }

  const T getValue(){

    return value;
  }

  void printValue(){

    cout << "stored value is: "<<value<< endl;
  }
  void printName(){

    cout << "name is: "<< name << endl;
  }
  // overloading sum operator
  Number<T> operator+ ( Number<T> n){

    //this->name = this->name + " + " + n.getName();
    //this->value = this->value + n.getValue();
    //return *this;


    string n_ret =  this->name + " + " + n.getName();
    T v_ret = this->value + n.getValue();

    Number<T> number_ret(n_ret, v_ret);


    return number_ret;


  }


bool operator==( Number<T> n){

    if( this->name == n.getName() && this->value == n.getValue() ){
      return true;
    }
    else{
      return false;
    }

  }

Number<T> operator+= ( Number<T> n){

    this->name = this->name + " + " + n.getName();
    this->value = this->value + n.getValue();
    return *this;
  }
};

//tranq class
class Tranq{
public:
  int z;
  string n;
  Tranq(){};
  Tranq(string s, int v){
     z = v;
     n = s;
  }

  Tranq operator+ (Tranq t){

    this->z = this->z + t.z;
    this->n = this->n +" "+ t.n;

    return *this;
  }

  void info(){

    cout << "TRANQ ==> name: "<< n <<" => value: "<< z<<endl;
  }
};


//test Behaviour class -> explaining purpose of attribute members
class BeClass{
public:
  int &thing; // thing will be from now on saved via memory address
              //    --> think like a HugeObject and passing it through memory
              //        address instead of copying the entire object
              //        when creating an instance.

  int id;
  static int id_cnt;

  BeClass(int &m_thing): thing(m_thing){

    id_cnt++;
    id = id_cnt;

 }
public:

  void info(){
    cout <<" stored value is: "<< thing <<" , id is: "<<id<<endl;
  }
};

int BeClass::id_cnt =-1; // static members NEED to be initialized OUT of class definition!!




int main(){


  cout << "\n ____ SCARING FACTS IN C++ ___ \n"<<endl;

  int* x = new (int);
  *x = 100;

  cout <<"text x puntatore: "<< *x << " " <<&x<<endl;

  delete(x);
  *x = 20;

  cout <<"text x puntatore: "<< *x << " " <<&x<<endl;


  int a = 10;
  int b = 20;



  cout << "\n ____ BEST PRACTISE ON FUNCTIONS___ \n"<<endl;

  int c = sum_function<int,int>(a,b);
  cout << "c = sum_function<int,int>(a,b) = "<<c<<endl;

  cout << "\n ____TEST ON TRANQ CLASS FOR SUM OVERLOAD ___ \n"<<endl;

  Tranq t1("hello",2);
  Tranq t2("FuCK",4);
  Tranq t3;
  t3 = t2 + t1;

  t3.info();


  cout << "\n ____TEST ON BEHAVIOUR OF REFERENCE ATTRIBUTES____\n"<<endl;

  int v1 =10;
  BeClass be1(v1);
  cout <<"call be1.info() with value intially setted as BeClass be1(10) "<<endl;
  be1.info();

  int v2 =29;
  BeClass be2(v2);
  cout <<"call AGAIN be1.info() after having intantiated =>  BeClass be2(134)"<<endl;
  be1.info();
  be2.info();


  cout << "\n ____ BEST PRACTISE ON CLASSES___ \n"<<endl;

  Number<int> n1("number-1",3);
  Number<int> n2("number-2",4);


  cout <<"before setter: "<< n1.getValue()<<endl;
  n1.setValue(13);

  n1.printName();
  n1.printValue();


  n2.printName();
  n2.printValue();


  Number<int> n3; // use empty constructor.
  n3 = n1 + n2;

  n3.printName();
  n3.printValue();

  Number<int> n_;
  n_ = n1;

  n1.printName();
  n1.printValue();

  n2.printName();
  n2.printValue();


  if (n_ == n1){

    cout << "n_ is coincident with n1 Q.E.D"<<endl;


  }
  else{

    cout << "n_ is NOT coincident with n1"<<endl;
  }


  if (n_ == n2){

      cout<< "n_ is coincident with n2 "<<endl;
  }
  else{

      cout << "n_ is NOT coincident with n2 Q.E.D"<<endl;
    }

    n1 += n2;
    n1.printName();
    n1.printValue();

    n2.printName();
    n2.printValue();

    n1 += n3;

    n1.printName();
    n1.printValue();

    n3.printName();
    n3.printValue();





  cout << "\n \n Dealing with GooGle notations in C++\n \n "<<endl;

return 0;
}
