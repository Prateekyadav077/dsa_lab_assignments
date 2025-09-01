#include <iostream>
using namespace std;

void rowSum(int a[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) {
            sum += a[i][j];
        }
        cout << "Sum of row " << i + 1 << " = " << sum << endl;
    }
}

void colSum(int a[10][10], int r, int c) {
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) {
            sum += a[i][j];
        }
        cout << "Sum of col " << j + 1 << " = " << sum << endl;
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

    rowSum(a, r, c);
    colSum(a, r, c);
    return 0;
}
