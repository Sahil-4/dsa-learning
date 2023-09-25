
def reverse(strr, i, j):
    # for p1()
    if i >= j:
        return strr

    strr = strr[:i] + strr[j:j+1] + strr[i+1:j] + strr[i:i+1] + strr[j+1:]
    return reverse(strr, i+1, j-1)


def p1():
    # Problem 1 : Reverse the String - https://www.codingninjas.com/codestudio/problems/reverse-the-string_799927

    # Statement : given a string str,
    # reverse the str

    # Logic : using recursion
    # make a recursive function reverse()
    # which takes 3 arguments
    # string strr, int low_index, int high_index
    # inside reverse() add base conditon
    # if low_index > high_index return strr
    # processing part :
    # swap strr[i] with strr[j]
    # then recursive relation :
    # increament low_index and decreament high_index by 1
    # and call reverse function again with strr, low_index and high_index
    # as a reture statement

    # Code
    strr = "abcde"
    rev = reverse(strr, 0, 4)
    print(rev)

    strr = "abcd"
    rev = reverse(strr, 0, 3)

    strr = "a"
    rev = reverse(strr, 0, 0)

    strr = "ab"
    rev = reverse(strr, 0, 1)

    strr = ""
    rev = reverse(strr, 0, 0)


def checkPalindrome(binary, i, j):
    # for p2()
    if i >= j:
        return True

    if binary[i] != binary[j]:
        return False

    return checkPalindrome(binary, i+1, j-1)


def returnBinary(binary, n):
    # for p2()
    if n == 0:
        return binary

    bit = n & 1
    binary.insert(0, bit)
    n = n >> 1

    return returnBinary(binary, n)


def p2():
    # Problem 2 : Check If Binary Representation of a Number is Palindrome - https://www.codingninjas.com/codestudio/problems/check-palindrome_920555

    # Statement : You are given an integer ‘N’.
    # find whether the binary representation of integer ‘N’
    # is palindrome or not.
    # A palindrome is a sequence of characters
    # that reads the same backward as forward.

    # Logic : using recursion
    # first convert number to binary[]
    # then check if binary is palindrome or not
    # to convert a number into binary
    # create a function returnBinary()
    # which takes a list/arr and a number
    # and return list of binary bits
    # inside returnBinary() function
    # add base condition
    # if number == 0 simply return list/arr of bits
    # processing part
    # get bit from number and insert it at the very beginning of array/list
    # after that right shift the number 1 time
    # then call returnBinary() function with required arguments
    # after getting binary bits check if this array/list is palindrome or not
    # create a function checkPalindrome()
    # which will take an array/list of bits
    # and two int indexes low and high
    # inside checkPalindrome() function add base condition
    # if i >= j simply return true
    # processing part :
    # check arr[i] != arr[j]
    # if true return false
    # else increase i and
    # decrease j by 1
    # then call checkPalindrome() function
    # with required arguments

    # Code
    n = 2
    binary = returnBinary([], n)
    if checkPalindrome(binary, 0, len(binary)-1):
        print(f"binary representation of {n} is palindrome")
    else:
        print(f"binary representation of {n} is not palindrome")


def power(a, b):
    # for p3()
    if b == 0:
        return 1
    if b == 1:
        return a

    ans = power(a, int(b/2))

    if b & 1:
        return a * ans * ans
    else:
        return ans * ans


def p3():
    # Problem 3 : fint a^b

    # Statement : given two integers a and b
    # find a ^ b and return that

    # Logic : using recursion
    # power(a, b) = power(a, int(b/2)) * power(a, int(b/2)), if b is even and
    # power(a, b) = a * power(a, int(b/2)) * power(a, int(b/2)), if b is odd
    # create a recursive function power(),
    # which will take two integer arguments a and b
    # add base conditions
    # if b == 0 return 1
    # if b == 1 return a
    # recursive relation
    # intialise int ans = power(a, int(b/2))
    # check if b is odd or even
    # if b is even
    # return ans * ans
    # and if b is odd
    # return ans * ans * a

    # Code
    a = 5
    n = 10

    p = power(a, n)
    print(p)


def sortBubble(arr, n):
    # for p4()
    if n == 0 or n == 1:
        return arr

    for i in range(n-1):
        if arr[i] > arr[i+1]:
            temp = arr[i+1]
            arr[i+1] = arr[i]
            arr[i] = temp

    return sortBubble(arr, n-1)


def p4():
    # Problem 4 : Implement bubble sort using

    # Statement : given an array/list of integers
    # sort that array using recursive bubble sort

    # Logic :
    # create a recursive function sortBubble(arr[], int n)
    # add base case if n == 0 or n == 1 return arr
    # run a loop from i = 0 to i < n-1
    # swap arr[i] with arr[i+1] if they are in wrong order
    # after placing one element at its correct place
    # make a recursive call
    # sortBubble(arr, n-1)

    # Code :
    arr = [5, 2, 1, 7, 8, 6, 2, 0, 5]
    size = len(arr)

    arr = sortBubble(arr, size)

    print(arr)


if __name__ == "__main__":
    # Lecture 34 : Recursion IV Strings

    # p1()

    # p2()

    # p3()

    # p4()

    pass
