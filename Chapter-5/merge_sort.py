def Merge(arr1, p, q, r):
    n1 = q - p + 1
    n2 = r - q

    L = [0] * n1
    M = [0] * n2

    for i in range(0, n1):
        L[i] = arr1[p + i]
    for j in range(0, n2):
        M[j] = arr1[q + 1 + j]

    i = 0
    j = 0
    k = p


    while i < n1 and j < n2:
        if L[i] <= M[j]:
            arr1[k] = L[i]
            i += 1
        else:
            arr1[k] = M[j]
            j += 1
        k += 1

    while i < n1:
        arr1[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr1[k] = M[j]
        j += 1
        k += 1




def Merge_Sort(arr1, l, r):
    if l < r:
        m = l + (r - l) // 2

        Merge_Sort(arr1, l, m)
        Merge_Sort(arr1, m + 1, r)
        Merge(arr1, l, m, r)


def display_array(arr1, size):
    for i in range(0, size):
        print(arr1[i], end=" ")


arr1 = []
num = int(input("Enter the number of elements in the array : "))
start = 0
end = num - 1
print("Enter the elements : ")
for i in range(0, num):
    elements = int(input())
    arr1.append(elements)

Merge_Sort(arr1, start, end)
print(f"The Merge Sorted array is : ")
display_array(arr1, num)
