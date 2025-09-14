#include <iostream>
using namespace std;
class Stack{
    int size;
    char* arr;
    int top;
    public:
    Stack(int size){
        this->size = size;
        arr = new char[size];
        top = -1;
    }
    void push(int value){
        if(top==size-1){
            cout<<"full";
            return;
        }
        top++;
        arr[top]=value;
        
    }
    void pop(){
        if(top==-1){
            cout<<"\nempty";
            return;
        }
        top--;
    }
    char topp(){
        if(top==-1){
        cout<<"\n empty";
        return '\0';
    }
    return arr[top];
    }
    
    bool empty(){
        if(top==-1){
            return true;
        
    }
    else{return false;}
    
}
};
int priority(char c){
    if(c=='^'){
        return 3 ;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
void infixtopostfix(string s){
    int i = 0;
    Stack s1(20);
    string ans = "";
    int n = s.size();
    while(i<n){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
            ans = ans + s[i];
        }
        else if(s[i]=='('){
            s1.push(s[i]);
        }
        else if(s[i]==')'){
            while(!s1.empty()&& s1.topp() != '('){
                ans= ans+s1.topp();
                s1.pop();
            }
            s1.pop();
            
        }
        else{
            
            while(!s1.empty()&& priority(s[i])<=priority(s1.topp())){
                ans= ans+ s1.topp();
                s1.pop();
                
            }
            s1.push(s[i]);
                }
        i++;
    }
    while(!s1.empty()){
        
    ans = ans+s1.topp();
    
    s1.pop();
    
}
cout<<ans;
}

int main(){
    string expression;
    cin>>expression;
    infixtopostfix(expression);
    
}
