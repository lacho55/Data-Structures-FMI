#include<iostream>

template<class T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& newData, Node<T>* newLeft = nullptr, Node<T>* newRight = nullptr){
        data = newData;
        left = newLeft;
        right = newRight;
    }
};


template<class T>
bool areMirror(const Node<T>* rootFirst, const Node<T>* rootSecond){
    if(rootFirst == nullptr && rootSecond == nullptr){
        return true;
    }
    if(rootFirst == nullptr || rootSecond == nullptr){
        return false;
    }

    return rootFirst->data == rootSecond->data &&
    areMirror(rootFirst->left, rootSecond->right) &&
    areMirror(rootFirst->right, rootSecond->left);
}


int main(){
     Node<int>* tree1 = new Node<int>{1,
                                    new Node<int>{2, nullptr, nullptr},
                                    new Node<int>{3, nullptr, nullptr}};
     Node<int>* tree2 = new Node<int>{1,
                                    new Node<int>{3, nullptr, nullptr},
                                    new Node<int>{2, nullptr, nullptr}};

    std::cout << areMirror(tree1, tree2);

    return 0;
}