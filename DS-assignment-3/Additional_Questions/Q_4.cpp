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
void small_temp(int arr[],int n){
    Stack s1(n);
    int array[n];
    
    
    for(int i = n-1; i>=0;i--){
 
        
            while(!s1.isempty()&&arr[s1.peek()]>=arr[i]){
                
                    s1.pop();
                    
                    
                }
                if(s1.isempty()){
                    array[i]=0;
                }
                else{
                array[i]= s1.peek()-i;
                }
                s1.push(i);
            
        
            
        
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
    cout<<"\n enter array with temp ";
   
    for(int i = 0; i<size; i++){
        cin>>array[i];
    }
    cout<<"\ndays until you have to wait for warmer temp for each day coresponding to above array";
    small_temp(array,size);
    
        return 0;}
