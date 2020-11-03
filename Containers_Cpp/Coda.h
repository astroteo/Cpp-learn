#ifndef Coda_h
#define Coda_h

#include <cstring>
#include <cstdlib> // standard C library!!
#include <iostream>
#include <cstring>
#include <cstdlib> // standard C library!!
#include <iostream>

using std::cout;
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;

using std::string;


class Coda{

private:
  struct nodo{

    int val;
    nodo *successivo;
};

  nodo *head;
  nodo *tail;
  nodo *elem;

public:
  Coda();
  void push(int n);
  int pop();


};

#endif /* Coda_h */
