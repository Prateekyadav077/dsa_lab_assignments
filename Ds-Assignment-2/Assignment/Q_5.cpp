#include <iostream>
using namespace std;

void diagonalMatrix(int arr[10][10], int n) {
    int array[10];
    for (int i = 0; i < n; i++) {
        array[i] = arr[i][i];
    }
    cout << "Diagonal: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void triDiagonalMatrix(int arr[10][10], int n) {
    int array[30], k = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            array[k++] = arr[i][i-1];
        }
        array[k++] = arr[i][i];
        if (i < n-1) {
            array[k++] = arr[i][i+1];
        }
    }
    cout << "Tri-diagonal: ";
    for (int i = 0; i < k; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void lowerTriangularMatrix(int arr[10][10], int n) {
    int array[55], k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            array[k++] = arr[i][j];
        }
    }
    cout << "Lower triangular: ";
    for (int i = 0; i < k; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void upperTriangularMatrix(int arr[10][10], int n) {
    int array[55], k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            array[k++] = arr[i][j];
        }
    }
    cout << "Upper triangular: ";
    for (int i = 0; i < k; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void symmetricMatrix(int arr[10][10], int n) {
    int array[55], k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            array[k++] = arr[i][j];
        }
    }
    cout << "Symmetric: ";
    for (int i = 0; i < k; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 3;

    int diagonal[10][10] = {{1, 0, 0},{0, 2, 0},{0, 0, 3}};

    int triDiagonal[10][10] = {{1, 2, 0},{3, 4, 5},{0, 6, 7}};

    int lower[10][10] = {{1, 0, 0},{2, 3, 0},{4, 5, 6}};

    int upper[10][10] = {{1, 2, 3},{0, 4, 5},{0, 0, 6}};

    int symmetric[10][10] = {{1, 2, 3}, {2, 4, 5},{3, 5, 6}};

    diagonalMatrix(diagonal, n);
    triDiagonalMatrix(triDiagonal, n);
    lowerTriangularMatrix(lower, n);
    upperTriangularMatrix(upper, n);
    symmetricMatrix(symmetric, n);

    return 0;
}
