
def reach(src, dest):
    # for p1
    # reach to dest from src

    if src == dest:
        # we have reached to destination
        print("We're home")
        return

    # going to next source
    reach(src+1, dest)


def p1():
    # p1 : Recursion quick recap

    # Recursion : when a function calls itself, directly or in-directly

    # we use recursion to solve a problem by breaking it into parts

    # Components of recursive function :
    # 1. Base condition
    # 2. Processing
    # 3. Recursive relation

    # Why base condition is important :
    # to stop recursion at some point of time
    # else it will keep caliing itself and keep using resources

    # in recursion we solve a single part of problem and rest will be get solved by recursive calls

    # example :
    src = 0  # we're at src
    dest = 13  # we have to reach dest

    # we'll keep calling reach function till we have not reached dest
    reach(src, dest)


def fibo(n):
    # for p2
    # find fibbonacci of n

    # base case 1
    if n < 0:
        return -1

    # base case 2
    if n == 0 or n == 1:
        return n

    # recurrence relation
    a = fibo(n-1)
    b = fibo(n-2)

    # processing
    return a + b


def fibo_loop(n):
    # for p2
    # Extra homework question
    if n >= 0:
        print("0th fibbonacci is 0")

    if n >= 1:
        print("1st fibbonacci is 1")

    a = 0
    b = 1
    c = a + b

    i = 2
    while (i <= n):
        print(f"{i}th fibbonacci is {c}")
        a = b
        b = c
        c = a + b
        i += 1


def p2():
    # Problem 1 : LC 509 Fibonacci Number - https://leetcode.com/problems/fibonacci-number/

    # Statement : The Fibonacci numbers, commonly denoted F(n) form a sequence,
    # called the Fibonacci sequence,
    # such that each number is the sum of the two preceding ones,
    # starting from 0 and 1. That is,
    # F(0) = 0, F(1) = 1
    # F(n) = F(n - 1) + F(n - 2), for n > 1.
    # Given n, calculate F(n).

    # Logic : using recursion
    # make a function fibo,
    # which takes an integer n as argument
    # and return nth fibbonacci
    # inside function check if n == 0 or n == 1
    # if true simply return n
    # else make two variable a = fibo(n-1)
    # and b = fibo(n-2)
    # and lastly return a + b

    # Code :
    n = 6
    f = fibo(n)
    print(f"{n}th fibbonacci is : {f}")

    # fibo_loop(n)


def count_climb(src, dest):
    # for p3
    if src > dest:
        return 0

    if src == dest:
        return 1

    a = count_climb(src+1, dest)
    b = count_climb(src+2, dest)

    return a + b


def p3():
    # Problem 2 : Count Ways To Reach The N-th Stairs - https://www.codingninjas.com/codestudio/problems/count-ways-to-reach-nth-stairs_798650

    # Statement : You have been given a number of stairs.
    # Initially, you are at the 0th stair,
    # and you need to reach the Nth stair.
    # Each time you can either climb one step or two steps.
    # You are supposed to return the number of distinct ways
    # in which you can climb from the 0th step to Nth step.

    # Logic : using recursion
    # make a function count_climb()
    # which takes two integer arguments src and dest
    # inside function check for base conditions
    # 1. if src > dest:
    # return 0 if true
    # 2. if src == dest:
    # return 1 if true
    # otherwise
    # make two variable a = count_count(src+1, dest) took one step
    # and b = count_count(src+2, dest) took two step
    # then lastly return a + b

    # Code :
    n = 1  # output : 1
    n = 2  # output : 2
    n = 3  # output : 3
    n = 4  # output : 5
    n = 8  # output : 34
    n = 10  # output : 89
    n = 0  # output : 1
    n = -5  # output : 0

    ways = count_climb(0, n)
    print(f"there are {ways} ways to climb {n} number of stairs")


def sayCounting(x, arr_counting):
    # for p4
    if x <= 9:
        print(arr_counting[x], end=" ")
        return

    d = x % 10
    x = int(x/10)
    sayCounting(x, arr_counting)
    print(arr_counting[d], end=" ")


def p4():
    # Problem : say digit

    # Statement : given a digit
    # get all digits from it
    # and print it in english
    # Example : 123
    # 1 : One
    # 2 : Two
    # 3 : Three

    # Logic : using recursion
    # create an array for english counting arr_counting[]
    # make a function sayDigit()
    # which takes a number x and a array of countings
    # inside function write a base case
    # if x <= 9
    # simply print arr[x]
    # otherwise
    # remove the last digit of x and store it into d
    # then call itself with remaining number
    # and lastly print arr[d]

    # Code :
    arr_counting = ["Zero", "One", "Two", "Three", "Four", "Five", "Six"]
    x = 512

    print(x)
    sayCounting(x, arr_counting)


if __name__ == "__main__":
    # Lecture 32 : Recursion II

    # p1()

    # p2()

    # p3()

    # p4()

    pass
