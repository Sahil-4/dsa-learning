#include <iostream>

using namespace std;


void update1(int n) {
    n++;
}

void update2(int &n) {
    n++;
}

// BAD PRACTICE 
// int &giveReference() {
//     int n = 45;

//     return n;
// }

void p1() {
    // p1 : Explain reference variable 
    
    // Reference variable : when a variable points to an already created memory, 
    // it is called as reference variable.

    // creating reference variable 
    int i = 5; // integer variable 
    int &r = i; // integer reference variable 

    // now we have same memory with two different names 

    // because i and r are pointing to same memory address changes made on i will also be reflected on r 

    cout << i << endl;
    cout << r << endl;

    i++;
    cout << i << endl;
    cout << r << endl;

    r++;
    cout << i << endl;
    cout << r << endl;

    cout << &i << endl;
    cout << &r << endl;

    // why reference variable :
    // whenever we want to pass variables as reference, 
    // we can make a function that takes a reference variables as one of its parameters, 
    // and if we make any changes on that reference variable inside the function, 
    // that change will also be reflected outside the function 

    int n = 5;
    // update1(n);
    update2(n);

    cout << n << endl;

    // we can also make a function to return a reference variable 
    // but it is a BAD PRACTICE as all the variables declared inside the function 
    // will be get destroyed after return of function 
    // the same thing will apply on pointers also 

    // BAD PRACTICE
    // int &x = giveReference();
    // cout << x << endl;
}

void p2() {
    // p2 : Variable size array 

    // int size;
    // cin >> size;

    // int arr[size]; // BAD PRACTICE 
    
    // Why ? 
    // because when a program runs it is allocated some memory HEAP > STACK 
    // when we do this : int arr[size]; 
    // it allocates memory in stack for size integers 
    // but as we dont know size it may be possible 
    // that the memory of stack will not be enough to make array of given size 
    // which may lezd our program to crash 

    // How to solve this issue 
    // to solve this issue and make an array of variable size 
    // we can use Heap memory 
    // we can allocate some memory in Heap 
    // and then store data there 
    // to allocate memory inside Heap 
    // we have to use keyword new 

    int *n = new int; // allocating memory in Heap 
    // as new keyword return the memory address 
    // we used pointer to store that 

    cout << *n << endl; // garbage value 

    *n = 12;
    cout << *n << endl;

    // to make an array of variable size 
    int size;
    cin >> size;

    int *arr = new int[size]; // this is how we can allocate memory for size integers 

    // initialising array 
    for (int i = 0; i < size; i++) {
        *(arr+i) = i*i;
        // arr[i] = i*i; // we can also do this 
    }

    // printing values 
    for (int i = 0; i < size; i++) {
        cout << *(arr+i) << " ";
    }
    cout << endl;
}

void p3() {
    // p3 : Static and Dynamic 

    // Static memory allocation  : allocating memory in stack 
    int a = 5;

    // Dynamic memory allocation : allocating memory in heap 
    int *b = new int;
    *b = 5;

    // it also has difference in memory size 
    // Dynamic memory allocation memory takes 8byte more 
    // then Static memory allocation 
    // to store pointer 
    // memory allocation is happens in Heap 
    // but poimter is always stored in Stack 

    // while using Dynamic memory allocation 
    // we have to free up memory after using it with delete keyword 

    delete b; // deleting or freeing up or deallocating memory 

    // if we do not deallocate memory 
    // than it might be possible that 
    // out program will use all the Heap memory 
    // and will crash at some point of time 
}

int main() {
    // Lecture 28 : Reference variable, Static and Dynamic memory allocation 

    // p1();

    // p2();

    // p3();

    // Check out below links to learn more about pointers and dynamic memory allocation 
    // - https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118785/offering/1381101
    // - https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/

    return 0;
}
