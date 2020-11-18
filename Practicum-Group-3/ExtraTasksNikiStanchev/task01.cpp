#include <iostream>


struct Node{
    int data;
    Node* left;
    Node* right;
};


int sumParents(Node* current, int x){
    if(current == nullptr){
        return 0;
    }
    if(current->left != nullptr && current->right != nullptr && (current->left->data == x || current->right->data == x)){
        return current->data + sumParents(current->left, x) + sumParents(current->right, x);;
    }
    
    return sumParents(current->left, x) + sumParents(current->right, x);
}

int main(){
   Node* tree = new Node{4,
                        new Node{2,
                                new Node{7, nullptr,nullptr}, 
                                new Node{2, nullptr, nullptr}},
                        new Node{5, 
                                new Node{2, nullptr, nullptr}, 
                                new Node{3, nullptr, nullptr}}};

    std::cout << sumParents(tree, 2) << std::endl;


    return 0;
}
