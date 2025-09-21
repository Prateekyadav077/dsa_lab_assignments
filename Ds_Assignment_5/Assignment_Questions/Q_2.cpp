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
int countkey(Node* &head, int key) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) count++;
        temp = temp->next;
    }
    return count;
}
void delete_key(Node* &head,Node* &tail, int key){
    while(head!=NULL && head->data ==key){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    if(head==nullptr){
        tail = nullptr;
        return;
    }
    Node* current = head;
    while(current->next!=NULL){
        if(current->next->data==key){
       Node* keyelement =  current->next;
       current->next = keyelement->next;
       if(current->next==nullptr){
           tail = current;
       
        }
        delete keyelement;
    }
    else{
        current = current->next;
    }
    }
}
int main() {
   Node* node1 = new Node(1);
   Node* head = node1;
   Node* tail = node1;
   inserttail(tail,2);
   inserttail(tail,1);
   inserttail(tail,2);
   inserttail(tail,1);
   inserttail(tail,3);
   inserttail(tail,1);
   print(head);
   int x = countkey(head,1);
   delete_key(head,tail,1);
   print(head);
   cout<<"no of key that is 1 : "<<x;

    return 0;
}
