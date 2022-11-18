#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    int a, b;
    a = 10;
    if (++a) {
        printf("%d\n", b);
    } else {
        printf("%d\n", ++b);
    }

    printf("%d\n", a);
}

void p2() {
    int a = 1, b = 2;
    if (a-- > 0 || ++b > 2) {
        printf("Stage 1 - inside if\n");
    } else {
        printf("Stage 2 - inside else\n");
    }

    printf("%d %d\n", a, b);
}

void p3() {
    int n = 3;
    printf("%d", 25 * (++n));
}

void p4() {
    int a = 1, b = a++, c = ++a;
    printf("%d %d", b, c);
}

void p5() {
    int a = 1, b = 2;
    if (a-- > 0 || ++b > 2) {
        printf("Stage 1 - inside if\n");
    } else {
        printf("Stage 2 - inside else\n");
    }

    printf("%d %d\n", a, b);
}

void p6() {
    // fibbonacci series 
    int a = 0;
    int b = 1;
    int next, n;
    
    n = 10;

    printf("%d %d ", a, b);
    for (int i = 2; i <= n; i++) {
        next = a + b;
        printf("%d ", next);

        a = b;
        b = next;
    }
}

void p7() {
    for (int i = 0; i <= 5; i++) {
        printf("%d ", i);
        i++;
    }
}

void p8() {
    for (int i = 0; i <= 5; i--) {
        printf("%d ", i);
        i++;
    }
}

void p9() {
    for (int i = 0; i <= 15; i += 2) {
        printf("%d ", i);

        if (i % 1) {
            continue;
        }

        i++;
    }
}

void p10() {
    for (int i = 0; i < 5; i++) {
        for (int j = i; j <= 5; j++) {
            printf("[%d,%d] ", i, j);
        }
        printf("\n");
    }
}

void p11() {
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i + j == 10) {
                break;
            }

            printf("[%d,%d] ", i, j);
        }
        printf("\n");
    }
}

void p12() {
    // leetcode problem : 1218 - https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
    // Problem Statement : Given an integer number n, 
    // return the difference between the product of its digits and the sum of its digits.
    
    // take last digit from int 
    // multiply by prod
    // add in sum 
    // perform above tasks till n != 0
    // finally print the answer 

    int prod = 1;
    int sum = 0;
    
    int n = 1201;

    while (n > 0) {
        int d = n % 10;
        prod *= d;
        sum += d;
        
        n /= 10;
    }
    
    printf("%d", prod - sum);
}

void p13() {
    // leetcode problem : 191 - https://leetcode.com/problems/number-of-1-bits/
    // Problem Statement : Write a function that takes an unsigned integer 
    // and returns the number of '1' bits it has (also known as the Hamming weight).

    // convert n into binary 
    // check last bit for 1
    // if last bit is 1 increament count by 1 
    // perform operation while n != 0 

    int n = 11;
    int c = 0;

    while (n != 0) {
        if (n&1) {
            c++;
        }

        n = n>>1;
    }
}


int main() {
    // lecture 5 problem solutions 
    // p1();
    // p2();
    // p3();
    // p4();
    // p5();
    // p6();
    // p7();
    // p8();
    // p9();
    // p10();
    // p11();
    // p12();

    // leetcode problems 
    // p13();
    // p14();


    return 0;
}
