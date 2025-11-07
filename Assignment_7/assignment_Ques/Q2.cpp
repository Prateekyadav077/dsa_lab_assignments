#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 8, 1, 3, 7, 4, 6};
    int n = 8;
    int left = 0, right = n-1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;
        if (maxIndex == left)
            maxIndex = minIndex;
        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }
    cout << "Sorted array: ";
    for (int i = 0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}
