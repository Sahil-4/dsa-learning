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

    while (i <= (size-M)/2) {
        if (M+i == size-i) {
            break;
        }

        int temp = arr[M+i];
        arr[M+i] = arr[size-i];
        arr[size-i] = temp;

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

    // Logic : using selection sort 
    // take an integer c = 0 
    // loop through the array the array from n to n+m;
    // run another loop from j = i to j >= 0; 
    // if arr_1[j-1] < arr_2[c] 
    // assign arr_1[j] = arr_2[c] 
    // increament c by 1 
    // then break the inner loop 
    // if arr_1[j-1] < arr_2[c] is not true 
    // assign arr_1[j] = arr_1[j-1] 

    // Code : 
    int n = 3, arr_1[6] = {1,2,3,0,0,0};
    int m = 3, arr_2[3] = {2,5,6};
    int c = 0;

    for (int i = n; i < n+m; i++) {
        for (int j = i; j >= 0; j--) {
            if (j == 0 || arr_1[j-1] < arr_2[c]) {
                arr_1[j] = arr_2[c];
                c++;
                break;
            } else {
                arr_1[j] = arr_1[j-1];
            }
        }
    }

    for (int i = 0; i < n+m; i++) {
        printf("%d ", arr_1[i]);
    }
    printf("\n");

    // optimised solution : 
}

void p3() {
    // Problem 3 : 283. Move Zeroes - https://leetcode.com/problems/move-zeroes/

    // Statement : given an integer array of size n, 
    // move all 0's in the end of the array 
    // without disturbing other elements 

    // Logic : loop through the array from i = size-2 to i >= 0 
    // check arr[i] == 0 if true : 
    // run inner loop from j = i to j < size-1 
    // update arr[j] = arr[j+1] 
    // lastly update arr[size-1] = 0 

    // Code : 
    int size = 5, arr[5] = {0,1,0,3,12};
    // int size = 1, arr[1] = {0};
    
    // for (int i = size-2; i >= 0; i--) {
    //     if (arr[i] != 0) {
    //         continue;
    //     } else {
    //         for (int j = i; j < size-1; j++) {
    //             arr[j] = arr[j+1];
    //         }
    //         arr[size-1] = 0;
    //     }
    // }

    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    // optimised solution : 
    int c = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[c++] = arr[i];
        }
    }

    for (int i = c; i < size; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Lecture 20 : Solving Leetcode Arrays Problems 
    
    // p1();

    // p2();

    p3();

    return 0;
}