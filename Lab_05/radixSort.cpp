//Programmed by Albert Nguyen

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void radixSort(vector<vector<int> >& vectors);
void countSort(vector<vector<int> >& vectors, int column);

int main() {
    int numOfVectors;
    
    cin >> numOfVectors;
    
    vector<vector<int> > twoDVector(numOfVectors);

    //fill 2d vector
    for(int i = 0; i < numOfVectors; i++) {
        twoDVector[i].resize(10);
        cin >> twoDVector[i][0] >> twoDVector[i][1] >> twoDVector[i][2] >> twoDVector[i][3] >> twoDVector[i][4] 
            >> twoDVector[i][5] >> twoDVector[i][6] >> twoDVector[i][7] >> twoDVector[i][8] >> twoDVector[i][9];
    }
    //radix sort
    radixSort(twoDVector);
    
    //print out sorted vectors
    for(int i = 0; i < twoDVector.size(); i++) {
        for(int j = 0; j < twoDVector[i].size(); j++) {
            cout << twoDVector[i][j] << ";";
        }
        cout << endl;
    }

    return 0;
}

void radixSort(vector<vector<int> >& vectors) {
    //sort by column starting with last column
    for(int i = vectors[i].size() - 1; i >= 0; i--) {
        countSort(vectors, i);
    }
}

void countSort(vector<vector<int> >& vectors, int column) {
    vector<vector<int> > temp(vectors.size());
    int count[10] = {0};

    //initialize each row of vector and count how many times a digit appears
    for(int i = 0; i < vectors.size(); i++) {
        temp[i].resize(vectors[i].size());
        count[vectors[i][column]]++; 
    }
    //add previous index value to current index starting from 1
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1]; 
    }
    //copy 2d vector row to temp vector row based on the count array
    for(int i = vectors.size() - 1; i >= 0; i--) { 
        temp[count[vectors[i][column]] - 1] = vectors[i];
        count[vectors[i][column]]--;
    }
    //set 2d vector to newly sorted 2d vector
    vectors = temp;
}
