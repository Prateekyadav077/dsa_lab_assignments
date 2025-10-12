// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
#include<climits>
#include<stack>
using namespace std;
bool arrange(queue<int> &q1, queue<int> &q2, stack<int> &st){
    int expected = 1;
    while(!q1.empty()){
        int x = q1.front();
        q1.pop();
        if(x==expected){
            q2.push(x);
            expected++;
        }
        else{
            st.push(x);
        }
    }
    if(st.empty()){
        return true;
    }       
 int y = st.top();
 st.pop();
 int min = y;
 q2.push(y);
    while(!st.empty()){
        y = st.top();
        st.pop();
        if(y>min){
            q2.push(y);
            min = y;
        }
        else{
            return false;
        }
        
    }
    return true;
}
int main() {
    // Write C++ code here
    queue<int> q1,q2;
    stack<int> st;
    q1.push(5);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
if(arrange(q1,q2,st)){
    cout<<"yes";
}
else{
    cout<<"no";
}

    return 0;
}
