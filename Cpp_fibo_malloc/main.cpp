#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>


using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::pair;
using std::malloc;
using std::realloc;
using std::free;
using std::printf;

// fibonacci recursive function
int fibo(int n){

  if (n==0){
    return 1;
  }
  else if(n==1){

    return 1;
  }
  else{

return fibo(n-1)+fibo(n-2);
}

}

int factorial(int n){

  if(n <= 1){
    return 1;
  }
  else{

    return(n * factorial(n-1));
  }
}

int *pseq;
int N =12;


int main(int argc, const char * argv[]){
cout << "fattoriale di 5 è: " << factorial(5)<<endl;

cout<<"malloc, inizializzazione array length="<< 1<<endl;
/* malloc resituisce un puntatore a void *void()
Di cui va poi fatto il casting a puntatore intero
*/
  pseq = (int *) malloc(sizeof(int)*1);

  for (int i=0; i<N; i++){
  cout<<"fibonacci series at #-"<<i<<"returns: "<<fibo(i)<<endl;

  int f = fibo(i);

  if(i==0){

    pseq[i] = f;
  }
  else{

    int* pseq_tmp;
    pseq_tmp = pseq;

    //free(pseq) ==> this leads to an error:
    pseq = (int *) malloc(sizeof(int)*(i+1));

    for(int j=0; j<i; j++){
      pseq[j] = pseq_tmp[j];
    }
    free(pseq_tmp);
    pseq[i] = f;
  }


}

cout <<"\n stored values in malloc allocated array: "<<endl;

for(int i=0; i<N ; i++){

  cout<<"Malloc stored value at position #-"<<i<<" is: "<<pseq[i]<<endl;


}
free(pseq);

// Learning the calloc function, Let's do the classical example:
int *int_seq;
int_seq = (int*) malloc(sizeof(int) *1);
int cnt = 0;
while(true){

  cout<<"inserisci un intero: " <<endl;
  int int_new;
  cin >> int_new;

  if(int_new ==0){
    break;
  }
    else{

      if(!cnt){

        int_seq[cnt] =int_new;

      }
      else{

        // this avoids the tour of the temp--> free(temp)
        int_seq =(int*)realloc(int_seq, sizeof(int)*(cnt+1)); // !! ALWAYS CAST !!
        int_seq[cnt] = int_new;

      }


    }
cnt++;
}

cout <<"\n I numeri precedentemente inserit sono: "<<endl;

for(int i=0; i<cnt; i++){
  cout<<"Realloc=> value stored value at position #-"<<i<<" is: "<<int_seq[i]<<endl;
}

free(int_seq);




  cout<< "GoodBye World"<<endl;
  }
