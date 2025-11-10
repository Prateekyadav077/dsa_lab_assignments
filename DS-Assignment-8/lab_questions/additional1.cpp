#include<iostream>
using namespace std;
#include<algorithm>
class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int value){
		data = value;
		left = right = NULL;
	}
};
Node* insert(Node* root, int n){
	if(root == NULL){
		return new Node(n);
	}
	if(n < root->data)
        root->left = insert(root->left, n);
    else if (n > root->data)
        root->right = insert(root->right, n);

    return root;
}
Node* Min(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
Node* Max(Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}
Node* deletenode(Node* root, int n){
	if (root==nullptr){
		return root;
	}
	if(n<root->data){
		root->left = deletenode(root->left, n);
	}
	else if(n>root->data){
		root->right = deletenode(root->right,n);
	}
	
	else{
	if(root->left==NULL && root->right!=NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
	else if(root->right==NULL && root->left!=NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else if (root->left == NULL && root->right == NULL) {
    delete root;
    return NULL;
}
	
	else{
		Node* temp = Min(root->right);
		root->data = temp->data;
		root->right = deletenode(root->right, temp->data);
		return root;
	}
	
}
return root;
}
int max_depth(Node* root){
	if(root==NULL){
		return 0;
	}
	return 1+ max(max_depth(root->right),max_depth(root->left));
	
}
int min_depth(Node* root){
	if(root==NULL){
		return 0;
	}
	if(root->right==NULL){
		return 1+ min_depth(root->left);
	}
	else if(root->left == NULL){
		return 1+ min_depth(root->right);
	}
	return 1+ min(min_depth(root->right), min_depth(root->left));
}
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int sum(Node* root){
	if(!root){
		return 0;
	}
	int total = 0;
	  if (root->left && !root->left->left && !root->left->right) {
        total += root->left->data;
    }
    total += sum(root->left);
    total+= sum(root->right);
    return total;
}


int main()
{
    Node* root = new Node(5);
    insert(root,4);
    insert(root,3);
    insert(root,8);
    insert(root,7);
    insert(root,6);
    insert(root,9);
    inorder(root);
    deletenode(root,8);
    cout<<endl;
    inorder(root);
    int x =max_depth(root);
    cout<<"\n max depth= "<<x;
    int y = min_depth(root);
    cout<<"\n min depth= "<<y;
//    if(bst(root)){
//    	cout<<"\nbst? yes";
//    }
//    else{
//    	cout<<"\n bst? no";
//    }
    cout<<"\n sum of left leaves= "<<sum(root);
    return 0;
}
