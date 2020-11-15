#include<iostream>
#include<assert.h>

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
class BinTree{
    private:
        Node<T>* root;

    public:
        BinTree();
        void insert(const T&);//Task01
        void print() const;

    private:
        void insertHelper(const T&, Node<T>*&); //Task01
        void printHelper(const Node<T>*) const;

};


template<class T>
BinTree<T>:: BinTree(){
    root = nullptr;
}


//Task01
template<class T>
void BinTree<T>:: insert(const T& element){
    insertHelper(element, root);
}


template<class T>
void BinTree<T>:: print() const{
    printHelper(root);
}


//Task01
template<class T>
void BinTree<T>:: insertHelper(const T& element, Node<T>*& node){
    if(node){
        if(element < node->data){
            if(node->left){
                insertHelper(element, node->left);
            }
            else{
                node->left = new Node<T>(element, nullptr, nullptr);
            }
        }
        else if(element == node->data){
            return;
        }
        else{
            if(node->right){
                insertHelper(element, node->right);
            }
            else{
                node->right = new Node<T>(element, nullptr, nullptr);
            }
        }
    }
    else{
        node = new Node<T>(element, nullptr, nullptr);
    }
}


template<class T>
void BinTree<T>:: printHelper(const Node<T>* node) const{
    if(node){

        printHelper(node->left);

        std:: cout << node->data << " ";

        printHelper(node->right);
    }
}


int main(){
    BinTree<int> tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);

    tree.print();


    return 0;
}
