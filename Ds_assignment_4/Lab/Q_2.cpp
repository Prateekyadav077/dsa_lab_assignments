#include<iostream>
using namespace std;
class Q{
	int size;
     int *arr; 
     int rear;
     int front ;
     public:
     
     Q(){
     	size = 4;
     	arr = new int[size];
     	rear=-1;
     	front=-1;
     	
	}

void enqueue(int value){
	if(((rear+1)%size)==front){
		cout<<"full"<<endl;
		
	}
else if(front==-1){
	front = rear = 0;
	
}
else if(rear==size-1 && front!=0){
	rear=0;
}
else{rear++;
}

	arr[rear]= value;
	
}
void dequeue(){
if(front==-1){
	cout<<"empty"<<endl;
	return ;

}
arr[front]=-1;
if(front==rear){
	front=rear=-1;
}
else if(front == size-1){
	front = 0;
	
}
else{
	front++;
}

}

bool isEmpty(){
	if(front ==-1){
		return true;
	}
	else{
		return false;
	}
}
bool isFull(){
	if(((rear+1)%size)==front){
		return true;
	}
	else{
		return false;
	}
}
void empty(){
	if(isEmpty()){
		cout<<"empty"<<endl;}
		else{
			cout<<"not empty"<<endl;
		}
	
}
void full(){
	if(isFull()){
		cout<<"full"<<endl;}
		else{
			cout<<"not full"<<endl;
		}
	
}
void display(){
	int temp = front;
	while(temp!=rear){
		cout<<arr[temp]<<" ";
		temp= (temp+1)%size;
	}
	cout<<arr[rear];
	cout<<endl;
}
void peek(){
	if(isEmpty()){cout<<"no element"<<endl;
	return;}
	cout<<"top element = "<<arr[front]<<endl;
}

};
int main()
{
	Q s;
     
    int choice;
    
    
    while(1){
    	
    	cout<<"1. Enqueue, 2. Dequeue, 3. check empty, 4. check full, 5. peek, 6. display, 7. exit"<<endl;
    	cin>>choice;
    	switch(choice){
	    
    		case 1: int n; cout<< "enter element"<<endl;
		    cin>>n ;s.enqueue(n);break;
    		case 2: s.dequeue();break;
    		case 3: s.empty(); break;
    		case 4: s.full(); break;
    		case 5: s.peek();break;
    		case 6: s.display(); break;
    		case 7 : cout<<"exit"<<endl; return 0;
    	 default: cout<<"invalid"<<endl;
    	
    	
    }
    }
    
    
    return 0;
}
