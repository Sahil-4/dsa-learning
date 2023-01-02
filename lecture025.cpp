#include <iostream>

using namespace std;

void p1() {
    // p1 : Explain pointers

    // Pointers : pointers are variables that are used to store address of other variables

    int n = 5; // this creates a block on a address with value 5

    // Symbol table : data structure created and maintained by the compiler
    // it keeps track of scope and bindings of names and other information about
    // variables, function names, classes, objects etc.
    // it maps different variables, functions, classes, objects with a unique address

    cout << n << endl; // this will check the address then go to that address and take value from there then return value to cout function

    // & - address of operator
    cout << &n << endl; // this will print the address of n

    // pointers : are used to store address of variables

    // declaration of pointers
    // int *p; // this is a bad practice because now we have a garbage value or address in p

    // declaration and initialisation of pointers
    int *p = &n; // datatype *variable_name = &variable_name;

    cout << p << endl; // this will print the address of n

    cout << *p << endl; // this will print value of n
    // above * is derefrence operator

    // we can also modify the value of n using pointer
    *p = 1;

    cout << *p << endl;

    // this change will also reflect on n
    // so if we print the value of n
    cout << n << endl;
    // we can see that value of n is also changed

    // this same will happen if we change value of n
    n = 5;
    // this will also reflect on *p
    cout << *p << endl;
    // as *p is just pointing to the address where n is

    // type of pointer [datatype *ptr] will always be same as the variable which you want to store in it
    // if we have to store an address where char is stored so we have to use char pointer
    char ch = 'A';
    char *p2 = &ch;

    // copy pointers
    int x = 5;

    int *y = &x;
    int *z = y;

    cout << "Address of y : " << y << endl;
    cout << "Address of z : " << z << endl;
    cout << "Value of y : " << *y << endl;
    cout << "Value of z : " << *z << endl;

    z = z + 1; // this will go to next location (or memory block)
    cout << *z << endl;

    z = z - 1; // this will go to prev location (or memory block)
    cout << *z << endl;
}

int main() {
    // Lecture 25 : Pointers

    // p1();

    // To learn more about pointers visit below links 
    // - https://www.codingninjas.com/codestudio/guided-paths/pointers
    // - https://www.geeksforgeeks.org/c-pointers/

    return 0;
}
