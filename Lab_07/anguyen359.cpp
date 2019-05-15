//Programmed by Albert Nguyen

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void cutRod(int* prices, int length);

int main() {
    int length;
    
    cin >> length;
    
    int prices[length];

    for(int i = 0; i < length; i++) {
        cin >> prices[i];
    }

    cutRod(prices, length);

    return 0;
}

void cutRod(int* prices, int length) {
    int arr[length + 1];
    int cuts[length + 1];
    arr[0] = 0;
    for(int i = 1; i <= length; i++) {
        int q = INT_MIN;
        for(int j = 1; j <= i; j++) {
            if(q < prices[j - 1] + arr[i - j]) {
                q = prices[j - 1] + arr[i - j];
                cuts[i] = j; 
            }
        }
        arr[i] = q;
    }
    cout << arr[length] << endl;
    while(length > 0) {
        cout << cuts[length] << " ";
        length -= cuts[length];
    }
    cout << "-1" << endl;
}
