#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <vector>
#include <list>
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>

using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;

#include "SensoreTemplate.cpp"
#include "MyPair.cpp"

// 2 funzioni per ciascun parametro
void testFun(float p){

  cout << "mi hai passato "<< p <<endl;

}

void testFun(string p){

  cout << "mi hai passato "<< p <<endl;

}

// con i template posso richiamare a valle il tipo del parametro della funzione
template <typename T>// va dichiarato assolutamente con la funzione.
void testTemplateFun(T p){
cout << "mi hai passato "<< p <<endl;
  }
template <typename T>
T maxTemplate(T a, T b){


  if(a >= b){
    return a ;
  }
  else{
    return b;
  }
}
template <typename T>
void detType(T x){

if(strcmp(typeid(x).name(),typeid(string).name())==0){

  cout << "\n il parametro passato e una stringa"<<endl;
}

else if(strcmp(typeid(x).name(),typeid(float).name())==0){

  cout << "\n il parametro passato e un float"<<endl;
}
else{

  cout<< "\n non so che parametro mi hai passato"<<endl;
  /*
  cout <<typeid(x).name()<<endl;
  cout << strcmp(typeid(x).name(),typeid(string).name())<<endl;
  */

}
}

// possono essere utilizzate anche 2 diversi typename
template <class T,class U >// la scrittura con class equivale a typedef
T minTemplate(T x,U y){

  if (x > (T)y){
    return x;
  }
  else{
    return (T) y;
  }
}


int main(int argc, const char * argv[]){

testFun("una stringa");
testFun(12.0);

testTemplateFun("una stringa");
testTemplateFun(12.0);

cout << "valore ritornato da maxTemplate(12.0,13.5): "<< maxTemplate(12.0,13.5)<< endl;
cout << "valore ritornato da maxTemplate('ciao','fanculo'): "<<maxTemplate("ciao","fanculo")<< endl;

string f = "fuck";
detType(f);
float a = 11.3;
detType(a);
float *point_a = &a;
detType(point_a);

float a_f = 11.3;
double b_d = 14.5;
                                                                                      //diamond operator è opzionale
cout << "valore ritornato da minTemplate(float = 11.3 ,double = 14.5): "<< minTemplate <float,double>(a_f,b_d)<< endl;

// Usare la classe MyPair
int a_i =20;
int b_i =40;

MyPair <int> myIntPair(a_i,b_i);
MyPair <float> myFloatPair((float)a_i, (float)b_i);

cout<< "\n maximum value between 2 INT pairs(20,40) "<< myIntPair.getmax()<<endl;
cout<< "\n maximum value between 2 FLOAT pairs(20,40) "<< myFloatPair.getmax()<<endl;


// Usare la classe sensore inserendo diversi tipi di val

int p_read = 10;
SensoreTemplate<int> s1("pressione",1);
s1.setVal(p_read);

float t_read = 11;
SensoreTemplate <float> s2("temperatura",2);
s2.setVal(t_read);

SensoreTemplate <float> s3("temperatura",3);
s3.setVal(t_read);



vector<SensoreTemplate<float> > v_sens; // the hybridate vector isn't possible anymore
v_sens.push_back(s3);
v_sens.push_back(s2);

for(SensoreTemplate <float> s: v_sens){

  cout<< "sensor-Id "<< s.getId() << " measuring " << s.measure << " Last read: " << s.getVal() <<endl;

}




  cout <<"\n GoodBye world"<<endl;
}
