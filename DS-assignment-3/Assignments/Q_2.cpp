#include <iostream>
using namespace std;
#include<string>
class Stack{
    
    int size;
    char *arr;
    int top;
    
    public:
    
    Stack(int size){
        this->size = size;
         top =-1;
        arr = new char[size];
    }
    
    void push(char value){
        if(top==size-1){
            cout<<"full";
            return;
        }
        
        top++;
        arr[top]=value;
        
    }
    void pop(){
        if(top==-1){
            cout<<"\nempty";
            return;
            
        }
        top--;
    }
    void peek(){
        if(top==-1){
            cout<<"\nempty";
            return;
        }
        cout<<arr[top];
    }
};

int main() {
    // Write C++ code here
    Stack s(13);
    string c= "DataStructure";
    
    for(int i=0;i<13;i++){
    
        s.push(c[i]);
    }
     for(int i=0;i<13;i++){
        s.peek();
        s.pop();
    }

    return 0;
}
