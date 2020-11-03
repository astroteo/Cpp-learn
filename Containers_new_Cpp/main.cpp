#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <exception>

using namespace::std;

class Person{

public:
  string name;
  int age;
  Person(int a, string n){ age = a; name = n;}

  class Arm{
  public:
    int length;
    Arm(int l){ length = l;}
    void print_length(){cout<< "arm lenght is equal to: "<< length<<endl;}

  };

};

using namespace::std;

int main(){

  // using a container
  vector<int> vi;
  for (int i=0; i< 12; i++)
    vi.push_back(i);

  vi[11] =1;

  //obtaining the iterator => a nested classs inside vector!
  vector<int>::iterator iter_vi;
  // totally analogous:
  cout << "________NESTED-CLASS example of usage"<<endl;
  Person::Arm a(12);
  a.print_length();
   cout << "________Iterator for looping over a container: example of usage"<<endl;

  /* ITERATOR ( read- write )

  iterator has methods that can be used for running over the container:
  (i) 'Cooperating' with container (c):
  c.begin()
  c.end()

  (ii) the iterator keep in memory a single value of the container
  (iii) the value is stored as pointer

  (iV) => DEPENDING ON CONTAINER if I do *iter_vi = 4 CAN BE ALLOWED OR NOT


  */
  int cnt;
  for(iter_vi = vi.begin(); iter_vi != vi.end();iter_vi++){
    cout<<" element #-"<<cnt <<" ==> value: "<< *iter_vi <<endl;

    if(cnt > 3)
      *iter_vi =100;

    cnt++;
  }
  cout<< "MODIFIED CONTAINER AFTER PREVIOUS LOOOP"<<endl;
  cnt =0;
  for(iter_vi = vi.begin(); iter_vi != vi.end();iter_vi++){
    cout<<" element #-"<<cnt <<" ==> value: "<< *iter_vi <<endl;



    cnt++;
  }



/* OUTPUT-ITERATOR (write/add/? delete ?)
MUSTbe initialized with the container on wich we are iterating

*/

cout<< "AFTER THE USAGE OF A back_insert_iterator"<<endl;
back_insert_iterator < vector<int> > back_it(vi);
*back_it = 660;
/*back_it++;*/  //~~~~> no necessity to explicitely increase the iterator =>  automatically increases
*back_it = 770;

cnt = 0;
/*
for( int e: vi){
  cout<<" element #-"<<cnt <<" ==> value: "<< e<<endl;
  cnt++;
}
*/

//using the iterator to loop on container:
vector<int>::iterator iter_vi_new;
cnt =0;
for(iter_vi_new = vi.begin(); iter_vi_new != vi.end(); iter_vi_new++){
  cout<<" element #-"<<cnt <<" ==> value: "<< *iter_vi_new<<endl;
  cnt++;
}



cout << "________'copy()' usage: SUPER-CRUCIAL WHEN USING COLLECTIONS "<<endl;

vector<int> v_copy_constructor(vi);// a copy constructor is always fun
vector <int> vo(vi.size());// !! MUST BE preallocated of the exact size !!

copy(vi.begin(), vi.end(), vo.begin());
cnt =0;
for(auto e_out : vo){
cout<<" element #-"<<cnt <<" ==> value: "<< e_out <<endl;
cnt++;
}
copy(vi.begin(), vi.end(), vo.begin());

cout << "BTW: ?? vi.begin() = " <<" ERROR (iterators cannot be printed, it's like i'm trying to print a function)" << " ??"<<endl;









  cout <<"FCK you iterators"<<endl;
  return 0;
}
