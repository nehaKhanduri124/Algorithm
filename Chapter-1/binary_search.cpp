#include<iostream>

using namespace std;

int binary(int arr[],int n,int ele){
    int first_ele=0;
    int last_ele = n-1;
    while(last_ele>=first_ele){
        int half = (first_ele+last_ele)/2;
        if(arr[half]==ele){
            return half;
        }
        else if(arr[half]<ele){
            first_ele = half +1;
        }
        else{
            last_ele = half-1;
        }
    }
    return -1;
}

int main(){
    int n,key;
    cout<<"Enter the size of array = ";
    cin>>n;

    int arr[n];
    cout<<"Enter the element in ascending order = ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter a element to find index : ";
    cin>>key;

    if(binary(arr,n,key)!=-1){
        cout<<"Element Found at "<<binary(arr,n,key)<<" Index";
    }
    else{
        cout<<"Element Not Found!";
    }
    return 0;
}
