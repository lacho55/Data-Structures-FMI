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
bool findElement(const T& elem, Node<T>* root){
    if(root == nullptr){
        return false;
    }
    if(elem == root->data){
        return true;
    }

    return findElement(elem, root->left) || findElement(elem, root->right);
}


int main(){
    Node<int>* tree = new Node<int>{1,
                                    new Node<int>{2, nullptr, nullptr},
                                    new Node<int>{3, nullptr, nullptr}};

    Node<int>* tree2 = new Node<int>{4,
                        new Node<int>{2,
                                new Node<int>{7, nullptr,nullptr}, 
                                new Node<int>{2, nullptr, nullptr}},
                        new Node<int>{5, 
                                new Node<int>{2, nullptr, nullptr}, 
                                new Node<int>{3, nullptr, nullptr}}};

    std::cout << findElement(10,tree) << std::endl;
    std::cout << findElement(7,tree2);

    return 0;
}