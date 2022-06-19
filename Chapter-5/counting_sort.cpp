#include<bits/stdc++.h>

using namespace std;

void Counting_Sort(int a[], int num) {
    int output_array[10];
    int count_array[10];
    int max = a[0];

    for(int i=1;i<num;i++) {
        if (a[i]>max)
        max = a[i];
    }
    for(int i=0;i<=max;++i) {
        count_array[i] = 0;
    }

    for(int i=0;i<num;i++) {
        count_array[a[i]]++;
    }

    for(int i=1;i<=max;i++) {
        count_array[i] += count_array[i-1];
    }

    for(int i = num-1;i>=0;i--){
        output_array[count_array[a[i]] - 1] = a[i];
        count_array[a[i]]--;
    }

    for(int i = 0; i < num; i++){
        a[i] = output_array[i];
    }
}

void Display(int a[], int num){
    cout<<endl<<" After Counting Sort : ";
    for (int i = 0; i < num; i++)
        cout << a[i] << " ";
  cout << endl;
}

int main() {
int num, i;
	cout<<"enter the number elements in the array : ";
	cin>>num;

	int a[num];
    cout<<"enter the elements : ";
	for(i = 0; i < num; i++){
		cin>>a[i];

	}
  //cout<<"Before counting sort array is :"<<a[i];

    Counting_Sort(a, num);
    Display(a, num);
}
