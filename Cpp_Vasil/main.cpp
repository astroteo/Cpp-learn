#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <unistd.h>
#include <vector>
using namespace::std;
int pid;

int  main (int argc, const char * argv[]){
  pid = fork();
  //int pid2;
  //pid2 =fork();
      // return 0 ~~> child process
      // return 1 ~~> father process


  if (pid == 0){                // id child process     // id father process
    cout <<" generated a child: "<<getpid()<<  " --- "<<getppid()<<endl;
    execl("./exec_from_main",0);
  }
  else if (pid<0){
    cout <<"error"<<endl;

  }
  else {

    cout <<" generated a father"<<endl;
    sleep(9); // must be ensured that father ends later
  }

  cout << "EHLLO "<< "F "<< getpid()<<  " --- "<< "C: "<<getppid()<<endl;

  return 0;
}
