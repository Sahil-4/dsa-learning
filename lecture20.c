#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // Problem 1 : Reverse The Array - https://www.codingninjas.com/codestudio/problem-details/reverse-the-array_1262298

    // Statement : given an array of some integers,
    // and position M
    // task is to reverse the array after position M

    // logic : using bruteforce(linearly)
    // loop through the array from i=1 to <=l, (l = (size_of_array-M)/2)
    // swap arr[M+i], arr[size-i]
    // increament i by 1

    // Code :
    // int size = 6, arr[6] = {1, 2, 3, 4, 5, 6}; // output : {1 2 3 4 6 5}
    // int size = 7, arr[7] = {1, 2, 3, 4, 5, 6, 7}; // output : {1 2 3 4 7 6 5}
    int size = 8, arr[8] = {1, 2, 3, 4, 5, 6, 7, 8}; // output : {1 2 3 4 8 7 6 5}
    int M = 3;
    int i = 1;

    while (i <= (size - M) / 2) {
        int temp = arr[M + i];
        arr[M + i] = arr[size - i];
        arr[size - i] = temp;

        i++;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void p2() {
    // Problem 2 : 88. Merge Sorted Array - https://leetcode.com/problems/merge-sorted-array/

    // Statement : you are given two arrays arr_1 and arr_2 of size n and m,
    // sorted in non decreasing order
    // merge the both arrays in arr_1 in non decreasing order

    // Logic : using two pointer approach 
    // take i = last index of first array i.e. n-1, 
    // j = last index of second array, 
    // h = last index of final array 
    // run a loop till i >= 0 and j >= 0, 
    // check if arr_1[i] > arr_2[j], 
    // in this case assign arr_1[hi] = arr_1[i], 
    // then update hi = hi-1 and i = i-1 
    // else assign arr_1[hi] = arr_2[j], 
    // then update hi = hi-1 and j = j-1 
    // after that add remaining elements in the array 

    // Code :
    int arr_1[6] = {1,2,3,0,0,0}, n = 3, arr_2[3] = {2,5,6}, m = 3;
    // int arr_1[1] = {1}, n = 1, arr_2[1] = {}, m = 0;
    // int arr_1[1] = {0}, n = 0, arr_2[1] = {1}, m = 1;

    int i = n-1; int j = m-1, hi = n+m-1;

    while (i >= 0 && j >= 0) {
        if (arr_1[i] > arr_2[j]) {
            arr_1[hi--] = arr_1[i--];
        } else {
            arr_1[hi--] = arr_2[j--];
        }
    }

    while (i >= 0) {
        arr_1[hi--] = arr_1[i--];
    }

    while (j >= 0) {
        arr_1[hi--] = arr_2[j--];
    }

    for (int i = 0; i < n + m; i++) {
        printf("%d ", arr_1[i]);
    }
    printf("\n");
}

void p3() {
    // Problem 3 : 283. Move Zeroes - https://leetcode.com/problems/move-zeroes/

    // Statement : given an integer array of size n,
    // move all 0's in the end of the array
    // without disturbing other elements

    // Logic : removing all 0s and adding them in the end 
    // take an integer c = 0 
    // traverse the array from i = 0 to i < size 
    // check if arr[i] is not 0 
    // in this case assign arr[c] = arr[i] 
    // update c = c+1 
    // after then run a loop from i = c to i < size 
    // assign arr[i] = 0 

    // Code :
    int size = 5, arr[5] = {0, 1, 0, 3, 12};
    // int size = 1, arr[1] = {0};

    int c = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[c++] = arr[i];
        }
    }

    for (int i = c; i < size; i++) {
        arr[i] = 0;
    }

    // printing array 
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Lecture 20 : Solving Leetcode Arrays Problems

    // p1();

    // p2();

    // p3();

    return 0;
}