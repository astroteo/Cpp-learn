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

void writer( const char* message, int count, FILE *stream){
  for(; count >0; --count){
    fprintf(stream,"%s\n", message);
    fflush(stream);
    sleep(1);
  }
}


void reader(FILE *stream){
  char buffer[1024];
  /* read until the end of the stream is reached,
  read until a new line or the end-of-file*/

  while(!feof(stream) && !ferror(stream) && fgets(buffer, sizeof(buffer),stream) != NULL){

    fputs(buffer,stdout);

  }
}

int main(){

  cout<<" trying to create a UNIX-pipe => a sort of 'buffer' for writing data, shared between processes!!"<<endl;

  FILE *stream;
  /* create the pipe => place 2 ends pipe file descriptor at the end of it*/
  int fds[2];
  pipe(fds);

  // fork the main process => CHILD ~> consumer, PARENT ~> producer
  pid_t pid = fork();

  if(pid ==(pid_t) 0){ //CHILD <-> CONSUMER

    // 1 => close the stream:
    close(fds[1]);

    // 2 => re-open the stream [reading-mode], at the initial point of the pipe
    stream = fdopen(fds[0],"r");

    // 3 => give the stream to the reader
    reader(stream);

    //4 =>  close the stream at the beginning:
    close(fds[0]);
  }
  else{ //~> FATHER <-> PRODUCER

    // 1 => close the stream at the beginning
    close(fds[0]);

    // 2 => open the stream [writing-mode], at the bottom of the file
    stream = fdopen(fds[1],"w");

    // 3 => pass to writer function
    writer("Hello from parent,",10,stream);

    // 4 => close the stream.
    close(fds[1]);



  }


  return 0;
}
