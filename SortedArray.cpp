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
    int insert(DT& newElement);
    // int insert(DT& newElement, int location);
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
int SortedArray<DT>::insert(DT& newElement){
    DT* tempElements = new DT[arraySize];
    int index;
    int low = 0;
    int high = arraySize;
    while(low <= high){
        int mid = (low + high)/2;
        if(elements[mid] == NULL){
            high = mid - 1;
            if(mid == 0 && elements[mid] == NULL){
                index = 0;
                low = high + 1;
            }
        } else if(elements[mid] < newElement && (elements[mid + 1] > newElement || elements[mid + 1] == NULL)){
            if(elements[mid + 1] == NULL){
                index = mid + 1;
            } else {
                index = mid;
            }
            low = high + 1;
        } else if(elements[mid] < newElement){
            low = mid + 1;
        } else if(elements[mid] > newElement && (elements[mid - 1] < newElement || elements[mid - 1] == NULL)){
            index = mid;
            low = high + 1;
        } else if(elements[mid] > newElement){
            high = mid - 1;
        }
    }

    // cout << "Index: " << index;

    for(int i = 0; i < arraySize; ++i){
        if(i < index){
            tempElements[i] = elements[i];
        }
        if(i == index){
            tempElements[i] = newElement;
        }
        if(i > index){
            tempElements[i] = elements[i - 1]; 
        }
    }
    elements = tempElements;

    return index;
}

template<class DT>
int SortedArray<DT>::remove(DT& oldElement){
    int index;
    int low = 0;
    int high = arraySize;
    while(low <= high){
        int mid = (low + high)/2;
        if(elements[mid] == oldElement){
            index = mid;
            low = high + 1;
            elements[mid] = NULL;
            --numElements;
            cout << "FOUND" << endl;
        } else if(elements[mid] < oldElement) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return index;
}

template<class DT>
void SortedArray<DT>::print(){
    for(int i = 0; i < arraySize; ++i){
        if(elements[i] != NULL){
            cout << "{" << i << "," << elements[i] << "}" << endl;
        } else {
            cout << "At least one null" << endl;
        }
    }
}

int main(){
    SortedArray<int>* newArray = new SortedArray<int>(5);

    int val = 1;
    int temp = newArray->insert(val);
    cout << temp << endl;

    val = 6;
    temp = newArray->insert(val);
    cout << temp << endl;

    val = 4;
    temp = newArray->insert(val);
    cout << temp << endl;

    val = 2;
    temp = newArray->insert(val);
    cout << temp << endl;

    newArray->print();

};