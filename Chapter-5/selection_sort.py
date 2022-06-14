def Selection_Sort(arr, num):
    for i in range(0, num - 1):
        min_idx = i
        for j in range(i + 1, num):
            if arr[min_idx] > arr[j]:
                min_idx = j

        arr[min_idx], arr[i] = arr[i], arr[min_idx]
    return arr


arr = []
num = int(input("Enter the number of elements in an array :"))
print("Enter the elements : ")
for i in range(0, num):
    ele = int(input())
    arr.append(ele)

print(f"The Selection Sort is: {Selection_Sort(arr, num)}")
