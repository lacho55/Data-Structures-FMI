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
T max(Node<T>* root){

    Node<T>* node = root;

    while(node->right){
        node = node->right;
    }


    return node->data;
}

template<class T>
void deleteFromTree(const T& elem, Node<T>*& node){

    if(elem < node->data){
        deleteFromTree(elem, node->left);
    }
    else if(elem > node->data){
        deleteFromTree(elem, node->right);
    }
    else{
        if(node->left && node->right){
            node->data = max(node->left);
            deleteFromTree(max(node->left), node->left);
        }
        else if(node->left){
            Node<T>* tmp = node;
            node = node->left;
            delete tmp;
        }
        else{
            Node<T>* temp = node;
            node = node->right;
            delete temp;
        }
    }
}


template<class T>
void printTree(const Node<T>* root){
    if(root){
        std::cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main(){
    Node<int>* tree = new Node<int>{1,
                                    new Node<int>{2, nullptr, nullptr},
                                    new Node<int>{3, nullptr, nullptr}};


    deleteFromTree(9, tree);
    printTree(tree);

    return 0;
}