#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <pthread.h>
#include<unistd.h>

using namespace::std;



/*
main() is a single default thread.
 => create a new-one by invoking: pthread_create()
                                 * callable anywere in the code,
                                 * callable anytime needed
 pthread_create(pthread_t *thread, pthread_attr_t *attr,void *(*start_routine)(void*), void* arg )

 WHERE:
   ~> thread = identifier to a new  thread { is a pointer to pthread_t struct}
   ~> attr  = is an attribute object that might be used for setting threads attributes
   ~> start_routine = is the routine the thread will execute once created
                     {HAVE TO PASS:
                     THE ADDRESS OF A FUNCTION input => (*void) POINTER TO A VOID &&
                                               output =>(*void) POINTER TO A  VOID }

   ~> arg = single argument that can be passed to start_routine
             {MUST BE PASSED AS A VOID POINTER}

this function returns 0 if thread is created, otherwise an error is given
*/

void* printSomething(void * msg_from_thread){
  for(int i=0; i< 10; i++){
  cout << "Hello from Thread"<<endl;
}
  return msg_from_thread;
}

void* threadableFunction(void* msg_from_thread){

  char* ps = (char*) msg_from_thread;
  int size_message_t =sizeof(msg_from_thread)/sizeof(char);

  for(int i =0; i<10; i++){

    cout<< "iteration #-"<<i<<" => message: ";
    for (int j=0; j< 30; j++){
    cout<< *(ps+j);
  }
  cout<<endl;
  }
  return msg_from_thread;
  pthread_exit(NULL);
}

void* producerThread(void* p_cc){

  int r_add;

  for (int i=0; i< 10; i++){

  int* p_cc_int = (int*) p_cc;

  r_add = rand()%10;
  *p_cc_int = *p_cc_int + r_add;
  cout << "[PRODUCER #-"<<i<<"]=> Current C.C. value: "<< *p_cc_int <<"\n"<<endl;
  p_cc = (void*)p_cc_int;

  int r_sleep;
  r_sleep = rand()%100*10;
  usleep(r_sleep);
}


  return NULL;
  pthread_exit(NULL);
}

void* consumerThread(void* p_cc){
  int r_sub;
  for (int i=0; i< 10; i++){

  int* p_cc_int = (int*) p_cc;


  r_sub = rand()%10;
  *p_cc_int = *p_cc_int - r_sub;
  p_cc = (void*)p_cc_int;
  cout << "[CONSUMER #-"<<i<<"]=> Current C.C. value: "<< *p_cc_int <<"\n"<<endl;

  int r_sleep;
  r_sleep = rand()%100*10000;
  usleep(r_sleep);



}


return NULL;
pthread_exit(NULL);
}


typedef struct varRW{

  bool writer;// determines if the thread is a reader or a writer.
  int* point_sv;// integer shared variable for the thread,

}var_rw_t;


void* threadRW(void* p_var_struct){

  cout<<"Function called: first call"<<endl;

 var_rw_t* p_struct = (var_rw_t*) p_var_struct;
for (int i = 0; i< 10; i++){

   if (p_struct -> writer){

     int* p_temp = p_struct->point_sv;
     cout << "[WRITER] read value: "<< *(p_struct -> point_sv);
     *p_temp = rand()%10;

     cout << " new written value: "<<*(p_struct -> point_sv) <<endl;


   }
  else{

    cout << "[READER] read value: "<< *(p_struct -> point_sv) <<endl;
  }


  int r_sleep;
  r_sleep = rand()%100*10000;
  usleep(r_sleep);
  }
return NULL;
pthread_exit(NULL);
}
pthread_mutex_t mutex_rw = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t mutex_rw_cond = PTHREAD_COND_INITIALIZER;

void* threadSynchroRW(void* p_var_struct){

 var_rw_t* p_struct = (var_rw_t*) p_var_struct;
for (int i = 0; i< 10; i++){


  pthread_mutex_lock(&mutex_rw);

   if (p_struct -> writer){

     int* p_temp = p_struct->point_sv;
     cout << "[WRITER] read value: "<< *(p_struct -> point_sv);
     *p_temp = rand()%10;

     cout << " new written value: "<<*(p_struct -> point_sv) <<endl;



   }
  else{

    cout << "[READER] read value: "<< *(p_struct -> point_sv) <<endl;

  }

  int r_sleep;
  r_sleep = rand()%100*10000;
  usleep(r_sleep);

  pthread_mutex_unlock(&mutex_rw);



  }
return NULL;
pthread_exit(NULL);
}




// it's sufficient to declare the mutex as a global variable
pthread_mutex_t mutex_cc = PTHREAD_MUTEX_INITIALIZER;
  // ?? conditions  on threads?? => ask for mutex condition =>
                    //pthread_cond_t mutex_cond = PTHREAD_COND_INITIALIZER;



