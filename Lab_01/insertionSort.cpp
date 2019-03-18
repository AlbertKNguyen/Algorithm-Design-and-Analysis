//Programmed by Albert Nguyen

#include <iostream>

using namespace std;

int main() {
    int numOfElements;
    
    cin >> numOfElements;
    
    int intArray[numOfElements];

    for(int i = 0; i < numOfElements; i++) {
        cin >> intArray[i];
    }

    //insertion sort
    for(int i = 1; i < numOfElements; i++) {
        for(int j = i; j > 0; j--) {
            if(intArray[j] < intArray[j - 1]) {
                int temp = intArray[j - 1];
                intArray[j - 1] = intArray[j];
                intArray[j] = temp;
            } 
        }
        for(int j = 0; j <= i; j++) {
            cout << intArray[j] << ";";
        }
        cout << endl;
    }

    return 0;
}