#include <vector>
#include <iostream>

class Wrap{

  std::vector<int> v;
public:
  Wrap(std::vector<int> &v_);
public:
  void
  print()
  {
    for(auto vel:v)
    {
      std::cout <<vel<<std::endl;
    }
  }

};
