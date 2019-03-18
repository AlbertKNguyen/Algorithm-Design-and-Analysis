//Programmed by Albert Nguyen

#include <iostream>

using namespace std;

void heapSort(int intArray[], int size);
void maxHeapify(int intArray[], int size, int i);
void buildMaxHeap(int intArray[], int size);

int main() {
    int numOfElements;
    
    cin >> numOfElements;
    
    int intArray[numOfElements];

    for(int i = 0; i < numOfElements; i++) {
        cin >> intArray[i];
    }
    
    //heap sort
    heapSort(intArray, numOfElements);

    for(int i = 0; i < numOfElements; i++) {
        cout << intArray[i] << ";";
    }

    return 0;
}

void heapSort(int intArray[], int size) {
    buildMaxHeap(intArray, size);
    for(int i = size - 1; i >= 0; i--) {
        int temp = intArray[0];
        intArray[0] = intArray[i];
        intArray[i] = temp;
        maxHeapify(intArray, i, 0);
    }
}

void maxHeapify(int intArray[], int size, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2; 
  
    if(left < size && intArray[left] > intArray[largest]) {
        largest = left;         
    }
    if (right < size && intArray[right] > intArray[largest]) {
        largest = right; 
    }
    if (largest != i) { 
        int temp = intArray[largest];
        intArray[largest] = intArray[i];
        intArray[i] = temp;
        maxHeapify(intArray, size, largest); 
    } 
}

void buildMaxHeap(int intArray[], int size) {
    for(int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(intArray, size, i);
    }
}