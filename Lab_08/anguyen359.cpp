//Programmed by Albert Nguyen

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void matrixChainOrder(int *matrices, int numOfDimens);
void printOptimalParens(int **s, int i, int j);

int main() {
    int numOfMatrices;
    
    cin >> numOfMatrices;
    
    int numOfDimens = numOfMatrices + 1;
    int matrix[numOfDimens];

    for(int i = 0; i < numOfDimens; i++) {
        cin >> matrix[i];
    }

    matrixChainOrder(matrix, numOfDimens);

    return 0;
}

void matrixChainOrder(int* matrix, int numOfDimens) {
    int **m = (int**)malloc(numOfDimens * sizeof(int*));
    int **s = (int**)malloc(numOfDimens * sizeof(int*));
    for(int i = 0; i < numOfDimens; i++) {
        m[i] = (int*)malloc(sizeof(int*) * numOfDimens);
        s[i] = (int*)malloc(sizeof(int*) * numOfDimens);
    }
    for (int i = 0; i < numOfDimens; i++) {
        m[i][i] = 0; 
    }
    for(int l = 2; l < numOfDimens; l++) {
        for(int i = 1; i < numOfDimens - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + matrix[i-1]*matrix[k]*matrix[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][numOfDimens - 1]  << endl;
    printOptimalParens(s, 1, numOfDimens - 1);
    cout << endl;
}

void printOptimalParens(int **s, int i, int j) {
    if(i == j) {
        cout << "A" << i - 1;
    }
    else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}
