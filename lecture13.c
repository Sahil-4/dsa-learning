#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int findFirstOccurrence(int *arr, int size, int key) {
    // for p1();
    int ans = -1;
    int low = 0, high = size - 1;
    int mid = low + (high - low) / 2;

    while (low <= high) {
        if (arr[mid] == key) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        mid = low + (high - low) / 2;
    }

    return ans;
}

int findLastOccurrence(int *arr, int size, int key) {
    // for p1();
    int ans = -1;
    int low = 0, high = size - 1;
    int mid = low + (high - low) / 2;

    while (low <= high) {
        if (arr[mid] == key) {
            ans = mid;
            low = mid + 1;
        }else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

        mid = low + (high - low) / 2;
    }

    return ans;
}

void p1() {
    // Problem 1 : Find first and last occurrence - https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549 

    // Stattement : You have been given a sorted array/list ARR consisting of ‘N’ elements,
    // and an integer ‘K’,
    // the task is to find the first and last occurrence of ‘K’ in ARR

    // Logic : using Binary Search
    // find the first occurrence of element k in the array
    // find the last occurrence of element k in the array
    // initialise answer with -1
    // initialise indexes low = 0, high = n-1
    // make mid index 
    // run a loop till low < high 
    // check if arr[mid] == key, 
    // if yes store mid as answer, 
    // and then for finding first occurrence update high = mid-1,
    // and for finging last occurrence update low = mid+1 
    // if arr[mid] < key, 
    // update low = mid+1
    // if arr[mid] > key, 
    // update high = mid-1
    // lastly in the loop update mid 

    // Code : 
    // int size = 12, arr[12] = {0, 2, 2, 5, 5, 12, 12, 12, 14, 17, 18, 18};
    // int key = 12;

    int size = 11, arr[11] = {0, 2, 2, 5, 5, 12, 12, 12, 14, 17, 18};
    int key = 12;

    int f, l;

    f = findFirstOccurrence(arr, size, key);
    l = findLastOccurrence(arr, size, key);

    printf("first occurred at index : %d\nlast occurrence at index : %d\nTotal number of occurrence is %d\n", f, l, l-f+1);
}

void p2() {
    // Problem 2 : 852. Peak Index in a Mountain Array - https://leetcode.com/problems/peak-index-in-a-mountain-array/

    // Statement : Given a mountain array arr, 
    // return the index i 
    // such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

    // Logic : using binary search 
    // take low = 0, high = <last_index>, 
    // mid = low + (high-low)/2 
    // run a loop till low < high 
    // check for below 3 conditions 
    // 1. arr[mid-1] > arr[mid] > arr[mid+1] 
    // 2. arr[mid - 1] < arr[mid] 
    // 3. arr[mid] > arr[mid + 1] 
    // if condition 1 is true simply return the mid as peak index 
    // if condition 2 is true update low = mid+1 
    // if condition 3 is true update high = mid 

    // Code : 
    // int size = 4, arr[4] = {0,2,1,0};
    // int size = 3, arr[3] = {0,1,0};
    // int size = 4, arr[4] = {0,10,5,2};
    int size = 10, arr[10] = {24,69,100,99,79,78,67,36,26,19};
    int low = 0, high = size-1;
    int mid = low + (high - low)/2;
    int peak = -1;

    while (low < high) {
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            peak = mid;
            break;
        } else if (arr[mid - 1] < arr[mid]) {
            low = mid+1;
        } else if (arr[mid] > arr[mid + 1]) {
            high = mid;
        }
        mid = low + (high - low)/2;
    }

    printf("peak element is %d at index %d", arr[peak], peak);
}

void p3() {
    // Problem 3 : 724. Find Pivot Index - https://leetcode.com/problems/find-pivot-index/

    // Statement : Given an array of integers nums,
    // calculate the pivot index of this array.
    // The pivot index is the index where the sum of all the numbers,
    // strictly to the left of the index is 
    // equal to the sum of all the numbers,
    // strictly to the index's right.
    // NOTE : If the index is on the left edge of the array,
    // then the left sum is 0 because there are no elements to the left.
    // This also applies to the right edge of the array.

    // Logic : 
    // take 2 variables right_sum = 0, left_sum = 0
    // loop through the array 
    // calculate right_sum summing all the elements 
    // run loop from i = 0 to i < size 
    // add arr[i-1] in left_sum, 
    // and subtract arr[i] from right_sum 
    // check if right_sum == left_sum,
    // if yes return i as pivot index 
    // else move to next index 

    // int size = 6, arr[6] = {1,7,3,6,5,6}; // 3 
    // int size = 3, arr[3] = {2,1,-1}; // 0 
    // int size = 3, arr[3] = {1,2,3}; // -1 
    int size = 6, arr[6] = {1, 7, 3, 6, 5, 6};

    int left_sum = 0, right_sum = 0;

    for (int i = 0; i < size; i++) {
        right_sum += arr[i];
    }

    for (int i = 0; i < size; i++) {
        if (i != 0) {
            left_sum += arr[i-1];
        }
        right_sum -= arr[i];
        if (left_sum == right_sum) {
            printf("%d", i);
            return;
        }
    }

    printf("%d", -1);
}

int main() {
    // Lecture 13 : Binary search interview questions 

    // p1();

    // p2();

    // p3();

    return 0;
}