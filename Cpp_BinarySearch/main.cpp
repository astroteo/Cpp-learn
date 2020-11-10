#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {
       int rootVal = root.getValue();
       if(rootVal == value){
           return true;
       }
       else if(rootVal > value){
           if(root.getLeft()){
               return contains(*root.getLeft(),value);
           }
           else{
               return false;
           }
       }
       else{
           if(root.getRight()){
               return contains(*root.getRight(),value);
           }
           else{
               return false;
           }
       }

   }
};

#ifndef RunTests
int main()
{
    Node n1(1, NULL, NULL);
    Node n3(3, NULL, NULL);
    Node n2(2, &n1, &n3);
    std::cout << "......................."<<std::endl;
    std::cout << BinarySearchTree::contains(n2, 3)<<std::endl;
    std::cout << "......................."<<std::endl;
}
#endif
