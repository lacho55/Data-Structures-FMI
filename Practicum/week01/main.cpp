#include<iostream>
#include "DLList.cpp"

int main(){
    DLList<char> list;


    DLList<char> list1;
    DLList<char> list2;
    DLList<char> mergedLists;

    //list1
    list1.push_back('T');
    list1.push_back('H');
    list1.push_back('I');
    list1.push_back('N');
    list1.push_back('K');
    list1.print();

    //list2
    list2.push_back('S');
    list2.push_back('M');
    list2.push_back('I');
    list2.push_back('L');
    list2.push_back('E');
    list2.print();

    mergedLists.mergeWithSymbol(list1,list2);

    mergedLists.print();

    mergedLists.push_back('#');
    mergedLists.push_back('K');
    mergedLists.push_back('N');
    mergedLists.push_back('O');
    mergedLists.push_back('W');
    mergedLists.push_back('#');
    mergedLists.push_back('E');
    mergedLists.push_back('A');
    mergedLists.push_back('T');

    mergedLists.print();

    std :: cout << std :: boolalpha << mergedLists.checkLastFirst()<<std::endl;

    DLList<char> secondList;

    secondList.push_back('T');
    secondList.push_back('H');
    secondList.push_back('I');
    secondList.push_back('N');
    secondList.push_back('K');
    secondList.push_back('#');
    secondList.push_back('S');
    secondList.push_back('M');
    secondList.push_back('I');
    secondList.push_back('L');
    secondList.push_back('E');
    secondList.push_back('#');
    secondList.push_back('O');
    secondList.push_back('L');
    secondList.push_back('D');

    secondList.print();
    std :: cout << std :: boolalpha << secondList.checkLastFirst() << std :: endl;


    //TASK02
    DLList<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.push_back(3);
    intList.push_back(3);
    intList.push_back(4);

    intList.print();

    intList.removeClone();

    intList.print();

    return 0;
}
