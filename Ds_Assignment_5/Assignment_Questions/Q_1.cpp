#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data= value;
        next = nullptr;}
};
void inserthead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next =head;
    head=temp;;
}
void inserttail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp ;
    tail = temp;
}
void insertposition(Node* &head,Node* &tail, int d, int pos){
if(pos==1){
    inserthead(head,d);
    return;
}
    Node* temp = new Node(d);
    Node* position = head;
    int i = 0;
    while( i<pos-2 && position!= nullptr  ){
        position = position->next;
        i++;
    }
        if(position == nullptr){
        cout << "Invalid position!" << endl;
        return;
    }
    temp->next = position->next;
    position->next = temp ;
    if(temp->next == NULL){
        tail = temp;
    }
}
void delete_start(Node* &head){
    if(head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
void delete_last(Node* &head,Node* &tail){
    if(head == nullptr) return; 
    if(head == tail){  
        delete head;
        head = tail = nullptr;
        return;
    }
    Node*temp  = head;
    Node* last = tail;
    while (temp->next != tail){
        temp = temp->next;
    }
    temp->next = NULL;
    tail = temp;
    delete last;
}
void delete_pos(Node* &head, Node* &tail, int pos){
    if(pos==1){
        delete_start(head);
    return;}
    Node* temp = head;
    int i = 0;
    while(i<pos-2){
        temp= temp->next;
        i++;
    }
    Node* position = temp->next;
    temp->next = temp->next->next;
    
    if(temp->next == NULL){
        tail = temp;
    }
    delete position;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice = -1, value, pos;

    while (choice != 0) {
        cout << "\n---- Singly Linked List Menu ----\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete from beginning\n";
        cout << "5. Delete from end\n";
        cout << "6. Delete from position\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                inserthead(head, value);
                if (tail == nullptr) tail = head;
                break;
            case 2:
                cout << "Enter value: ";
                cin >> value;
                if (tail == nullptr) {
                    inserthead(head, value);
                    tail = head;
                } else {
                    inserttail(tail, value);
                }
                break;
            case 3:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insertposition(head, tail, value, pos);
                break;
            case 4:
                delete_start(head);
                break;
            case 5:
                delete_last(head, tail);
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                delete_pos(head, tail, pos);
                break;
            case 7:
                print(head);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}
