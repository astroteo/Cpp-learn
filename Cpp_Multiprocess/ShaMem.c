#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <pthread.h>
#include<sys/types.h>// ~> first library supporting multiprocessing
#include<unistd.h>// ~> second library supporting multiprocessing

//sha-mem libraries => F*ck you mississippi
#include<fcntl.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/mman.h>

using namespace::std;

int main(){

  cout << "Dealing with ShaMems => a piece of memory shared between processes!!\n"<<endl;

  const char* shm_name ="/AOS";
  const int SIZE = 4096;
  const char* message[] = { "this ","is","going","2","be","written","on" ,"a" ,"ShaMem"};

  int i, shm_fd;
  void* ptr;

  shm_fd = shm_open(shm_name, O_CREAT | O_RWDR, 0666);

}
