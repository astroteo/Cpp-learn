// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;
int main (int argc, char *argv[])
{
  VectorXd x(2);
  x(0) =10;
  x(1) =11;

  cout << " Eigen test-vector is: x= \n" << x <<endl;

  if (argc < 2)
    {
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
  double outputValue = sqrt(inputValue);
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}
