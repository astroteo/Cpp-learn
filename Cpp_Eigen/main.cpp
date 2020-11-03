#include <stdexcept>
#include <limits>
#include <iostream>

#include <eigen3/Eigen/Dense>

using namespace std;
using namespace Eigen;

#define pi  3.14159265


double scalarProd(VectorXd v1,RowVectorXd v2)
{
  assert (v1.rows() == v2.cols());// if condition not verified programs kills !!
  return v2*v1;

}

int main(){

  cout<< "correctly compiled Eigen"<<endl;

  /* undefine matrix size */
  MatrixXd A(2,2);
  A(0,0) = 10;
  A(0,1) = 11;
  A(1,0) = 12;
  A(1,1) = A(0,0)+A(1,0);

  VectorXd x(2);
  x(0) =10;
  x(1) =11;

  cout << "matrices/vectors are directly printable:\n  A = \n"<< A << " \n x = \n "<< x <<endl;
  VectorXd y(2);
  y = A*x;

  cout << "operation-1: A*x = \n "<< y(0)<<"\n "<<y(1)<<endl;;

  /* THE MATRIX TEMPLATE:

  Matrix<typename Scalar, int RowsAtCompileTime, int ColsAtCompile>

  ... a few typedef are already available:
     typedef Matrix<float, 4, 4> Matrix4f ~~> a 4x4 matrix;
     typedef Matrix<float, 3, 1> Vector3f ~~>   column vector of floats
     typedef Matrix<int, 1, 2> RowVector2i ~~>  row-vector of integer ...

  Matrix<typename Scalar, int Dynamic, int Dynamic> => dymensions are defined at run-time

  MaxtrixXf m(4,4) => float!,  4 x 4 size is defined at compile time!!
  VectorXd v(4) => double! 4 x 1 size;
  */
  VectorXd z(3);
  RowVectorXd z_t(3);

  for (int i=0; i< 3; i++)
  {
    z(i) = (double) i;
    z_t(i) = (double) i;
  }

  double s = scalarProd(z,z_t);
  cout << " z = \n"<< z <<endl;
  cout << "z_t = \n "<< z_t <<endl;

  cout << "scalar product result => " << s << endl;

  /*NOT possible hybrid operations between dyn/stat allocated Vector/Matrix */
  Vector3f v(1,2,3);
  RowVector3f v_t;
  v_t(0) = 1;
  v_t(1) = 2;
  v_t(2) = 3;

  cout << "directly computable norm as VectorXx.norm() => v.norm() = "<< v.norm() <<endl;

  cout <<"hybrid-type operations are not allowed product "<< v_t * v <<endl;


  /* TRANSFORMATIONS:
        1 => Affine, indicates a roto-translation
        2 => rotation (euler-style) Transform< ScalarType, Dim, Affine> t(AngleAxis(angle,axis))

  */
double angle = pi/2;
Vector3d axis(0,0,1);
AngleAxis<double> aa(angle,axis);

Transform<double,3,Affine> R_z(aa);
Translation<double,3>      T_x(1,0,0);
Transform<double,3,Affine>   T_x_R_z;
Transform<double,3,Affine>   R_z_T_x;
Transform<double,3,Affine>   R_z_R_z;
T_x_R_z = T_x * R_z;
R_z_R_z = R_z * R_z;
R_z_T_x = R_z * T_x;


Vector3d v1(1,0,0);

Vector3d v1_r = R_z * v1;
cout <<" x axis pure-rotation about z (pi/2) \n v1_rot = \n" << v1_r <<endl;


Vector3d v1_t = T_x * v1;
cout <<"point pure-translation along x \n v1_rot = \n" << v1_t<<endl;


Vector3d v1_rt = R_z * (T_x * v1);
Vector3d v1_tr = T_x * (R_z * v1);
cout <<" roto-translation =>  T_x_R_z \n v1_rt = \n"<< v1_rt <<endl;
assert(v1_rt == R_z_T_x * v1);

cout <<" roto-translation =>  T_x_R_z \n v1_tr = \n"<< v1_tr <<endl;
assert(v1_tr == T_x_R_z * v1);

Vector3d v1_r_r = R_z_R_z * v1;
cout <<" x axis pure-rotation about z (pi) \n v1_r_r = \n"<< v1_r_r <<endl;


/*get the rotation matrix out of (Euler e ={ e*i, e*j, e*k}) AngleAxis => call it as a constructor, same for quaternions */
Matrix3d  M_rot(aa);
Quaternion<double> q(aa);
cout <<"quaternions ..."<<endl;
cout << q.x()<<endl; // e1 * sin(phi/2) = 0 * sin(pi/4)
cout << q.y()<<endl; // e2 * sin(phi/2) = 0 * sin(pi/4)
cout << q.z()<<endl; // e3 * sin(phi/2) = 1* sin(pi/4)
cout << q.w()<<endl; // cos(phi/2) = cos(pi/4)

cout <<"Euler axis ..."<<endl;


/* Each roto-translation can be modeled via a Matrix4d where:
| 1 0 0 x |  \
| 0 1 0 y |   }-> The identity 3x3 matrix (no rotation) on the left
| 0 0 1 z |  /
| 0 0 0 1 |  -> We do not use this line (and it has to stay 0,0,0,1)

// DENAVIT-HARTEMBERG => http://www.prisma.unina.it/courses/Cinematica.pdf
this transformation screw me =>
*/

Matrix4f transform_4 = Matrix4f::Identity();

float theta = M_PI/4; // The angle of rotation in radians about z
  transform_4 (0,0) = cos (theta);
  transform_4 (0,1) = -sin(theta);
  transform_4 (1,0) = sin (theta);
  transform_4 (1,1) = cos (theta);


float d = 2.5;// 2.5 meters along x axiz
  transform_4 (3,0) = d;

Vector4f v_0(10,0,0,1);// a point in space is setted up to be =>


cout<<" 4 X 4 transform => transform_4 = \n"<< transform_4 <<endl;

Vector4f v_1 = transform_4 * v_0;
















  return 0;
}

/*
compile this as: g++ -I /usr/local/Cellar/eigen/3.3.5/include main.cpp -o exec

*/
