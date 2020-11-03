#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <vector>
#include <deque>
#include <set>

using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;
using std::vector;
using std::pair;
using std::deque;
using std::set;



class Persona{

public:
  string nome;
  int eta;

public:
  Persona(string n, int e){
    nome = n;
    eta = e;
  }
  void printPersona() {
   cout <<"\n Info persona: "<<endl;
    cout << " nome: "<< nome << " , eta: "<< eta <<endl;
  }

  void printInfo(){

    printPersona();
  }
  /*  type function(arg1, arg2,...) const{ ... }

the usage of const after the function:

http://duramecho.com/ComputerInformation/WhyHowCppConst.html
https://stackoverflow.com/questions/3141087/what-is-meant-with-const-at-end-of-function-declaration */
  bool operator<(const Persona &p_guess) const{

    if( eta < p_guess.eta){
      return true;
    }

    else if ( eta == p_guess.eta){
       bool  ret;

      if(nome < p_guess.nome){

        ret = true;
      }
      else{
          ret = false;
        }
        return ret;
      }


    else {
      return false;}
}
/* ALTERNATIVE OVERRIDE FOR operator <(...):
friend bool operator< (const Persona &p1 , const Persona &p2);*/




 friend bool operator == (const Persona &p1, const Persona &p2);
 /*ALTERNATIVE OVERRIDE FOR operator ==  (...) INSIDE CLASS:
  bool operator == (const Persona &p_guess)const{
      return nome == p_guess.nome && eta == p_guess.eta;
  }
  */
};

  /* ALTERNATIVE OVERRIDE IMPLEMENTATION FOR operator <(...):
  bool Persona::operator< (const Persona &p1 , const Persona &p2){
   return p1.eta > p2.eta;
};*/

bool operator == (const Persona &p1, const Persona &p2){

  return p1.nome == p2.nome && p1.eta == p2.eta;
}

namespace std
{
  template<>
    struct hash<Persona>
    {
      size_t operator()(const Persona & p) const
      {
        return hash<int>()(p.eta);
      }
    };
}


class Studente: public Persona{

   int matr;
   static int cnt_matr;
   string corsoDiLaurea;
/* SUPER-HUGE DIFFERENCE FROM JAVA: NO NEED TO DEFINE ATTRIBUTES ALREADY
DEFINED IN SUPERCLASS. (no super at all!!)

NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO
 public:
   string nome;
   int eta;
NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO
   */

 public:
   Studente(string nome, int eta, string cdl): Persona(nome,eta){

     matr = cnt_matr;
     corsoDiLaurea = cdl;

     cnt_matr++;
   }

   int getMatr(){return matr;}

   // Let's override printInfo()
   void printInfo(){

     Persona :: printInfo();
     cout <<"Info studente: "<<endl;
     cout <<" Corso di laurea: "<< corsoDiLaurea<< " , matricola: "<< matr <<endl;
   }

   // Let's compute years of university:
   int getUniYears(){

     return eta-19;
   }

   void setMatr(int n){
     this-> matr = n;
   }
   // using the keyword 'friend' this function has acces to private members of this class;
   Studente duplicate(const Studente &stud){
     Studente s(stud.nome,stud.eta,stud.corsoDiLaurea);
     return s;
   }


   Studente duplicateMe(){
     Studente s(this->nome,this->eta,this->corsoDiLaurea);

     return s;
   }

  // Let's implement a method to compare 2 students:
  bool compareStudents(Studente s_guess){
    return this-> getUniYears() >= s_guess.getUniYears();
  }

};

int Studente::cnt_matr =0;


class StudenteFico:public Studente{
private:
  int limoni_anni_uni;
public:
  StudenteFico(string n, int e, string cdl,int l_a_u):Studente(n, e, cdl){
    limoni_anni_uni = l_a_u;
  }

  //If a function is defined as a friend function then,
  //the private and protected data of a class can be accessed using the function.
  /* Here we are just declearing that a function coolnessIndex( par1, par2)
  can access StudenteFico members like if it was defined within StudnteFico.
  https://www.programiz.com/cpp-programming/friend-function-class


  */
  friend float coolnessIndex(StudenteFico , int);
  // still valid : friend float coolnessIndex(StudenteFico sf , int beautiful_girls);

  /*When a class is made a friend class,
  all the member functions of that class becomes friend functions.*/
  friend class StudenteCoolnessExplorer;
};

float coolnessIndex(StudenteFico sf, int belle_ragazze_limonate){
                          /*!! limoni_anni_uni is private for StudenteFico !!
                           Thanks to friend i can in any case access the value
                            in the totally external function coolnessIndex*/
  float c_i = ((float)belle_ragazze_limonate)/((float)sf.limoni_anni_uni);
    return c_i;
  }


  class StudenteCoolnessExplorer{

  public:
    void exploreCoolness(StudenteFico sf ,int belle_ragazze_limonate){


      sf.printInfo();
      float c_i = ((float)belle_ragazze_limonate)/((float)sf.limoni_anni_uni);

      cout << "the coolnessIndex for this student is ci = "<<c_i<<endl;

    }
  };






int main(int argc, const char * argv[]){

  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n A SIMPLE INHERITANCE Studente -> persona "<<endl;

  Persona p1("mario",32);
  Studente s1(p1.nome, p1.eta,"fisica");
  Studente s2("federica", 20,"fisica");
  cout << s1.nome <<endl;

  p1.printInfo();
  s1.setMatr(111);
  s1.printInfo();
  s2.printInfo();

  if(s1.compareStudents(s2)){
    cout << " studente: "<< s2.nome << ", matr: "<< s2.getMatr()<< " is better than studente: "<< s1.nome<<", matr: "<< s1.getMatr()<<endl;
  }
  else{
    cout << " studente: "<< s1.nome << ", matr: "<< s1.getMatr()<< " is better than studente: "<< s2.nome<<", matr: "<< s2.getMatr()<<endl;

  }


  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n FRIENDSHIP FUNCTION:  StudenteFico -> Studente "<<endl;

  Studente s3 = s1.duplicateMe();
  s3.printInfo();

  Studente s4 = s1.duplicate(s2);
  s4.printInfo();

  vector<Studente> vs;
  vs.push_back(s1); vs.push_back(s2); vs.push_back(s3); vs.push_back(s4);
  cout << "\n Recap for all students: "<<endl;
  for(auto v: vs){v.printInfo();}

  StudenteFico sf1("federica", 20,"fisica",22);

  float ci = coolnessIndex(sf1, 10);

  cout <<" coolnessIndex ci  for StudenteFico sf1 of name: "<< sf1.nome << ", and matr: " << sf1.getMatr()<<" is equal to: ci = coolnessIndex(sf1, 10); => ci = "<<ci <<endl;
  cout << "\n ______________________________________________________\n " <<endl;
  cout <<"\n FRIENDSHIP CLASS:  StudenteFico - - > StudenteCool "<<endl;

  StudenteCoolnessExplorer sCEx;
  sCEx.exploreCoolness(sf1,30);




















  cout << "\n GoodBye World"<<endl;
}
