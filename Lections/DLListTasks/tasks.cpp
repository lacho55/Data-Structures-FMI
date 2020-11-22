
#include<iostream>


template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& newData, Node<T>* newNext = nullptr, Node<T>* newPrev = nullptr){
        data = newData;
        next = newNext;
        prev = newPrev;
    }
};


template<class T>
class DLList{
    private:
    Node<T>* first;
    Node<T>* last;
    size_t currentSize;

    void copy(const DLList<T>&);
    void destroy();

    public:
    DLList();
    DLList(const DLList<T>&);
    DLList<T>& operator= (const DLList<T>&);
    ~DLList();

    void print() const;
    void push_back(const T&);
    void push_front(const T&);

};

template<class T>
void DLList<T>:: copy(const DLList<T>& other){

    first = last = nullptr;
    currentSize = 0;

    if(other.first != nullptr){

        Node<T>* otherIterate = other.first->data;

        if(otherIterate != nullptr){

            Node<T>* newElem = new Node<T>(otherIterate->data);

            if(first == nullptr){
                first = last =  newElem;
            }
            else{
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

    first = last = nullptr;
    currentSize = 0;

}


template<class T>
DLList<T> :: DLList(){
    first = nullptr;
    last = nullptr;
    currentSize = 0;
}


template<class T>
DLList<T> :: DLList(const DLList<T>& other){
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


template<class T>
void DLList<T>:: print() const{

    Node<T>* curr = first;

    while(curr != nullptr){
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}


template<class T>
void DLList<T>:: push_back(const T& newElem){

    if(first == nullptr){
        first = last = new Node<T>(newElem, nullptr, nullptr);
        currentSize++;
    }
    else{

        Node<T>* toAdd = new Node<T>(newElem, nullptr, nullptr);

        last->next = toAdd;
        toAdd->prev = last;
        last = last->next;      

        currentSize++;
    }
}


template<class T>
void DLList<T>:: push_front(const T& newElem){

    if(first == nullptr){
        first = last = new Node<T>(newElem, nullptr, nullptr);
        currentSize++;
    }
    else{

        Node<T>* toAdd = new Node<T>(newElem, nullptr, nullptr);

        toAdd->next = first;
        first->prev = toAdd;
        first = toAdd;

        currentSize++;
    }
}

int main(){
    DLList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.push_front(5);

    list.print();



    return 0;
}
