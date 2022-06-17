#include <iostream>
using namespace std;

void Heapify(int ar[], int num, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l<num && ar[l] > ar[largest])
      largest = l;

    if(r< num && ar[r] > ar[largest])
      largest = r;

    if(largest != i) {
        swap(ar[i], ar[largest]);
        Heapify(ar, num, largest);
    }
}

void Heap_Sort(int ar[], int num){
    for(int i = num / 2 - 1; i >= 0; i--)
        Heapify(ar, num, i);

    for(int i = num - 1; i >= 0; i--){
        swap(ar[0], ar[i]);

        Heapify(ar, i, 0);
    }
}

void Display(int ar[], int num){
    cout<<endl<<"Sorted array using Heap Sort : ";
    for (int i = 0; i < num; ++i)
        cout << ar[i] << " ";
}

int main() {
    int num, i;
	cout<<" enter the number of elements in the array : ";
	cin>>num;

	int ar[num];
	cout<<"enter the elements: ";
	for(i = 0; i < num; i++){
		cin>>ar[i];
	}
    Heap_Sort(ar, num);
    Display(ar, num);
}
