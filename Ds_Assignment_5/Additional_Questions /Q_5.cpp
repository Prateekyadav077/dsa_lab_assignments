/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;

    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
};
*/

class Solution {
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    Node *addPolynomial(Node *head1, Node *head2) {
        // Your code here
        Node* dummy = new Node(0,0);
        Node* head = dummy;
     Node* temp1 = head1;
     Node* temp2 = head2;
     while(temp1!=NULL || temp2!=NULL){
         if(temp1!=NULL&& temp2!=NULL && temp1->pow==temp2->pow){
             temp1->coeff = temp1->coeff + temp2->coeff;
             dummy->next = temp1;
             dummy = temp1;
             temp1= temp1->next;
             temp2 = temp2->next;
         }
         else if(temp1!=NULL && (temp2==NULL || temp1->pow>temp2->pow)){
             dummy->next  = temp1;
             dummy = temp1;
             temp1= temp1->next;
         }
         else{
             dummy->next = temp2;
             dummy = temp2;
             temp2= temp2->next;
         }
     }
     Node* temp = head;
     head = head->next;
     delete temp;
     return head;
    }
};
