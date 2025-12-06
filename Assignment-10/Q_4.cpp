// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<unordered_map>
#include<vector>

int frequency(vector<int>&s, unordered_map<int,int>&freq){
    for(int i:s){
        freq[i] = freq[i]+1;
    }
   for(int x:s){
       if(freq[x]==1){
           return x;
       }
   }
   return -1;
}
int main() {
    // Write C++ code here
    vector<int>s = {4,5,1,2,0,4};
    unordered_map<int,int>freq;
   cout<< frequency(s,freq);
    

    return 0;
}
