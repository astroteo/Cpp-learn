#include "TestClass.h"

TestClass::TestClass(std::string &conf_string_, bool path)
{
  if(path)
  {
    std::cout << " Correctly called constructor with a default value "<<std::endl;
    conf_string = conf_string_;
  }
}
