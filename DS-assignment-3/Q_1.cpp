#include<iostream>
using namespace std;

class Stack{
public:
int *arr;
int top;
int size;

Stack(int s){
size=s;
arr=new int[size];
top=-1;
}

void push(int x){
if(top==size-1){
cout<<"Overflow\n";
}
else{
top++;
arr[top]=x;
 }
 }

void pop(){
if(top==-1){
cout<<"Underflow\n";
}
else{
cout<<"Popped: "<<arr[top]<<"\n";
top--;
  }
  } 

void isEmpty(){
if(top==-1) cout<<"Empty\n";
else cout<<"Not Empty\n";
}

void isFull(){
if(top==size-1) cout<<"Full\n";
else cout<<"Not Full\n";
 }

void display(){
if(top==-1) cout<<"Empty\n";
else{
cout<<"Stack:\n";
for(int i=top;i>=0;i--){
cout<<arr[i]<<"\n";
 }
 }
  }

void peek(){
if(top==-1) cout<<"Empty\n";
else cout<<"Top: "<<arr[top]<<"\n";
}
   };

int main(){
int n;
cout<<"Enter size: ";
cin>>n;
Stack s(n);
int ch,v;
while(1){
cout<<"\n1.Push 2.Pop 3.Empty? 4.Full? 5.Display 6.Peek 7.Exit\n";
cin>>ch;
switch(ch){
case 1: cout<<"Val: ";cin>>v; s.push(v); break;
case 2: s.pop(); break;
case 3: s.isEmpty(); break;
case 4: s.isFull(); break;
case 5: s.display(); break;
case 6: s.peek(); break;
case 7: return 0;
default: cout<<"Wrong\n";
}
  }
  }
