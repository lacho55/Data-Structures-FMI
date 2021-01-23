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
int depth(const Node<T>* node){
    int d = 0;

    while(node != nullptr){
        d++;
        node = node->left;
    }

    return d;
}


template<class T>
bool isPerfectHelper(const Node<T>* node, int d, int level = 0){
    if(node == nullptr){
        return true;
    }
    if(node->left == nullptr && node->right == nullptr){
        return (d == level + 1);
    }
    if(node->left == nullptr || node->right == nullptr){
        return false;
    }

   return isPerfectHelper(node->left, d, level + 1) &&
   isPerfectHelper(node->right, d, level + 1);
}

template<class T>
bool isPerfect(const Node<T>* root){
    int d = depth(root);
    isPerfectHelper(root, d);
}

int main(){
     Node<int>* tree = new Node<int>{1,
                                    new Node<int>{2, nullptr, nullptr},
                                    new Node<int>{3, nullptr, nullptr}};
                                
    Node<int>* tree2 = new Node<int>{1,
                                    new Node<int>{2, 
                                                new Node<int>{3, nullptr, nullptr}, 
                                                nullptr},
                                    new Node<int>{4, nullptr, nullptr}};
    
    std::cout << isPerfect(tree) << std::endl;
    std::cout << isPerfect(tree2);

    return 0;
}