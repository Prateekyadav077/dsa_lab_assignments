#include <iostream>
using namespace std;

void transpose(int a[10][10], int r, int c) {
    int t[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }

    cout << "Transpose of matrix is:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[10][10], r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    cout<<"entered matrix:"<<endl;
    for(int i =0; i<r;i++){
        for(int j = 0;j<c;j++){
        cout<<a[i][j]<<" ";}
        cout<<endl;

    }

    transpose(a, r, c);

    return 0;
}
