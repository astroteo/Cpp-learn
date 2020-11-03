#ifndef QUAT_DLL_H
#define QUAT_DLL_H
#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef BUILDING_QUAT_DLL

#ifdef __cplusplus
}
#endif

//  this function is not declared extern "C"
void QUAT_DLL CppFuncDescription(void);

class QUAT_DLL Quat
{

public:
  double q1;
  double q2;
  double q3;
  double q4;
public:
        Quat(vector<double> q) {};
        virtual ~Quat() {};
        void printQuat();
};

#endif  // EXAMPLE_DLL_H
