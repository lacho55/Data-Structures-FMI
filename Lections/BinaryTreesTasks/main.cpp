#include<iostream>
#include "binTree.h"
bool even(const int& v) {
    return ( v % 2 == 0);
}


int main(){
    BinTree<int> tree;

    tree.insert(4);
    tree.insert(3);
    tree.insert(5);
    tree.insert(52);

  // tree.remove(4);
  // tree.remove(3);

   // tree.print();

   //TASK 19.1
   tree.count();
   std:: cout << std::endl;

   //TASK 19.2
   tree.countEvens();

   //TASK 19.3
   std:: cout << tree.searchCount(even);
   std:: cout << std:: endl;

   //TASK19.4
   std:: cout <<"Tree's height: " << tree.height();
    

    return 0;
}
