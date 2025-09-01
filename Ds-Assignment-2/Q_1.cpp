#include <iostream>
using namespace std;
int binary_search(int arr[100],int n,int target){
    
    int left = 0,
    right = n-1;
    
    while(left<=right){
         int mid = left + ((right - left)/2);
         
         if(arr[mid]==target){
             return mid;
         }
        else if(arr[mid]<target){
            
            left = mid+1;
            
        }
        
        else{
            right = mid-1;
        }
     
        
    }
    
       return - 1;
    
}

int main() {
    
    int n, arr[100], target;
    
    cout<<"enter size of array"<<endl;
    cin>>n;
    cout<<"\n enter a sorted array of size n"<<endl;
    for(int i =0; i<n;i++){
        cout<<"\n Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    cout<<"\n enter the value you want to find: ";
    cin>>target;
    cout<<"\nthe value you want to find is at index: "<<binary_search(arr, n,target);
    return 0;
    
}
