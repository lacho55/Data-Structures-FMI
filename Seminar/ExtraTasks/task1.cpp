#include <iostream>

struct Node{
    int data;
    Node* left;
    Node* right;
};



bool isOrdered(Node* root){
    if(root == nullptr){
        return true;
    }
    if(root->left->data >= root->data && root->left != nullptr){
        return true;
    }
    if(root->right->data >= root->data && root->right != nullptr){
        return true;
    }

    return isOrdered(root->left) && isOrdered(root->right);
}


int main(){
    Node* tree = new Node {10, 
                            new Node{5,
                                    new Node{2, nullptr, nullptr},
                                    new Node{7, nullptr, nullptr}},
                            new Node{70, nullptr, nullptr}};


    std::cout << std::boolalpha << isOrdered(tree) << std::endl;

    return 0;
}
