#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>

using namespace::std;

int factorial(int n){

  int f;
  if(n<=0){
    f =1;
  }
  else{
    f = n*factorial(n-1);
  }
  return f;

}


int factorial_vector(int n, vector <int> &fseq){


  int f;
  if(n<=0){
    f =1;
  }
  else{
    f = n*(factorial_vector(n-1,fseq));
  }

  fseq.push_back(f);
  return f;

}

int* factorial_malloc(int* fseq){

  int* fseq_new;
  int* fseq_ret;

  int l = sizeof(fseq)/sizeof(int);

  fseq_new = (int *) malloc(sizeof(int)*(l+1));
  fseq_ret = (int *) malloc(sizeof(int)*(l+1));

  int f;
  int n = fseq[l-1];

  for(int i=0; i<l; i++){
    fseq_new[i] = fseq[i];
    fseq_ret[i] = fseq[i];
  }



  if(n<=0){
    fseq_new[l] = 1;
    fseq_ret = fseq_new;
  }
  else{
    fseq_new[l] = n * (n-1);
    fseq_ret = (factorial_malloc(fseq_new));
  }


  return fseq_ret;

}

using namespace::std;
int main(int argc, const char * argv[]){
cout << "fattoriale di 5 è: " << factorial(5)<<endl;

vector<int> fseq_vector;
int fact = factorial_vector(5,fseq_vector);

for (int i =0; i< fseq_vector.size() ; i++){

  cout << "series element #-"<<i<<" value = "<< fseq_vector[i]<<endl;
}

int* fseq;
fseq = (int *) malloc(sizeof(int)*(1));
fseq[0] = 5;

int* fseq_ret = factorial_malloc(fseq);
free(fseq);




}
