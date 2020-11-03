#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>


using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::pair;


template <class T>
 T plus1(T i){
  cout << "before-value: "<<i <<endl;
  i++;
  cout << "after-value: "<<i <<endl;
  return i;

}

template <class T>
void plus1Ref(T &i){
  i++;
}

template <class T>
void plus1Point(T *i){
  *i = *i +1;
}

template <class K,class V>
struct dict{

   vector <K> &k;
   vector<V> &v;

   vector <K> ka;// auxiliary vectors
   vector<V> va;

   dict(K key, V value): k(ka),v(va){
     ka.push_back(key);
     va.push_back(value);

     k = ka;
     v = va;
   }


   void append(string key, V value){

     // aggiungere controllo su chiave;
     k.push_back(key);
     v.push_back(value);

   }

  // return vector of keys
   vector <K> keys(){

     return k;
   }

   vector <V> values(){

     return v;
   }

   // return refernce to keys-vector
   vector <K>& keysRefs(){

     return k;
   }

   vector <V>& valuesRefs(){

     return v;
   }

   void printDic(){
     for(int i =0; i <k.size(); i++){

       cout<< "PD: key-value #-"<<i<<" => key = "<< k.at(i) <<", value  = "<< v.at(i) << endl;

     }

   }
};


int main(int argc, const char * argv[]){
  cout << "\n ______________________________________________________\n " <<endl;
  cout<<"FUNCTIONS REVIEWS..."<<endl;

  //Pass by value: Just the standard way a function is thought!!
  float x = 10;
  auto y = plus1(x);
  cout << "auto y = plus1(x); => y = "<<y<<endl;

  //Pass by reference: the variable is updated into it's memory address!!
  cout <<"before x = "<< x <<endl;
  plus1Ref(x);
  cout << "after plus1Ref:  x = "<<x <<endl;

  plus1Point(&x);

  cout << "after plus1Point:  x = "<<x <<endl;


  cout << "\n ______________________________________________________\n " <<endl;
  cout<<"MORE COMPLEX EXCERCISE: DICTIONARIES IN C++..."<<endl;
  // My dictionary implementation:
  dict <string,int> d("a",11);
  d.append("b",12);
  d.append("c",13);
  d.append("d",14);

  for(int i =0; i < d.keys().size(); i++){

    cout<< "key-value #-"<<i<<"=> key = "<< d.keys().at(i) <<", value  = "<< d.values().at(i) << endl;


  }

  vector <string> & keys_refs = d.keysRefs();
  vector <int> & values_refs = d.valuesRefs();

  /*fatal-error:
  you can't have back references if you doesn't declear them:
  vector <string>  keys_refs = d.keysRefs();
  vector <int>  values_refs = d.valuesRefs();

  this just returns the 2 vectors, not the references to the vectors members of the struct !!
  */

  for(int i =0; i <keys_refs.size(); i++){

    cout<< "REF: key-value #-"<<i<<" => key = "<< keys_refs.at(i) <<", value  = "<< values_refs.at(i) << endl;

  }



  // The  crucial test:
  cout << "setting standard vector (keys[0] = 'banana', values[0] = 0)... "<<endl;
  vector <string> keys = d.keys();
  vector <int> values = d.values();
  d.keys()[0] = " banana";
  d.values()[0] = 0;

  d.printDic();
  cout << "... CORRECT: it doesn't work!!"<<endl<<endl;

  cout << "setting reference vector (keys[1] = 'apple', values[1] = 1)... "<<endl;
  d.keysRefs()[1] = "apple";
  d.valuesRefs()[1] = 1;

  keys_refs[0] = "banana";
  values_refs[0] = 0;


  d.printDic();
  cout << "... OK: it works"<<endl<<endl;

   cout << "\n ______________________________________________________\n " <<endl;
   cout << "GoodBye World"<<endl;
}
