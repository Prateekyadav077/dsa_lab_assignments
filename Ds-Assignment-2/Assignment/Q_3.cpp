#include <iostream>
using namespace std;
int linearSearch(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
     if (arr[i] != i+1) {
    return i+1;
 }
    }
    return n; 
}
int binary(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == arr[0] + mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return arr[0] + left;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Missing number using linear search is: " << linear(arr, n) << endl;
    cout << "Missing number using binary serch is: " << binary(arr, n) ;
    return 0;
}
