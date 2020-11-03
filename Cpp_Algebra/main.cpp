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




template <class T>
T scalar_product(T a[], T b[], int n){

  T scal = 0; // non potrà mai ricevere una stringa ma int,double,float,etc.. SI

  for(int i=0; i< n; i++){

    scal += a[i]*b[i];

  }
  return scal;
}
template <class T>
T scalar_product_p(T* a, T* b, int n){

  T scal = 0; // non potrà mai ricevere una stringa ma int,double,float,etc.. SI

  for(int i=0; i< n; i++){

    scal += a[i]*b[i];

  }
  return scal;
}




template <class T>
T power(T a,int n){

  if( n<= 0){
    return 1;
  }
  else{
    return a*power(a,n-1);
  }

}

template <class T>
T module(T a[],int n){
  T m=0;

  for(int i=0; i< n; i++){

    m += power(a[i],2);

  }
  return sqrt(m);
}

template <class T>
T module_alt(T* a,int n){
  T m=0;

  for(int i=0; i< n; i++){

    m += power(a[i],2);

  }
  return sqrt(m);
}

template <class M>
void stampa_matrice(M m[]){


}

int * getRandom( int N) {

   int  r[N];

   // set the seed
   srand( (unsigned)time( NULL ) );

   for (int i = 0; i < N; ++i) {
      r[i] = rand();

   }

   return r;
}
//syntactic-sugar for take4( int* v)
int * take4(int v[]){

  int *y = new (int);

  for(int i=0; i < 4; i++){

    y[i] = v[i];

  }
  return y;
}

int * max_min(int *v, int n){
  int max = v[0];
  int min = v[n-1];
  int *y;

  for (int i=0; i< n; i++){
    if(v[i] >= max ){
      max = v[i];
    }
    if (v[i]<= min){
      min = v[i];

    }
  }


  y[0] = min;
  y[1] = max;
  return y;
}
template <class V>
V* mat_times_vect(V** A ,V* x, int n, int m){

  V* y;

  for (int i=0; i<n ; i++){
    y[i] = scalar_product(A[i],x,m);
  }

  return y;
}


