#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <pthread.h>
#include<sys/types.h>// ~> first library supporting multiprocessing
#include<unistd.h>// ~> second library supporting multiprocessing

using namespace::std;

void char_at_a_time(const char* str){
  while(*str != '\0'){
    putchar(*str++);// increment pointer
    fflush(stdout);// fflush() put to stdout [ or any other stream ] without buffering
            /*
            here is crucial since it's assumed that the 2 processes, will
            communicate on a stream that is the stdout
            */
    usleep(50);
  }
}
int spawn(const char *program, char ** args){

  pid_t child_pid = fork(); // create a parallel process,

  if(child_pid!=0){
    return child_pid; /* this is the parent process speaking, else the value 0
                        is assigned to child_pid IN the child process*/

  }
  else{

    execvp(program, args);/*executing the program in child process*/
    cout << "An error occurred in execvp"<<endl;
    abort();




  }
}
int main(){

  cout << " \n ___________fork() COMMAND AND SYNCHRONIZATION IN MULTIPROCESSING_________________ \n "<<endl;
  int example =3;
  if (example ==1){

  pid_t child_pid;
  cout << "main() process ID is pid = "<<(int) getpid()<< " => main()'S parent process ID is ppid = "<< (int) getppid()<<endl;


  child_pid = fork();// ==> pid  the first time is called
                    // ==> 0 second time it's called
                    // ==> process it's executed down from this line

  if(child_pid != 0){
    cout <<" forked process => process ID is pid = "<<(int) getpid()<<endl;// mi aspetto sia uaguale al main()
    cout<< "created copy of main() process\n Parent say: child's process id is pid =  "<< child_pid <<endl;

  }
  else{
    cout << "Child say: my process id is pid = " <<(int) getpid() <<"\n while my parent id is pid = "<< (int) getppid()<<endl;
  usleep(20000);
  }
  /*
  bool flag = true;

  if (flag){
    usleep(2000000);
    flag = false;
  }*/

}

else if(example == 2){

  bool sync = true;


  if(fork()==0){

    char_at_a_time("...........");


  }
  else{


    if(sync){
      // make a guess: make the parent to wait for the child to finish before going further
      // => desired output .....||||||
      /* E.g. The parent process forks a child process to perform a computation, goes on in
     parallel, and then it reaches an execution point where it needs to use the output
     data of the child process*/

      wait(NULL); // block itself until status changes in the child
    }
    char_at_a_time("||||||||||||");
  }





}
else if (example == 3){

  cout << "aaahAHAHAHAHA run a program from this program "<<endl;
  char prog_path[] = "./exec_test";

  spawn(prog_path,NULL);// equivalent: execl(prog_path, NULL);
  execl(prog_path, NULL);
}
else if (example == 4){



}









  return 0;
}
