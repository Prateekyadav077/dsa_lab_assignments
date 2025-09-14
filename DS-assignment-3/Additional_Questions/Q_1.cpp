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
void nearest(int arr[],int n){
    Stack s1(n);
    int array[n];
    int i = 0;
    
    while(i<n){
 
        
            while(!s1.isempty()&&s1.peek()>=arr[i]){
                    s1.pop();
                    
                    
                }
                if(s1.isempty()){
                    array[i]=-1;
                }
                else{
                array[i]= s1.peek();
                }
                s1.push(arr[i]);
            
        
            
        i++;    
        }
        
    
    for(int p =0; p <n;p++){
        cout<<array[p]<<" ";
    
}
    
}
int main(){
    int *array;
    int size;
    cout<<"size for array: ";
    cin>>size;
    array = new int[size];
    cout<<"\n enter array ";
   
    for(int i = 0; i<size; i++){
        cin>>array[i];
    }
    cout<<"\narray with nearest smallest value corresponding to entered array ";
    nearest(array,size);
    
    
    return 0;}
