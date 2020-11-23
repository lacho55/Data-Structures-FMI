#include<iostream>
#include<vector>


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
    bool empty() const;
    void push_back(const T&);
    void push_front(const T&);

    int count(const DLList<T>&, int) const; //TASK01
    Node<T>* range(int, int); //TASK02
    void removeAll(const T&); //TASK03
    void append(DLList<T>&); //TASK04
    DLList<T>* concat(DLList<T>*, DLList<T>*); //TASK05
    void reverse(); //TASK06
    void removeDuplicates(); //TASK07

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
bool DLList<T>:: empty() const{
   return (first == nullptr && last == nullptr);
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


//TASK01
template<class T>
int DLList<T>:: count(const DLList<T>& list , int x) const{

    int counter = 0;

    Node<T>* curr = first;

    while(curr != nullptr){
        if(curr->data == x){
            counter++;
        }
        curr = curr->next;
    }

    return counter;
}


//TASK02
template<class T>
Node<T>* DLList<T>:: range(int x, int y){
    if(x <= y){

        destroy();
        Node<T>* curr = first;

        while(x <= y){
            Node<T>* toAdd = new Node<T>(x, nullptr, nullptr);

            if(first == nullptr){
                curr = first = last = toAdd;
            }
            else{
                curr->next = toAdd;
                toAdd->prev = curr;
                curr = curr->next;
            }

            x++;
        }

        last = first;

        return first;
    }
    else{
        std::cout << "X is greater than Y!" << std::endl;
        return nullptr;
    }
}


//TASK03
template<class T>
void DLList<T>::removeAll(const T& x){

    Node<T>* curr = first;

    if(curr != nullptr){

        while(curr != nullptr){

        if(first->data == x){
            Node<T>* toDelete = first;
            first = first->next;
            first->prev = nullptr;
            delete toDelete;
            currentSize--;
            curr = first;
        }
        if(last->data == x){
            Node<T>* toDelete = last;
            last = last->prev;
            last->next = nullptr;
            delete toDelete;
            currentSize--;
        }

        if(curr->data == x){
            Node<T>* temp = curr->next;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
            curr = temp;
            currentSize--;
        }
            curr = curr->next;
       }
    }
    else{
        std::cout << "The list is empty !!!" << std::endl;
    }
}

//TASK04
template<class T>
void  DLList<T>:: append(DLList<T>& list2){
    
    if(this->empty() && list2.empty()){
        std::cout << "Cannot append empty lists" <<std::endl;
    }
    else if(this->empty() && !list2.empty()){
        list2.print();
    }
    else if(!this->empty() && list2.empty()){
        this->print();
    }
    else{
        Node<T>* toAdd = list2.first;

        while(toAdd != nullptr){
            this->push_back(toAdd->data);
            toAdd = toAdd->next;
        }

        this->print();
    }
}


//TASK05
template<class T>
DLList<T>* DLList<T>:: concat(DLList<T>* list1, DLList<T>* list2){

    Node<T>* curr = list1->first;

    while(curr != nullptr){
        this->push_back(curr->data);
        curr = curr->next;
    }

    curr = list2->first;

    while(curr != nullptr){
        this->push_back(curr->data);
        curr = curr->next;
    }

    return this;
}


//TASK06
template<class T>
void DLList<T>:: reverse(){

   Node<T>* temp = nullptr;
   Node<T>* curr = first;

   while(curr != nullptr){
       temp = curr->prev;
       curr->prev = curr->next;
       curr->next = temp;
       curr = curr->prev;
   }

   if(temp != nullptr){
       first = temp->prev;
   }
}


//TASK07
template<class T>
void DLList<T>:: removeDuplicates(){
    int counter = 1;


    Node<T>* curr = first;
    Node<T>* otherIterate = curr->next;

    while(curr != nullptr && otherIterate != nullptr){  
        
        while(otherIterate != nullptr){
            if(curr-> data == otherIterate->data){
                counter++;
            }

            otherIterate = otherIterate->next;
        }

        int x = curr->data;

        if(counter > 1){
            removeAll(x);
            curr = first;
            otherIterate= curr->next;
            counter = 1;
            
        }
        else{
            counter = 1;
        curr = curr->next;
        otherIterate = curr->next;
        }        
    }
}




int main(){
    /*DLList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.push_front(5);
    list.push_front(3);
    list.push_front(4);

    list.print();

    std::cout << std::endl;
    //TASK01
    std::cout << list.count(list,3) << std::endl;

    //TASK02
    DLList<int> list2;
    
    std:: cout << list2.range(1, 10)->data << std::endl;


    //TASK03
    std::cout << "TASK03: " << std::endl;

    DLList<int> list3, caller;

    list3.push_back(1);
    list3.push_back(3);
    list3.push_back(2);
    list3.push_front(5);
    list3.push_front(3);
    list3.push_front(4);


    list3.print();
    list3.removeAll(4);
    list3.print();
    list3.removeAll(2);
    list3.print();
    list3.removeAll(5);
    list3.print();
    list3.removeAll(3);
    list3.print();

    */
    //TASK04
    /*std::cout << "TASK04: " <<std::endl;
    DLList<int> list4, list5;

    list4.push_back(3);
    list4.push_back(5);
    list4.push_back(8);
    list4.push_back(25);
    list5.push_back(1);
    list5.push_back(53);
    list5.push_back(331);
    list5.push_back(126);
    
    list4.append(list5);*/

    //TASK05
    /*std::cout << "TASK05: " <<std::endl;
    DLList<int> list6, list7, list8;

    list7.push_back(2);
    list7.push_back(5);
    list8.push_back(22);
    list8.push_back(41);

    list6.concat(&list7, &list8)->print();*/


    //TASK06
    /*DLList<int> list9;

    list9.push_back(1);
    list9.push_back(2);
    list9.push_back(3);

    list9.reverse();
    list9.print();*/

    //TASK07
    std::cout << "TASK07: " << std::endl;
    DLList<int> list10;

    list10.push_back(1);
    list10.push_back(2);
    list10.push_back(1);
    list10.push_back(5);
    list10.push_back(2);
    list10.push_back(1);

    list10.print();

    list10.removeDuplicates();
    //list10.removeAll(1);
    //list10.removeAll(2);

    list10.print();


    return 0;
}
