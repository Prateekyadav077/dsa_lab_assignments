#include<iostream>
using namespace std;
class Q{
	int size;
     char *arr; 
     int rear;
     int front ;
     public:
     
     Q(){
     	size = 1000;
     	arr = new char[size];
     	rear=0;
     	front=0;
     	
	}

void enqueue(char value){
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
char peek(){
	if(isEmpty()){
	return '\0';}
 return arr[front];
}
int getSize(){
        return rear-front;
    }
    int getElement(int i){
        return arr[front+i];
    }

};
void firstNonRepeating(string s){
    Q q;
    int freq[256]={0};
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch==' ') continue; 
        q.enqueue(ch);
        freq[(int)ch]++;
        while(!q.isEmpty() && freq[(int)q.peek()]>1){
            q.dequeue();
        }
        if(q.isEmpty()) cout<<"-1 ";
        else cout<<q.peek()<<" ";
    }
}

int main()
{
 string s;
 getline(cin,s);
 firstNonRepeating(s);
}
