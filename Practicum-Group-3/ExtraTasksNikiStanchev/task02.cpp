#include <iostream>


struct Node{
    int data;
    Node* left;
    Node* right;
};

bool isFull(Node* current){
    if(current == nullptr){
        return true;
    }
    if(current->left == nullptr && current->right == nullptr){
        return true;
    }
    if(current->left != nullptr && current->right != nullptr){
        return true;
    }
    if((current->left != nullptr && current->right == nullptr) || (current->left == nullptr && current->right != nullptr)){
        return false;
    }

    return isFull(current->left) && isFull(current->right);
}


int main(){
    Node* tree = new Node{4, 
                        new Node{2, nullptr, nullptr},
                     nullptr};


    std::cout << std::boolalpha << isFull(tree);

    return 0;
}
