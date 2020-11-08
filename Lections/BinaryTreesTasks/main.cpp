#include<iostream>
#include "binTree.h"

int main(){
    BinTree<int> tree;

    tree.insert(2);
    tree.insert(3);

   tree.remove(2);
   tree.remove(3);

   // tree.print();

   tree.count();

    return 0;
}
