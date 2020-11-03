#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <typeinfo>
#include <string.h>
#include <vector>
#include<math.h>
using namespace::std;

extern void someFunction (int x);

int main()
{
  someFunction(666);
  cout << "correctly loaded dll"<<endl;

}

// compile dylib(dll) -->   g++ -c dylib_folder/dll_test.c -o dylib_folder/dll_test.o
// create dylib--> g++  -dynamiclib -current_version 1.0 dylib_folder/dll_test.o -o dylib_folder/dll_test.dylib
