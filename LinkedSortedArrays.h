#include <iostream>
#include <list>
#include "SortedArray.h"
using namespace std;

template <class DT>
class LinkedSortedArrays{
protected:
    list<DT>* linkedArrays;
    int arraySizeFactor;
public:
    LinkedSortedArrays();
    LinkedSortedArrays(SortedArray<DT>* array);
    int addArray(DT* array);
    int find(const DT& lookFor);
    int insert(const DT& newElement);
    int remove(const DT& oldElement);
};

template <class DT>
LinkedSortedArrays<DT>::LinkedSortedArrays(){
    linkedArrays = new list<DT>();
    cout << "Added new SortedArray" << endl;
}

template <class DT>
int LinkedSortedArrays<DT>::addArray(DT* array){
    linkedArrays->push_back(*array);
    linkedArrays->front().print();
}