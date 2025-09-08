#include <iostream>
using namespace std;

void sort(int a[], int n) {
 int low=0, mid=0, high=n-1;
 while(mid<=high) {
  if(a[mid]==0) {
   int t=a[low]; a[low]=a[mid]; a[mid]=t;
   low++; mid++;
  }
  else if(a[mid]==1) {
   mid++;
  }
  else {
   int t=a[mid]; a[mid]=a[high]; a[high]=t;
   high--;
  }
 }
}

int main() {
 int a[]={0,2,1,2,0,1,1,0,2};
 int n=sizeof(a)/sizeof(a[0]);
 sort(a,n);
 for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
