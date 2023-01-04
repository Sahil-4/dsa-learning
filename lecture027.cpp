#include <iostream>

using namespace std;

void p1() {
    // p1 : Revisit

    // declaration and initialisation of a pointer
    int n = 1;
    int *ptr = &n;

    // we write datatype *var_name because
    // it tells us the datatype of value on which it is pointing
    // give idea about the memory size

    // when we initialise a variable int i = 1;
    // it creates a block at some address in memory
    // and store 1 at that address suppose xx700
    // when we initialise a pointer int *ptr = &n;
    // it also creates a block in memory at some address suppose xx1002
    // and stores the address of n which is xx700 at that address which is xx1002
    // and now we can make changes at memory address xx700
    // with the help of poimter ptr
}

void update(int **ptr_l2) {
    // update values of ptr_l2

    cout << "before values inside function" << endl;
    cout << "value of **ptr_l2 : " << **ptr_l2 << endl;
    cout << "value of *ptr_l2 : " << *ptr_l2 << endl;
    cout << "value of ptr_l2 : " << ptr_l2 << endl;
    cout << endl;

    // ptr_l2 = ptr_l2 + 1;
    // changes will reflect inside the function
    // but will not reflect outside this function

    // *ptr_l2 = *ptr_l2 + 1;
    // this will only change the value stored at ptr_l2 (address of ptr)
    // and this change will be also reflected outside this function
    // but on *ptr_l2 changes will also be reflected outside of this function

    // **ptr_l2 = **ptr_l2 + 1;
    // this will only change the value stored at *ptr_l2
    // and this change will reflect inside the function
    // and also outside the function

    cout << endl;
    cout << "after values inside function" << endl;
    cout << "value of **ptr_l2 : " << **ptr_l2 << endl;
    cout << "value of *ptr_l2 : " << *ptr_l2 << endl;
    cout << "value of ptr_l2 : " << ptr_l2 << endl;
}

void p2() {
    // p2 : Double Pointer

    // Double Pointer : pointer that points to another pointer
    // also called pointer to pointer

    int n = 1;
    int *ptr = &n;     // pointer
    int **ptr2 = &ptr; // double pointer

    /*
    // we can also do this
    int ***ptr_l3 = &ptr2;
    int ****ptr_l4 = &ptr_l3;
    int *****ptr_l5 = &ptr_l4;
    int ******ptr_l6 = &ptr_l5;
    // and so on
    // to create it just put an extra asterisk after the datatype(including *)

    // int *ptr3 = &ptr_l5; // this is not valid
    // int ******ptr_l6 = &ptr; // this is also not valid
    */

    // working with double pointers
    cout << "value of n : " << n << endl;       // will print value
    cout << "value of ptr : " << ptr << endl;   // will print value
    cout << "value of ptr2 : " << ptr2 << endl; // will print value

    cout << "address of n : " << &n << endl;       // will print address
    cout << "address of ptr : " << &ptr << endl;   // will print address
    cout << "address of ptr2 : " << &ptr2 << endl; // will print address

    cout << "value at " << ptr << " : " << *ptr << endl;     // will print value stored at ptr
    cout << "value at " << ptr2 << " : " << *ptr2 << endl;   // will print value stored at ptr2
    cout << "value at " << *ptr2 << " : " << **ptr2 << endl; // will print value stored at *ptr

    // different ways to print value of n
    n = 124;
    cout << "value of n by n : " << n << endl;
    cout << "value of n by ptr : " << *ptr << endl;
    cout << "value of n by ptr2 : " << **ptr2 << endl;
    // we can also modify values like this

    // different ways to print address of n
    cout << "address of n by n : " << &n << endl;
    cout << "address of n by ptr : " << ptr << endl;
    cout << "address of n by ptr2 : " << *ptr2 << endl;

    // trying to update values
    cout << endl;
    cout << "before values outside update function" << endl;
    cout << "value of n : " << n << endl;
    cout << "value of ptr : " << ptr << endl;
    cout << "value of ptr2 : " << ptr2 << endl;
    cout << endl;

    update(ptr2);

    cout << endl;
    cout << "after values outside update function" << endl;
    cout << "value of n : " << n << endl;
    cout << "value of ptr : " << ptr << endl;
    cout << "value of ptr2 : " << ptr2 << endl;
    cout << endl;
}

void update2(int *p) {
    // for MCQ 18
    *p = (*p) * 2;
}

void fun(int arr[]) {
    // for MCQ 19
    // Output : ?
    cout << arr[0] << " ";
}

void square(int *n) {
    // for MCQ 20
    *n = (*n) * (*n);
}

void increment(int **p) {
    // for MCQ 24
    ++(**p);
}

void Q(int z) {
    // for MCQ 30
    z += z;

    // Output : ?
    cout << z << " ";
}

void P(int *y) {
    // for MCQ 31
    int x = *y + 2;
    Q(x);
    *y = x - 1;

    // Output : ?
    cout << x << " ";
}

int f(int x, int *py, int **ppz) {
    // for MCQ 33
    int y, z;

    **ppz += 1;
    z = **ppz;
    *py += 2;
    y = *py;
    x += 3;

    // Output : ?
    return x + y + z;
}

