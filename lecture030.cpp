#include <iostream>

using namespace std;

// defining a macro that holds value of PI 
#define PI 3.14159

// another macro to calculate the area of a circle 
#define AREA(r) (PI * (r*r))


void p1() {
    // p1 : Macros 

    // Macros : a peice of code in a program that is replaced by the macro 

    // a macro is a pre-defined entity 
    // it can a variable that stores value of PI 
    // or can be a funtion to calculate minimum of two numbers 
    // macro is used to replace the repeatitive code 

    int r = 5;
    double ar = AREA(r);

    // using macros 
    cout << PI << endl;
    cout << ar << endl;
}

void p2() {
    // p2 : Types of macros 

    // Types of macros :

    // 1. Object-like Macros - 
    #define VAL 5 

    // using 
    cout << VAL << endl;

    // 2. Chain Macros - 
    #define first second
    #define second 500 

    // using 
    cout << second << endl;
    cout << first << endl;

    // 3. Multi-line Macros - 
    #define ELE 1, \
                2, \
                3, \
                4, \
                5

    int arr[] = { ELE };

    cout << *(arr+3) << endl; // element at index 3 

    // 4. Function-like Macro - 
    #define min(a, b) (((a) < (b)) ? (a) : (b))

    int a = 5;
    int b = 1;
    cout << "min of " << a << " and " << b << " is " << min(a, b);
}

// global variable 
// int n = 45;
// any function can access this 

void p3() {
    // p3 : Global variables 

    // Local variables : variables that are limited to a block or scope 

    {
        int n = 4; // local variable limited to this scope {} only 
        cout << n << endl;
    }

    // cout << n << endl; // n is not defined 

    // Global variables : variables that are defined globally in a program 
    // any function or entity in the program can access that variaable 
    // we can use global variable to share values between different function or entities 

    // but using global variable is a BAD PRACTICE 
    // as any function can modify value of that variable 
    // it may lead us to some problems 

    // cout << n << endl; // defined in global scope 
}

inline int sum(int a, int b) {
    return a+b;
}

void p4() {
    // p4 : inline functions 

    // inline functions are used to reduce 
    // the function calls and usage of recources 
    
    // suppose if we are calling a function so many times 
    // it will also use memory and other resources so many times 

    // to avoid this we can use inline function 
    // if we have any function of 1 to 3 lines of code 
    // then we can convert it to inline function 

    // so that every time we called that function in our program 
    // will be get replaced by the function code 
    // before compiling 

    // to make a function inline just put keyword inline 
    // before the signature or definition of that function 
    
    int n = sum(5, 7);
    cout << n << endl;
}

// function with default argument 
void print(int *arr, int size, int start=0) {
    for (start; start < size; start++) {
        cout << arr[start] << " ";
    }
    cout << endl;
}

void p5() {
    // p5 : Default arguments 

    // when we create any function 
    // it can have some parameters 
    // but all the parameters
    // may not be mandatory 
    // to solve this issue 
    // we can make some of its parameters optional 
    // by giving then a default value 

    // eg : 
    // void print(int arr[], int size, int start=0) { ... } 
    // above we have made start parameter as optional 
    // now we can call that function with or without giving third argument 

    int arr[] = {2, 5, 13, 45, 7, 5};
    int size = 6;

    print(arr, size, 0);
    print(arr, size, 2);
    print(arr, size);

    // NOTE : except the rightmost argument 
    // we can only set default arguments 
    // if the rightmost argument is also optional 
}

void p6() {
    // p6 : Constant variables 

    // Constant variables : constant variables are used to store values 
    // that we dont want to change any how 

    // to declare a constant variable we use const keyword before variable declaration 
    const int a = 13;

    cout << a << endl;

    // a = 5; // this will give error 

    // we cannot change the value of constant variables 
}

int main() {
    // Lecture 30 : Macros, Global variables, Inline Functions, Default Arguments 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // To learn more follow below links 
    // - https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/ 
    // - https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381150 
    // - https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381154 
    // - https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381157 

    return 0;
}