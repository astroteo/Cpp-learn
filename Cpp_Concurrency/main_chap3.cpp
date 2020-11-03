#include <iostream>
#include <thread>
#include <unistd.h>


using namespace std;

void func();

int main()
{

  /* TEST-1: on initialization via function with parameters */
  bool test1 = true;
  if(test1)
  {
  thread t(func);
  }


  /* TEST-2: */
  cout <<"end of MTh"<<endl;
  return 0;
}

void func() {
  int N=10;
  for(int i=0; i<N; i++)
      {
        cout << "si "<<endl;
      }
}
