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

template<class T>
void insert(const T& element, Node<T>*& node){

    if(node){

        if(element < node->data){

            if(node->left){
                insert(element, node->left);
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
                insert(element, node->right);
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
void print(Node<T>*& root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << root->data << ' ';
	print(root->left);
	print(root->right);
}


int main(){
    Node<int>* tree = nullptr;

    insert(1, tree);
    insert(2, tree);

    print(tree);


    return 0;
}