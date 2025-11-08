#include<iostream>
using namespace std;
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
node* insert(node* root, int n) {
    if (root == nullptr)
        return new node(n);

    if (n < root->data)
        root->lchild = insert(root->lchild, n);
    else if (n > root->data)
        root->rchild = insert(root->rchild, n);

    return root;
}
bool searchR(node* root, int n) {
    if (root == NULL) return false;
    if (root->data == n) return true;
    else if (n<root->data) return searchR(root->lchild,n);
    else return searchR(root->rchild,n);
}
bool searchNR(node* root, int n) {
    while (root != NULL) {
        if (n == root->data) return true;
        else if (n<root->data) root = root->lchild;
        else root = root->rchild;
    }
    return false;
}
node* Max(node* root) {
    while (root && root->rchild != NULL)
        root = root->rchild;
    return root;
}
node* Min(node* root) {
    while (root && root->lchild != NULL)
        root = root->lchild;
    return root;
}
//node* successor(node*root){
//	if(root->rchild == NULL){
//		return NULL;
//	}
//	else{
//		root = Min(root->rchild);
//	}
//	return root;
//}
//node* predecessor(node* root){
//	if(root->lchild==NULL){
//		return NULL;
//	}
//	else{
//		root = Max(root->lchild);
//	}
//	return root;
//}

node* inorderSuccessor(node* root, node* target) {
    if (target->rchild != NULL)
        return Min(target->rchild);

    node* succ = NULL;
    while (root != NULL) {
        if (target->data < root->data) {
            succ = root;
            root = root->lchild;
        } 
        else if (target->data > root->data) {
            root = root->rchild;
        } 
        else break;
    }
    return succ;
}


node* inorderPredecessor(node* root, node* target) {
    if (target->lchild != NULL)
        return Max(target->lchild);

    node* pred = NULL;
    while (root != NULL) {
        if (target->data > root->data) {
            pred = root;
            root = root->rchild;
        } 
        else if (target->data < root->data) {
            root = root->lchild;
        } 
        else break;
    }
    return pred;
}
node* findNode(node* root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return root;
    else if (key < root->data) return findNode(root->lchild, key);
    else return findNode(root->rchild, key);
}


int main() 
{
	node* root = new node(5);
	insert(root,3);
	insert(root,9);
	insert(root,6);
	insert(root,4);
	insert(root,1);
	insert(root,8);
  int m,c;
cout<<"\n enter value to search recursively: ";
cin>>m;
if(searchR(root,m)){
	cout<<"root present";
}
else{
	cout<<"root not present";
}
cout<<"\n enter value to search non recursively: ";
cin>>c;
if(searchNR(root,c)){
	cout<<"root present";
}
else{
	cout<<"root not present";
}
cout<<"\nmax element of tree= "<<Max(root)->data;
cout<<"\nmin element of tree= "<<Min(root)->data;
node* target = findNode(root, m);
    if (target) {
        node* succ = inorderSuccessor(root, target);
        node* pred = inorderPredecessor(root, target);

        cout << "\nInorder Successor of " << m << " = ";
        if (succ) cout << succ->data;
        else cout << "None";

        cout << "\nInorder Predecessor of " << m << " = ";
        if (pred) cout << pred->data;
        else cout << "None";
    } else {
        cout << "\nValue " << m << " not found in tree.";
    }

	  return 0;
}
