/*
class Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* rotate(Node* head, int k) {
        // code here
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        for(int i = 0; i<k; i++){
            temp->next = head;
            temp = head;
           head = head->next;
            
        }
        temp->next =NULL;
        return head;
    }
};
