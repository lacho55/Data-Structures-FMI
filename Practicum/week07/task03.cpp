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
void add(const T& elem, Node<T>*& node){
    if(node){
        if(elem < node->data){
            if(node->left){
                add(elem, node->left);
            }
            else{
                node->left = new Node<T>(elem, nullptr, nullptr);
            }
        }
        else if(elem == node->data){
            return;
        }
        else{
            if(node->right){
                add(elem, node->right);
            }
            else{
                node->right = new Node<T>(elem, nullptr, nullptr);
            }
        }
    }
    else{
        node = new Node<T>(elem, nullptr, nullptr);
    }
}


template<class T>
void fromArrToTree(const T arr[], int size, Node<T>*& root){

    for(int i = 0; i < size; i++){
        add(arr[i], root);
    }

}


template<class T>
int* fromTreeToArr(const Node<T>* root, T* arr){

    if(root == nullptr){
        return arr;
    }
    
    int* left = fromTreeToArr(root->left, arr);
    left[0] = root->data;

    return fromTreeToArr(root->right, left + 1);
}

template<class T>
const int sizeOfTree(Node<T>*& root){
    if(root == nullptr){
        return 0;
    }

    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
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
    int arr[] = {1, 2, 3};
    Node<int>* tree = nullptr;

    fromArrToTree(arr, 3, tree);
    printTree(tree);

    Node<int>* treeForArr = new Node<int>{1,
                                    new Node<int>{2, nullptr, nullptr},
                                    new Node<int>{3, nullptr, nullptr}};

    
    int size = sizeOfTree(treeForArr);
    int* newArr = new int[size];
    int* t = fromTreeToArr(treeForArr, newArr);
    
    for(int i = 0; i < size; i++){
        std::cout << newArr[i] << " ";
    }
    
    return 0;
}