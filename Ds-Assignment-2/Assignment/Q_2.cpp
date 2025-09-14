#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    
    
    
    for(int i = 0; i <n-1 ; i++){
         int swap = 0;
        for(int j = 0; j<n-i-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
            
        }
        if(swap == 0){break;}
        }
        cout<<"sorted array = "<<endl;
        for(int i = 0; i<n;i++){
            cout<<arr[i]<<" ";
        }
        
    }
    
    int main(){
           
    int  arr[7]={64,34,25,12,22,11,90};
 
 
    bubble_sort(arr,7);
    return 0;
    }
    
    
