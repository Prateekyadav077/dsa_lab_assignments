#include <iostream>
using namespace std;
class Stack{
    int size;
    int* arr;
    int top;
    public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
    return false;
        
    }
    
    void push(int value){
        if(top == size-1){
            cout<<"\nfull";
        }
        top++;
        arr[top]= value;
    }
    void pop(){
        if(isempty()){
            cout<<"\n empty";
            return;
        }
        top--;}

    int peek(){
        if(isempty()){
            cout<<"\n empty";
            return -1;
        }
        return arr[top];
    }
    
};


void postfix(string s){
    Stack s1(20);
    int n = s.size();
    int i =0;
    while(i<n){
        if((s[i]>='0'&&s[i]<='9')){
            s1.push(s[i]-'0');
            
        }
        else{
           int x=s1.peek();
            s1.pop();
            int  y = s1.peek();
            s1.pop();
            if(s[i]=='^'){
                int z =1;
                for(int j = 0; j<x;j++){
                 z = z*y;
                }
                s1.push(z);
            }
            else if(s[i]=='+'){
                s1.push(y+x);
            }
            else if(s[i]=='-'){
                s1.push(y-x);
            }
            else if(s[i]=='/'){
                s1.push(y/x);
            }
            else{
                s1.push(y*x);
            }
        }
i++;
    }
  cout<< "\nevaluated expression = "<<s1.peek();
}
int main() {
    string c;
    cout<<"\n enter a postfix expression: ";
    cin>>c;
    postfix(c);
    return 0;}
