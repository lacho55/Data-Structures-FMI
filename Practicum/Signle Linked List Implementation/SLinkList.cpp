#include "SLinkList.h"

//Helper functions

SLinkList :: copy(const SLinkList& rhs){

    this->first = new Node(rhs.data->data);

    Node* copy = rhs.first;
    Node* cur = this->first;

    while(copy->next != nullptr){
        cur->next = new Node(copy->next->data);
        copy = copy->next;
        cur = cur->next;
    }
}


SLinkList :: clear(){

    Node* temp = nullptr;

    while(first != nullptr){
        temp = new Node(first->data);
        first = first->next;
        delete temp;
    }

    this->first = nullptr;
}


SLinkList :: SLinkList(){
    this->first = nullptr;
}


SLinkList :: SLinkList(const SLinkList& rhs){
    this->copy(rhs);
}


SLinkList :: operator=(const SLinkList& rhs){
    if(this != &rhs){
        this->clear();
        this->copy(rhs);
    }

    return *this;
}

SLinkList :: ~SLinkList(){
    this->clear();
}