#include <iostream>
using namespace std;

int lenStr(char s[]) {
 int i=0;
 while(s[i]!='\0') i++;
 return i;
}

int main() {
 char s1[100],s2[100];
 cin>>s1>>s2;

 int n1=lenStr(s1), n2=lenStr(s2);
 if(n1!=n2) { cout<<"NO"; return 0; }

 int used[100]={0}; 

 for(int i=0;i<n1;i++) {
  int found=0;
  for(int j=0;j<n2;j++) {
   if(s1[i]==s2[j] && !used[j]) {
    used[j]=1;
    found=1;
    break;
   }
  }
  if(!found) { cout<<"NO"; return 0; }
 }
 cout<<"YES";
}
