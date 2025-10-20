#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfterNode(int target, int data) {
        Node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;

        if (!temp) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void insertBeforeNode(int target, int data) {
        Node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;

        if (!temp) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp;
        newNode->prev = temp->prev;

        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;

        temp->prev = newNode;
    }
    void deleteNode(int target) {
        Node* temp = head;
        while (temp && temp->data != target)
            temp = temp->next;

        if (!temp) {
            cout << "Node " << target << " not found.\n";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << target << " deleted.\n";
    }
    void searchNode(int target) {
        Node* temp = head;
        while (temp) {
            if (temp->data == target) {
                cout << "Node " << target << " found.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << target << " not found.\n";
    }};
int main() {
    DoublyLinkedList dll;
    int choice, data, target;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search a node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                dll.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                dll.insertAtEnd(data);
                break;
            case 3:
                cout << "Enter node after which to insert: ";
                cin >> target;
                cout << "Enter data: ";
                cin >> data;
                dll.insertAfterNode(target, data);
                break;
            case 4:
                cout << "Enter node before which to insert: ";
                cin >> target;
                cout << "Enter data: ";
                cin >> data;
                dll.insertBeforeNode(target, data);
                break;
            case 5:
                cout << "Enter node to delete: ";
                cin >> target;
                dll.deleteNode(target);
                break;
            case 6:
                cout << "Enter node to search: ";
                cin >> target;
                dll.searchNode(target);
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
