//Programmed by Albert Nguyen

#include <iostream>

using namespace std;

void mergeSort(int intArray[], int start, int end);
void merge(int intArray[], int start, int mid, int end);

int main() {
    int numOfElements;
    
    cin >> numOfElements;
    
    int intArray[numOfElements];

    for(int i = 0; i < numOfElements; i++) {
        cin >> intArray[i];
    }

    //merge sort
    mergeSort(intArray, 0, numOfElements - 1);

    for(int i = 0; i < numOfElements; i++) {
        cout << intArray[i] << ";";
    }

    return 0;
}

void mergeSort(int intArray[], int start, int end) {
    if(start < end) {
        int mid = (start + end)/2;
        mergeSort(intArray, start, mid);
        mergeSort(intArray, mid + 1, end);
        merge(intArray, start, mid, end);
    }
}

void merge(int intArray[], int start, int mid, int end) {
    int i, j;
    int temp[end];
    for(i = start; i <= mid; i++) {
        temp[i] = intArray[i];
    }
    for(j = mid + 1; j <= end; j++) {
        temp[j] = intArray[j];
    }
    i = start;
    j = mid + 1;
    for(int k = start; k <= end; k++) {
        if(temp[i] <= temp[j] && i <= mid || j > end) {
            intArray[k] = temp[i];
            i++;
        }
        else{
            intArray[k] = temp[j];
            j++;
        }
    }
}