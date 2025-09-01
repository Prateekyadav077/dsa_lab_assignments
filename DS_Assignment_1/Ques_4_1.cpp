#include <iostream>
using namespace std;

void reverse_array(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

int main() {
    int n, arr[50];

    cout << "Enter number of elements (max 50): ";
    cin >> n;

    if (n > 50 || n <= 0) {
        cout << "Invalid size!" << endl;
        return 0;
    }

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverse_array(arr, n);

    cout << "Reversed array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
