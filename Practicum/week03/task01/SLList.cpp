#pragma once

#include "SLList.h"


/* ----- Helpers ------ */
template<class T>
void SLList<T>:: copy(const SLList<T>& other){
    
    Node* copy = other.first;
    Node* curr = this->first;

    while(copy->next != nullptr){
        curr->next = new Node(copy->next->data);
        copy = copy->next;
        curr = curr->next;
    }

}


template<class T>
void SLList<T>:: clear(){
    Node* temp = nullptr;

    while(first != nullptr){
        temp = new Node(first->data);
        first = first->next;
        delete temp;
    }

    this->first = nullptr;

}



/* ----- Constructors ----- */
template<class T>
SLList<T> :: SLList(){
    first = nullptr;
}


template<class T>
SLList<T>:: SLList(const SLList<T>& other){
    this->copy(other);
}


template<class T>
SLList<T>& SLList<T>:: operator=(const SLList<T>& other){
    if(this != &other){
        destroy();
        copy(other);
    }

    return *this;
}


template<class T>
SLList<T>:: ~SLList(){
    destroy();
}
