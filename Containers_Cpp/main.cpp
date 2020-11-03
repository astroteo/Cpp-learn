#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <vector>
#include "Pila.h"
#include "Coda.h"

using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;

class Sensor{

private:
  float val;
  int id;

public:
  string measure;

public:
  Sensor(string m, int id_n);
  void setVal(float f);
  float getVal();
  int getId();
};

Sensor :: Sensor(string m, int id_n){
    measure = m;
    id = id_n;

  }

float  Sensor :: getVal(){
    return val;
  }

int  Sensor :: getId(){
      return id;
    }

void Sensor :: setVal(float f){
  val = f;
}

int main(int argc, const char * argv[]){
  // Strutture dati di tipo astratto

  /**/


  // dealing with containers
  cout << "\n DEALING WITH CONTAINERS \n"<<endl;

  //1) => Dealing with a Stack ==> LIFO
  cout << "\n I-st => Stack \n"<<endl;
  Pila p;
  int val_p_0 = 10;
  cout << "first value pushed into the stack: Pila p => p.push(val_0), val_0: "<< val_p_0 <<endl;


  p.push(val_p_0);
  cout <<" Let's do a pop(): Pila p => p.pop() "<< p.pop()<<endl;

  // testing the stack in a for loop:
  for(int i =0; i< 10; i++){
    cout<<"pushed value: "<< i <<endl;;

    p.push(i);
    }

  for (int i=0; i<=10; i++){
    cout << "iteration #-"<< i <<" popped value: " <<p.pop()<<endl;
  }


  //2) => Dealing with a Queue ==> FIFO

  cout << "\n II-nd => Queue \n"<<endl;
  Coda c;
  int val_c_0 = 10;
  cout << "first value pushed into the Queue: Queue q => q.push(val_c_0), val_c_0: "<< val_c_0 <<endl;

  for(int i =0; i< 10; i++){
    cout<<"pushed value: "<< i <<endl;;

    c.push(i);
    }

  for (int i=0; i< 10; i++){
    cout << "iteration #-"<< i <<" popped value: " <<c.pop()<<endl;
  }


  //3) => collections ==> library
  cout << "\n III-rd => Dynamic Vector Standard Library \n"<<endl;
  vector<float> v(3);
  v[0]=1;
  v[1]=2;
  v[2]=3;
  v[3] =33;// this command doesn't insert in the next position
  v.push_back(44);//<== that's the way to add the value at the end of the vecor


  int count= 0;
  for(float val:v){

    cout << "position #-"<<count << "value: " << val<<endl;
    count++;

  }

  Sensor sens("pressure",1);
  sens.setVal(10.0);


  vector <Sensor> vector_sens;// it's impossible to initialize this vector<Objects> as vector <Sensor> vector_sens(N);
  vector_sens.push_back(sens);

  cout << "\n ... Delaing with a vector of objects \n"<<endl;
  Sensor sens1("tempereature",2);
  sens1.setVal(100.0);
  vector_sens.push_back(sens1);


  for (int i=0; i< vector_sens.size(); i++){

    Sensor s = vector_sens.at(i);

    cout<< "sensor-Id "<< s.getId() << " measuring " << s.measure << " Last read: " << s.getVal() <<endl;

    Sensor ss = vector_sens[i];// both workin

    cout<< "sensor-Id "<< s.getId() << " measuring " << s.measure << " Last read: " << s.getVal() <<endl;

  }




















  cout<<"\n\n Goodbye World \n\n"<<endl;
}
