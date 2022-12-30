#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void problem1() {
    // Problem : 7. Reverse Integer - https://leetcode.com/problems/reverse-integer/

    // Problem statement : Given a signed 32-bit integer x, 
    // return x with its digits reversed. 
    // If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], 
    // then return 0.

    int n = 123; // output : 321 
    n = 321; // output : 123 
    n = 655554445; // output : 544455556 
    n = 544455556; // output : 655554445 
    n = 1534236469; // output : 0 

    //code here 
    int ans = 0; // for final answer 

    // reversing n 
    while (n != 0) {
        // if reversed goes out of range 
        if ((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
            printf("%d", 0);
            return;
        }

        int d = n%10;
        ans = (ans * 10) + d;
        n = n / 10;
    }

    printf("%d", ans);
}

void problem2() {
    // Problem : 1009. Complement of Base 10 Integer - https://leetcode.com/problems/complement-of-base-10-integer/ 

    // Problem statement : Given an integer n, return its complement.
    // The complement of an integer is the integer you get,
    // when you flip all the 0's to 1's 
    // and all the 1's to 0's in its binary representation.

    int n;
    n = 0; // out : 1 
    n = 4; // out : 3 
    n = 5; // out : 2 

    if (n == 0) {
        printf("1");
        return;
    }

    int not_of_n = ~n;
    int mask = 0;

    while (n != 0) {
        n = n >> 1;
        mask = mask << 1; // xxxxxxxx x 
        mask = mask | 1; // xxxxxxxxx 1 
    }

    printf("%d", not_of_n & mask);
}

void problem3() {
    // Problem : 231. Power of Two - https://leetcode.com/problems/power-of-two/ 

    // Problem statement : Given an integer n, 
    // return true if it is a power of two. 
    // Otherwise, return false.

    int n = 32;
    int m = 1;

    for (int i = 0; i < 31; i++) {
        if (m == n) {
            printf("true\n");
            return;
        }
        m = m << 1;
    }

    printf("false");
}

int main() {
    // lecture 7 : Leetcode problem solving 

    // problem1();

    // problem2();

    // problem3();

    return 0;
}