#include<iostream>
using namespace std;

class Stack{
public:
char arr[100];
int top;
Stack(){ top=-1; }
void push(char x){ arr[++top]=x; }
char pop(){ return arr[top--]; }
bool empty(){ return top==-1; }
};

bool match(char a,char b){
return (a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']');
}

int main(){
int n;
cout<<"Enter size: ";
cin>>n;
Stack st;
cout<<"Enter brackets: ";
for(int i=0;i<n;i++){
char ch;
cin>>ch;
st.push(ch);
}

bool balanced=true;

char b[n];

for(int i=0;i<n;i++) b[i]=st.pop();

for(int i=0;i<n/2;i++){
if(!match(b[i],b[n-i-1]))

{ balanced=false; 

break; }
}

if(balanced) cout<<"Balanced\n";

else cout<<"Not Balanced\n";

return 0;
}
