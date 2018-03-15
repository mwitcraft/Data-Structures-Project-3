#include <iostream>
#include <list>
#include "LinkedSortedArrays.h"
using namespace std;

// template <class DT>
// class LinkedSortedArrays{
// protected:
//     list<SortedArray<DT>>* linkedArrays;
//     int arraySizeFactor;
// public:
//     LinkedSortedArrays();
//     LinkedSortedArrays(SortedArray<DT>* array);
//     int addArray(DT* array);
//     int find(const DT& lookFor);
//     int insert(const DT& newElement);
//     int remove(const DT& oldElement);
// };

template <class DT>
LinkedSortedArrays<SortedArray<DT>>::LinkedSortedArrays(){
    // cout << "HERE" << endl;
    linkedArrays = new list<SortedArray<DT>>();
}

// template <class DT>
// int LinkedSortedArrays<DT>::addArray(DT* array){
//     array->print();
//     linkedArrays->push_back(*array);
//     linkedArrays->front().print();
// }

int main(){
    SortedArray<int>* arr = new SortedArray<int>(5);
    for(int i = 0; i < 5; ++i){
        arr->insert(i);
    } 
    // LinkedSortedArrays<SortedArray<int>>* myList = new LinkedSortedArrays<SortedArray<int>>();
}