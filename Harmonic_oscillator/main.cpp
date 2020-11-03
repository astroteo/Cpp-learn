/*
How to use Odeint library => that's also the first external library we are trying to manage

Il linguaggio C e l’ambiente Unix forniscono tre strade per suddividere il codice:
1. inclusione diretta di file sorgente e compilazione unica;
2. inclusione di header file e compilazione separata;
3. creazione di librerie statiche o dinamiche.

1) => installing Boost: ~$ brew install boost
2) => find boost location: ~$ brew info boost
                                  --> /usr/local/Cellar/boost/1.67.0_1
                                  --> /usr/local/Cellar/boost/1.67.0_1/include (probably this is the right path)

~$pwd (!! super-usefull command to see the folder in wich you are)

3) => compile as: ~$ g++ -I  /usr/local/Cellar/boost/1.67.0_1/include/ -o exec main.cpp

4) => create simlink to boost, in order to compile faster
                ~$ ln -s /usr/local/Cellar/boost/1.67.0_1/include/  boost
   =>to compile ~$ g++ -I boost main.cpp -o exec
*/

#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include<math.h>
using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::pair;

#include <boost/numeric/odeint.hpp>
using boost::numeric::odeint::runge_kutta4; // -> it's a template
using boost::numeric::odeint::integrate_const; // -> it's a template
using boost::numeric::odeint::integrate; // -> it's a template
/*
 create a void container function that implements the ODE
 dz/dt^2 + gam * z =f/m

 this is straigth-forward passed to states: !! LIKE IN MATLAB ODE btw !!
 x = { z,dz } => dx = { dz,ddz } => dx[0] =  x[1], dx[1] = -gam * x[0]
 !! this is a void !!
*/
typedef std::vector< double > state_type;

const double gam = 0.1;
const double k = 1;

void harmonic_oscillator(const state_type &x,  state_type &dxdt,  double /* t */){

  dxdt[0] = x[1];
  dxdt[1] = -k * x[0];

}
void harmonic_oscillator_damped(const state_type &x,  state_type &dxdt, double /* t */){

  dxdt[0] = x[1];
  dxdt[1] = -gam * x[1]- k * x[0];

}

/*
n C++ the only difference between a class and a struct is that:
 --> members and base classes are PRIVATE by default in classes,
 --> members and base classes are PUBLIC by default in structs.

So structs can have constructors, and the syntax is the same as for classes.



*/

struct push_back_state_and_time
{
    vector< state_type >& m_states;
    vector< double >& m_times;

    /*INITIALISATION-LIST: see the reflections.cpp file to understand this constructor
      **************************************************************************
      * THIS IS THE ONLY WAY IN WHICH YOU CAN INITIALIZE A CLASS MEMEBER       *
      * THAT IS A REFERENCE:                                                   *
      *                         vector< state_type >& m_states                 *
      * CANNOT BE SET VIA CONSTRUCTOR AS:
      *                         cosntr(  vector< state_type >& c_states ){
      *                                   m_states = c_states;
      *                                              }
      **************************************************************************
    */

    push_back_state_and_time( vector< state_type > &states ,vector< double > &times)
    : m_states( states ) , m_times( times ){ } // also struct allows constructor ??

    /*This is the INLINE CONSTRUCTOR:
    see reflections.cpp*/

    void operator()( const state_type &x , double t )
    {
        m_states.push_back( x );
        m_times.push_back( t );
    }

    /*

    ?? l'observer chiamato dalla ode deve implmeentare operator() ??

    YES:Note, the argument structure of the ()-operator: odeint calls the observer exactly in this way,
    providing the current state and time.
    Now, you only have to pass this container to the integration function.
    https://www.boost.org/doc/libs/1_61_0/libs/numeric/odeint/doc/html/boost_numeric_odeint/getting_started/short_example.html

    */
};

// Let's try re-implement a container using a standard c++: NOT WORKING BECAUSE ODE IMPLEMENTATION
//                                                         REQUIRES REFERENCE ATTRIBUTES
struct push_back_state_and_time_BAD
{
    vector< state_type > m_states; // here is requred a reference memeber
    vector< double > m_times;

    push_back_state_and_time_BAD( vector< state_type > &states ,vector< double > &times);

    void operator()( const state_type &x , double t )
    {
        m_states.push_back( x );
        m_times.push_back( t );
    }
};

push_back_state_and_time_BAD :: push_back_state_and_time_BAD( vector< state_type > &states ,vector< double > &times){
  m_states = states;
  m_times = times;
}

int main(int argc, const char * argv[]){

  //                          Integration with Constant Step Size:

  //[initial conditions
  state_type x(2);
  x[0] = 0;
  x[1] = 0.1;
  //]

  //[ integration
  runge_kutta4<state_type> solver;

  //[ fast approach {adaptive}
  // default:

   size_t steps = integrate( harmonic_oscillator ,
        x , 0.0 , 10.0 , 0.1 ); // this functions returns only the number of steps used for the integration

//]

cout << " steps used for the integration: steps = "<<steps<<endl;

/* to actually retrieve the datas, an observer has to be passed to the integrator */
vector<state_type> x_vec;
vector<double> times;
size_t steps1 = integrate( harmonic_oscillator ,
        x , 0.0 , 10.0 , 0.1 ,
        push_back_state_and_time( x_vec , times ) );

for( size_t i=0; i<=steps1; i++ )
{
    cout << "time: "<< times[i] << '\t' <<" position: " <<x_vec[i][0] << '\t' <<"velocity: "<< x_vec[i][1] << '\n';
}

/* harmonic_oscillator_damped with different container implementing operator()*/







cout <<"GoodBye World, we played with ODEs \n Always a pleasure! "<<endl;
}
