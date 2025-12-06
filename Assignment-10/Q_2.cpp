#include<iostream>
using namespace std;
#include<unordered_set>
#include<vector>
void duplicate(vector<int>&s,vector<int>&v){
    unordered_set<int>hash(s.begin(),s.end());
    int flag = 0;
    for(int u:v){
        if(hash.find(u)!= hash.end()){
            cout<<u<<" ";
            flag = 1;
        }
        hash.insert(u);
    }
if (flag==0){
    cout<<"no";
}
}
 int main(){
     vector<int>s= {1,2,3,4};
          vector<int>v= {3,4,5,6};
     duplicate(s,v);
 }
