#include<iostream>

struct Node{
    int data;
    Node* next;

    Node(const int& data, Node* next = nullptr){
        this->data = data;
        this->next = next;
    }
};

void pushBack(Node*& first, int data){
    if(first == nullptr){
        first = new Node(data);
        return;
    }

    Node* cur = first;

    while(cur->next != nullptr){
        cur = cur->next;
    }

    cur->next = new Node(data);

}

void swapSecond(Node *& first, int element){
    Node* cur = first;

    while(cur->next != nullptr){
        if(cur->data == element && cur->next->next != nullptr){
            int tempData = cur->data;
            cur->data = cur->next->next->data;
            cur->next->next->data = tempData;
        }

        cur = cur->next;
    }
}

void print( Node* first){
    Node* cur = first;

    while(cur != nullptr){
        std::cout<<cur->data<<" ";
        cur = cur->next;
    }
}

int main(){

    Node* first = nullptr;

    pushBack(first, 1);
    pushBack(first, 2);
    pushBack(first, 3);
    pushBack(first, 4);

    print(first);
    
    std::cout<<std::endl;

    swapSecond(first,2);
    print(first);

    return 0;
}