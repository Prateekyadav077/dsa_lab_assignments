#include <iostream>
using namespace std;

void duplicate(int a[], int n) {
 int cnt=0;
 for(int i=0;i<n;i++) {
  if(a[i]==2) cnt++;
 }
 int i=n-1, j=n+cnt-1;
 while(i>=0 && j>=0) {
  if(a[i]==2) {
   if(j<n) a[j]=2;
   j--;
   if(j<n) a[j]=2;
   j--;
  } else {
   if(j<n) a[j]=a[i];
   j--;
  }
  i--;
 }
}

int main() {
 int a[]={1,2,3,2,4,5};
 int n=6;
 duplicate(a,n);
 for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
