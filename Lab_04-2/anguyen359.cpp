//Programmed by Albert Nguyen

#include <iostream>

using namespace std;

void quickSort(int intArray[], int start, int end);
int partition(int intArray[], int start, int end);

int main() {
    int numOfElements;
    
    cin >> numOfElements;
    
    int intArray[numOfElements];

    for(int i = 0; i < numOfElements; i++) {
        cin >> intArray[i];
    }

    //quick sort
    quickSort(intArray, 0, numOfElements - 1);

    for(int i = 0; i < numOfElements; i++) {
        cout << intArray[i] << ";";
    }

    return 0;
}

void quickSort(int intArray[], int start, int end) {
    if(start < end) {
        int partitionIndex = partition(intArray, start, end);
        quickSort(intArray, start, partitionIndex - 1);
        quickSort(intArray, partitionIndex + 1, end);
    }
}

int partition(int intArray[], int start, int end) {
    int pivot = intArray[end];
    int i = start - 1;

    for(int j = start; j <= end - 1; j++) {
        if(intArray[j] <= pivot) {
            i++;
            int temp = intArray[i];
            intArray[i] = intArray[j];
            intArray[j] = temp;
        }
    }
    int temp = intArray[i + 1];
    intArray[i + 1] = intArray[end];
    intArray[end] = temp;

    return i + 1;
}

