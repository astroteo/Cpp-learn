#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <unistd.h>// library for time.sleep
#include <vector>


#include <pthread.h> // multithread library for a unix machine.

using namespace::std;


void* countAgain(void *n){
   int* n_;
   n_ = (int*) n;
   cout <<"setted iterations = "<< *n_ <<endl;

   for (int i =0; i< *n_; i++){

     cout << "iter #- "<< i<< " Hello from me "<< endl;
     usleep(rand() % 1000);
   }

  return NULL;


}



typedef struct input_thread{

  int count;
  string message;

}input_thread_t;





void* messageNtimes(void* st_n_m){
   input_thread_t* st_n_m_;
   st_n_m_ = (input_thread_t*) st_n_m;


   int n_ = st_n_m_->count;

   for (int i =0; i< n_; i++){

     cout << "iter #- "<< i<< " Hello from thread "<<st_n_m_->message << endl;
     usleep(rand() % 10000);
   }

  return NULL;


}


typedef struct sharedVar{

  int curr;
  string name;

}svar_t;

typedef struct sharedVarThread {

  svar_t shared_variable;
  int n_operations;

}svar_thread_t;

pthread_mutex_t lock_sv = PTHREAD_MUTEX_INITIALIZER;
vector<int> all_sv_states;

void* consumerFunc(void* svar_cons){

  svar_thread_t* p_svar_thread;

  p_svar_thread = (svar_thread_t*) svar_cons;


  int n_ops = p_svar_thread -> n_operations;

  for(int n=0; n<n_ops; n++){

   int delta = (rand()%10)*2;
   if(p_svar_thread -> shared_variable.curr   - delta <0 ){

     pthread_mutex_lock(&lock_sv);
     cout << "temporary locked state"<<endl;

   }
   else{

     p_svar_thread -> shared_variable.curr = p_svar_thread -> shared_variable.curr   - delta ;
     all_sv_states.push_back(p_svar_thread -> shared_variable.curr);
 }

   cout << "C-thread =>\n iter"<< n << " ops: -"<< delta << " current " <<p_svar_thread ->shared_variable.name <<" stored value: "<< p_svar_thread ->shared_variable.curr <<endl;
   usleep(rand() % 100000);


  }

  return NULL;

}

void* producerFunc(void* svar_cons){

  svar_thread_t* p_svar_thread;

  p_svar_thread = (svar_thread_t*) svar_cons;


  int n_ops = p_svar_thread -> n_operations;

  for(int n=0; n<n_ops; n++){

   int delta = rand()%10;
   p_svar_thread -> shared_variable.curr = p_svar_thread -> shared_variable.curr + delta ;

   cout << "P-thread =>\n iter"<< n << " ops: +"<< delta << " current " <<p_svar_thread ->shared_variable.name <<" stored value: "<< p_svar_thread ->shared_variable.curr <<endl;
   all_sv_states.push_back(p_svar_thread -> shared_variable.curr);

   usleep(rand() % 100000);
   pthread_mutex_unlock(&lock_sv);
   }

  return NULL;

}






int main(){// a main is alwais a single default thread --> all other threads need to be created.

  cout <<"____ BASIC CASE _____"<<endl;
  bool basic = false;

  if (basic){
  // 1 ==>  define a pointer to a pthread_t struct.
  pthread_t th1; // define an object pthread_t

  //2 ==> define a pointer to an a pthread_attr_t struct
  pthread_attr_t attr;


  //3 => USELESS define a pointer to a function that accepts as parameter : pointer to void and returns a pointer to void again
  typedef void* (*Pt_fun_thread)(void* n_times);
  Pt_fun_thread pt_f_thread;
  pt_f_thread = countAgain;

  // 4 => define the arguments to be sent to the thread function => will be casted to void
  int* n_count = new (int);
  *n_count = 10;

  // 5 => launch and start the thread, 0 -> success, 1 -> failure
  int success = pthread_create( &th1, NULL, countAgain,(void*) n_count);

  if (!success){
    cout << "thread has correctly started"<<endl;
    pthread_join(th1,NULL); // join the thread with main() thread
  }
}


bool non_mutex = false;
if (non_mutex)
{
cout <<"____ NONMUTEX  CASE _____"<<endl;
/* new excercise with  multiple threads receiving a struct as input*/
input_thread_t inp[5];
pthread_t pt_array[5];

int cnt =0;

for (int i=0; i<5; i++){

  (inp+i)->count = 10;
  (inp+i)->message = to_string(i);

  cnt++;

}

for (int i=0; i<cnt; i++){

  int success_i = pthread_create( &pt_array[i], NULL, messageNtimes,(void*) (inp+i));
  if(!success_i){
    pthread_join(*(pt_array +i),NULL);
  }

}
}


cout <<"____ PRODUCER-CONSUMER PARADIGM _____"<<endl;

bool prod_cons = true;

if(prod_cons){

  pthread_t c_th1;
  pthread_t c_th2;
  pthread_t p_th;

  svar_t sv;

  sv.curr = 10;
  sv.name = "shared variable";

  svar_thread_t* p_sv_th = new (svar_thread_t);
  p_sv_th -> shared_variable = sv;
  p_sv_th -> n_operations = 10;

  int success_c1 = pthread_create(&c_th1, NULL, consumerFunc,(void*) p_sv_th);
  //int success_c2 = pthread_create(&c_th2, NULL, consumerFunc,(void*) p_sv_th);
  int success_p = pthread_create(&p_th, NULL, producerFunc,(void*) p_sv_th);
  if(!success_c1 && !success_p){

    cout << "All thread successfully started"<<endl;
    pthread_join(c_th1, NULL);
    //pthread_join(c_th2, NULL);
    pthread_join(p_th,NULL);

  }

  cout << "All consecutive states for the shared variable: "<<endl;
  for(auto s: all_sv_states){

    cout << s <<endl;
  }


}










  cout << "Hello, what the fuck"<<endl;
}
