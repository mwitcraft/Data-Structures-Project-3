#include <iostream>
#include "LinkedSortedArrays.h"
// #include "SortedArray.h"
using namespace std;

int main(){
    SortedArray<int>* newArray = new SortedArray<int>(5);

    for(int i = 5; i > 0; --i){
        newArray->insert(i);
    }

    newArray->print();

    LinkedSortedArrays<SortedArray<int>>* myList = new LinkedSortedArrays<SortedArray<int>>();
    myList->addArray(newArray);
}