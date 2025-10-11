/* This is the ListNode class definition

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
*/

void removeLoop(ListNode* list) {
    // add your logic here
	if(list==NULL){
		return;
	}
	if(list->next == list){
		list->next =NULL;
		return;
	}
	ListNode* fast= list;
	ListNode* slow = list;
	do{
		if(fast==NULL || fast->next==NULL)return;
		fast = fast->next->next;
		slow = slow->next;
	} while(fast != slow);
	slow = list;
	if(fast == list){
		while(fast->next!=slow){
			fast = fast->next;
		}
		fast->next =NULL;
		return;
	}
	while(slow->next!=fast->next){
		slow = slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
	return;
	}
