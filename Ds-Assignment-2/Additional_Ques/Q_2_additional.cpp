#include <iostream>
using namespace std;

int length(string x) {
 int p=0;
 while(x[p]!='\0') p++;
 return p;
}

bool possible(string x) {
 int mark[26]={0};
 int l=length(x);
 for(int k=0;k<l;k++) 
 {mark[x[k]-'a']++;}
 for(int k=0;k<26;k++) {
  if(mark[k]>=3) return true;
 }
 return false;
}

int main() {
 string w;
 cin>>w;
 if(possible(w)) cout<<"YES";
 else cout<<"NO";
 return 0;
}
