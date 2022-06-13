def partition(arr, last, first):
    i = (last - 1)
    piv = a[first]

    for j in range(last, first):
        if a[j] <= piv:
            i = i + 1
            a[i], a[j] = a[j], a[i]

    a[i + 1], a[first] = a[first], a[i + 1]
    return i + 1


def Quick_Sort(arr, last, first):
    if last < first:
        pi = partition(a, last, first)
        Quick_Sort(a, last, pi - 1)
        Quick_Sort(a, pi + 1, first)


a = []
num = int(input("enter the number of elements in array : "))
print("Enter the elements : ")
for i in range(0, num):
    ele = int(input())
    a.append(ele)


Quick_Sort(a,0,num-1)
print("\nSorted array after QuickSort : ",end=" ")
for i in range(num):
    print(a[i],end=" ")
