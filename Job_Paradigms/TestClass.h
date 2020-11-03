#include <iostream>
#include <string>
#include <fstream>
/*
Questo è il paradigma usato in 3dtLib/source/utility/parser/ini.cc


*/

class TestClass
{

public:
  std::string conf_string;
  //constructor with default stuff.
public:
  TestClass(std::string &conf_string_, bool path = true);
};
