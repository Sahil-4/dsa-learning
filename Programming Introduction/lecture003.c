#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


int main() {
    // Lecture 3 : Conditionals and Loops 

    // Print output on screen 
    printf("Hello 👋\n");

    // take input from user 
    int n;
    printf("Please enter a number : ");
    // scanf("%d", &n);

    // print value of n 
    printf("Your number is %d\n", n);

    // %d : for integer 
    // %c : for char 
    // %f : for float 
    // etc 

    // conditionals statements : perform actions on the basis of a condition 
    // loops : perform any task or action repeatedly 

    // if statement 
    if (1 < 2) {
        printf("1 is less then 2\n");
    }

    // multiple if statements 
    if (1 < 2) {
        printf("1 is less then 2\n");
    }
    if (1 > 2) {
        printf("1 is not less then 2\n");
    }
    
    // if else statement 
    if (1 > 2) {
        printf("1 is not less then 2\n");
    } else {
        printf("1 is less then 2\n");
    }

    // if else if else statement 
    if (1 == 2) {
        printf("1 is equal to 2\n");
    } else if (1 < 2) {
        printf("1 is less then 2\n");
    } else if (1 > 2) {
        printf("1 is bigger then 2\n");
    } else {
        printf("something else\n");
    }

    // nested is else 
    int age = 12;
    if (age > 125 || age < 1) {
        printf("invalid age");
    } else if (age < 21) {
        if (age > 18) {
            printf("You are young");
        } else if (age < 18 && age > 12) {
            printf("You are teenage");
        } else if (age < 12) {
            printf("You are a child");
        }
    } else {
        if (age > 60) {
            printf("You are old");
        } else {
            printf("You are adult");
        }
    }

    // while loop : 
    n = 1;
    while (n <= 5) {
        printf("%d ", n);
        n++;
    }
    printf("\n");

    // for loop : 
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");


    // 1. program to tell whether n is positive, negative or zero 
    printf("Enter value of n : ");
    // scanf("%d", &n); // take input of n 

    if (n > 0) {
        printf("n is positive\n");
    } else if (n < 0) {
        printf("n is negative\n");
    } else {
        printf("n zero\n");
    }

    // 2. check in which category char ch lies in 
    //   i) a-z : 97-122 
    //  ii) A-Z : 65-90 
    // iii) 0-9 : 48-57 

    char ch = 'F';
    if (ch >= 97 && ch <= 122) {
        printf("Belongs to [a-z] group\n");
    } else if (ch >= 65 && ch <= 90) {
        printf("Belongs to [A-Z] group\n");
    } else {
        printf("Belongs to [0-9] group\n");
    }

    // 3. calculate sum of n natural numbers using while loop 
    n = 10;
    int i = 0;
    int sum = 0;
    while (i <= n) {
        sum += i;
        i++;
    }
    printf("sum of %d natural numbers is %d\n", n, sum);

    // 4. check if n is prime or not 
    n = 13;
    int flag = -1;
    for (int i = 2; i < n; i++) {
        if (n%i == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("%d is not prime number", n);
    } else {
        printf("%d is prime number", n);
    }

    return 0;
}
