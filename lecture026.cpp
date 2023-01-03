#include <iostream>

using namespace std;

void p1() {
    // p1 : pointers and array

    // when we declare an array we are just allocating memory for n objects
    int arr[5] = {2, 5, 13};

    // above arr is a pointer pointing to the the very first location in the array
    cout << "address of arr is : " << arr << endl; // this will return the address of very first element

    // and *arr will return the value that is stored at that address
    cout << "first element in array is : " << *arr << endl;

    // if we want to get second locations value i.e. 1st index
    cout << "second element of array : " << *(arr + 1) << endl;

    cout << "first element plus 1 : " << *arr + 1 << endl; // this will return the value at address arr then add 1 into that

    // in the same way we can access other indexes also
    cout << "element at index 2 : " << *(arr + 2) << endl; // value at second index

    // when we use arr[index] this same process happens
    // so arr[index] is same as *(arr+index)

    // below arr[0] will return the first element in the array
    cout << "value at address arr+0" << arr[0] << endl;

    // what if we do this
    cout << "value at address 0+arr" << 0[arr] << endl;

    // both arr[0] and 0[arr] will return same result
    // because arr[0] and 0[arr] both will evaluate as *(arr+0) 

    // Explanation :
    // arr[0] is *(arr+0)
    // and 0[arr] is *(0+arr)
    // so this is how they both are same and gives the same output

    // size
    cout << "memory size of array arr is : " << sizeof(arr) << endl; // size of array * memory required by datatype

    cout << "memory size of element at address arr is : " << sizeof(*arr) << endl; // memory size of element stored at address arr

    // using pointers to access array
    int *ptr = arr; // we are just copying the arr pointer into ptr
    // we don't use &(address of operator) because arr itself returns the memory address

    // accessing element
    cout << *arr << endl;
    cout << *ptr << endl;

    cout << *(arr + 1) << endl;
    cout << *(ptr + 1) << endl;

    // modifying elements
    *(arr + 1) = 50;

    // printing
    cout << *(arr + 1) << endl;
    cout << *(ptr + 1) << endl;

    // modifying elements
    *(ptr + 1) = 5000;

    // printing
    cout << *(arr + 1) << endl;
    cout << *(ptr + 1) << endl;

    // accessing address
    cout << arr << endl; // address of first element
    cout << ptr << endl; // value of ptr (address)

    cout << &arr[0] << endl; // address of first element
    cout << ptr << endl;     // value of ptr (address)

    cout << &arr << endl; // array first element address
    cout << &ptr << endl; // pointers address

    // modifying addresses
    // arr = arr + 1; // we cannot change the address of array

    ptr = ptr + 1;        // but we can change the address of pointer
    cout << *ptr << endl; // value at address

    // printing address
    cout << &arr + 1 << endl;
    cout << ptr << endl;
}

void p2() {
    // p2 : pointers and char array

    int arr[5] = {1, 2, 3, 4, 4};
    char ch[6] = "abcde";

    cout << arr << endl; // this will print the address
    cout << ch << endl;  // but this will print the whole string

    // this is because implementation of cout is different for int and char

    // using pointers to acheive above result
    char *c_ptr = ch;

    cout << c_ptr << endl; // this will also print whole string

    cout << &c_ptr << endl; // this will return the address

    char temp = 'a';
    char *ch2 = &temp;
    cout << ch2 << endl; // cout continuously keep print chars until it found the null char
}

void print(int *p) {
    // helper function for p3

    cout << "address of ptr is : " << p << endl;
    cout << "value at address at ptr is : " << *p << endl;
}

void updateValue(int *p) {
    // helper function for p3

    *p = (*p) * (*p);
}

void updateAddress(int *p) {
    // helper function for p3

    cout << "address of pointer before " << p << endl;

    // modifying address of p
    p = p + 1;

    cout << "address of pointer after " << p << endl;

    // here inside function address is changed
    // but outside this function change in address is not reflected
    // because inside the function p is just a copy
    // all the changes are made on that copy
}

int sumOfArray(int arr[], int size) {
    // helper function for p3

    // cout << "size of arr is : " << sizeof(arr) << endl;
    // because arr is a pointer size is different

    int sum = 0;

    // calculating sum of all elements in arr 
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

int sumOfArray2(int *arr, int size) { // this is same as sumOfArray()
    // helper function for p3

    cout << "size of arr is : " << sizeof(arr) << endl;
    // because arr is a pointer size is different

    int sum = 0;

    // calculating sum of all elements in arr 
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

void p3() {
    // function and pointers

    int n = 5;
    int *ptr = &n;

    // before
    print(ptr);

    // updating address
    updateAddress(ptr);

    // updating value
    updateValue(ptr);

    // after
    print(ptr); // address is not updated
    // but value is updated

    // when we call updateAddress() function and passed ptr
    // it creates a copy of ptr pointer
    // and perform changes on it only

    // arrays and function
    int arr[5] = {1, 2, 5, 12, 7};
    // int sum = sumOfArray(arr, 5);
    int sum = sumOfArray2(arr, 5);
    cout << "sum is  : " << sum << endl;

    // when we pass an array to a function
    // we are just passing an pointer

    // because we are passing pointer with array
    // so we can also pass a specific part of array
    // like :
    sum = sumOfArray2(arr + 2, 3);       // {5, 12, 7}
    cout << "sum is  : " << sum << endl; // 24
}

int main() {
    // Lecture 26 : Pointers II

    // p1();

    // p2();

    // p3();

    return 0;
}
