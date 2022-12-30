#include <iostream>
#include <array>

using namespace std;

void p1() {
    // linear search 

    // searching in array by traversing each element 

    int arr[7] = {2, 13, 12, 1, 5, 5, 7};
    int n = 7;
    int key = 11;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "key found" << endl;
            return;
        }
    }

    cout << "key not found" << endl;
}

void p2() {
    // reverse the array 

    // given an array of size n 
    // reverse all elements in the array 

    // int arr[7] = {2, 13, 12, 1, 5, 5, 7};
    // int n = 7;

    int arr[6] = {2, 13, 12, 1, 5, 5};
    int n = 6;

    for (int i = 0; i < n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void p3() {
    // sum of all elements in the array 
    int arr[12] = {1, 5, 7, 12, 4, 3, 0, 5, 7, 45, 10, 11};
    int size = 12, sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("%d\n", sum);
}

int main() {
    // Lecture 9 : Array Introduction 

    // Array declaration 
    int arr[12];
    int n = 12;

    // array initialisation 
    arr[0] = 5; // array indexes starts from 0 
    arr[1] = 12;
    arr[2] = 7;
    arr[3] = 2;
    arr[4] = 25;
    arr[5] = 3;
    arr[6] = 5;
    arr[7] = 2;
    arr[8] = 6;
    arr[9] = 1;
    arr[10] = 0;
    arr[11] = 9; // last index 

    // change value 
    arr[5] = 13;

    // array traversal 
    for (int i = 0; i < n; i++) {
        // cout << arr[i] << " ";
    }
    // cout << endl;

    // p1();

    // p2();

    // p3();

    return 0;
}