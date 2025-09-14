#include<iostream>
using namespace std;

class Q{
    int size;
    int *arr;
    int rear;
    int front;
public:
    Q(){
        size=1000;
        arr=new int[size];
        front=0;
        rear=0;
    }
    void enqueue(int x){
        if(rear==size) return;
        arr[rear]=x;
        rear=rear+1;   
    }
    void dequeue(){
        if(front==rear) return;
        front=front+1;  
        if(front==rear) front=rear=0;
    }
    int peek(){
        if(front==rear) return -1;
        return arr[front];
    }
    bool isEmpty(){
        return front==rear;
    }
    int getSize(){
        return rear-front;
    }
};

class StackOne{
    Q q;
public:
    void push(int x){
        int n=q.getSize();
        q.enqueue(x);
        for(int i=0;i<n;i++){
            int val=q.peek();
            q.enqueue(val);
            q.dequeue();
        }
    }
    void pop(){
        if(q.isEmpty()){
            cout<<"Stack empty\n";
            return;
        }
        cout<<"Popped: "<<q.peek()<<endl;
        q.dequeue();
    }
    int top(){
        if(q.isEmpty()) return -1;
        return q.peek();
    }
};

int main(){
    StackOne st;
    st.push(5);
    st.push(10);
    st.push(15);
    cout<<"Top: "<<st.top()<<endl; 
    st.pop();                       
    cout<<"Top: "<<st.top()<<endl; 
}
