#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <exception>

// inheritance from exception class
/*
class E1 : public std::exception {};
class E2 : public std::exception {};
*/

using namespace::std;


void printArray(int *pa, const int N){



  for (int i=0; i<N ; i++)
    cout<< pa[i]<<endl;

}
// syntactic-sugar for funtcion receiving an array
template<size_t l>
void printArray(int(&pa)[l]){


  cout<<l<<endl;
  for (int i=0; i<l ; i++)
    cout<< pa[i]<<endl;

}

int * flipArray(int *a,const int N){

  int* fa = new int(N); // this new is what actually allocates the array

  for (int i=0; i< N ; i++){

    fa[i] = a[ N-1-i];

  }
  return fa;
}

/* 3 Ways for passing a matrix to a function:
https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function

1) as a reference
2) as a pointer
3) as pointer to a pointer
*/
template <size_t rows, size_t cols>
void printMatrByRef(int (&m)[rows][cols]){
  cout <<"... Matrix by reference \n M=[ "<<endl;
  for (int i=0; i<rows ; i++){

      cout<<"[ ";
    for (int j=0; j<cols; j++){

        cout<< m[i][j]<< " " ;
        if (j== cols-1)
        cout <<" ]"<<endl;

    }
  }
    cout <<" ]"<<endl;

}


void printMatrByPointer(int (*m)[2][5]){

    cout <<"... Matrix by pointer \n M= ["<<endl;
    for (int i=0; i<2; i++){
      cout<<"[ ";
      for (int j=0; j<5; j++){

          cout<< *(m[i])[j]<< " " ;
          }
      cout <<" ]"<<endl;
    }
      cout <<" ]"<<endl;
    }
void printMatrByValue(int m [][5]){

        cout <<"... Matrix by value \n M= ["<<endl;
        for (int i=0; i<2; i++){
            cout<<"[ ";
          for (int j=0; j<5; j++){

              cout<< m[i][j]<< " " ;
              }
          cout <<" ]"<<endl;
        }
          cout <<" ]"<<endl;

        }

  void printMatrByDoublePointer(int **m,const int N,const int M){
    cout <<"... Matrix by double pointer: \n M= [ "<<endl;
    for (int i=0; i<N; i++){
     cout<<"[ ";
      int *pa = new int[M];
      pa = m[i];

      for (int j=0; j<M ; j++){

        cout<< pa[j]<<" ";
      }
      cout <<" ]"<<endl;

    }
    cout <<" ]"<<endl;

  }

  struct Person{

    string name;
    int age;
    string cf;

    Person(string n, int a, string fc){
      name =n;
      age = a;
      cf = fc;
    }

    void printInfo(){

      cout << "name: "<< name << " age: "<< " fiscal-code: "<< cf<<endl;

    }
  };

  // simple inheritance
  struct Student: Person{

    string cdl;

    Student(string n, int a, string fc, string cdl_c ): Person(n, a,fc){
      cdl = cdl_c;
    }

    // override di printInfo:
    void printInfo(){
      printInfo();
      cout << "this is a student in: "<< cdl <<endl;
    }
  };

  struct Pet{

    string pet_name;
    int pet_age;
    Pet(string pn, int pa){

      pet_age = pa;
      pet_name = pn;
    }

    void printInfo(){

      cout << "Pet => name: "<<pet_name << " age "<<pet_age <<endl;
    }

  };

  struct PersonWithPet:Person,Pet{


    PersonWithPet(string n, int a, string cf, string pn,int pa): Person(n,a,cf),Pet(pn,pa){};


    void printInfo(){
      Person::printInfo();
      Pet::printInfo();
    }

  };


