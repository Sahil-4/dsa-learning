
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


def findOccurrences(arr, key, index, low, high, fl):
    # for p5()
    if low > high:
        return index

    mid = low + int((high-low)/2)

    if arr[mid] == key:
        index = mid
        if fl == 0:
            # 0 for first occurrence
            high = mid-1
        elif fl == 1:
            # 1 for last occurrence
            low = mid+1
    elif arr[mid] > key:
        high = mid-1
    else:
        low = mid+1

    return findOccurrences(arr, key, index, low, high, fl)


def p6():
    # Problem 6 : Find first and last occurrence - https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549

    # Stattement : You have been given a sorted array/list ARR consisting of ‘N’ elements,
    # and an integer ‘K’,
    # the task is to find the first and last occurrence of ‘K’ in ARR

    # Logic : using Recursive Binary Search
    # find the first occurrence of element k in the array
    # find the last occurrence of element k in the array
    # create a recursive function findOccurrences()
    # which will take an array, key, answer = -1, low index, high index, flag = 0 or flag = 1
    # inside function add a base condition
    # if low > high return answer
    # calculate mid = low + (high-low)/2
    # check for below 3 conditions
    # 1. arr[mid] == key
    # 2. arr[mid] > key
    # 3. arr[mid] < key
    # if 1 is true update answer = mid
    # and then check value flag
    # if flag == 0
    # update high = mid-1
    # if flag == 1
    # update low = mid+1
    # if 2 is true update high = mid-1
    # if 3 is true update low = mid+1
    # then finally return recursive call to findOccurrences()

    # Code :
    arr = [0, 2, 2, 5, 5, 12, 12, 12, 14, 17, 18, 18]
    key = 12

    arr = [0, 2, 2, 5, 5, 12, 12, 12, 14, 17, 18]
    key = 12

    arr = [12, 12, 12, 12, 12, 12]
    key = 12

    occurrence_first = findOccurrences(arr, key, -1, 0, len(arr)-1, 0)
    occurrences_last = findOccurrences(arr, key, -1, 0, len(arr)-1, 1)

    # first and last occurrence
    print(occurrence_first, occurrences_last)

    # total occurrences
    print(occurrences_last-occurrence_first)


def findPeak(arr, low, high):
    # for p7()
    if low > high:
        return -1

    mid = low + int((high-low)/2)

    if arr[mid-1] < arr[mid] > arr[mid+1]:
        return mid
    elif arr[mid] > arr[mid-1]:
        low = mid+1
    else:
        high = mid

    return findPeak(arr, low, high)


def p7():
    # Problem 7 : 852. Peak Index in a Mountain Array - https://leetcode.com/problems/peak-index-in-a-mountain-array/

    # Statement : Given a mountain array arr,
    # return the index i
    # such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

    # Logic : using recursive binary search
    # create a recursive function findPeak(arr[], low_index, high_index)
    # add base condition
    # if low_index > high_index return -1
    # check for below condtions
    # 1. arr[mid-1] < arr[mid] > arr[mid+1]
    # 2. arr[mid] > arr[mid-1]
    # 3. arr[mid] < arr[mid-1]
    # if 1 is true simply return mid as peak index
    # if 2 is true update low = mid+1
    # if 3 is true update high = mid
    # then finally return a recursive call findPeak(arr[], low_index, high_index)

    # Code :
    arr = [24, 69, 100, 99, 79, 78, 67, 36, 26, 19]

    peak = findPeak(arr, 0, len(arr)-1)

    print(peak)


def sum(arr, l, h):
    # for findPivot(arr, low, high)
    sum = 0
    for i in range(l, h):
        sum += arr[i]

    return sum


def findPivot(arr, low, high):
    # for p8()
    if low > high:
        return -1

    mid = low + int((high-low)/2)

    l_sum = sum(arr, 0, mid)
    r_sum = sum(arr, mid+1, len(arr))

    if l_sum == r_sum:
        return mid
    elif l_sum > r_sum:
        high = mid-1
    else:
        low = mid+1

    return findPivot(arr, low, high)


def p8():
    # Problem 8 : 724. Find Pivot Index - https://leetcode.com/problems/find-pivot-index/

    # Statement : Given an array of integers nums[],
    # calculate the pivot index of this array.
    # The pivot index is the index where the sum of all the numbers,
    # strictly to the left of the index is
    # equal to the sum of all the numbers,
    # strictly to the index's right.
    # NOTE : If the index is on the left edge of the array,
    # then the left sum is 0 because there are no elements to the left.
    # This also applies to the right edge of the array.

    # Logic :
    # take 2 variables right_sum = 0, left_sum = 0
    # loop through the array
    # calculate right_sum summing all the elements
    # run loop from i = 0 to i < size
    # add arr[i-1] in left_sum,
    # and subtract arr[i] from right_sum
    # check if right_sum == left_sum,
    # if yes return i as pivot index
    # else move to next index
    # NOTE : will only work if array contains only positive integers

    arr = [1, 7, 3, 6, 5, 6]
    # arr = [1, 2, 3]
    # arr = [1, 7, 3, 6, 5, 6]

    print(findPivot(arr, 0, len(arr)-1))


