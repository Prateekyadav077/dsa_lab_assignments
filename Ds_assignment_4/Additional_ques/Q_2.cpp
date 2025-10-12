// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
using namespace std;
 
 void sort(queue<int> &q,int n){
     for(int i = 0; i<n-1;i++ ){
         int f = q.front();
         q.pop();
         for(int j = 0 ; j<n-1; j++){
             int s = q.front();
             if(s<f){
                 q.pop();
                 q.push(s);
             }
             else{
                 q.push(f);
                 q.pop();
                 f = s;
             }
         }
         q.push(f);
     }
 }

int main() {
    // Write C++ code here
queue<int> q;
q.push(11);
q.push(5);
q.push(4);
q.push(21);
int size = q.size();
sort(q,size);
for(int i = 0 ; i<size ; i++){
cout<<q.front()<<" ";
q.pop();}
    return 0;
}
