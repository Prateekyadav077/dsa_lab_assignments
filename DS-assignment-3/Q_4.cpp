#include<iostream>
using namespace std;

class Stack{
public:
    char *stk;
    int top;
    int size;
    Stack(int s){
        size = s;
        stk = new char[size];
        top = -1;
    }
    void push(char x){
        if(top == size-1){ cout<<"Overflow\n"; return; }
        stk[++top] = x;
    }
    char pop(){
        if(top == -1){ cout<<"Underflow\n"; return '\0'; }
        return stk[top--];
    }
    char peek(){ return (top==-1)?'\0':stk[top]; }
    bool empty(){ return top==-1; }
    ~Stack(){ delete[] stk; }
};

int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='^') return 3;
    return 0;
}


bool isOp(char ch){
    return ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^';
}
int main(){
    string exp, res="";
    cout<<"Enter infix expression: ";
    cin>>exp;

    Stack stk(exp.length());

    for(int i=0;i<exp.length();i++){
        char ch = exp[i];
        if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9')){
            res += ch; 
        }
        else if(ch=='(') stk.push(ch);
        else if(ch==')'){
            while(!stk.empty() && stk.peek()!='(')
                res += stk.pop();
            if(!stk.empty()) stk.pop(); 
        }
        else if(isOp(ch)){
            while(!stk.empty() && precedence(stk.peek())>=precedence(ch))
                res += stk.pop();
            stk.push(ch);
        }
    }a+
    while(!stk.empty()) res += stk.pop();

    cout<<"Postfix expression: "<<res<<endl;
    return 0;
}

