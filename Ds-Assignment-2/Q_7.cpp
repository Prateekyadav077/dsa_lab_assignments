#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"enter length ";
    cin >> n;
    int arr[n];
    cout<<"enter element "<<endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int inversions = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                inversions++;
        }
    }

    cout << inversions << endl;

    return 0;
}
