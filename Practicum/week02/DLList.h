#pragma once
#include<iostream>

template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& newData, Node<T>* newNext = nullptr, Node<T>*  newPrev = nullptr ){
        this->data = newData;
        this->next = newNext;
        this->prev = newPrev;
    }

};


template<class T>
class DLList{
    private:
        Node<T>* first;
        Node<T>* last;
        size_t currentSize;

    /* ------ Helping Functions ------ */
    void copy(const DLList<T>&);
    void destroy();    

    public:
    /* ------ Constructors ------ */
    DLList();
    DLList(const DLList<T>&);
    DLList<T>& operator=(const DLList<T>&);
    ~DLList();

    /* ----- Increasing Functionality ------ */
    void print() const;
    bool empty() const;
    void push_back(const T&);
    void push_front(const T&);

    /* ----- Tasks from week02 practicum -------- */
    void mergeLists(DLList<T>&);
    bool checkLastFirst();
    void removeClone();

};


/* ------ Helping Fuctions ------ */
template<class T>
void DLList<T>:: copy(const DLList<T>& other){

    first = last = nullptr;
    currentSize = 0;

    if(other.first != nullptr){

        Node<T>* otherIterate = other.first->data;

        while(otherIterate != nullptr){

            Node<T>* newElem = new Node<T>(otherIterate->data);

            if(first == nullptr){
                first = last = newElem;
            }else{
                last->next = newElem;
                newElem->prev = last;
                last = last->next;
            }
            currentSize++;
            otherIterate = otherIterate->next;

        }
    }
}


template<class T>
void DLList<T>:: destroy(){

    while(first != nullptr){
        Node<T>* toDelete = first;
        first = first->next;
        delete toDelete;
    }

    first  = last = nullptr;
    currentSize = 0;
}


/* ------- Constructors ------ */
template<class T>
DLList<T>:: DLList(){
    this->first = nullptr;
    this->last = nullptr;
    this->currentSize = 0;
}


template<class T>
DLList<T>:: DLList(const DLList<T>& other){
    copy(other);
}


template<class T>
DLList<T>& DLList<T>:: operator=(const DLList<T>& other){

    if(this != &other){
        destroy();
        copy(other);
    }

    return *this;
}


template<class T>
DLList<T>:: ~DLList(){
    destroy();
}


/* ----- Increasing Functionality -------- */
template<class T>
void DLList<T>:: print() const{

    Node<T>* cur = first;

    while(cur != nullptr){
        std::cout << cur->data << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}


template<class T>
bool DLList<T>:: empty() const{
    return (first == nullptr && last == nullptr);
}


template<class T>
void DLList<T>:: push_back(const T& newNode){

    if(first == nullptr){
        first = last = new Node<T>(newNode);
        currentSize++;
        return;
    }

    Node<T>* toAdd = new Node<T>(newNode);

    last->next = toAdd;
    toAdd->prev = last;
    last = last->next;

    currentSize++;
}


template<class T>
void DLList<T>:: push_front(const T& newNode){

    if(first == nullptr){
        first = last = new Node<T>(newNode);
        currentSize++;
        return;
    }

    Node<T>* toAdd = new Node<T>(newNode);

    first->prev = toAdd;
    toAdd->next = first;
    toAdd->prev = nullptr;
    first = toAdd;
    
    currentSize++;
}


 /* ----- Tasks from week02 practicum -------- */
template<class T>
void DLList<T>:: mergeLists(DLList<T>& rhs){

    Node<T>* separator = new Node<T>('#');

    this->push_back('#');

    while(rhs.first != nullptr){
        this->push_back(rhs.first->data);
        rhs.first = rhs.first->next;
    }

}


template<class T>
bool DLList<T> ::checkLastFirst() {

	Node<T>* curr = first;
	int hashTags = 0, words = 1;
	bool isTrue = 0;


	if (first != nullptr) {

		while (curr != nullptr) {

			//counting hashtags for words number and skipping the first one
			if (curr->data == '#') {
				hashTags++;
			}

			if (curr->data == '#' && hashTags > 1) {
				if (first->data == curr->prev->data || first->data == last->data) {
					isTrue = true;
					words++;
				}

				if (last->data == curr->next->data) {
					isTrue = true;
					words++;
				}

				if (curr->prev->data == curr->next->data) {
					isTrue = true;
					words++;
				}

			}

			curr = curr->next;
		}

	}

	return (isTrue && words != 2);
}


template<class T>
void DLList<T> ::removeClone() {
	Node<T>* curr = first;

	int counter = 0;

	while (curr->next != nullptr) {
		if (curr->next->data == curr->data) {
			++counter;

			if (counter == 2) {
				Node<T>* toDelete = new Node<T>(curr->prev->data);
				curr->prev->prev->next = curr;
				curr->prev = curr->prev->prev;

				delete toDelete;
				counter = 0;
				continue;
			}
		}
		curr = curr->next;

	}
}
