// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include<unordered_map>
#include<vector>

void frequency(vector<int>&s, unordered_map<int,int>&freq){
    for(int i:s){
        freq[i] = freq[i]+1;
    }
    unordered_map<int, int>::iterator it;
    for(it = freq.begin();it!=freq.end();it++){
        int key = it->first;
        int count = it->second;
        cout<<key<<":"<<count<<endl;
    }
}
int main() {
    // Write C++ code here
    vector<int>s = {2,3,2,4,3,2};
    unordered_map<int,int>freq;
    frequency(s,freq);

    return 0;
}
