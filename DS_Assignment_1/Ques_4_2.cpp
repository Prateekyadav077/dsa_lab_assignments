#include <iostream>
using namespace std;

void multiply_matrix(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2) {
    int c[10][10];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and cols of first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and cols of second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }
    cout<<"first matrix: "<<endl;
       
    for(int i =0; i<r1;i++){
        for(int j = 0;j<c1;j++){
        cout<<a[i][j]<<" ";}
        cout<<endl;
        }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }
       cout<<"matrix 2 :"<<endl;
    for(int i =0; i<r2;i++){
        for(int j = 0;j<c2;j++){
        cout<<a[i][j]<<" ";}
        cout<<endl;}


    multiply_matrix(a, b, r1, c1, r2, c2);

    return 0;
}
