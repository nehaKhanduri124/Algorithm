#include <iostream>
using namespace std;


void Merge(int arr1[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr1[p + i];
    for(int j = 0; j < n2; j++)
        M[j] = arr1[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if(L[i] <= M[j]) {
            arr1[k] = L[i];
            i++;
        }
        else {
            arr1[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr1[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr1[k] = M[j];
        j++;
        k++;
    }
}

void Merge_Sort(int arr1[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        Merge_Sort(arr1, l, m);
        Merge_Sort(arr1, m + 1, r);
        Merge(arr1, l, m, r);
    }
}

void display_array(int arr1[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr1[i] << " ";
}

int main() {
    int num;
    cout<<"Enter the number of elements in the array : ";
    cin>>num;
    int arr1[num];
    cout<<"Enter the elements in array : ";
    for(int i=0;i<num;i++){

        cin>>arr1[i];
    }
    int start_with = 0;
    int end_with = num-1;

  Merge_Sort(arr1,start_with,end_with);

  cout << "Sorted array after merge sort is : \n";
  display_array(arr1, num);
  return 0;
}
