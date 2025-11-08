#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* lchild;
	node* rchild;
	
	node(int n){
		data = n;
		lchild = NULL;
		rchild = NULL;
	}
};

node* createNode() {     
    int val;
  
    cin >> val;

    if (val==-1)
        return NULL;

    node* newNode = new node(val);
    cout << "Enter left child of " << val << ":\n";
    newNode->lchild = createNode();
    cout << "Enter right child of " << val << ":\n";
    newNode->rchild = createNode();

    return newNode;
}
void preorder(node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->lchild);
		preorder(root->rchild);
	}
	
}
void inorder(node* root){
	if(root!=NULL){
		inorder(root->lchild);
	    cout<<root->data<<" ";
	     inorder(root->rchild);
	}
	
}
void postorder(node* root){
	if(root!=NULL){
		postorder(root->lchild);
		postorder(root->rchild);
		cout<<root->data<<" ";
	
}
}


int main()
{
  cout << "enter tree value(-1 for NULL): ";
    node* root = createNode();
    cout<<"\nPreorder Traversal: ";
    preorder(root);
    cout<<"\nInorder Traversal: ";
    inorder(root);
    cout<<"\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
