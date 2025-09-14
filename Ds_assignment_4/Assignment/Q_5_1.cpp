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

class StackTwoQ{
    Q q1,q2;
public:
    void push(int x){
        q1.enqueue(x);
    }
    void pop(){
        if(q1.isEmpty()){
            cout<<"Stack empty\n";
            return;
        }
        int n=q1.getSize();
        for(int i=0;i<n-1;i++){
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        cout<<"Popped: "<<q1.peek()<<endl;
        q1.dequeue();
        swap(q1,q2);
    }
    int top(){
        if(q1.isEmpty()) return -1;
        int n=q1.getSize();
        for(int i=0;i<n-1;i++){
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        int res=q1.peek();
        q2.enqueue(res);
        q1.dequeue();
        swap(q1,q2);
        return res;
    }
};

int main(){
    StackTwoQ st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<"Top: "<<st.top()<<endl; 
    st.pop();                       
    cout<<"Top: "<<st.top()<<endl; 
}
