#include <iostream>
#include <assert.h>

template<class T>
struct Node{
    int data;
    Node<T>* left;
    Node<T>* right;
};


template<class T>
bool isMirrorHelper(Node<T>* leftTree, Node<T>* rightTree){
    if(leftTree == nullptr && rightTree == nullptr){
        return false;
    }
    if(leftTree->data == rightTree->data && leftTree && rightTree){
        return true;
    }

    return isMirrorHelper(leftTree->left, rightTree->right) && isMirrorHelper(leftTree->right, rightTree->left);
}

template<class T>
bool isMirror(Node<T>* current){
    if(current == nullptr){
        return false;
    }

    return isMirrorHelper(current->left, current->right);
}


int main(){
   Node<int>* tree = new Node<int>{1, 
                                new Node<int>{2,
                                            new Node<int>{3, nullptr, nullptr},
                                             nullptr},
                                new Node<int>{2, 
                                            new Node<int>{3, nullptr, nullptr}, nullptr}};

    std::cout << std::boolalpha << isMirror(tree);


    return 0;
}
