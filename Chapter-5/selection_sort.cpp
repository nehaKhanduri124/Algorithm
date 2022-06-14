#include<iostream>

 using namespace std;

int main(){
    int num;
    cout<<"enter the number of elements in an array: ";
    cin>>num;
    int arr[num];
      cout<<"enter elements of an array : ";
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    for(int i=0;i<num-1;i++){
        int min_idx = i;
        for(int j=i+1;j<num;j++){
            if(arr[min_idx]>arr[j]){
                min_idx= j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    cout<<" after Selection sort : "<<" ";
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
 }
