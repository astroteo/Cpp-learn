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


class Polygon{
protected://!! this is super-important, this two members MUST be inheritated
  float base, height;
public:
  Polygon(){}
  Polygon(float b,float h){
    base =b;
    height = h;
  }
  void set_values(float b, float h ){
    base =b;
    height = h;

  }
                    // actually pair is a template ahahahaha
   pair<float,float> get_values(){
     pair <float,float>  p(base,height);
     return p;
  }
  //virtual {<-> Java abstract method}
public:
  virtual float area(){
    return NULL;
  }
};

class Rectangle :public Polygon{
public:
  float area(){

    return base*height;

  }
};

class Triangle: public Polygon{

public:
  float area(){
    return base*height/2;
  }
};


int main(int argc, const char * argv[]){

Polygon pol_gen;// calling empty constructor doing like this

Polygon *ppol_gen = &pol_gen;
ppol_gen -> set_values(3.0,4.0);
cout << "virtual method called: " <<ppol_gen ->area()<<endl;

Rectangle *prect = new Rectangle;
prect -> set_values(3.0,4.0);

Triangle *ptri = new Triangle;
ptri -> set_values(3.0,4.0);

cout << "virtual method called,\n => class Recatangle implements area(): " <<prect -> area()<<endl;
cout << "virtual method called,\n => class Triangle implements area(): " <<ptri -> area()<<endl;


// Key point in polymorphism:UPCASTING!!
Polygon *ptri_polymorphic = new Triangle;
ptri_polymorphic -> set_values(3.0,4.0);
cout << "virtual method called,\n => class Triangle implements area(): " <<ptri_polymorphic -> area()<<endl;

vector<Polygon*> v_polygon;
v_polygon.push_back(ptri);
v_polygon.push_back(prect);
v_polygon.push_back(ppol_gen);
v_polygon.push_back(ptri_polymorphic);

for(int i=0; i< v_polygon.size();i++){

cout << "Polygon of sides:"<< v_polygon.at(i)-> get_values().first<< "," <<v_polygon.at(i)-> get_values().second << "=> area: " <<v_polygon.at(i) -> area()<<endl;
}



cout<< "GoodBye World"<<endl;
}
