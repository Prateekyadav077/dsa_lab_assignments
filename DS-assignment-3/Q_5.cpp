#include<iostream>
using namespace std;
  class Stack{
   public:
   int *s;
   int top;
   int size;
   Stack(int n){ size=n; s=new int[size]; top=-1; }
    void push(int x){ s[++top]=x; }
    int pop(){ return s[top--]; }
    bool empty(){ return top==-1; }
 };
int main(){
   char p[100];
   cout<<"Enter postfix expression: ";
   cin>>p;
   int i=0;
  Stack st(100);
  while(p[i]!='\0'){
     char c=p[i];
     if(c>='0'&&c<='9') st.push(c-'0');
     else{
     int a=st.pop();
     int b=st.pop();
     if(c=='+') st.push(b+a);
     else if(c=='-') st.push(b-a);
     else if(c=='*') st.push(b*a);
     else if(c=='/') st.push(b/a);
}
i++;
}
cout<<"Result: "<<st.pop()<<endl;
return 0;
}
