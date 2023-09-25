#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // Implementing linear search 

    // Logic : 
    // make a loop 
    // take index i = 0, 
    // till i < size_of_array 
    // check if arr[i] == key, 
    // if yes then just return the index 
    // else increament i by 1, 
    // and check for next element 

    int size = 12, arr[12] = {2, 5, 6, 7, 9, 10, 15, 18, 28, 32, 45};
    int key = 15;

    // algorithm 
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("key : %d found at index : %d\n", key, i);
            return;
        }
    }

    printf("key : %d not found\n", key);

    // Time complexity : O(n) 
    // Space complexity : O(1) 
}

void p2() {
    // Implementing Binary Search

    // Logic : 
    // take three indices low = 0, high = n-1
    // make mid = low + (high-low)/2 
    // run a loop till low <= high 
    // check if arr[mid] == key, 
    // if yes just return the index mid 
    // else check if arr[mid] < key, 
    // if yes update low = mid+1
    // else if arr[mid] > key 
    // return true update high = mid-1
    // finally in the same loop, 
    // update mid = low + (high-low)/2 
    // NOTE : binary search will only work on sorted arrays 

    // code : 
    // int size = 12, arr[12] = {1, 2, 5, 7, 12, 13, 14, 17, 19, 20, 25, 27}; // even array 
    int size = 11, arr[11] = {1, 2, 5, 7, 12, 13, 14, 17, 19, 20, 25}; // odd array 
    int low = 0, high = size-1, mid;
    int key = 20;

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

    // Time complexity : O(log(n)) 
    // Space complexity : O(1) 
}

int main() {
    // Lecture 12 : Binary Search Explanation 

    // Linear Search : searching in an array by traversing whole array or visiting every index 
    // p1();

    // Binary Search : searching in an array by deviding the array into two half 
    // p2();

    return 0;
}
