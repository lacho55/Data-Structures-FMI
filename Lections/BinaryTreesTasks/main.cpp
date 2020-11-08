#include<iostream>
#include "binTree.h"

int main(){
    BinTree<int> tree;

    tree.insert(4);
    tree.insert(3);

  // tree.remove(4);
  // tree.remove(3);

   // tree.print();

   //TASK 19.1
   tree.count();
   std:: cout << std::endl;

   //TASK 19.2
   tree.countEvens();

    return 0;
}
