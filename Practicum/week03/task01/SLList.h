#pragma once

#include<iostream>


template<class T>
class SLList{
    private:
        struct Node{    
            T data;
            Node* next;

            Node(const T& newData, Node* next = nullptr){
                this->data = newData;
                this->next = next;
            }
        };

        Node* first;


    /* ---- Helpers ----- */
    void copy(const SLList&);
    void destroy();

    public:
        /* ----- Constructors -----*/
        SLList();
        SLList(const SLList&);
        SLList& operator=(const SLList&);
        ~SLList();
};
