#include <iostream>
#include <list>
#include "SortedArray.h"
using namespace std;

template <class DT>
class LinkedSortedArrays{
protected:
    list<SortedArray<DT>> linkedArrays;
    int arraySizeFactor;
public:
    LinkedSortedArrays(int size);
    int insert(const DT& newElement);
    template<class T>
    friend ostream& operator<<(ostream& os, LinkedSortedArrays<T> lsa);
};

template<class DT>
LinkedSortedArrays<DT>::LinkedSortedArrays(int size){
    linkedArrays = list<SortedArray<DT>>();
    arraySizeFactor = size;

    SortedArray<DT> initialArr = SortedArray<DT>(size);

    linkedArrays.push_back(initialArr);
}

template<class DT>
int LinkedSortedArrays<DT>::insert(const DT& newElement){
    // cout << "*" << newElement << endl;
    typename list<SortedArray<DT>>::iterator iList;
    SortedArray<DT>* splitArr;
    iList = linkedArrays.begin();
    if(linkedArrays.size() == 1){
        if((*iList).insert(newElement) == -1){
            splitArr= new SortedArray<DT>(arraySizeFactor);
            splitArr = (*iList).split(arraySizeFactor/2);
            splitArr->insert(newElement);
            linkedArrays.insert(++iList, *splitArr);
            --iList;
        }
    } else if(linkedArrays.front().getMin() > newElement){
        iList = linkedArrays.begin();
        if((*iList).insert(newElement) == -1){
            splitArr = new SortedArray<DT>(arraySizeFactor);
            splitArr = (*iList).split(arraySizeFactor/2);
            (*iList).insert(newElement);
            linkedArrays.insert(iList, *splitArr);
        }
    } else if(linkedArrays.back().getMax() < newElement){
        iList = linkedArrays.end();
        --iList;
        if((*iList).insert(newElement) == -1){
            splitArr = new SortedArray<DT>(arraySizeFactor);
            splitArr = (*iList).split(arraySizeFactor/2);
            splitArr->insert(newElement);
            linkedArrays.insert(++iList, *splitArr);
            --iList;
        }
    } else {
        for(iList = linkedArrays.begin(); iList != linkedArrays.end(); ++iList){
            if(newElement > (*iList).getMin() && newElement < ((*iList).getMax())){
                if((*iList).insert(newElement) == -1){
                    splitArr = new SortedArray<DT>(arraySizeFactor);
                    splitArr = (*iList).split(arraySizeFactor/2);
                    splitArr->insert(newElement);
                    linkedArrays.insert(++iList, *splitArr);
                    --iList;
                }
            }
        }
    }

}

template<class T>
ostream& operator<<(ostream& os, LinkedSortedArrays<T> lsa){
    typename list<SortedArray<T>>::iterator iList;
    int i = 0;
    for(iList = lsa.linkedArrays.begin(); iList != lsa.linkedArrays.end(); ++iList, ++i){
        os << i << ": " << (*iList);
    }
    return os;
}

int main(){
    LinkedSortedArrays<int>* lsa = new LinkedSortedArrays<int>(4);
    SortedArray<int>* arr = new SortedArray<int>(4);
    for(int i = 2; i < 9; ++i){
        lsa->insert(i);
    }

    // // cout << *arr;

    // lsa->insert(2);
    // lsa->insert(1);
    // lsa->insert(4);
    // lsa->insert(3);
    // lsa->insert(5);
    lsa->insert(1);

    cout << *lsa;
    cout << *lsa;
    cout << *lsa;

}