#include<iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

    void insert_at_head(Node* &head,char data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
        bool palindrome(Node*& head, Node*& tail){
    if(!head){
        return true;
    }
    Node* temp1 = head;
    Node* temp2 = tail;
    while(temp1!=temp2){
        if(temp1->next == temp2)break;
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    return true;
}
    int main(){
        Node* n = new Node('L');
    Node* head = n;
    Node* tail = n;
    insert_at_head(head,'E');
    insert_at_head(head,'V');
    insert_at_head(head,'E');
    insert_at_head(head,'L');
    if(palindrome(head,tail)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
    }
    
