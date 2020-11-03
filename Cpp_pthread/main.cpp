
#include <iostream>
#include <vector>

using namespace std;

void print_char_array(char** cc)
{
  for(int i =0; i < sizeof(cc)/sizeof(char); i++)
  {
    cout << cc++ <<endl;
 }
}

template<class T>
class Vector{
public:
  Vector(T &elements_) : elements(elements_){};
  ~Vector(){}
public:
    T& elements;
};

int main(int argc, char** argv)
{
  int a =0;
  int b = a++;
  cout << "a: "<< a << "b: "<< b<<endl;

  int c=0;
  ++c;
  cout << b << endl;
{
  cout << "--------------------------------------------------------------------------------" <<endl;
  char* pchar;
  char a = 'a';

  pchar = &a;
  a='b';

  cout << "&a: " << &a << " pchar: " << pchar << "a ==> " << a << "  *pchar ==> "<<*pchar << endl;
  cout << "--------------------------------------------------------------------------------" <<endl;
}
{
  char* p_vchar;
  char vchar[] ="hellooooo" ;

  p_vchar = &vchar[0];

  char** pp_vchar;
  pp_vchar = &p_vchar;

  for(int i=0; i< sizeof(vchar)/sizeof(char)-1; ++i)
  {
    cout << "i: " << i <<" vchar[i]: " << vchar[i]
         << " *p_vchar++: " << *(p_vchar)
         << " **p_vchar++: " << **pp_vchar << endl;

         p_vchar++;
   }


  cout << "--------------------------------------------------------------------------------" <<endl;

}
{
  cout << "--------------------------------------------------------------------------------" <<endl;

  vector<char> *p_vchar;
  p_vchar = new vector<char>;

  vector<char> vc = {'h','e','l','l'};

   p_vchar = &vc;

   for(auto pvc : *p_vchar)
    cout << pvc<<endl;

   cout << "--------------------------------------------------------------------------------" <<endl;

}
  cout << "--------------------------------------------------------------------------------" <<endl;
  int elements[3];
  elements[0] =1; elements[1] =2 ; elements[2] = 3;
  Vector<int> v1(elements[0]);

  cout << "--------------------------------------------------------------------------------" <<endl;
   int m[3][3];
   int *pr = &m[0][0];
   m[0][0] =1; m[0][1] =2; m[0][2] =0;
   m[1][0] =0; m[1][1] =1; m[1][2] =0;
   m[2][0] =0; m[2][1] =0; m[2][2] =1;
   for(int i=0; i<3; i++)
   {
     for(int j=0; j<3; j++)
     {
       cout << m[i][j] << "?=?"<<*pr++<<endl;
     }

   }
  cout << "--------------------------------------------------------------------------------" <<endl;

  char* mtfk = "motherfucker";
  cout << mtfk << endl;
  char* pt[100];

  cout << "Plaaying with " << argc << " threads" << endl;
  for(int ar=1; ar<argc-1;ar++ )
  {
    cout<<"Thread-"<< ar << " will say: " << argv[ar]<<endl;
    pt[ar] = argv[ar];
  }

  print_char_array(pt);

return 0;
}
