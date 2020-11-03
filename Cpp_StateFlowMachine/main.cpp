#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi
#include <typeinfo> // per determinare il tipo dinamicamente passato a funzioni
#include <string.h>
#include <pthread.h>
#include<unistd.h>

using namespace::std;

/*events:*/
enum Signal{CHAR_SIG, SLASH_SIG, STAR_SIG};//An enumeration is a distinct type whose value is restricted to a range of values

/*states:*/
enum State{CODE, SLASH, COMMENT, STAR};
string  StateStr[4] ={"CODE","SLASH","COMMENT","STAR"};

/* this class is actually the whole machine !!*/
class CParser1{
private:
  State myState; // state variable
  long myCommentCtr;// comment character counter

public:
  /* Default transition */
  void init(){
    cout << "machine started => code mode activated as default"<<endl;
    myCommentCtr = 0;
    tran(CODE);};

  /* calls the transition from a state to another */
  void tran(State targetState){
    cout << "transition from state: "<<StateStr[(int)myState]<<endl;
     myState = targetState;
     cout << "transiton to state: "<< StateStr[(int)myState]<<endl;

  };

  /* ? send a signal ? => to be implemented */
  void dispatch(unsigned const sig);
};

void CParser1::dispatch(unsigned const int sig){

  switch(myState){

    case CODE:
      switch(sig){
          case SLASH_SIG:
            tran(SLASH);
            break;
      }
      break;

    case SLASH:
      switch(sig){
        case STAR_SIG:{
          tran(COMMENT);
          ++myCommentCtr;
          break;
        }
        case CHAR_SIG:{
          tran(CODE);
          break;
        }
        }
        break;

    case COMMENT:
      switch(sig){
        case STAR_SIG:{
          tran(STAR);
          break;
        }
        case CHAR_SIG:{
          myCommentCtr++;
        }
        case SLASH_SIG:{
          myCommentCtr++;
        }
      }
      break;

    case STAR:
      switch(sig){
        case STAR_SIG:
        case SLASH_SIG:{
          tran(CODE);}
        }
        break;

  }

};

Signal string2Signal(string signalString){
  if (signalString == "CHAR"){
      return CHAR_SIG;
  }
  else if (signalString == "SLASH")
    return SLASH_SIG;
  else if (signalString == "STAR")
    return STAR_SIG;
  else
  return CHAR_SIG;
}

int main(){

  CParser1 cp1;
  cp1.init();
  while (true){
    string action;
    cout<< " choose an action betewenn CHAR, SLASH, STAR ,EXIT"<<endl;

    cin >> action;
    if(action=="EXIT"){
      break;
    }
    else{
      cp1.dispatch(string2Signal(action));
    }
  }

  cout << "This is the Finite State Machine implementation in C/C++"<<endl;
}
