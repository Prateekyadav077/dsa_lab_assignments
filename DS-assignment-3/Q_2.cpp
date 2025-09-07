#include<iostream>
using namespace std;

class Stack{
 public:
char *arr;
 int top;
int size;

 Stack(int s){
 size=s;
arr=new char[size];
 top=-1;
 }

 void push(char x){
 if(top==size-1){
   cout<<"Overflow\n";
}
 else{
   arr[++top]=x;
 }
 }

 char pop(){
 if(top==-1){
   return '\0';
   }
 else{
  return arr[top--];
 }
 }
};

 int main(){
 int n;
 cout<<"Enter length: ";
 cin>>n;
 char str[100];
 cout<<"Enter string: ";
 for(int i=0;i<n;i++){cin>>str[i];}

 Stack s(n);
 for(int i=0;i<n;i++){s.push(str[i]);}

 cout<<"Reversed: ";
 for(int i=0;i<n;i++){ cout<<s.pop(); }
 cout<<"\n";
 return 0;
 }
