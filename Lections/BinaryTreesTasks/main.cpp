#include<iostream>
#include "binTree.h"
bool even(const int& v) {
    return ( v % 2 == 0);
}


int main(){
    BinTree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(15);
    tree.insert(25);

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
   std:: cout << "Tree's height: " << tree.height();
   std:: cout << std:: endl;

   //TASK 19.5
   std:: cout << std:: endl;
   tree.countLeaves();

   //TASK 19.6
   std:: cout << std::endl;
   tree.maxLeaf();
    

    return 0;
}
