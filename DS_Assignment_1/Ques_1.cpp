#include <iostream>
using namespace std;

int arr[100], size_array = 0;

void createArray() {
    cout << "Enter size: ";
    cin >> size_array;
  
    for (int i = 0; i < size_array; i++) {
        
          cout << "Enter element "<< i+1<<" : ";
        cin >> arr[i];

    }
}

void displayArray() {
    for (int i = 0; i < size_array; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void insertElement() {
    int pos, value;
    cout << "Enter position and value: ";
    cin >> pos >> value;
    if (pos < 1 || pos > size_array + 1) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = size_array; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    size_array++;
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    if (pos < 1 || pos > size_array) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = pos - 1; i < size_array - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size_array--;
}

void linearSearch() {
    int key, found = 0;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < size_array; i++) {
        if (arr[i] == key) {
            cout << "Found at position " << i + 1 << "\n";
            found = 1;
        }
    }
    if (found=0) cout << "Not found\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 6);
}
