#include<iostream>
using namespace std;
class Q{
	int size;
     int *arr; 
     int rear;
     int front ;
     public:
     
     Q(){
     	size = 1000;
     	arr = new int[size];
     	rear=0;
     	front=0;
     	
	}

void enqueue(int value){
	if(rear==size){
		cout<<"full"<<endl;
		return;
	}
	arr[rear]= value;
	rear++;
}
void dequeue(){
if(front==rear){
	return ;

}
arr[front]=-1;
front++;
if(front == rear){
	front = 0;
	rear = 0;
}
}

bool isEmpty(){
	if(rear==front){
		return true;
	}
	else{
		return false;
	}
}
bool isFull(){
	if(rear==size){
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
		temp++;
	}
	cout<<endl;
}
void peek(){
	if(isEmpty()){cout<<"no element"<<endl;
	return;}
	cout<<"top element = "<<arr[front]<<endl;
}
int getSize(){
        return rear-front;
    }
    int getElement(int i){
        return arr[front+i];
    }
};
void interleave(Q &q){
    int n=q.getSize();
    int half=n/2;
    for(int i=0;i<half;i++){
        cout<<q.getElement(i)<<" "<<q.getElement(i+half)<<" ";
    }
    cout<<endl;
}
int main()
{
	Q q;
     
    int n;
    cin>>n; 
    for(int i=0;i<n;i++){
    int x;
    cin>>x;
    q.enqueue(x);
    }
    interleave(q);
    return 0;
}
