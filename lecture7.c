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
    
    int n = 123;
    int ans = 0; // for final answer 
    
    // reversing n 
    while (n != 0) {
        int d = n%10;
        
        // if reversed goes out of range 
        if ((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
            printf("%d", 0);
            break;
        }
        
        ans = (ans * 10) + d;
        n = n / 10;
    }
    
    printf("%d", ans);
}

void problem2() {
    // Problem : 1009. Complement of Base 10 Integer
    // Problem statement : Given an integer n, return its complement.
    // The complement of an integer is the integer you get,
    // when you flip all the 0's to 1's 
    // and all the 1's to 0's in its binary representation.

    int n = 0;
    
    if (n == 0) {
        printf("1");
        return;
    }

    int temp = ~n;
    int mask = 0;

    while (n != 0) {
        n = n >> 1;
        mask = mask << 1;
        mask = mask | 1;
    }
    
    printf("%d", temp & mask);
}

void problem3() {
    // Problem : 231. Power of Two 
    // Problem statement : Given an integer n, 
    // return true if it is a power of two. 
    // Otherwise, return false.

    int n = 0;
    int m = 1;
    
    while (n > 1) {
        if (n == m) {
            printf("true");
            return;
        }

        n = n >> 1;
        m = m << 1;
    }
    
    printf("false");
}

int main() {
    // lecture 7 : Leetcode problem solving 
    // problem1();
    // problem2();
    problem3();

    return 0;
}