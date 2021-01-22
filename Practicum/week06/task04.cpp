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


void addNumberToNode(Node<int>*& root, int num){
    if(root == nullptr){
        return;
    }

   
    root->data += num;
    addNumberToNode(root->left, num);
    addNumberToNode(root->right, num);
} 


template<class T>
int nodeCounter(const Node<T>* root){
    if(root == nullptr){
        return 0;
    }

    return 1 + nodeCounter(root->left) + nodeCounter(root->right);
}


template<class T>
void print(const Node<T>* root){
    if(root){
        print(root->left);
        std::cout << root->data << " ";
        print(root->right);
    }
}


int main(){
      Node<int>* tree = new Node<int>{1,
                                    new Node<int>{2, nullptr, nullptr},
                                    new Node<int>{3, nullptr, nullptr}};

    addNumberToNode(tree, 1);
    print(tree);

    std::cout << std::endl;
    std::cout << nodeCounter(tree);


    return 0;
}