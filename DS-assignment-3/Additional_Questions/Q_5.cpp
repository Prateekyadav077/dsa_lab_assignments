#include <iostream>
using namespace std;

bool canSortStack(int A[],int n){
    if(n<=2)return true;
    
    for(int i=1;i<n-1;i++){
      if(A[i]>A[i-1]&&A[i]>A[i+1]){
          return false;
      }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    if(canSortStack(A,n)){
        
        cout<<"YES\n";}
        
    else {cout<<"NO\n";}
    return 0;
}
