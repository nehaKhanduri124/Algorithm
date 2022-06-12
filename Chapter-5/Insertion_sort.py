def Insertion_Sort(arr):
    for i in range(1,len(arr)):
        temp = arr[i]

        while arr[i-1] > temp and i>0:
            arr[i],arr[i-1] = arr[i-1],arr[i]
            i = i-1

    print(arr)

arr = []
num = int(input("enter the number of elements in array : "))
print("enter the elements: ")
for i in range(0,num):
    ele = int(input())
    arr.append(ele)

print("The Insertion sort array is: ",end=" ")
Insertion_Sort(arr)