#include<iostream>

template<class T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& newData, Node<T>* newLeft = nullptr, Node<T>* newRigth = nullptr){
        data = newData;
        left = newLeft;
        right = newRigth;
    }
};


template<class T>
void printLeaves(const Node<T>* root){
    
    if(root == nullptr){
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        std::cout << root->data << " ";
        return;
    }
    else{
        printLeaves(root->left);
        printLeaves(root->right);
    }
}

template<class T>
void printLRR(const Node<T>* root){
    if(root == nullptr){
        return;
    }
        printLRR(root->left);
        std::cout << root->data << " ";
        printLRR(root->right);
    
}


template<class T>
void printRLR(const Node<T>* root){
    if(root == nullptr){
        return;
    }
    std::cout << root->data << " ";
    printRLR(root->left);
    printRLR(root->right);
}


template<class T>
void printRRL(const Node<T>* root){
    if(root == nullptr){
        return;
    }

    printRRL(root->right);
    std::cout << root->data << " ";
    printRRL(root->left);
}

int main(){
    Node<int>* tree = new Node<int>{1, 
                                     new Node<int>{2,
                                        new Node<int>{3, nullptr, nullptr}, nullptr}, 
                                     new Node<int>{4, nullptr, nullptr}};

    printLeaves(tree);
    std::cout << std::endl;

    printLRR(tree);
    std::cout << std::endl;

    printRLR(tree);
    std::cout << std::endl;

    printRRL(tree);

    return 0;
}