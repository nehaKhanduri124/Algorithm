from sys import maxsize

def max_SubArraySum(arr, size):
    max_so_far = -maxsize - 1
    max_ending_here = 0

    for i in range(0, size):
        max_ending_here = max_ending_here + arr[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here

        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far

arr = [-1,7,4,3,-2]

print("Maximum contiguous sum is : ", max_SubArraySum(arr, len(arr)))


