#include <iostream>
#include <vector>
#include <assert.h>

template<class T>
struct Node{
    int data;
    Node<T>* left;
    Node<T>* right;
};

template<typename T>
void palindromeTreesHelper(Node<T>* current, size_t level, std::vector<T>& nodes)
{
    if(current == nullptr)
    {
        return;
    }
    if(level == 0 && current!=nullptr)
    {
        nodes.push_back(current->data);
        return;
    }
    palindromeTreesHelper(current->left, level-1, nodes);
    palindromeTreesHelper(current->right, level-1, nodes);
}

template<typename T>
bool isPalindrome(std::vector<T>& elementsAtLevel)
{
    size_t size = elementsAtLevel.size();
    for(size_t i = 0; i < size/2; i++)
    {
        if(elementsAtLevel[i] != elementsAtLevel[size-i-1])
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool palindromeTrees(Node<T>* current, size_t level)
{ 
    if(current == nullptr || level == 0)
    {
        return true;
    }

    std::vector<T> elementsAtLevel;
	palindromeTreesHelper(current, level, elementsAtLevel);
	return isPalindrome(elementsAtLevel);
}

int main(){
   Node<int>* tree = new Node<int>{1, 
                                new Node<int>{2,
                                            new Node<int>{1, nullptr, nullptr},
                                            new Node<int>{3, nullptr, nullptr}},
                                new Node<int>{2, 
                                            new Node<int>{3, nullptr, nullptr},
                                            new Node<int>{1, nullptr, nullptr}}};

    std::cout<< isPalindrome(tree, 2);


    return 0;
}
