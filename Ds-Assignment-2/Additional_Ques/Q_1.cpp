#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
   for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
       int temp = arr[j];
       arr[j] = arr[j + 1];
        arr[j + 1] = temp;
 }
    }
    }
}

int countPairs(int arr[], int n, int k) {
    sortArray(arr, n);
    int count = 0;
    int i = 0, j = 1;

    while (i < n && j < n) {
        if (i != j && arr[j] - arr[i] == k) {
            count++;
            i++;
            j++;
        } 
        else if (arr[j] - arr[i] < k) {
            j++;
        } 
        else {
            i++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << "Count of pairs: " << countPairs(arr, n, k) << endl;
    return 0;
}
