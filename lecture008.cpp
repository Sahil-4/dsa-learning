#include <iostream>

using namespace std;

void p1() {
    // Demonstrate switch statement use 

    int n = 5;

    switch (n) {
    case 0:
        /* code for case 0 */
        printf("0\n");
        break;
    case 1:
        /* code for case 0 */
        printf("1\n");
        break;
    case 2:
        /* code for case 0 */
        printf("2\n");
        break;
    case 5:
        /* code for case 0 */
        printf("5\n");
        break;
    case 10:
        /* code for case 0 */
        printf("10\n");
        break;
    default:
        printf("no match found\n");
        break;
    }
}

void p2() {
    // Create a mini calculator 

    int a, b;

    cout << " Enter the value of a " << endl;
    cin >> a;

    cout << " Enter the value of b " << endl;
    cin >> b;

    char op;
    cout << " Enter the Operation you want to perform" << endl;
    cin >> op;

    switch(op) {
        case '+': cout << (a+b) << endl; 
                  break;

        case '-': cout << (a-b) << endl;
                  break;  

        case '*': cout << (a*b) << endl;
                  break;

        case '/': cout << (a/b) << endl;
                  break;

        case '%': cout << (a%b) << endl;
                  break;

        default: cout << "Please enter a valid Operation " << endl;
    }
}

void p3() {
    // demonstration on function 

    // this is a function to print hello 👋

    cout << "hello 👋" << endl;
}

void p4() {
    // check for odd and even 

    int n;
    cin >> n;

    if (n&1) {
        cout << "odd" << endl;
    } else {
        cout << "even" << endl;
    }
}

int factorial(int n) {
    // helper function for p5()
    int fact = 1;

    for(int i = 1; i<=n; i++ ) {
        fact = fact * i;
    }

    return fact;
}

void p5() {
    // find nCr 

    // given n r 

    int n, r;

    n = 5, r = 3; // out : 10 
    n = 5, r = 5; // out : 1 
    n = 3, r = 5; // out : 0 

    int num = factorial(n);

    int denom = factorial(r) * factorial(n-r);

    cout << num/denom << endl;
}

void p6() {
    // print counting from 1 to n 

    int n = 13;
    int i = 1;

    while (i <= n) {
        cout << i++ << " ";
    }
    cout << endl;
}

void p7() {
    // check for prime numbers 

    int n;
    n = 13;

    // checking for prime 
    for(int i = 2; i < n; i++){
       if(n % i == 0) {
           //divide hogya h , not a prime no.
           cout << "not prime" << endl;
           return; // end the function 
        }
   }

   cout << "prime number" << endl;
}

int add(int a, int b) {
    // Helper function for p8()
    return a+b;
}

void p8() {
    // demonstrating function call stack 

    int a, b;
    a = 5, b = 7;

    int sum = add(a, b);

    // call stack 
    // main() => p8() => add() => p8() => main() 

    cout << sum << endl;
}

int modify(int n) {
    // modify 
    n = 13; // here we have changed the value of n 
}

void p9() {
    // demo of pass by value 

    int n;
    n = 5; 

    modify(n);

    // here we will not see any change 
    // because we pass only a copy of value 
    cout << n << endl;
}

int p10(int n) {
    // ap : 3n + 7 
    // given : n  
    // calculate the nth term or 3n + 7
    
    return (3 * n) + 7;
}

int p11(int a, int b) {
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

int p12(int n) {
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

void p13(int amount) {
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
    // Lecture 8 : Switch statements and functions 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();
    
    // p8();

    // p9();

    // printf("%d", p10(5));

    // printf("%d", p11(0, 0));

    // printf("%d\n", p12(4));

    // p13(512);

    return 0;
}