void* consumerSynchroThread(void* p_cc){

  int r_sub;
  for (int i=0; i< 10; i++){

  int* p_cc_int = (int*) p_cc;
  cout << "[CONSUMER #-"<<i<<"]=> Current C.C. value: "<< *p_cc_int <<"\n"<<endl;
  r_sub = rand()%10;

  if(*p_cc_int - r_sub >= 0){
   *p_cc_int = *p_cc_int - r_sub;
   p_cc = (void*)p_cc_int;

  int r_sleep;
  r_sleep = rand()%100*10;
  usleep(r_sleep);
}
else{
  cout << "mutex-locked access to C.C., => 'virtual C.C. value:' "<< *p_cc_int - r_sub <<endl;
  pthread_mutex_lock(&mutex_cc);
}


}
return NULL;
}

void* producerSynchroThread(void* p_cc){

  int r_add;

  for (int i=0; i< 10; i++){

  int* p_cc_int = (int*) p_cc;

  cout << "[PRODUCER #-"<<i<<"]=> Current C.C. value: "<< *p_cc_int <<"\n"<<endl;
  r_add = rand()%10;
  *p_cc_int = *p_cc_int + r_add;


  p_cc = (void*)p_cc_int;

  int r_sleep;
  r_sleep = rand()%100*10;
  usleep(r_sleep);
  pthread_mutex_unlock(&mutex_cc);
}
return NULL;
}

int main(){


  // testing the start_routine function by it's own:
  cout << "\n____Testing the threadble function in main___\n "<<endl;
  char message[30] = "hello from main";
  void* t_pv =threadableFunction(message);


  // testing multithreading on a simple function:
  cout << "\n____Testing a simple function passed to pthread_create___\n "<<endl;
  pthread_t t1; // ~> pointer to a thread_t structure!!
  int tc = pthread_create(&t1, NULL, printSomething,NULL);
  /* AS ALWAYS:
              thread is started parallel to main() execution => could end before
                                      => invoke .join() to synchronize the thread*/
  if(tc){
      cout <<" unable to create & start the thread "<<endl;
  }
  else{

      bool join = true;
      if(join){
      pthread_join(t1,NULL);
    }
  }




   // putting the original function into a thread:
   pthread_t t2;
   char message_thread[30] = "hello Vasile from thread";


   cout << "\n____Testing threadable function passed to pthread_create with the parameter___\n "<<endl;
   pthread_create(&t2, NULL, threadableFunction,message_thread) ;
   pthread_join(t2,NULL);


   //concurrency between two threads.
   cout << "\n____Testing the C.C. issue between multiple producer/consumer___\n "<<endl;


   int cc = 10;

   pthread_t pt,ct1,ct2;
   bool synchro = true;

   if (!synchro){
   pthread_create(&ct1, NULL, consumerThread, &cc);
   pthread_create(&ct2, NULL, consumerThread, &cc);
   pthread_create(&pt, NULL, producerThread, &cc);
   pthread_join(pt,NULL);
   pthread_join(ct1,NULL);
   pthread_join(ct2,NULL);
 }
 else{

   /* MUTEX-MECHANISM => one thread at the time can acquire the lock!!
                        all other threads cannot access a shared variable,
                        until the the thread whom holds the lock doesn't release
                        that f*cking lock.

      MUTEX-PURPOSE => prevent from data inconsistencies for multiple threads
                      upon the same ara performead at rhe same time and/or
                      avoiding race-conditions.

      IMPORTANT CONSIDERATION=> MUTEX can be used between THREADS, while
                                SEMAPHORES can be used ALSO between PROCESSES.


   */
   pthread_create(&ct1, NULL, consumerSynchroThread, &cc);
   pthread_create(&ct2, NULL, consumerSynchroThread, &cc);
   pthread_create(&pt, NULL, producerSynchroThread, &cc);

   bool join_all_threads = true;
   if (join_all_threads){
   pthread_join(pt, NULL);
   pthread_join(ct1, NULL);
   pthread_join(ct2, NULL);
 }
}






 cout << "\n____Testing the RW issue between multiple producer/consumer\n  => guarantee acid operation between reading & writing___\n "<<endl;

 int shared_variable = 10;
 var_rw_t shared_struct_writer;
 var_rw_t shared_struct_reader;

 shared_struct_writer.writer = true;
 shared_struct_writer.point_sv = &shared_variable;

 shared_struct_reader.writer = false;
 shared_struct_reader.point_sv = &shared_variable;

bool sync_rw_function = true;
pthread_t rt, wt;

if (!sync_rw_function){


    pthread_create(&wt, NULL, threadRW, (void*) &shared_struct_writer);
    pthread_create(&rt, NULL,threadRW,(void*) &shared_struct_reader);
    pthread_join(wt, NULL);
    pthread_join(rt,NULL);
}

else{

  pthread_create(&wt, NULL, threadSynchroRW, (void*) &shared_struct_writer);
  pthread_create(&rt, NULL,threadSynchroRW,(void*) &shared_struct_reader);
  pthread_join(wt, NULL);
  pthread_join(rt,NULL);


}
  /*
  TO LAUNCH THIS SCRIPT: g++ main.cpp -lpthread -o exec
  need to include the default library for lpthread
  */
  cout << " end of dealing with POSIX =>  multithread in C++"<<endl;




   return 0;
 }
