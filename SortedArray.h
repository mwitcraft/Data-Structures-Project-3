#include <iostream>
// #include "SortedArray.h"
using namespace std;

template <class DT>
class SortedArray{
private:
    DT* elements;
    int arraySize;
    DT minElement;
    DT maxElement;
    int numElements;
public:
    SortedArray();
    SortedArray(int size);
    int find(DT& lookFor);
    int insert(DT& newElement);
    // int insert(DT& newElement, int location);
    int remove(DT& oldElement);
    SortedArray<DT>* split(int i);
    DT& operator[](int index);
    int operator=(SortedArray arr);
    bool operator>(SortedArray arr);
    bool operator<(SortedArray arr);
    bool operator==(SortedArray arr);
    ~SortedArray();

    int getMax(){
        return maxElement;
    }

    int getMin(){
        return minElement;
    }

    void print();
};

template<class DT>
SortedArray<DT>::SortedArray(){};

template<class DT>
SortedArray<DT>::SortedArray(int size){
    arraySize = size;
    elements = new DT[size];
    numElements = 0;
    minElement = 0;
    maxElement = 0;
}

template<class DT>
int SortedArray<DT>::find(DT& lookFor){
    int low = 0;
    int high = numElements;
    while(low <= high){
        int mid = (low + high)/2;
        if(elements[mid] == lookFor){
            return mid;
        }
        if(elements[mid] > lookFor){
            high = mid - 1;
        }
        if(elements[mid] < lookFor){
            low = mid + 1;
        }
    }
    return -1;
}

template<class DT>
int SortedArray<DT>::insert(DT& newElement){
    if(numElements == arraySize){
        return -1;
    }
    elements[numElements] = newElement;
    ++numElements;

    for(int i = 1; i < numElements; ++i){
        int cur = elements[i];
        int j = i - 1;
        while((j >= 0) && (elements[j] > cur)){
            elements[j + 1] = elements[j];
            --j;
        }
        elements[j+1] = cur;
    }

    minElement = elements[0];
    maxElement = elements[numElements - 1];

    return find(newElement);
    
























    // DT* tempElements = new DT[arraySize];
    // int index;
    // int low = 0;
    // int high = arraySize;
    // while(low <= high){
    //     int mid = (low + high)/2;
    //     if(elements[mid] == NULL){
    //         high = mid - 1;
    //         if(mid == 0 && elements[mid] == NULL){
    //             index = 0;
    //             low = high + 1;
    //         }
    //     } else if(elements[mid] < newElement && (elements[mid + 1] > newElement || elements[mid + 1] == NULL)){
    //         if(elements[mid + 1] == NULL){
    //             index = mid + 1;
    //         } else {
    //             index = mid;
    //         }
    //         low = high + 1;
    //     } else if(elements[mid] < newElement){
    //         low = mid + 1;
    //     } else if(elements[mid] > newElement && (elements[mid - 1] < newElement || elements[mid - 1] == NULL)){
    //         index = mid;
    //         low = high + 1;
    //     } else if(elements[mid] > newElement){
    //         high = mid - 1;
    //     }
    // }

    // // cout << "Index: " << index;

    // for(int i = 0; i < arraySize; ++i){
    //     if(i < index){
    //         tempElements[i] = elements[i];
    //     }
    //     if(i == index){
    //         tempElements[i] = newElement;
    //     }
    //     if(i > index){
    //         tempElements[i] = elements[i - 1]; 
    //     }
    // }
    // elements = tempElements;

    // return index;
}

template<class DT>
int SortedArray<DT>::remove(DT& oldElement){
    int index = find(oldElement);
    if(index == -1){
        return index;
    }

    int* tempArray = new int[arraySize];
    for(int i = 0; i < numElements; ++i){
        if(i < index){
            tempArray[i] = elements[i];
        }
        if(i > index){
            tempArray[i - 1] = elements[i];
        }
    }
    elements = tempArray;

    --numElements;
    minElement = elements[0];
    maxElement = elements[numElements - 1];
    return numElements;
}

template<class DT>
SortedArray<DT>* SortedArray<DT>::split(int splitAt){
    int* oldElements = new int[arraySize];
    SortedArray<DT>* splitArray = new SortedArray(arraySize);
    for(int i = 0; i < arraySize; ++i){
        if(i >= splitAt){
            splitArray->insert(elements[i]);
            elements[i] = NULL;
        }
    }
    numElements = splitAt;

    return splitArray;
}

template<class DT>
DT& SortedArray<DT>::operator[](int index){
    return elements[index];
}

template<class DT>
void SortedArray<DT>::print(){
    // for(int i = 0; i < arraySize; ++i){
    //     if(elements[i] != NULL){
    //         cout << "{" << i << "," << elements[i] << "}" << endl;
    //     } else {
    //         cout << "At least one null" << endl;
    //     }
    // }
    for(int i = 0; i < numElements; ++i){
        cout << elements[i] << " ";
    }
    cout << endl;
}

// int main(){
//     SortedArray<int>* newArray = new SortedArray<int>(5);

//     for(int i = 5; i > 0; --i){
//         newArray->insert(i);
//     }

//     newArray->print();
// };