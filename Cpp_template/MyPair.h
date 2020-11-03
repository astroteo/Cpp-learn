#ifndef MyPair_h
#define MyPair_h
/*
Because templates are compiled when required,
this forces a restriction for multi-file projects: the implementation (definition)
of a template class or function must be in the same file as its declaration.
That means that we cannot separate the interface in a separate header file, and that we must
include both interface and implementation in any file that uses the templates.

==> the main will have: #include "MyPair.cpp" instead of #include "MyPair.h"
==> the final command to launch will be: g++  -o exec MyPair.cpp  main.cpp
*/
template <class T>
class MyPair {
    T a, b;
  public:
    MyPair (T first, T second)
      {a=first; b=second;}
    T getmax ();
};


#endif /* MyPair_h */
