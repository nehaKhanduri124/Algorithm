def binary(list, key):
    first_ele = 0
    last_ele = len(list)
    while  first_ele < last_ele:
        half = (first_ele + last_ele) // 2
        if list[half] > key:
            last_ele = half
        elif list[half] < key:
            first_ele = half + 1
        else:
            return half
    return -1


list = input('Enter elements in ascending order:')
list = list.split()
list = [int(x) for x in list]

key = int(input('The number to search for: '))
index = binary(list, key)
if index < 0:
    print(' not found ')
else:
    print('element found at {} index'.format(index))