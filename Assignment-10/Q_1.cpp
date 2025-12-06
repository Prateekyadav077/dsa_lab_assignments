#include<iostream>
using namespace std;
#include<unordered_set>
#include<vector>
bool duplicate(vector<int>&s){
    unordered_set<int>hash;
    for(int u:s){
        if(hash.find(u)!= hash.end()){
            return  true;
        }
        hash.insert(u);
    }
    return false;
}
 int main(){
     vector<int>s= {1,2,3,4};
     if(duplicate(s)){
         cout<<"yes";
     }
     else{
         cout<<"no";
     }
     
 }
