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


int sumNodes(const Node<int>* root){
    if(root == nullptr){
        return 0;
    }

    if(root->data > 0){
        return root->data + sumNodes(root->left) + sumNodes(root->right);
    }
    else{
        return sumNodes(root->left) || sumNodes(root->right);
    }

}



int main(){
        Node<int>* tree = new Node<int>{1,
                                    new Node<int>{-2, nullptr, nullptr},
                                    new Node<int>{3, nullptr, nullptr}};

    std::cout << sumNodes(tree);

    return 0;
}