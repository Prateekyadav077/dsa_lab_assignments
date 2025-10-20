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
bool circular(Node* & head){
    if(!head){return false;}
    Node* temp = head->next;
   while(temp!=NULL&&temp!=head){temp = temp->next;}
    if(!temp){
        return false;
    }
    return true;
}
    int main(){
          Node* n = new Node(60);
    Node* head = n;
    Node* tail = n;
    insert_at_head(head,tail,80);
    insert_at_head(head,tail,40);
    insert_at_head(head,tail,100);
    insert_at_head(head,tail,20);
    if(circular(head)){
        cout<<"yes";
        
    }
    else{
        cout<<"false";
    }

      
    return 0;
}
