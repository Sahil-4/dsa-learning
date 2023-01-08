
def facto(n):
    # for p1
    if n == 1:
        return 1

    # return n * (n-1)!
    return n * facto(n-1)


def p1():
    # p1 : Recursion explain

    # Recursion : recursion is when a function calls itself directly or in-directly

    # we use recursion to solve problems thzt can be solved by breaking into parts

    # like : finding 2^n or factorial of n

    # finding 2^n
    # 2^n = 2 x 2 x 2 x ... x 2
    # 2^n = 2 x 2^(n-1)
    # so f(n) = 2 x f(n-1)

    # finding factorial of n
    # n! = n * (n-1)!
    # let n = 5
    # 5! = 5 x 4 x 3 x 2 x 1
    # or 5! = 5 x 4!
    # so f(n) = 5 x f(n-1)

    # in finding 2^n
    # base case is 2^0
    # and in finding factorial of n
    # base case is when n == 1
    # because we cant go ahead

    # in a recursive function also we have to give a base condtion,
    # where our function will stop calling itself
    # if we dont give base condition
    # our program will keep calling itself infinitely

    # write a recursive function to find factorial of n
    n = 3
    f = facto(n)
    print(f)

    # components of a recursive function
    # - base condition
    # - processing
    # - recursive relation (calling itself)

    # types of retursion
    # - Head Recursion : recursive relation before processing
    # - Tail Recursion : recursive relation after processing


def p2():
    # p2 : Recursive function call stack

    # function call stack for facto(n) from starting

    # initially we had main() in our call stack

    # we call p1
    # then we got main() -> p1()

    # from p1 we called facto(3)
    # now we have main() -> p1() -> facto(3)

    # then in facto() we checked condition for n == 1 which is false
    # so we call facto(n-1) which is facto(3-1) or facto(2)
    # now we have main() -> p1() -> facto(3) -> facto(2)

    # then again in facto() we checked condition for n == 1 which is again false
    # so again we call facto(n-1) which is facto(2-1) or facto(1)
    # now we have main() -> p1() -> facto(3) -> facto(2) -> facto(1)

    # then again in facto() we checked condition for n == 1 which is now true
    # so we returned 1
    # now we have main() -> p1() -> facto(3) -> facto(2)

    # now from facto(2) we will return 2 * 1, where 1 is facto(1)
    # from facto(3) we will return 3 * 2, where 2 is facto(2)

    # and after that all calls will be get destroyed after terminating return statement one by one
    # at the end we will cone at a position when we will only have
    # main() in our function call stack

    pass


def power(n):
    if n == 0:
        return 1

    return 2 * power(n-1)


def p3():
    # p3 : find 2^n using recursion

    # Statement : given an integer n
    # find 2's power n

    # Logic :
    # create a function power
    # which takes and return integer
    # inside function add base condition
    # if n == 0 simply return 1
    # else return 2 x power(n-1)
    # with power(n-1) we are calling power function

    n = 5
    ans = power(n)
    print(ans)
    pass


def writecounting1(n):
    # using Head recursion
    if n == 0:
        return

    writecounting1(n-1)

    print(n)


def writecounting2(n):
    # using Tail recursion
    if n == 0:
        return

    print(n)

    writecounting2(n-1)


def p4():
    # p4 : print 1 to n using recursion

    n = 5
    writecounting1(n)
    writecounting2(n)

    pass


if __name__ == "__main__":
    # Lecture 31 : Recursion

    # p1()

    # p2()

    # p3()

    # p4()

    # To learn more check out below links :
    # - https://www.geeksforgeeks.org/introduction-to-recursion-data-structure-and-algorithm-tutorials/
    # - https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380913

    pass
