#pragma once
using namespace std;


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
class BinTree{
    private:
        Node<T>* root;

    public:
    /* --------- Public Methods ------ */
    BinTree();
    T search(const T&);
    void insert(const T&);
    void remove(const T&);
    void destroy();
    void count(); //TASK 19.1
    void countEvens(); //TASK 19.2
    int searchCount (bool (*pred)(const T&)); //TASK 19.3
    ~BinTree();

    private:
    /* ------ Private Methods ------ */
    T findElement(const T&, Node<T>*&) const;
    T max(Node<T>*) const;
    void add(const T&, Node<T>*&);
    void deleteElement(const T&, Node<T>*&);
    void destroyTree(Node<T>*);
    T countElements(Node<T>*, size_t);
    T countEvenElements(Node<T>*, size_t);
    T countPredElements(Node<T>*, bool (*pred)(const T&), size_t);

};


/* --------- Public Methods ------ */
template<class T>
BinTree<T>:: BinTree(){
    root = nullptr;
}


template<class T>
T BinTree<T>:: search(const T& element){
    return findElement(element, this->root);
}


template<class T>
void BinTree<T>:: insert(const T& element){
    add(element, this->root);
}


template<class T>
void BinTree<T>:: remove(const T& element){
    deleteElement(element, this->root);
}


template<class T>
void BinTree<T>:: destroy(){
    destroyTree(this->root);
}


//TASK19.1
template<class T>
void BinTree<T>:: count(){
    cout <<"Binary Tree's elements: " <<  countElements(this->root, 1);
}


//TASK 19.2
template<class T>
void BinTree<T>:: countEvens(){
    cout << "Binary Tree's even elements: " << countEvenElements(this->root, 0) << endl;
}


//TASK 19.3
template<class T>
int BinTree<T>:: searchCount(bool (*pred)(const T& data)){

    return countPredElements(this->root, pred, 0);
}


template<class T>
BinTree<T>:: ~BinTree(){
    destroy();
}


 /* ------ Private Methods ------ */
template<class T>
T BinTree<T>:: findElement(const T& element, Node<T>*& node) const{

    if(element == node->data){
        return node->data;
    }
    else if(element < node->data){
        findElement(element, node->left);
    }
    else{
        findElement(element, node->right);
    }

    return nullptr;
}


template<class T>
T BinTree<T>:: max(Node<T>* val) const{

    Node<T>* node = val;

    while(node->right){
        node = node->right;
    }

    return node->data;
}


template<class T>
void BinTree<T>:: add(const T& element, Node<T>*& node){

    if(node){

        if(element < node->data){

            if(node->left){
                add(element, node->left);
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
                add(element, node->right);
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
void BinTree<T>:: deleteElement(const T& element, Node<T>*& node){

    if(element < node->data){
        deleteElement(element, node->left);
    }
    else if(element > node->data){
        deleteElement(element, node->right);
    }
    else{

        if(node->left && node->right){
            node->data = max(node->left);
            deleteElement(max(node->left), node->left);
        }
        else if(node->left){
            Node<T>* temp = node;
            node = node->left;

            delete temp;
        }
        else{
            Node<T>* temp = node;
            node = node->right;

            delete temp;
        }
    }
}


 template<class T>
 void BinTree<T>:: destroyTree(Node<T>* node){

     if(node){
         destroyTree(node->left);
         destroyTree(node->right);

         delete node;
     }
 }


//TASK19.1
 template<class T>
 T BinTree<T>:: countElements(Node<T>* node, size_t cnt){

    if(node){
        if(node->left){
            countElements(node->left,cnt++);
        }
        else if(node->right){
            countElements(node->right,cnt++);
        }

        
    }else{
        return 0;
    }

    return cnt;
 }


 //TASK 19.2
 template<class T>
 T BinTree<T>:: countEvenElements(Node<T>* node, size_t cnt){

     //if(node->left->data == 2) cout<<"da";

     if(node){

         if(node->data % 2 == 0){
             cnt++;
         }

         if(node->left && (node->left->data % 2 == 0)){
             countEvenElements(node->left, cnt++);
         }
         else{
             countEvenElements(node->left, cnt);
         } 

        if(node->right && (node->right->data % 2 == 0)){
            countEvenElements(node->right, cnt++);
        }
        else{
            countEvenElements(node->right, cnt);
        }

     }
     

     return cnt;
 }


//TASK 19.3
 template<class T>
 T BinTree<T>:: countPredElements(Node<T>* node, bool (*pred)(const T&), size_t cnt){

     if(node){
         if(pred(node->data)){
             countPredElements(node->left, pred, cnt++);
             countPredElements(node->left, pred, cnt++);
         }
         if(node->left && pred(node->left->data)){
             countPredElements(node->left, pred, cnt++);
         }
         else{
             countPredElements(node->left,pred,cnt);
         }
         if(node->right && pred(node->right->data)){
             countPredElements(node->right, pred, cnt++);
         }
         else{
             countPredElements(node->right, pred,cnt);
             
         }
     }

     return cnt;
 }
