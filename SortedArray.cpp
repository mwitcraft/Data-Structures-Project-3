#include <iostream>
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
    // int insert(DT& newElement);
    int insert(DT& newElement, int location);
    int remove(DT& oldElement);
    SortedArray split(int i);
    DT* operator[](int index);
    int operator=(SortedArray arr);
    bool operator>(SortedArray arr);
    bool operator<(SortedArray arr);
    bool operator==(SortedArray arr);
    ~SortedArray();

    void print();
};

template<class DT>
SortedArray<DT>::SortedArray(){};

template<class DT>
SortedArray<DT>::SortedArray(int size){
    arraySize = size;
    elements = new DT[size];
}

template<class DT>
int SortedArray<DT>::insert(DT& newElement, int location){
    elements[location] = newElement;
}

template<class DT>
int SortedArray<DT>::remove(DT& oldElement){
    DT* newElements = new DT[(arraySize - 1)];
    int index;
    int low = 0;
    int high = arraySize;
    while(low <= high){
        int mid = (low + high)/2;
        // cout << mid << endl;
        if(elements[mid] == oldElement){
            index = mid;
            low = high + 1;
            // cout << "FOUND" << endl;
        } else if(elements[mid] < oldElement) {
            low = mid + 1;
            // cout << "Smaller" << endl;
        } else {
            high = mid - 1;
            // cout << "Larger" << endl;
        }
    }
    
    for(int i = 0; i < arraySize; ++i){
        if(i < index){
            newElements[i] = elements[i];
        } else if(i > index){
            newElements[i - 1] = elements[i];
        }
    }

    arraySize = arraySize - 1;
    elements = newElements;
}

template<class DT>
void SortedArray<DT>::print(){
    for(int i = 0; i < arraySize; ++i){
        cout << "{" << i << "," << elements[i] << "}" << endl;
    }
}

int main(){
    SortedArray<int>* newArray = new SortedArray<int>(5);
    for(int i = 0; i < 5; ++i){
        int val = i + 10;
        newArray->insert(val ,i);
    }

    int elem = 12;
    newArray->remove(elem);
    elem = 10;
    newArray->remove(elem);

    newArray->print();

};