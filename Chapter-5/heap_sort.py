def Heapify(a, num, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < num and a[i] < a[l]:
        largest = l

    if r < num and a[largest] < a[r]:
        largest = r

    if largest != i:
        a[i], a[largest] = a[largest], a[i]
        Heapify(a, num, largest)


def Heap_Sort(a):
    num = len(a)

    for i in range(num // 2, -1, -1):
        Heapify(a, num, i)

    for i in range(num - 1, 0, -1):
        a[i], a[0] = a[0], a[i]
        Heapify(a, i, 0)


a = []
num = int(input("enter the number of elements in the array : "))
print("Enter the elements : ")
for i in range(0, num):
    elements = int(input())
    a.append(elements)
Heap_Sort(a)
print(" Sorted Array using Heap Sort is : ", end = " ")
for i in range(num):
    print(a[i], end=" ")
