
def isSorted(arr, i):
    # for p1
    if i == 0:
        return True

    if arr[i] < arr[i-1]:
        return False

    return isSorted(arr, i-1)


def p1():
    # Problem 1 : check if array is sorted

    # Statement : given an array of n integers,
    # check if array is sorted or not

    # Logic : using Recursion
    # create a recursive function isSorted(),
    # which will take two arguments array arr[]
    # and last index of array int i
    # and return true is array is sorted else false
    # add base condition :
    # if i == 0 return true
    # processing part :
    # check for arr[i] < arr[i-1]
    # if true return false
    # decreament i by 1
    # recursive relation part :
    # call isSorted() function again with arr and i

    # Code :
    arr = [1, 2, 5, 7, 8, 9, 12, 12, 13, 45]
    # arr = [1, 2, 5, 7, 8, 19, 12, 12, 13, 45]
    # arr = [1, 2, 5, 7, 8, 19, 92, 112, 113, 145]
    size = 10

    if isSorted(arr, size-1):
        print("array is sorted")
    else:
        print("array is not sorted")


def giveSum(arr, i):
    # for p2
    if i == -1:
        return 0

    return arr[i] + giveSum(arr, i-1)


def p2():
    # Problem 2 : Sum of array

    # Statement : given an array of n integers,
    # return the sum of all the integers in the array

    # Logic : using Recursion
    # create a recursive function giveSum(),
    # which will take array arr[], and last index of array i
    # add base condition if i == -1: return 0
    # processing part :
    # create a variable s = arr[i]
    # decrease i by 1
    # recursive relation :
    # return a + giveSum(arr, i)

    # Code :
    arr = [1, 2, 5, 7, 8, 9, 12, 12, 13, 45]
    # arr = [1, 2, 5, 7, 8, 19, 12, 12, 13, 45]
    # arr = [1, 2, 5, 7, 8, 19, 92, 112, 113, 145]
    size = 10

    sum = giveSum(arr, size-1)
    print(f"sum of array is {sum}")


def linearSearch(arr, key, i):
    # for p3
    if i == -1:
        return False

    if arr[i] == key:
        return True

    return linearSearch(arr, key, i-1)


def p3():
    # Problem 3 : Linear search using recursion

    # Statement : given an array of size n,
    # and an key
    # find that key in the array
    # and return true if key found else return false

    # Logic : using recursiom
    # create recursive function linearSearch(),
    # which will take 3 arguments array arr[], key key and last index i
    # and return true if key is found is arr
    # else false
    #

    # Code :
    arr = [1, 2, 5, 7, 8, 9, 12, 12, 13, 45]
    size = 10
    key = 9

    # arr = [1, 2, 5, 7, 8, 19, 12, 12, 13, 45]
    # size = 10
    # key = 4

    # arr = [1, 2, 5, 7, 8, 19, 92, 112, 113, 145]
    # size = 10
    # key = 15

    if linearSearch(arr, key, size-1):
        print("key found")
    else:
        print("key not found")


def binarySearch(arr, key, low, high):
    # for p4
    if low > high:
        return False

    mid = int(low + (high-low)/2)

    if arr[mid] == key:
        return True
    elif arr[mid] > key:
        return binarySearch(arr, key, low, mid-1)
    else:
        return binarySearch(arr, key, mid+1, high)


def p4():
    # Problem 4 : Binary search using recursion

    # Statement : given a sorted array of n integers,
    # and an integer key
    # check if key is present in the array or not

    # Logic : using recursion
    # create a fucntion binarySearch(arr, key, low, high) -> Boolean
    # inside function add base condition
    # if low > high: return false
    # find mid = low + (high-low)/2
    # check for below conditions
    # 1. arr[mid] == key
    # 2. arr[mid] > key
    # 3. arr[mid] < key
    # if 1 is true return true
    # if 2 is true find key in left part of the array and return that result
    # to find key in left part
    # return binarySearch(arr, key, low, mid-1)
    # if 3 is true find key in right part of the array and return that result
    # to find key in right part
    # return binarySearch(arr, key, mid+1, high)

    # Code :
    arr = [1, 2, 5, 7, 8, 9, 12, 12, 13, 45]
    size = 10
    key = 9

    if binarySearch(arr, key, 0, size-1):
        print("key found in array")
    else:
        print("key not found in array")


def binarySearchIndex(arr, key, low, high):
    # for p5
    if low > high:
        return -1

    mid = int(low + (high-low)/2)

    if arr[mid] == key:
        return mid
    elif arr[mid] > key:
        return binarySearchIndex(arr, key, low, mid-1)
    else:
        return binarySearchIndex(arr, key, mid+1, high)


def p5():
    # Problem 5 : Binary Search - https://www.codingninjas.com/codestudio/problems/binary-search_972

    # Statement : You have been given a sorted(in ascending order) integer array/list(ARR)
    # of size N and an element X.
    # Write a function to search this element in the given input array/list
    # using 'Binary Search'.
    # Return the index of the element in the input array/list.
    # In case the element is not present in the array/list, then return -1.

    # Logic : using recursion
    # create a fucntion binarySearchIndex(arr, key, low, high) -> integer
    # inside function add base condition
    # if low > high: return -1
    # find mid = low + (high-low)/2
    # check for below conditions
    # 1. arr[mid] == key
    # 2. arr[mid] > key
    # 3. arr[mid] < key
    # if 1 is true return mid
    # if 2 is true find key in left part of the array and return that result
    # to find key in left part
    # return binarySearchIndex(arr, key, low, mid-1)
    # if 3 is true find key in right part of the array and return that result
    # to find key in right part
    # return binarySearchIndex(arr, key, mid+1, high)

    # Code :
    arr = [1, 2, 5, 7, 8, 9, 12, 12, 13, 45]
    size = 10
    key = 9

    index = binarySearchIndex(arr, key, 0, size-1)

    if index != -1:
        print(f"key found at index {index}")
    else:
        print("key not found")


if __name__ == "__main__":
    # Lecture 33 : Recursion III Binary search

    # p1()

    # p2()

    # p3()

    # p4()

    # p5()

    pass
