#include <iostream>
#include <thread>
#include <unistd.h>


void sayHello10Times ();
void sayHello(int i);
void sayFuck(int i);
void func_par(int n_times, const std::string &s);
void task1(int n_times);



class BackGroundTask
{

  public:
    int n_times;
    char* name;

    BackGroundTask(int n_times_, char* name_){n_times = n_times_; name = name_;}

  public:
      void operator()() const // overloading operator()() => that's enough to pass the function to the thread
      {
      for (int i=0; i< 10; i++)
        {
          sayHello(i);
          sayFuck(i);
          usleep(1000000/2);

        }
      }
};

using namespace std;

int main()
{
  /* TEST-1 */
  bool simple_threading_test = false;
  if(simple_threading_test)
  {
    thread t1(sayHello10Times);
    thread t2(sayHello10Times);
    t1.join();
    t2.join(); // join the thread to main thread
}

/* TEST-2 */
bool class_thread_test = false;
if(class_thread_test)
{
  BackGroundTask bkg_task(10, "th-1");

  thread t_joined(bkg_task);
  thread t_detached(bkg_task);
  t_detached.detach();
  t_joined.join();

}

/* TEST-3 */
bool pass_par_to_thread_func = false;
if(pass_par_to_thread_func)
{

  thread t_func(task1,10);

}



  cout <<" main thread ended !!"<<endl;
  return 0;
}

void sayHello10Times()
{
  for (int i=0; i< 10; i++)
  {
    cout << " hello #-" << i <<endl;
    usleep(1000000);

  }
}

void sayHello(int i)
{

  cout << " hello #- "<< i <<endl;

}
void sayFuck(int i)
{
  cout << " Fuck #- "<< i <<endl;
}

void func_par(int n_times, const std::string &s){
  cout <<s<<endl;
}

void task1(int n_times)
{
  for(int i=0; i<n_times; i++)
    cout << "task1 says: " << endl;
}
