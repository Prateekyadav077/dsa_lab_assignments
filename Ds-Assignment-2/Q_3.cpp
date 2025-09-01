#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
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
    cout << "Missing number is: " << findMissing(arr, n) << endl;
    return 0;
}
