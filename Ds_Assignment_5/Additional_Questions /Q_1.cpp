/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        	if(!headA || !headB){
		return nullptr;
	}
        ListNode* temp1 = headA;
	ListNode* temp2 = headB;
    int len1=0;
    int len2=0;
    while(temp1!=NULL){
        temp1= temp1->next;
        len1++;
    }
    while(temp2!=NULL){
        temp2= temp2->next;
        len2++;
    }
    temp1= headA;
    temp2 = headB;
    if(len1>=len2){
         int diff = len1-len2;
         for(int i = 0; i<diff;i++){
            temp1= temp1->next;
         }
    }
    else{
       int diff = len2-len1;
         for(int i = 0; i<diff;i++){
            temp2= temp2->next; 
    }}
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2 = temp2->next;
    }
    return temp1;}
};
