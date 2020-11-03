#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include<math.h>
//#include<highgui.h>

#include <boost/numeric/odeint.hpp>


typedef struct ts{

  int v;
} ts_t;


using namespace::std;

int main(){


  cout<< "\n___REFLECTIONS ON A SHARED POINTER ____\n"<<endl;


  cout<< "\n___VECTOR TEMPLATE DOUBLE TYPE \n => the second type MUST be allocator_type ____\n"<<endl;
  /*
L'allocator nn ho idea di che cazzo faccia, però una roba instanziata così si comporta in maniera normale
cioè => pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr;

vector <pcl::PointXYZ, Eigen::aligned_allocator>
  */
  vector< ts_t,allocator<ts_t> > v_dt;

  ts_t s;
  s.v =10;

  v_dt.push_back(s);
  v_dt.push_back(s);
  v_dt.push_back(s);

  for(auto v : v_dt){
    cout << v.v<<endl;
  }





  return 0;
}
