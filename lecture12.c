#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // Implementing Binary Search
    // Logic : 
    // take array let its low(initial index) and high(last index) get mid((low+high)/2)
    // check if mid element is same as key 
    // if key == arr[mid] return mid(index) 
    // if key < arr[mid] search element in the first half of the array 
    // if key > arr[mid] search element in the second half of the array 

    // code : 
    // int size = 12, arr[12] = {1, 2, 5, 7, 12, 13, 14, 17, 19, 20, 25, 27}; // even array 
    int size = 11, arr[11] = {1, 2, 5, 7, 12, 13, 14, 17, 19, 20, 25}; // odd array 
    int low = 0, high = size-1;
    int key = 20, mid;

    while (low <= high) {
        mid = low + (high - low)/2;

        if (arr[mid] == key) {
            printf("Key found at index : %d\n", mid);
            return;
        } 

        if (arr[mid] > key) {
            high = mid-1;
        } else if (arr[mid] < key) {
            low = mid+1;
        }
    }

    printf("Key not found");
}

int main() {
    // gcc lecture12.c -o main; ./main;

    p1();

    return 0;
}