
#include<stdio.h>
#include <cstdlib> // standard C library!!


/*dealing with templates -> best practise for functions
=> GooGle uses snake notation for functions*/



int main(){

  
{
  /*
  int* x = new (int);
  *x = 100;

  printf("text x puntatore: %d \n",*x);

  delete(x);
  *x = 20;

  printf("text x puntatore: %d \n",*x);

  */

int* pseq;
pseq = (int *) malloc(sizeof(int)*1);

*pseq = 19;
printf("MALLOC text x puntatore: %d \n",*pseq);
free(pseq);
printf("MALLOC text x puntatore: %d \n",*pseq);

*pseq = 20;
printf("MALLOC text x puntatore: %d \n",*pseq);



}

  return 0;
}
