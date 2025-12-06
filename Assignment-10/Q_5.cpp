#include<iostream>
using namespace std;
#include<unordered_set>
#include<vector>

class node{
    public:
  int data;
  node*next;
  node(int value){
      data = value;
      next = NULL;
  }
};
node* newNode(int data){
    node* temp = new node(data);
    temp->next = nullptr;
    return temp;
}
bool duplicate(node*&root){
    unordered_set<node*>hash;
    node* temp = root;
    while(temp!=NULL){
        if(hash.find(temp)!= hash.end()){
            return true;
        }
        hash.insert(temp);
        temp = temp->next;
    }
 return false;
}
 int main(){
    
    node* root = newNode(1);
     root->next = newNode(2);
     root->next->next = newNode(3);
     root->next->next->next = newNode(4);
    // root->next->next->next->next= root->next;
         
     
     
    if( duplicate(root)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
 }
