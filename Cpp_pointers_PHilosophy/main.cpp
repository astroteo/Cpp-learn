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

int main(int argc, const char * argv[]){

  // operatore "indirizzo-di:"
  int i = 10;
  cout << "\n assegno valore: int i = 10; " <<" uso operatore 'indirizzo-di:' =>  &i = "<< &i<<endl<<endl;

  // operatore referenziazione:
  cout<<" non puo essere assegnato: int j = &i => serve l'operatore di referenziazione '*' "<<endl;
  int *pi;
  pi = &i;
  cout << " assegnazione int* pi; pi = &i"<<endl<<"=> *pi = "<< *pi <<endl<<"=> i = "<<i<<endl<<endl;
  *pi =11;
  cout <<" ora le due variabili sono legate a 'filo doppio':\n *pi = 11; => i = "<< i <<endl<<endl;

  cout << " a livello più generale l'operatore '*' permette di recuperare la variable contenuta in un indirizzo di memeoria"<<endl<<endl;
  int j = *&i;
  cout<<"E.g. int j = *& i; => j ="<<j<<endl <<endl;

  cout << "\n _____________________________________________________________________\n " <<endl;
  cout<< "ESEMPIO UTILIZZO (vedi codice):" <<endl<<endl;
  int a, b, c;
  int *pt_a, *pt_b;
  pt_a = &a;
  pt_b = &b;
  a = 1;
  b = 2;
  c = *pt_a + *pt_b;
  *pt_a = 10;
  cout << "a = " << i << endl;
  cout << "c = " << c << endl<< endl;

  cout << "\n _____________________________________________________________________\n " <<endl;
  cout<< "PUNTATORE A PUNTATORE:" <<endl<<endl;

  int v = 3;
  cout<< "assegno v=3"<<endl;

  int *pt;
  pt = &v;
  cout<<"puntatore a v: int * pt; pt = &v; => *pt ="<<*pt<<endl;

  int **ptpt;// è un puntatore ad una variable di tipo puntatore
  ptpt = &pt;

  cout<<"puntatore a puntatore (pt): int * ptpt; ptpt = &pt; => *ptpt = &v "<<endl;
  cout<<"infatti:  *ptpt = "<<*ptpt<<", mentre: &v = "<<&v<<endl;
  cout<< " per richiamare v, ovviamente: **ptpt ="<<**ptpt<<endl;

  cout << "\n _____________________________________________________________________\n " <<endl;
  cout<< "PUNTATORI A VOID:" <<endl<<endl;
  cout << "è possibile definire puntatori a tipi generici con: void* p;" <<endl;
  void* p;
  char s='h';
  p = &s;
  cout <<"prima di poterlo utilizzare è però necessario il casting al tipo a cui è assegnato"<<endl;
  char* pchar = (char*) p;
  cout<<"e.g. char s = 'h'; p = &s; char* pchar = (char*) p; => *pchar =  "<<*pchar<<endl;




cout << "\n _____________________________________________________________________\n " <<endl;
cout << "BoodBye Wordl!"<<endl;
}
