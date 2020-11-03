//
//  main.cpp
//  Cpp_DynMemoryTn
//
//  Created by teo baiguera on 08/06/18.
//  Copyright © 2018 teo baiguera. All rights reserved.
//

#include <iostream>
#include <cstring> // string library
#include <cstdlib> // standard C library!!
#include <stdlib.h> // includes atoi

using std::cout;// with this command gettin prompt inputs is fucking easy
using std::cin;
using std::cin;
using std::endl;
using std::string;
using std::nothrow;

int* somma_point(int* &n1,int* &n2);// prototype for a function: MANDATORY !!
int* still_valid_somma(int* n1,int* n2);
int somma (int n1, int n2);


struct persona{
    string nome;
    int eta;
};


struct dict{
    string k;
    int v;
};
persona* sommaPersone(persona *&p1, persona *&p2);

int main(int argc, const char * argv[]) {
    
     /////////// THE SIMPLE POINTER ///////////
    cout << "TEST SIMPLE POINTER "<<endl;
    
    
    // dealing with pointers, Tn-studies
    int a = 10;
    std::cout << "a initial value: "<< a <<endl;
    std::cout << "a memory address: "<< &a <<endl;
    
    // a pointer always occupies 3 bytes
    int *point_a = &a;
    std::cout << "pointer to variable a value: "<< point_a <<endl;
    std::cout << "pointer to variable a address: "<< &point_a <<endl;
    
    if(&a == point_a){
        
        
        cout << "the pointer contains the memory address of a => point_a = &a" << point_a <<endl;
        // Address --> value: *pointer
        cout << "the value pointed by the pointer, can be recoverd => *point_a = "<< *point_a<<endl;
    }
    
    // Change value assigning variable:
    a = 11;
    cout << "a new value, command: a = 11 "<< endl;
    cout << "recalling value as *point_a = " << *point_a <<endl;
    // ?? wrong way to assign a pointer ??
    
    int *point_c;
    int c =9;
    //point_c = c; ahahahah
    
    //preferrable:
    point_c = new int;// assign no value to be pointed
    point_c = &c;
    cout<<" pointer assigned with 'new' usage before, *point_c = "<< *point_c <<endl;
    
    // Change value assigning new value to pointer:
    *point_a = 12;
    cout <<"assign new value to variable a  through command: *point_a = 12 "<<endl;
    cout<< "a new value: " << a << endl;
    
                // multiple pointers are accepted
                int* point_a_new = &a;
                *point_a_new =13;
                cout <<"MULTIPLE POINTERS TO a:  *point_a_new = 13 "<<endl;
                cout<< "a new value: " << a << endl;

    
    /////////// THE SWITCH EXAMPLE ///////////
    int b = 113;
    int *point_b = &b;
    
    
    // Exchange between variables (a,b) through pointers values:
    cout << " "<<endl;
    cout << "SWITCH BY VALUE "<<endl;
    
    cout << "Switch-pointers ==> a original value: "<< a <<endl;
    cout << "Switch-pointers ==> b original value: "<< b <<endl;
    

    cout <<"... *point_b = *point_a ..."<<endl;
    
    int temp = *point_a;
    
    *point_a = *point_b;// ITA: il valore puntato da point_a viene ora puntato da point_b
    *point_b = temp;// ITA: il valore puntato da point_b viene assegnato a temp
    
    
    
    cout << "Switch-pointers ==> a new value: "<< a <<endl;
    cout << "Switch-pointers ==> b new value: "<< b <<endl;
    
   
    // Exchange between pointers  (point_a,point_b) through pointers addresses:
    cout << " "<<endl;
    cout << "SWITCH BY ADDRESS "<<endl;
    
    cout << "Switch-by-values ==> *point_a original value: "<< *point_a <<endl;
    cout << "Switch-values ==> b original value: "<< *point_b <<endl;
    

    
    int *point_temp;// this must be a pointer
    
    point_temp = point_a;
    point_a = point_b;
    
    point_b = point_temp;
    
    
    cout <<"... point_b =  point_a ..."<<endl;
    
    cout << "Switch-pointers ==> a new value: "<< *point_a <<endl;
    cout << "Switch-pointers ==> b new value: "<< *point_b <<endl;
    
    /////////// THE STATIC-ARRAY EXAMPLE ///////////
    cout << " "<<endl;
    cout << "STATIC-ARRAY EXAMPLE "<<endl;
    
    int v[2] = {1,2};
    cout <<"sizeof(v) = "<<sizeof(v) << " ?? \n "<< "OK ==> 4 bytes each number"<<endl;
    cout <<"v[0] = " << v[0]<<endl;
    cout <<"v[1] = " << v[1]<<endl;
    //cout <<"*v[0] = " << *v[0]<<endl; THIS is not allowed
    
    
    /////////// THE MATRIX EXAMPLE ///////////
    cout << " "<<endl;
    cout << "MATRIX EXAMPLE "<<endl;
    
    int mat [2][2];
    
    mat[0][0] = 1;
    mat[1][0] = 2;
    mat[0][1] = 3;
    mat[1][1] = 4;
    cout <<"sizeof(mat) = "<<sizeof(mat) << " ?? \n"<<"OK ==> 4 x (4 bytes) = 16 "<<endl;
    cout << "*mat = "<<*mat<<endl;
    cout << "mat[0] = "<<mat[0]<<endl;
    cout << "mat[1] = "<<mat[1]<<endl;
  
                        // when declearing a matrix C++ creates an array with the addresses (starting address) of each row
                        cout << "                C++=> matrix as pointer-array:"<<endl;
                        for(int* m:mat){
                        cout <<"              "<< m<<endl; // distance between this 2 pointers is exactly 8 bytes
                            }
                        // This is true for any generic pointer (4 bytes to integer)
                        int vv = 0;
                        int *p = &vv;
                        cout << "                *p = & v => p = " << p<< endl;
                        cout <<"                  Exactly 4-bytes after we find the next address  p+1 = "<< p+1 <<endl;
    
    
    
    cout << "mat[0][0] => *mat[0] = "<<*mat[0]<<endl;
    cout << "mat[1][0] => *mat[1] = "<<*mat[1]<<endl;
    cout << "mat[0][1] => *(mat[0]+1)= " << *(mat[0]+1) << endl;//ITA: valore puntato dell' indirizzo di memoria mat[0] +1
     cout << "mat[1][1] => *(mat[1]+1)= " << *(mat[1]+1) << endl;

    
    cout<< "\n everything standard when looping over the matrix:"<< endl;
    for (int i =0; i < 2; i++){
        for(int j=0; j<2; j++){
        cout<< "mat("<<i<<","<<j <<") = " << mat[i][j]<<endl;
        }
    }
    
    
    ////////// FUNCTION WITH POINTERS EXAMPLE///////////
    cout << " "<<endl;
    cout << "FUNCTION WITH POINTERS EXAMPLE "<<endl;
    
    int v1 = 10;
    int v2 = 13;
    int ss = somma(v1,v2);
    cout << "sum through values: " << ss <<endl ;
    
    int* p1 = &v1;
    int* p2 = &v2;
    
    int* s = somma_point(p1,p2);
    int* s_alt = still_valid_somma(p1,p2);
    
    cout << "sum through pointers: " << *s <<endl ;
    cout << "sum through pointers alternative declaration: " << *s_alt<<endl ;
    
    //////////  POINTERS TO STRUCTS EXAMPLE ///////////
    cout << " "<<endl;
    cout << "FUNCTION WITH POINTERS EXAMPLE "<<endl;
    
    persona person1;
    person1.nome = "mario";
    person1.eta = 21;
    
    cout << " Struct: perso1.nome = "<< person1.nome <<endl;
    cout << " Struct: perso1.eta = "<< person1.eta <<endl;
    
    
    persona *point_person1 = &person1;
    cout << " accessing values insde the struct ?? "<<endl;
    cout << "persona* point_person1 = &person1;"<< endl;
    cout << "*point_person1.nome  ~>~>  point_person1 -> nome = "<< point_person1->nome <<endl;
                        // ITA: questo perchè una volta dichicato persona *point_person1
                        // anche gli attributi sono a loro volta puntatori
    
    cout << "this is because fields of the struct are pointers too.\n &(point_person1 -> nome)  return memomry addres of the field of the struct persona1: "<< &(point_person1 -> nome)<<endl;
    cout << " "<<endl;
    
    persona *point_person2; //ITA: finisce nella Heap(pezzo della ram dove vanno le variabili dinamiche=> possono sparire liberando ram)
                            //E.g. int x; " una volta allocata rimane in ram"
                            //     int *px; " viene messo nella heap, è consentito comando delete"
    point_person2 = new persona;
    
    point_person2 -> nome = "gigi";
    point_person2 -> eta = 12;
    cout << " putting values insde a pointer to  struct ?? "<<endl;
    cout << "persona *point_person2 ;"<< endl <<"persona point_person2 = new persona;"<<endl;
    cout << "point_person2 -> nome = gigi,  ~>~> point_person2-> nome: "<< point_person2->nome <<endl;
    
   
    delete point_person2;// this is allowed
    //delete person1; this is not allowed, since this is a static variable;
    //delete point_person1; // this makes the program to crashCpp_DynMemoryTn(83467,0x10037b3c0) malloc:          error for object 0x7fff5fbff0f0: pointer being freed was not allocated
    //*** set a breakpoint in malloc_error_break to debug
    
    persona *point_person3 = new persona;
    
    point_person3 -> nome = "gigi";
    point_person3 -> eta = 12;
    
    persona* pSum = new persona;
    
    pSum =sommaPersone(point_person1,point_person3);
    cout << "persone sommate, eta: " << pSum -> eta <<endl <<"persone sommate, nome: "<< pSum -> nome <<endl;
    
    
    
    ////////// DEEPER INTO DYNAMIC MEMORY///////////
    cout << " "<<endl;
    cout << " DEEPER INTO DYNAMIC MEMORY "<<endl;
    
    // tipo* point_tipo = new tipo ~~> for variables
    // tipo* point_tipo_array = new tipo[N] ~~> for arrays
    
    char * stringa;
    
    stringa = new char[3];
    stringa[0] = 'a';
    stringa[1] = 'b';
    stringa[2] = 'c';
                                    //{ new } tipically assigned to a pointer, but non necessarily
                                    //ITA: l'operatore new ~> alloca un'aread di memoria adatta a contenere l'oggetto di dimensione N
                                    //                      ~> inizializza a valore se specificato
                                   //                      ~> ritorna l'indirizzo del PRIMO ELEMENTO di tale  area
    delete[] stringa;
                                //{ delete[]/delete } destroys a the memory are previously setted
                                //ITA: l'operatore delete ~> se non associato ad una {new} => ERRORE
                                //                        ~> se associata ad new[resp new [] ]
                                //                        ~> al termine del programma tutto ciò che è stato allocato con new viene distrutto
    
    cout <<"String built as a dynamic array of chars: "<<stringa <<endl;
    
    cout << "insert array's length: "<< endl;
    int n;
    cin >> n;
    
    int *arr_dyn = new (nothrow) int[n]; // by default C++ aborts the program if {new} fails, adding {(nothrow)} if {new} fails the pointer                      retuns null;
    
    for(int i=0; i< n ; i++){
        
        cout << " inserisci valore #-"<<i <<endl;
        int new_val;
        cin >>new_val;
        arr_dyn[i] = new_val;
    }
    
    cout << " valori inseriti: "<<endl;
    for (int i=0; i< n ; i++){
        
        cout<<arr_dyn[i]<<endl;
        
    }
    
    delete[] arr_dyn;
    
    
    ////////// DEEPER INTO DYNAMIC MEMORY ==> my example of usage///////////
    cout << " "<<endl;
    cout << "DEEPER INTO DYNAMIC MEMORY ==> my example of usage "<<endl;
    
    
    int cnt_i =0;
    
    int *dyn_array_ins = NULL;
    
    
    
    
    while(true){
        
        string s = " ";
        
        while(s != "n" && s != "y"){
        cout << "new int ??[y/n]"<<endl;
       
        cin >> s;
        }
       
        if(s =="n"){
            break;
        }
        
        
        else{
            
            if(dyn_array_ins == NULL){
                
                dyn_array_ins = new int[1];
                cout << "insert int: " <<endl;
                int a_n;
                cin >> a_n;
                dyn_array_ins[0] = a_n;
            
                
                cnt_i++;
                
            }
            else{
               
                cout << "insert int: " <<endl;
                int curr_int;
                cin >> curr_int;
                
                int *temp_array = dyn_array_ins;
                
                
                //delete[] dyn_array_ins; ~~~~> this generates an error uhhhhhm
                dyn_array_ins = new int[cnt_i+1];// no specific need to delete[] dyn_array_ins
                
                for(int i=0; i< cnt_i ;i++){
                    
                    dyn_array_ins[i] = temp_array[i];
                   
                }
                
                dyn_array_ins[cnt_i] = curr_int;
                cnt_i ++;
                delete[] temp_array;
               
            }
            
            
        }
        
    }
    
  
    
    
    for(int  i=0; i<cnt_i; i++){
        
        int v = dyn_array_ins[i];
        cout<< v<<endl;
    }
    
    delete[] dyn_array_ins;
    
    //////////  DYNAMIC MEMORY ==> the dictionary case //////////
    int cnt_dic =0;
    dict *dict_array = NULL;
    
    while(true){
        
        dict curr_dict;
    cout <<"insert key: "<<endl;
    cin>> curr_dict.k;
        if(curr_dict.k == "stop"){
            break;
        }
    cout<< "insert value: " <<endl;
    cin >> curr_dict.v;
        
        if (dict_array == NULL){
            
            dict_array = new dict[1];
            dict_array[cnt_dic] = curr_dict;
            cnt_dic++;
        }
        else{
            
            dict* tmp_array = dict_array;
            dict_array = new dict[cnt_dic+1];
            
            for(int i=0; i< cnt_dic; ++i){
                
                dict_array[i] = tmp_array[i];
            }
            
            dict_array[cnt_dic] = curr_dict;
            delete[] tmp_array;
            cnt_dic++;
            
            
            
        }
    
       
        
    }
    
    
    
    
    for(int i=0; i< cnt_dic; i++){
        
        cout << "key #-"<< i << ": "<< dict_array[i].k;
        cout << " value #-"<< i << ": "<< dict_array[i].v << endl;
    }
    
    
    std::cout << "\n Goodbye, World!\n";
    
    return 0;
    
}

// la funzione ritorna una variabile di tipo puntatore
int* somma_point(int* &n1,int* &n2){
    int * v;
    v = new int; // ITA: inizializzazione puntatore vuoto
    
    *v = *n1 + *n2 ;
    return v;
    
}
int somma(int n1, int n2){
    return n1+n2;
}
int* still_valid_somma(int* n1,int* n2){
    
    int* v= new int;
    *v = *n1 + *n2;
    return v;
}

persona* sommaPersone(persona *&p1, persona *&p2){
    string ng = p1-> nome + p2-> nome;
    int eg = p1-> eta + p2-> eta;
    persona *pr = new persona;
    pr-> eta = eg;
    pr -> nome = ng ;
    
    return pr;
}
