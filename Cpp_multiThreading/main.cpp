#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <set>
#include<thread>
#include <unistd.h>// library for time.sleep

using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::pair;
using std::set;
using std::thread;

void threadableFunction(){

  for (int i=0; i< 10; i++){
  cout<< " command #-"<<i<<endl;
  usleep(rand() % 1000);
}
}
/*
As with much of the C++ Standard Library,
std::thread works with any callable type, so you can pass an instance of a class
 with a function call operator to the std::thread constructor instead:
*/

class background_task{
public:
  string t_name;
  int t_limit;
public:
  background_task(string name , int limit){
    t_name = name;
    t_limit = limit;

  }

  // this is the equivalent of java .run()
  void tf() const{

    for (int i=0; i< t_limit; i++){
    cout<< t_name << " say #-"<<i<<"/"<<t_limit-1<<endl;
    usleep(rand() % 1000000);
  }
}
  // void operator()() => to be overloaded in order to be passed to thread's constructor:
  //                 thread(class_that_overloads_operator()())
  void operator()() const
    {
      tf();
    }
};

int main(int argc, const char * argv[]){

  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n STANDARD MULTI-THREADING [NO-CONCURRENCY]"<<endl;

  // thread constructor: requires a function to be run!
  cout<< "make it easy: a thread object receiving a void function:\n void tf(){..}; \n thread t(tf)\n t.join();"<<endl;
  thread t(threadableFunction);
  t.join();

  cout<< " little-bit harder: wrap your function in a class implementing operator()() ==> a callable class."<<endl;
  background_task bt1("thread-1",11);
  background_task bt2("thread-2",11);

  thread t_wrap1(bt1);
  thread t_wrap2(bt2);

  t_wrap1.join();
  t_wrap2.join();









  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n CUDA MULTI-THREADING "<<endl;

  // main abstractions are kernels




cout << "\n ______________________________________________________\n " <<endl;
  cout << "\n GoodBye World"<<endl;
}
