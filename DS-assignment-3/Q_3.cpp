using namespace std;
#include<string>
class Stack{
    
    int size;
    char *arr;
    int top;
    
    public:
    
    Stack(int size){
        this->size = size;
         top =-1;
        arr = new char[size];
    }
    
    void push(char value){
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
    char peek(){
        if(top==-1){
            cout<<"\nempty";
            return '\0';
        }
        return arr[top];
    }
  
};
  bool valid(Stack &s1,char c){
        if (c=='}'){
            if(s1.peek()=='{'){
                s1.pop();
                return true;}
              else{return false;}  
        
        }
          else if (c==')'){
            if(s1.peek()=='('){
                s1.pop();
                return true;}
              else{return false;}  
        }
          if (c==']'){
            if(s1.peek()=='['){
                s1.pop();
                return true;}
              else{return false;}  
        }
    }
int main(){
    Stack s1(20);
    string c;
    int p =1;
    cout<<"\nenter brackets: ";
    cin>>c;
    int n = c.size();
    for(int i =0;i<n;i++){
        if(c[i]=='('||c[i]=='['||c[i]=='{'){
            s1.push(c[i]);
        }
        else {
            if(!valid(s1,c[i])){
        
        cout<<"\n invalid parenthesis";
        
         return -1;
    }
               
            }
        }
        
        cout<<"\nvalid parenthesis";
    
    return 0;    }
