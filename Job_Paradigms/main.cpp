#include <iostream>
#include<vector>

#include "wrap.h"
#include "TestClass.h"

using namespace std;


int main()
{
  cout << "___________CONSTRUCTOR BY REFERENCE ___________"<<endl;
  vector<int> v_;
  v_.reserve(10);

  for (int i =0; i< 10; i++)
  {
    v_.push_back(i);

  }
  cout<< "FUCK"<<endl;

  Wrap w(v_);
  w.print();

  cout << "___________CONSTRUCTOR WITH REFERENCE VALUE ___________"<<endl;
  std::string conf_string_;
  conf_string_ = "hello";
  TestClass tc(conf_string_);

  conf_string_ = "FUCK";

  std::cout << "conf_string_ = "<< conf_string_<<std::endl;
  std::cout << "tc.conf_string = " << tc.conf_string<< std::endl;

  tc.conf_string = "FUCK-YOU-THIS-IS-A-USEFULL-CONSTRUCTOR-OR-NOT??";

  std::cout << "conf_string_ = "<< conf_string_<<std::endl;
  std::cout << "tc.conf_string = " << tc.conf_string<< std::endl;



}
/*
compile here:
g++ -c Wrap.cpp
g++ -c TestClass.cpp
g++ -c main.cpp

g++ -o exec Wrap.o, TestClass.o, main.o



*/
