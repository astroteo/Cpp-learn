#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include<sys/types.h>// ~> first library supporting multiprocessing
#include<unistd.h>// ~> second library supporting multiprocessing

using namespace::std;
#define MAXHOSTNAME 256;



int main(){

  struct sockaddr_in socketAddress;
  char sysHost[MAXHOSTNAME];
  int portNumber = 8080; // >4096 x multicast
  


  int sd;




}