void p3() {
    // p3 : Questions on Pointers

    // 1.
    /**
    int fst = 8;
    int sec = 18;
    int *ptr = &sec;
    *ptr = 8;

    // Output : ?
    cout << fst << " " << sec << endl;
    /**/

    // 2.
    /**
    int fst = 6;
    int *p = &fst;
    int *q = p;
    (*q)++;

    // Output : ?
    cout << fst;
    /**/

    // 3.
    /**
    int a = 8;
    int *p = &a;

    // Output : ?
    cout << (*p)++ << endl;
    cout << a << endl;
    /**/

    // 4.
    /**
    int *p = 0; // null pointer
    int a = 110;
    *p = a;

    // Output : ?
    cout << *p << endl;
    /**/

    // 5.
    /**
    int a = 8;
    int b = 11;
    int *c = &b;

    a = *c;
    *c = *c + 2;

    // Output : ?
    cout << a << " " << b << endl;
    /**/

    // 6.
    /**
    float a = 12.5;
    float b = 21.5;
    float *ptr = &a;

    (*ptr)++;
    *ptr = b;

    // Output : ?
    cout << *ptr << " " << a << " " << b << endl;
    /**/

    // 7.
    /**
    int arr[5];
    int *ptr;
    // Output : ?
    cout << sizeof(arr) << " " << sizeof(ptr) << endl;
    /**/

    // 8.
    /**
    int arr[] = {11, 21, 13, 14};
    // Output : ?
    cout << *(arr) << " " << *(arr+1) << endl;
    /**/

    // 9.
    /**
    int arr[6] = {11, 12, 31};
    // Output : ?
    cout << arr << " " << &arr << endl;
    /**/

    // 10.
    /**
    int arr[6] = {11, 21, 13};
    // Output : ?
    cout << (arr + 1) << endl;
    /**/

    // 11.
    /**
    int arr[6] = {11, 21, 31};
    int *p = arr;
    // Output : ?
    cout << p[2] << endl;
    /**/

    // 12.
    /**
    int arr[] = {11, 12, 13, 14, 15};
    // Output : ?
    cout << *(arr) << " " << *(arr + 3);
    /**/

    // 13.
    /**
    int arr[] = {11, 21, 31, 41};
    int *ptr = arr++;
    // Output : ?
    cout << *ptr << endl;
    /**/

    // 14.
    /**
    char ch = 'a';
    char* ptr = &ch;
    ch++;
    // Output : ?
    cout << *ptr << endl;
    /**/

    // 15.
    /**
    char arr[] = "abcde";
    char *p = &arr[0];
    // Output : ?
    cout << p << endl;
    /**/

    // 16.
    /**
    char arr[] = "abcde";
    char *p = &arr[0];
    p++;
    // Output : ?
    cout << p << endl;
    /**/

    // 17.
    /**
    char str[]= "babbar";
    char *p = str;
    // Output : ?
    cout << str[0] << " " << p[0] << endl;
    /**/

    // 18.
    /**
    int i = 10;
    update2(&i);

    // Output : ?
    cout << i << endl;
    /**/

    // 19.
    /**
    int arr[] = {11, 12, 13, 14};
    fun(arr + 1);

    // Output : ?
    cout << arr[0] << endl;
    /**/

    // 20.
    /**
    int a = 70;
    square(&a);

    // Output : ?
    cout << a << endl;
    /**/

    // 21.
    /**
    int a = 10;
    int b = 20;
    int *p = &a;
    int **q = &p;
    *q = &b;
    (*p)++;
    // Output : ?
    cout << a << " " << b << endl;
    /**/

    // double pointer
    // 22.
    /**
    int first = 110;
    int *p = &first;
    int **q = &p;
    int second = (**q)++ + 9;
    // Output : ?
    cout << first << " " << second << endl;
    /**/

    // 23.
    /**
    int first = 100;
    int *p = &first;
    int **q = &p;
    int second = ++(**q);
    int *r = *q;
    ++(*r);
    // Output : ?
    cout << first << " " << second << endl;
    /**/

    // 24.
    /**
    int num = 110;
    int *ptr = &num;
    increment(&ptr);
    // Output : ?
    cout << num << endl;
    /**/

    // 25.
    /**
    int arr[] = {41, 52, 36, 74};
    int *p = (arr + 1);
    // Output : ?
    cout << *arr + 8;
    /**/

    // 26.
    /**
    char *p;
    char str[] = "pqrstuv";
    p = str;
    p += 3;
    // Output : ?
    cout << p;
    /**/

    // 27.
    /**
    char arr[20];
    int i;
    for (i = 0; i < 10; i++) {
        *(arr + i) = 65 + i;
    }
    *(arr + i) = '\0';
    // Output : ?
    cout << arr;
    /**/

    // 28.
    /**
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;
    // Output : ?
    cout << *ptr2 << " ";
    // Output : ?
    cout << ptr2 - ptr1;
    /**/

    // 29.
    /**
    char st[] = "ABCD";
    for (int i = 0; st[i] != '\0'; i++) {
        // Output : ?
        cout << st[i] << *(st) + i << *(i + st) << i[st] << endl;
    }
    /**/

    // 30.
    /**
    int x = 5;
    P(&x);

    // Output : ?
    cout << x;
    /**/


    // 31.
    /**
    int ***r, **q, *p, i = 8;
    p = &i;
    (*p)++;
    q = &p;
    (**q)++;
    r = &q;
    // Output : ?
    cout << *p << " " << **q << " " << ***r;
    /**/


    // 32.
    /**
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;

    // Output : ?
    cout << f(c, b, a);
    /**/
}

int main() {
    // Lecture 27 : Double Pointers

    // p1();

    // p2();

    // p3();

    return 0;
}
