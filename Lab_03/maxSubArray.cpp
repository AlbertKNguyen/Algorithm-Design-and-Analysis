//Programmed by Albert Nguyen

#include <iostream>

using namespace std;

int maxArraySum(int intArray[], int start, int end);
int maxCrossingSum(int intArray[], int start, int mid, int end);

int main() {
    int numOfElements;
    
    cin >> numOfElements;
    
    int intArray[numOfElements];

    for(int i = 0; i < numOfElements; i++) {
        cin >> intArray[i];
    }
    
    //maxArraySum sort
    int maxSum = maxArraySum(intArray, 0, numOfElements - 1);
    
    cout << maxSum;

    return 0;
}

int maxArraySum(int intArray[], int start, int end) {
    if(start == end) {
        return intArray[0];
    }

    int mid = (start + end)/2;
    int left = maxArraySum(intArray, start, mid);
    int right = maxArraySum(intArray, mid + 1, end);
    int cross = maxCrossingSum(intArray, start, mid, end);
    
    if(left >= right && left >= cross) {
        return left;
    }
    else if(right >= left && right >= cross) {
        return right;
    }
    else {
        return cross;
    }
}

int maxCrossingSum(int intArray[], int start, int mid, int end) {
    int sum = 0; 
    int left = -99999999; 
    for(int i = mid; i >= start; i--) { 
        sum = sum + intArray[i]; 
        if(sum > left) {
            left = sum;
        }
    } 
  
    sum = 0; 
    int right = -99999999; 
    for(int i = mid + 1; i <= end; i++) { 
        sum = sum + intArray[i]; 
        if(sum > right) {
            right = sum; 
        }
    } 

    return left + right; 
}