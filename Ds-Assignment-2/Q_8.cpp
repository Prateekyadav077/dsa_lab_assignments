#include <iostream>
using namespace std;

int count_distinct(char arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool duplicate = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            count++;
        }
    }
    return count;
}

int main() {
    char arr[1000];
    cout<<"enter string: ";
    cin >> arr;
    int n = 0;
    while (arr[n] != '\0') n++;
    cout <<count_distinct(arr, n) << endl;
    return 0;
}