int main(int argc, const char * argv[]){
cout << "\n _____________________________________________________________________\n " <<endl;
cout << "PRODOTTO SCALARE"<<endl;

float a[4] = {1,2,3,4};
float b[4] = {1,2,3,4};

float scal = scalar_product(a,b,4);
cout <<"prodotto scalare tra due array di float: "<<scal<<endl;

int a_i[4];
int b_i[4];

for(int i =0; i< 4; i++) a_i[i] = (int) a[i];
for(int i =0; i< 4; i++) b_i[i] = (int) b[i];

cout <<"prodotto scalare tra due array di int: "<<scalar_product(a_i,b_i,4)<<endl;
cout <<"prodotto scalare tra due array di int [funzione definita con puntatori]: "<<scalar_product_p(a_i,b_i,4)<<endl;

cout << "\n _____________________________________________________________________\n " <<endl;
cout << "ELEVAMENTO A POTENZA CON RICORSIONE"<<endl;

int x_p = 10;
int x_p_2 = power(x_p,2);
cout <<" elevemento: 10^2 = power(10,2) = "<< x_p_2<<endl;

int y_p = 4;
int y_p_3 = power(y_p,3);
cout <<" elevemento: 4^3 = power(4,3) = "<< y_p_3<<endl;

cout << "\n _____________________________________________________________________\n " <<endl;
cout << "ARRAY E PUNTATORI => GENERALITA"<<endl;


int array[12];
cout << "dichiarazione di un array: int array[12] "<<endl;
cout<<" C++ 'si salva' array come indirizzo del primo elemento => array = "<<array<<endl;
cout<<"                                                        => &array[0] = "<<&array[0]<<endl;

/*
questa sintassi è davvero fondamentale:
tipo array[N];
tipo * point_array;
point_array = array;

IL SENSO E' CHE UN ARRAY E' GIA UN PUNTATORE DI PER SE STESSO
*/


float* pa;
pa = a;

float *ppa;
ppa = &a[0];

cout<<" float a[4] = {1,2,3,4}; pa = a "<<endl;
cout<<" indirizzo di memoria a cui punta pa: pa = "<< pa<<endl;
cout<<" indirizzo di memoria del primo elemento dell'array a = "<<a<<endl;
cout<<" dereference di pa: *pa = "<< *pa<<endl;
cout<<" float a[4] = {1,2,3,4}; *(pa+2) = " <<*(pa+2)<<" pa[2] = " <<pa[2]<<endl;


if(pa == &a[0]){

  cout <<"OK, il mondo ha ancora un senso"<<endl;

}

cout <<"... un'altra enorme verita: UN PUNTATORE SI COMPORTA GIA COME UN ARRAY"<<endl;
float *pt_f = new (float);

pt_f[0] =1.111;
pt_f[1] =2.222;
pt_f[2] =3.333;

cout<<pt_f[0]<<endl;
cout<<pt_f[1]<<endl;
cout<<pt_f[2]<<endl;
cout<<pt_f[3] << " and this value is random";
cout << "\n _____________________________________________________________________\n " <<endl;
cout << "ARRAY E PUNTATORI => FUNZIONE MODULO"<<endl;

float mod_a = module(a,4);
cout <<"modulo di un array: "<<mod_a<<endl;

float mod_pa = module(pa,4);
cout <<"modulo di un array: "<<mod_pa<<endl;

cout<<" ridefinire la funzione accettando un puntatore non cambia nulla \n module_alt(float[] a,int n) == module_alt(float* pa,int n) = "<< module_alt(pa,4)<<endl;
cout<<"anzi è proprio la notazione funz(int v[],...) ad essere 'syntactic-sugar' " <<endl;//https://stackoverflow.com/questions/3473438/return-array-in-a-function

cout << "\n _____________________________________________________________________\n " <<endl;
cout << "ARRAY E PUNTATORI => MAX e MIN DI UN ARRAY, [RITORNATO COME ARRAY DI LUNGHEZZA 2]"<<endl;

// la sfida è una funzione che ritorni y = {min,max}

int t[8] = {1,2,5,2,0,99,44,22};
int *m_m = max_min(t,8);

cout << "array: double t[8] = {1,2,5,2,0,99,44,22}; \n => min: "<< m_m[0]<<"\n => max: "<<m_m[1]<<endl;


int *random_array = getRandom(3);
cout << "random array di lunghezza 3: {"<<random_array[0]<<"-"<<random_array[1]<<"-"<<random_array[2]<<"}"<<endl;

int tt[7] = {1000,2,4,5,5,6,7};
int *taken = take4(tt);
cout <<taken[0]<<endl;
cout <<taken[1]<<endl;
cout <<taken[2]<<endl;
cout <<taken[3]<<endl;





cout << "\n _____________________________________________________________________\n " <<endl;
cout << "MATRICE => SEMPLICEMENTE "<<endl;

float W[2][2];

W[0][0] = 1; W[0][1] = 2;
W[1][0] = 3; W[1][1] = 4;

// per accedere agli elementi;

//-> questa roba qui dovrebbe tornare un pointer (array),
cout <<"W[0] = "<< W[0]<< " ( puntatore ad array <==> indirizzo di memoria primo elemento array)" <<endl;
//      + precisamente un puntatore al primo elemento dell'array della prima riga, infatti:
cout<< " infatti *W[0] = " << *W[0]<<endl;
cout <<" peraltro *(W[0] +1) = " << *(W[0]+1) << " . coincide col secondo elemento della prima riga,\n sempre interrogabile come:  W[0][1] = "<< W[0][1]  <<endl;

float x[2];

x[0] = 1;
x[1] = 2;


cout << "\n _____________________________________________________________________\n " <<endl;
  cout <<"GoodBye World"<<endl;





}
