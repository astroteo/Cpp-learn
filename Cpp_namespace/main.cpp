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
/*
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
 ==> ALL THIS BLOCK COULD BE REPLACED BY A SIMPLER: using namespace::std; */

using namespace::std;

namespace first_ns{

  void sayMyName(){
    cout << " I am first-namespace"<<endl;
  }

}

// depending on the namespace used, a different sayMyName() function is called
namespace second_ns{

  void sayMyName(){
    cout << " I am second-namespace"<<endl;
  }
}
namespace third_ns{

  void sayMyName(){
    cout << " I am third-namespace"<<endl;
  }

}
//setting a default sayMyName variable
using third_ns::sayMyName;

namespace second_ns{
    void sayMyName_nTimes(int n){
    for(int i=0; i<n; i++){
      sayMyName();
    }
  }
}

using second_ns :: sayMyName_nTimes;


namespace D{

  template <class K, class V>
  class Dictionary{
  private:
    vector <K> &k;
    vector <V> &v;
    vector <K> ka;
    vector <V> va;
  public:
    Dictionary(K k_0,V v_0): k(ka),v(va){
      ka.push_back(k_0);
      va.push_back(v_0);

      k = ka;
      v = va;

    }
    void append(K kn, V vn){

      k.push_back(kn);
      v.push_back(vn);

    }

  vector<K> keys(){
      return k;
    }

    vector<V> values(){
      return v;
    }

  };

  /* SEE Cpp_STL_containers!!

  THAT'S EXACTLY WHAT HAPPENS WHENEVER IMPLEMENTING hash<UserDefinedClas>,
  !! a new struct hash<Persona> is added to the namespace std!!

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

      meaning that under the namespace std there's a:
      template<class T>
      struct hash
      {

      .....

      size_t operator() (const &T) const{

    .......
    
    }

    .....

    }
  }*/

  // Specialization for the string-float case:
  template<>
  class Dictionary<string,float>{
  private:
    vector <string> &k;
    vector <float> &v;
    vector <string> ka;
    vector <float> va;
  public:
    Dictionary(string k_0,float v_0): k(ka),v(va){

      cout<< "I'm a Dictionary made of string as key and float as value. \nA specialiazion of the standard dictionary"<<endl;
      ka.push_back(k_0);
      va.push_back(v_0);

      k = ka;
      v = va;

    }
    void append(string kn, float vn){

      k.push_back(kn);
      v.push_back(vn);

    }

    vector <string>keys(){
      return k;
    }

    vector<float> values(){
      return v;
    }

  };

}

using D:: Dictionary;




int main(int argc, const char * argv[]){


  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n BASIC namespace USAGE "<<endl;

  first_ns :: sayMyName();
  second_ns:: sayMyName();

  sayMyName();
  sayMyName_nTimes(3);

  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n  HOW TO DEFINE hash<UserClass> ...WHAT HAPPENS WHEN DOING: "<<endl;
  cout <<"\n  namespace std {\n template<> \n struct hash<UserClass> {...} \n} "<<endl;

  Dictionary<string,int>  d("h",1);
  d.append("e",3);

  Dictionary<string,float>  df("h",1.0);
  df.append("e",3.3);





  cout << "\n ______________________________________________________\n " <<endl;
  cout << "\n GoodBye World"<<endl;
}
