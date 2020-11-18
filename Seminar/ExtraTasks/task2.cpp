#include <iostream>
#include <assert.h>

template<class T>
struct Node{
    int data;
    Node<T>* left;
    Node<T>* right;
};


template<class T>
int cntNodes(Node<T>* current){
    if(current == nullptr){
        return 0;
    }
    return 1 + cntNodes(current->left) + cntNodes(current->right);
}


template<class T>
T sumTreeElems(Node<T>* nums, Node<char>* oprs){
    if(nums == nullptr && oprs == nullptr){
        return 0;
    }
    T nodeCalc;

    switch(oprs->data){
        case '*': nodeCalc = nums->data * cntNodes(nums);
                  break;
        case '+': nodeCalc = nums->data + cntNodes(nums);
                  break;
        case '-': nodeCalc = nums->data - cntNodes(nums);
                  break;
        default: assert(false);
    }

    return nodeCalc + sumTreeElems(nums->left, oprs->left) + sumTreeElems(nums->right, oprs->right);
}


int main(){
    Node<int> * tree = new Node<int>{5, 
				new Node<int>{4, 
					new Node<int>{3,nullptr,nullptr}, 
					new Node<int>{2,nullptr,nullptr}},
				new Node<int>{1,nullptr, 
                    new Node<int>{10, nullptr, nullptr}}};

    Node<char> * charTree = new Node<char>{'*',
                                    new Node<char>{'+', 
                                        new Node<char>{'+', nullptr, nullptr},
                                        new Node<char>{'*', nullptr, nullptr}},
                                    new Node<char>{'-',
                                         nullptr,
                                         new Node<char>{'-', nullptr, nullptr}}
                                    };

    std::cout << sumTreeElems(tree, charTree);

    


    return 0;
}
