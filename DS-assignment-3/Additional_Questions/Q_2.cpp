#include <iostream>
using namespace std;
class Stack{
    int size;
    int* arr;
    int top;
    int min;
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
        cout << "\nStack full\n";
        return;
    }
    if(isempty()){
        top++;
        arr[top] = value;
        min = value;
    }
    else if(value >= min){
        top++;
        arr[top] = value;
    }
    else{
        top++;
        arr[top] = 2*value - min;
        min = value;
    }
}

    void pop(){
    if(isempty()){
        cout << "\nStack empty\n";
        return;
    }

    int t = arr[top--];
    if(t < min){
        min = 2*min - t; 
    }
}


int peek(){
    if(isempty()){
        cout << "\nStack empty\n";
        return -1;
    }
    int t = arr[top];
    if(t >= min) return t;
    else return min;
}
int getMin(){
    if(isempty()){
        cout << "\nStack empty\n";
        return -1;
    }
    return min;
}


    
};
int main() {
    Stack s(10);
    s.push(3);
    s.push(5);
    cout << "Min: " << s.getMin() << endl; 
    s.push(2);
    s.push(1);
    cout << "Min: " << s.getMin() << endl; 
    s.pop();
    cout << "Min: " << s.getMin() << endl; 
    cout << "Top: " << s.peek() ;
}
