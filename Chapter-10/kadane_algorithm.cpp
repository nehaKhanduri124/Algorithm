#include<iostream>
using namespace std;
int Kadanes_Algorithm(int arr[],int num) {
   int Highest_Max = 0;
   int current_MaxElement = 0;
   for(int i = 0; i < num; i++){
      current_MaxElement =max(arr[i],current_MaxElement + arr[i]) ;
      Highest_Max = max(Highest_Max,current_MaxElement);
   }
   return Highest_Max;
}
int main() {
   cout << "Enter the number of elements in the array : ";
   int num;
   cin >> num;
   int arr[num];
   cout << "Enter the elements of an array : ";
   for (int i = 0; i < num; i++) {
      cin >> arr[i];
   }
   cout << "The maximum sum is : "<<Kadanes_Algorithm(arr,num) << endl;
   return 0;
}
