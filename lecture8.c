#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int p1(int n) {
    // ap : 3n + 7 
    // given : n  
    // return the nth term or 3n + 7
    
    return (3 * n) + 7;
}

int p2(int a, int b) {
    // given : a, b 
    // return all set bits in a and b 
    int count = 0;

    while (a != 0 || b != 0) {
        if (a & 1) {
            count++;
        }
        if (b & 1) {
            count++;
        }
        
        a = a >> 1;
        b = b >> 1;
    }

    return count;
}

int p3(int n) {
    // logic to get nth fibbonacci
    // 0 1 1 2 3 5 8 13 21 
    int a = 0, b = 1; // first 2 fibbonaccis 
    int fib = 1;

    if (n < 0) {
        return 0;
    }

    if (n == 0 || n == 1) {
        return n;
    }

    for (int i = 2; i <= n; i++) {
        fib = a + b;

        a = b;
        b = fib;
    }
    
    return fib;
}

void p4(int amount) {
    // calculate number of notes 
    // given number n 
    // return the total numbers of notes of 
    // notes : 100, 50, 20, 20 and 1 
    
    int hundreds = amount/100;
    amount = amount%100;

    int fifty = amount/50;
    amount = amount%50;

    int twenty = amount/20;
    amount = amount%20;

    int one = amount;

    printf("notes of hundred : %d\nnotes of fifty : %d\nnotes of twenty : %d\nnotes of one : %d\n", hundreds, fifty, twenty, one);
}

int main() {
    // Lecture 8 : homework 
    

    // printf("%d", p1(5));

    // printf("%d", p2(0, 0));

    // printf("%d\n", p3(i));

    p4(25);


    return 0;
}