#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // Problem 1 : Find pivot in an sorted and rotated array 

    // Statement : given a sorted and rotated array of integers 
    // return the pivot (minimum) element of the array 

    // Logic : Using binary search 
    // take 3 vars low = 0, high = size-1, mid = mid = (low+high)/2 
    // run a loop while (low < high) 
    // check for below conditions 
    // 1. arr[mid] >= arr[0] 
    // 2. arr[mid] < arr[0] 
    // if 1 is true update low = mid+1 
    // if 2 is true update high = mid 
    // then update mid = (low+high)/2 
    // after loop ends return low or high as answer 

    // Code : 
    int size = 5, arr[5] = {7, 9, 1, 2, 3}; // output : 1 
    int low = 0, high = size-1;
    int mid = low + (high - low)/2;

    while (low < high) {
        if (arr[mid] >= arr[0]) {
            low = mid+1;
        } else {
            high = mid;
        }

        mid = low + (high - low)/2;
    }

    printf("pivot element is %d at index %d", arr[low], low);
}

void p2() {
    // Problem 2 : Search In Rotated Sorted Array - https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554 

    // Statement : You have been given a sorted array of ‘N’ elements,
    // and an integer ‘K’ 
    // Now the array is rotated at some pivot point unknown to you 
    // For example, if ARR = [ 1, 3, 5, 7, 8] 
    // Then after rotating ARR at index 3, 
    // the array will be ARR = [7, 8, 1, 3, 5] 
    // find the index at which ‘K’ is present in array 

    // Logic : Using binary search 
    // first find pivot(smallest element of the array),
    // then check for below conditions 
    // 1. arr[0] < K && K < arr[pivot-1]
    // 2. arr[0] > K && K > arr[pivot]
    // if 1 find K in first part of the array i = 0 to i < pivot 
    // if 2 find K in second part of the array i = pivot to i < size_of_array 

    // Code : 
    int size = 4, arr[4] = {2, 3, 5, 8};
    int key = 2;
    // int size = 1, arr[1] = {2};
    // int key = 3;
    // int size = 8, arr[8] = {3, 4, 5, 6, 8, 9, 1, 2};
    // int key = 1;

    int low, high, mid;
    low = 0, high = size-1;
    mid = low + (high-low)/2;

    // finding pivot 
    while (low < high) {
        if (arr[mid] >= arr[0]) {
            low = mid+1;
        } else {
            high = mid;
        }

        mid = low + (high - low)/2;
    }

    int pivot = low;

    // checking conditions 
    if (arr[pivot] <= key && key <= arr[size-1]) {
        // search in second part i = pivot to i < size 
        low = pivot, high = size-1;
    } else {
        // search in first part i = 0 to i < pivot 
        low = 0, high = pivot-1;
    }

    // search binary
    mid = low + (high-low)/2;

    while (low <= high) {
        if (arr[mid] == key) {
            printf("key : %d found at index : %d", key, mid);
            return;
        }

        if (arr[mid] > key) {
            high = mid-1;
        } else {
            low = mid+1;
        }

        mid = low + (high-low)/2;
    }

    printf("key not found");
}

void p3() {
    // Problem 3 : find square root of n 

    // Statement : given an integer n,
    // return square root of n 

    // Logic : using binary search
    // low = 0, high = n 
    // get mid check for below conditions 
    // 1. mid*mid == n;
    // 2. mid*mid <= n;
    // 3. mid*mid > n;
    // if 1 is true return mid as answer 
    // if 2 is true save mid as answer and update low = mid+1
    // if 3 is true update high = mid-1

    // Code : 
    int n;
    scanf("%d", &n);

    int low = 0, high = n;
    long long int mid = low + (high-low)/2;
    int ans = -1;

    while (low <= high) {
        if (mid * mid == n) {
            ans = mid;
            break;
        }

        if (mid * mid <= n) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }

        mid = low + (high-low)/2;
    }

    printf("square root of %d in integer is %d\n", n, ans);

    double p_sol = ans;
    long long int temp = 0;

    while (temp <= n) {
        p_sol += 0.001;
        temp = p_sol * p_sol;

        if (temp > n) {
            p_sol -= 0.001;
            break;
        }
    }

    printf("square root of %d in float is %f\n", n, p_sol);
}

int main() {
    // Lecture 14 : Binary search interview questions 

    // p1();
    
    // p2();

    // p3();

    return 0;
}