def pivot(arr, low, high):
    # for p8()
    if low >= high:
        return low

    mid = low + int((high - low)/2)
    if arr[mid] >= arr[0]:
        low = mid+1
    else:
        high = mid

    return pivot(arr, low, high)


def p9():
    # Problem 9 : Find pivot in an sorted and rotated array

    # Statement : given a sorted and rotated array of integers
    # return the pivot (minimum) element of the array

    # Logic : Using binary search
    # take 3 vars low = 0, high = size-1, mid = mid = (low+high)/2
    # create a recursive function pivot()
    # which will take an array low index and high index
    # add base condition
    # if l >= h return low as answer
    # calculate mid = (low+high)/2
    # check for below conditions
    # 1. arr[mid] >= arr[0]
    # 2. arr[mid] < arr[0]
    # if 1 is true update low = mid+1
    # if 2 is true update high = mid
    # after that call the pivot() function again

    # Code :
    # arr = [5, 6, 7, 7, 9, 1, 2, 3, 4]
    # arr = [5, 7, 7, 9, 1]
    # arr = [13, 14, 15, 16, 17, 18, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    arr = [13, 14, 15, 168, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    p = pivot(arr, 0, len(arr)-1)

    print(p)

    pass


def findRoot(n, ans, low, high):
    if low > high:
        return ans

    mid = low + int((high-low)/2)
    sq = mid*mid
    if sq == n:
        return mid
    elif sq < n:
        ans = mid
        low = mid+1
    else:
        high = mid-1

    return findRoot(n, ans, low, high)


def p10():
    # Problem 10 : find square root of n

    # Statement : given an integer n,
    # return square root of n

    # Logic : using recursive binary search
    # low = 0, high = n
    # create a recursive function findRoot(),
    # which will take an integer n, answer ans, low range and high range
    # and will return the square root of n
    # add base condition
    # if low > high return ans
    # find mid and check below conditions
    # 1. mid*mid == n;
    # 2. mid*mid < n;
    # 3. mid*mid > n;
    # if 1 is true return mid as answer
    # if 2 is true save mid as answer and update low = mid+1
    # if 3 is true update high = mid-1
    # after that call the findRoot() function again with all the arguments

    # Code :
    n = 43
    r = findRoot(n, -1, 0, n)

    print(r)

    pass


def allocate(arr, m, mid):
    students = 1
    pages = 0

    for i in range(len(arr)):
        if arr[i] > mid:
            return False

        if pages + arr[i] <= mid:
            pages += arr[i]
        else:
            students += 1
            pages = arr[i]

    if students > m:
        return False
    else:
        return True


def solve_bookallocation(arr, m, n, ans, low, high):
    if low > high:
        return ans

    mid = low + int((high-low)/2)

    # if mid is a answer
    if allocate(arr, m, mid):
        ans = mid
        high = mid-1
    else:
        low = mid+1

    return solve_bookallocation(arr, m, n, ans, low, high)


def p11():
    # Problem 11 : Book allocation problem - https://www.codingninjas.com/codestudio/problems/allocate-books_1090540

    # Statement : given an array of n integers,
    # representing n number of book's pages,
    # and an integer m denoting number of students
    # the task is to allocate books in m students such that
    # 1. all books should be allocated
    # 2. every student should have atleast one book
    # 3. book allocation should be in contiguous manner
    # books should be allocated such that maximum number of pages,
    # allocated to a student should be minimum

    # Logic : using recursive Binary Search
    # first find the search space
    # in worst case low can be maximum number of pages of books,
    # and high can be sum of all pages
    # create a function solve_bookallocation(),
    # which will take array of books,
    # number of total students
    # answer ans (initially ans = -1)
    # low index and high index
    # add base condition
    # if low > high return ans
    # find mid and check if it can be a solution or not
    # if it is a solution save it as ans = mid and update high = mid-1
    # else update low = mid+1
    # to check wether mid is a solution or not
    # create a function allocate(),
    # which will take array of books pages
    # number of students
    # allocate mid number of pages to m students
    # initialise students = 1 
    # allocated_pages = 0
    # traverse the array of pages count of books from i = 0 i < size_of_array 
    # check if arr[i] > mid
    # if true return false 
    # check if allocated_pages + arr[i] < mid
    # if true then add arr[i] in allocated_pages 
    # else update students count by 1 
    # and pages = arr[i]
    # after this check if total count of students is bigger than the given number of students 
    # if true return false 
    # else return true 

    # Code :
    # arr = [21, 22, 40, 12, 45, 60]
    # arr = [5, 17, 100, 11]
    # m = 4
    # arr = [12, 34, 67, 90]
    # m = 2
    # arr = [25, 46, 28, 49, 24]
    # m = 4
    arr = [10, 10, 20]
    m = 2

    n = len(arr)

    ans = -1

    low = 0
    high = 0
    for elements in arr:
        if elements > low:
            low = elements
        high += elements

    ans = solve_bookallocation(arr, m, n, ans, low, high)

    print(ans)
    pass


if __name__ == "__main__":
    # Lecture 33 : Recursion III Binary search

    # p1()

    # p2()

    # p3()

    # p4()

    # p5()

    # p6()

    # p7()

    # p8()

    # p9()

    # p10()

    # p11()

    pass
