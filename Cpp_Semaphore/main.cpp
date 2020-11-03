#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>// Library for threading !!!

void *print_message_function( void *ptr );
using namespace::std;



void *print_message_function( void *ptr );


int main(int argc, const char * argv[]){

    /* var_t => The t stands for "type" or "typedef."
    You'll see a lot of POSIX headers (and others) with time_t, size_t, and others.

    These which hold (not necessarily defined) specific bit-sizes based on
    the operating system and machine architecture.*/

     pthread_t thread1, thread2;

     const char *message1 = "Thread 1";
     const char *message2 = "Thread 2";
     int  iret1, iret2;


  cout << "Hello pthread library works, wihtout building with an external library" <<endl;

  cout << "... testing print_message_function! insert a message: "<<endl;

  char* msg = new char[20];
  cin >> *msg;
  print_message_function((void*)msg);

  iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
}

void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
   }
