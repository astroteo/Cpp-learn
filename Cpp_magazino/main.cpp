#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <locale>         // std::locale, std::tolower

//#define debug_

/*
compile as: g++ -std=c++17 main.cpp -o exec
run as: ./exec
*/

class Node
{
  public:
    Node(std::string name, std::list<Node> children = {} )
    {
        name_ = name;
        children_= children;
    };

    static std::string cToLower(std::string data)
        {
            for(int i=0; i < data.length(); i++) {
                data[i] = tolower(data[i]);
            }
            return data;
        };

    void check(Node* node, std::string needle)
        {
            //if strings are equal => increment counter.
            std::string strNode = node->cToLower(node->getName());

            #ifdef debug_
            std::cout << strNode<< std::endl;
            #endif

            if (strNode == needle)
              this->count++;


            //childrens
            std::list<Node> sons = node->getChildren();
            std::list<Node>::iterator sons_it;


            for(sons_it=sons.begin(); sons_it != sons.end(); ++sons_it)
                this->check(&(*sons_it), needle);

        }

        int count_nodes_containing_string(std::string needle)
        {
            needle = this->cToLower(needle);

            check(this, needle);
            return this->count;
        };

        std::string getName(){
            return this->name_;
        }

        std::list<Node> getChildren(){
            return this->children_;
        }

        void resetCounter(){
             this->count =0;
        }

private:
    std::string name_;
    std::list<Node> children_;
    int count =0;
};

#ifndef RunTests
int main()
{
    //Create an example tree
    Node n("root",{
        {"MagaZino",{
            {"I"},
            {"Love"},
            {"magazino"}
            }},
        {"Hello",{
            {"Hello",{
                {"Hello",{
                    {"World"}
                }}
            }}
        }}
    });
    //Cout the solution
    std::cout << "searched word: " << "test" << std::endl
              << n.count_nodes_containing_string("test")
              << std::endl
              << "------------------------------------"<< std::endl
              << std::endl;

    n.resetCounter();

    std::cout << "searched word: " << "magazino" << std::endl
              << n.count_nodes_containing_string("magazino")
              << std::endl
              << "------------------------------------"<< std::endl
              << std::endl;

    n.resetCounter();

    std::cout << "searched word: " << "hello" << std::endl
              << n.count_nodes_containing_string("hello")
              << std::endl
              << "------------------------------------"<< std::endl
              << std::endl;
}
#endif