int main(int argc, const char * argv[]){
  // Reflection -0
  cout << "\n ______________________________________________________\n " <<endl;
  cout << "Arrays and pointers VS Arrays and matrices "<<endl;

  int a_test[5] = {1,2,3,4,4};

  // a_test de-facto is a memory address:
  cout << "an array is a pointer!! printing the array by it's name => a_test = "<< a_test << " => a memory address is printed (Q.E.D.)"<<endl;
  cout << "an array is a pointer!!dereferencing the array => *a_test = "<< *a_test << " => first element is returned (Q.E.D.)"<<endl;

  for(int i=0; i< 5; i++){

    cout << "scan the array=> treating it as a pointer=> *(a_test+i) =  "<<*(a_test+i) <<endl;


  }

  cout <<"... IN A TOTALLY ANALOGOUS WAY: "<<endl;
  int m_test[2][2] = {{1,2},{3,4}};
  printMatrByRef(m_test);

  cout << "the pointer to first row can be accessdìed as *m_test = "<< *m_test << " Being a matrix an array of pointers, this is a memory address (Q.E.D)"<<endl;
  cout << "therefore, dereferencing once again,  **m_test =  "<< **m_test<< " => return matrix's first element"<<endl;

  cout << " m_test[1][1] == **m_test , m_test[1][2] == *(*m_test +1)= "<< *(*m_test+1) <<endl;
  cout << " m_test[2][1] == *(*(m_test+1)) = "<< *(*(m_test+1)) <<", always callable as m_test[1][0] = "<<m_test[1][0]<<endl;
  cout << " m_test[2][2] == *(*(m_test +1)+1)= "<< *(*(m_test+1)+1) <<endl;


  // Reflection -1
  cout << "\n ______________________________________________________\n " <<endl;
  cout << "pointer decleared as NULL VS pointer decleard with 'new'"<<endl;

  int *p_NULL = NULL;
  int *p_new = new int;

  int p =10;


  if(p_NULL == NULL)
  p_NULL = &p;
  *p_NULL =110;

  if (p_new == NULL)
  *p_new =110;



  cout << "*p_NULL = "<< *p_NULL<<endl;
  cout << "*p_new = "<< *p_NULL<<endl;

  //Reflection-2:
  cout << "\n ______________________________________________________\n " <<endl;
  cout << "pointer to a void, [can always be casted]"<<endl;

  void *pt;
  int i=10;
  pt = &i;
  //try-catch for unknown exception type:
  /*
try { cout <<"*pt = "<<*pt<<endl;
           throw E2();
       }
       catch( ... ) {
           try {
               throw;
           }
           catch( const E1 & e ) {
               std::cout << "E1\n";
           }
           catch( const E2 & e ) {
               std::cout << "E2\n";
           }
       }
       */

  // pointers can always be casted:
  int* pti = (int*) pt;
  cout <<"*pti = "<<*pti<<endl;

  //Reflection-3:
  cout << "\n ______________________________________________________\n " <<endl;
  cout << "'new' command ==> pointer assigned from memory VS pointer assigned by value"<<endl;

  char c = 'B';
  char* pc = new char;
  *pc = 'A';
  pc = &c;

  cout<< "*pc = "<< *pc <<endl;

  //Reflection-4:
  cout << "\n ______________________________________________________\n " <<endl;
  cout << "Even if not explicitely assigned:  \n in C++ AN ARRAY VARIABLE IS ALWAYS A POINTER"<<endl;

  const int N = 5;// 'const' here is crucial.
  int a[N] = {1,2,3,4,5};

  int* a_new = new int(N);
  for(int i=0; i<N; i++) a_new[i] = a[i];

  cout << "in fact, if calling: a =  "<< a <<" \n [a memory address is returned]"<<endl;
  int * pa;
  pa = a; //



  cout << "after assigning: pa[2] = 10, let's print out the original array a[]:"<<endl;
  pa[2] =10;
  cout<<"original printArray(a):"<<endl;
  printArray(a,N);
  cout<<"overloaded printArray(a):"<<endl;
  printArray(a);

  cout << "flip the original array: "<<endl;
  printArray(flipArray(a,N),N);

  //Reflection-5:
  cout << "\n ______________________________________________________\n " <<endl;
  cout << " matrix:  \n in C++ A MATRIX IS AN ARRAY OF ARRAY => IS AN ARRAY OF POINTERS"<<endl;
  // insertion is straight forward:
  int M[2][3] = {{1,2,4},{1,22,5}};

  int b[N] = {1,2,3,4,5};
  int m[2][N];

  for(int i =0; i< 2; i++){

    for (int j=0; j<N; j++){
      if (i ==0)
      m[i][j] = a[j];
      else
      m[i][j] = b[j];

    }
  }

  // passing a matrix to a function:
  printMatrByRef(m);
  printMatrByPointer(&m);
  printMatrByValue(m);
  cout << " "<<endl;



  //Reflection-6:
  cout << "\n ______________________________________________________\n " <<endl;
  cout << " matrix:  \n  C++ DYNAMIC ALLOCATION"<<endl;

  //review: array dynamic allocation,
  int *v = new int[4];

  for (int i =0; i<4; i++){
    v[i] = 10;
  }

 cout << " REVIEW: printing a dynamic allocated vector: "<<endl;
  for (int i =0; i<4; i++){

    cout <<v[i]<<endl;;
  }

  int **matrix;
  const int ROWS = 5;
  const int COLS = 5;

  matrix = new int*[ROWS];// an array of pointers is dinamically allocated!

  for(i = 0; i < ROWS; i++) {
    matrix[i] = new int[COLS];
}

for (int i=0; i<ROWS; i++){
  for (int j=0; j<COLS; j++){

      matrix[i][j] = i+j;

    }
}

cout << " printing a dynamic allocated matrix filled as: M[i][j] = i + j; "<<endl;
printMatrByDoublePointer(matrix,ROWS,COLS);

delete[] matrix;

//Reflection-7:
cout << "\n ______________________________________________________\n " <<endl;
cout << " matrix:  \n  C++ MALLOC ALLOCATION"<<endl;

int in = 12;

int *v_in;
v_in = (int*) malloc(sizeof(int)); // malloc allocates memory always on a pointer

int cnt =0;
while(in != 0){

  cout << "please insert a number: "<<endl;
  cin >> in;

  if (cnt ==0){

    v_in[0] = in;

  }
  else{

    int* v_in_temp;
    v_in_temp =(int*) malloc(sizeof(int)*cnt);
    for(int i=0; i< cnt; i++){

      v_in_temp[i] = v_in[i];
    }

    free(v_in);
    v_in = (int*) malloc(sizeof(int)*(cnt+1));

    for(int i=0; i< cnt; i++){

      v_in[i] = v_in_temp[i] ;
    }
    free(v_in_temp);

  }
  v_in[cnt] =in;
  cnt++;
}


cout <<"Inserted numbers are: "<<endl;
for(int i=0; i< cnt; i++){

  if (i%2 == 0){

    // exploiting the fact that v_in is actually a pointer:
      cout <<"even iter=>  positon #-"<<i<< " value: "<< *(v_in+i) <<endl;
  }
  else{

  cout <<" odd iter =>  positon #-"<<i<< " value: "<<v_in[i] <<endl;
}
}
free(v_in);


//Reflection-8:
cout << "\n ______________________________________________________\n " <<endl;
cout << " OOP:  \n MULTIPLE INHERITANCE (aloowed in C++)"<<endl;

Person person_mario("mario", 32, "MRWWDA");
Student s_mario(person_mario.name, person_mario.age,person_mario.cf,"physic");

Pet  pet_mario("bobbi",4);
PersonWithPet mario_and_his_pet(person_mario.name, person_mario.age,person_mario.cf,pet_mario.pet_name,pet_mario.pet_age);

mario_and_his_pet.printInfo();


















cout << "\n ______________________________________________________\n " <<endl;
cout << "GoodBye World \n Dealing with a few reflections in C++"<<endl;
return 0;
}
