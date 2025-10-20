#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};
int size(Node* &head){
    int count = 0;
    Node* temp = head;
    do{
        temp = temp->next;
        count++;
    }while(temp!=head);
    return count;
}
void insert_at_head(Node*&head,Node*&tail, int n){
    Node* newNode = new Node(n);
    if(!head){head = tail =  newNode;
    tail->next = head;
        return;
    }
    newNode->next = head;
    head = newNode;
    tail->next = head;
    
}
void insert_pos(Node*&head, Node*&tail, int n, int p){
      
    if(!head){
         Node* newNode = new Node(n);
         head = tail =  newNode;
    tail->next = head;
        return;
    }
    if(p==1){
        insert_at_head(head,tail,n);
        return;
    }
     Node* newNode = new Node(n);
    Node* temp = head;
    int i = 0;
    while(i<p-1){
        temp = temp->next; i++;
    }
    if(temp->next!=head){
    newNode->next = temp->next;
    temp->next = newNode;}
    else{
        temp->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    
}
void del(Node*&head, Node*&tail, int p){
    if(p>size(head)){return;}
    if(!head){
        return;
    }
    if(head->next == head){
        head = tail = NULL;
    
        return;
    }
    if(p==1){
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        return;
    }
    Node* temp = head;
    int i = 0;
    while(i<p-1){
        temp= temp->next; i++;
    }
    if(temp->next == tail){
        tail = temp;
        tail->next = head;
    }
    if(temp->next == head){
        tail->next = head->next;
        head= head->next;
    }
    else{
        temp->next = temp->next->next;
    }
    
}
    Node* search(Node*&head, int n){
        if(!head)return nullptr;
        Node* temp = head->next;
        if(head->data == n){
            return head;
        }
        while(temp!=head){
            if(temp->data == n){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
        
    }
    int main(){
       Node*  head = nullptr;
Node* tail = nullptr;
          int choice, value, pos;
    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at position\n";
        cout << "3. Delete node at position\n";
        cout << "4. Search for a node\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insert_at_head(head, tail, value);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insert_pos(head, tail, value, pos);
                break;

            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                del(head, tail, pos);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                {
                    Node* found = search(head, value);
                    if (found) cout << "Node found: " << found->data << endl;
                    else cout << "Node not found\n";
                }
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
