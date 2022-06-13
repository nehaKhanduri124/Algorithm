#include<bits/stdc++.h>

using namespace std;

void Swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int arr[], int last, int first){
	int pivot, index, i;
	index = last;
	pivot = first;

	for(i=last; i < first; i++){
		if(arr[i] < arr[pivot]){
			Swap(&arr[i], &arr[index]);
			index++;
		}
	}
	Swap(&arr[pivot], &arr[index]);
	return index;
}

int random_partition(int arr[], int last, int first){
	int pvt, num, temp;
	num = rand();
	pvt = last + num%(first-last+1);
	Swap(&arr[first], &arr[pvt]);
	return Partition(arr, last, first);
}

int Quick_Sort(int arr[], int last, int first){
	int pindex;
	if(last < first){
		pindex = Partition(arr, last, first);
		Quick_Sort(arr, last, pindex-1);
		Quick_Sort(arr, pindex+1, first);
	}
	return 0;
}

void display(int arr1[],int num){
    cout<<endl<<"sorted Array after QuickSort is: ";
	for (int i=0;i<num;i++){
        cout<<arr1[i]<<" ";
	}
}

int main(){
	int num, i;
	cout<<"enter the number of elements in the array: ";
	cin>>num;

	int arr1[num];
	cout<<"enter elements : ";
	for(i = 0; i < num; i++){
    cin>>arr1[i];
	}

	Quick_Sort(arr1, 0, num-1);
	display(arr1,num);
	return 0;
}
