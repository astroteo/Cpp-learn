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



int moltiplica_per_indirizzo(int *a, int *b){
    // effettua la moltiplicazione tra i valori che si
    // trovano leggendo il contenuto della memoria
    // agli indirizzi x e y, tramite il prefisso '*'
    // (da non confondere con l'operatore di moltiplicazione)
  int c ;

  c = *a * *b;

  return c;
}

int moltiplica_per_reference( int &a , int &b ){
   // moltiplica ciò che trova presso gli indirizzi di memoria di x e y
   // ma non c'è bisogno di esplicitarlo
   int ret;
   ret = a*b;
  return ret;
}


void swap_point_value(int* a, int* b){
  /* intuition ==> THIS WORKS, SWAPPING ALSO ORIGINAL VARIABLES !!
  int t_a = *a;
  int t_b = *b;
  *b = t_a;
  *a = t_b;
  */
    int t = *a; //-> salvo in variable 't' il valore di puntato da a: t = *a
    *a = *b; //-> impongo:  valore_puntato_da_a = valore_puntato_da_b
    *b = t; // -> impongo  valore_puntato_da_b =  t
}


void swap_point_address(int* &point_a, int* &point_b){

  int *point_temp;// this must be a pointer

  point_temp = point_a;
  point_a = point_b;
  point_b = point_temp;
}

void swap_simple_values(int &a ,int &b){

  int t =a;
  a = b;
  b = t;

}


void order3(int* s, int* m, int* l){


  int v[3] = {*s,*m,*l};

  int min = v[0];
  int max = v[2];
  int avg;

  for (int i=0; i<3; i++ ){
    if (v[i] >= max){
      max = v[i];

        }

    else if(v[i] <= min ){
      min= v[i];


    }
  }

  for (int val : v){
    if (val != min && val != max){

      avg = val;
    }
  }
  *s = min;
  *m = avg;
  *l = max;
}



int main(int argc, const char * argv[]){





  cout<<"\n DEALING WITH A SIMPLE POINTER "<<endl;
  int z = 3;
  cout << "z original value: z=" <<z<<endl;

  int *pz = &z;
  cout<< "*pz = &z "<<endl<<" => pz = "<<pz <<endl<<" => *pz = "<<*pz <<endl;

  *pz = 13;
  cout << " after: *pz = 13: " << endl << " z="<<z<<endl;

  cout <<"assigning another pointer to the same address:"<<endl << " *pz_new = &z "<<endl;
  int* pz_new;
  pz_new = &z;
  *pz_new =19;

  cout << " after: *pz_new = 19: " << endl << " z="<< z <<endl;
  cout << " and obviously: " << endl << " *pz="<< *pz <<endl;
cout << "\n _____________________________________________________________________\n " <<endl;

  cout<< "\n PASSAGGIO PARAMETRI PER INDIRIZZO: funz(*a, *b) \n VS \n  PASSAGGIO PARAMETRI PER RIFERIMENTO: funz(&a,&b)"<<endl;

  int a =7;
  int b = 17;

  int* pa =&a;
  int* pb = &b;

  int c_ind = moltiplica_per_indirizzo(&a,&b);
  c_ind = moltiplica_per_indirizzo(pa,pb);
  cout << "c_ind = moltiplica_per_indirizzo(pa,pb) \n (*pa = 7, *pb = 17) => " << c_ind <<endl;
  cout <<"\n !! la funzione può essere comunque SEMPRE chiamata come: c_ind = moltiplica_per_indirizzo(&a,&b) " <<endl;

          //= moltiplica_per_reference(&a,&b); !! questa funzione è dichiarata così !!
  int c_ref = moltiplica_per_reference(a,b);//ma non c'è bisogno di specificare &a,&b, anzi se lo fai non compila
  cout << " \n \n c_ref = moltiplica_per_indirizzo(a,b) \n (a = 7, b = 17) => " << c_ref <<endl;

cout << "\n _____________________________________________________________________\n " <<endl;



  cout<<"\n THE SWAP PROBLEM"<<endl;

  int x =10;
  int y =13;

  int *px = &x;
  int *py = &y;
  cout<<"\n Before swapping ...\n "<<endl;
  cout<<"x: "<< x<<" , &x: " << &x <<endl;
  cout<<"px: "<<  px <<" *px: " << *px <<endl;

  cout<<"y: "<< y<<" , &y: " << &y <<endl;
  cout<<"py: "<<  py <<" *py: " << *py <<endl;



  swap_point_value(px,py);
  /* Ovviamente questa funzione può essere invocata anche come:
  swap_point_value(&x,&y);

  infatti: px = &x,
           py = &y

  */


  cout<<"\n \n After VALUE SWAPPING: swap_point_value(int* x,int* y),\n           called as swap_point_value(&x,&y) OR swap_point_address(px,py) ... \n"<<endl;
  cout<<"x: "<< x <<" , &x: " << &x <<endl;
  cout<<"px: "<<  px <<" , *px: " << *px <<endl;

  cout<<"y: "<< y<<" , &y: " << &y <<endl;
  cout<<"py: "<< py <<", *py: " << *py <<endl;


  swap_point_address(px,py);
  //swap_point_value(px,py);


  cout<<"\n  After ADDRESS SWAPPING: swap_point_address(int* &x,int* &y),\n     called as swap_point_address(&x,&y) OR swap_point_address(px,py)...\n "<<endl;

  cout<<"px: "<< px <<" , *px: " << *px <<endl;
  cout<<"py: "<< py <<" *py: " << *py <<endl;

  cout<<" But obviously..."<<endl;
  cout<<"x: "<< x <<", &x: "<< &x<<endl;
  cout<<"y: "<< y <<", &y: "<< &y<<endl;


  cout<<" After SIMPLE SWAP: swap_simple_values(int &x,int &y), \n              called as swap_simple_values(x,y)...\n "<<endl;
  swap_simple_values(x,y);

  cout<<"x: "<< x <<", &x: "<< &x<<endl;
  cout<<"y: "<< y <<", &y: "<< &y<<endl;






cout << "\n _____________________________________________________________________\n " <<endl;

  // ESERCIZI PRESI DA: http://www.dis.uniroma1.it/~bloisi/didattica/comunicazioniElettronica1011/lezioni/6.2-parametri-puntatore.pdf


cout<<"\n ES-1: "<<endl;

/*
Scrivere un programma che legga tre valori in tre
distinte variabili distinte variabili small, medium, large, e ne scambi i , e ne scambi i
valori in modo da avere il più grande nella variabile
large, il più piccolo nella variabile small ed il restante
nella variabile medium. Definire una funzione per lo
scambio dei tre valori che utilizzi il passaggio di
parametri puntatore.
*/
 int s = 123;
 int m =0;
 int l =11;

 cout<<"before function order3... \n s = "<< s <<" , m = " << m <<", l = "<< l <<endl;
 order3(&s,&m,&l);
 cout<<"after function order3... \n s = "<< s <<" , m = " << m <<", l = "<< l <<endl;









cout<< "GoodBye World"<<endl;
}
