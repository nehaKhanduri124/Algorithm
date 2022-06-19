def Counting_Sort(arr):
    size = len(arr)
    output_arr = [0] * size
    count_arr = [0] * 10

    for i in range(0, size):
        count_arr[arr[i]] += 1

    for i in range(1, 10):
        count_arr[i] += count_arr[i - 1]

    i = size - 1
    while i >= 0:
        output_arr[count_arr[arr[i]] - 1] = arr[i]
        count_arr[arr[i]] -= 1
        i -= 1

    for i in range(0, size):
        arr[i] = output_arr[i]

A = []
num = int(input("Enter the number of element in the array : "))
print("Enter the elements : ")
for i in range(0, num):
    elements = int(input())
    A.append(elements)

Counting_Sort(A)
print(" Sorted Array after Counting Sort : ", end = " ")
print(A)