#include <iostream>

using namespace std;

void merge(int *arr, int l, int h) {
    // for mergesort(int *arr, int l, int h)
    int mid = l + (h - l) / 2;

    int arr_1_len = mid - l + 1;
    int arr_2_len = h - mid;

    int *arr_1 = new int[arr_1_len]; // dynamic array
    int *arr_2 = new int[arr_2_len];

    // copy left part value in arr_1
    int k = l; // starting index
    for (int i = 0; i < arr_1_len; i++) {
        arr_1[i] = arr[k++];
    }

    // copy right part value in arr_2
    k = mid + 1; // starting index
    for (int i = 0; i < arr_2_len; i++) {
        arr_2[i] = arr[k++];
    }

    // merge both array
    int i = 0; // for left array
    int j = 0; // for right array
    int x = l; // for main array
    while (i < arr_1_len && j < arr_2_len) {
        if (arr_1[i] <= arr_2[j]) {
            arr[x++] = arr_1[i++];
        } else {
            arr[x++] = arr_2[j++];
        }
    }

    // merge rest elements
    // for left array
    while (i < arr_1_len) {
        arr[x++] = arr_1[i++];
    }

    // for right array
    while (j < arr_2_len) {
        arr[x++] = arr_2[j++];
    }

    delete arr_1;
    delete arr_1;
}

void mergesort(int *arr, int l, int h) {
    // for p1()
    if (l >= h)
        return;

    int mid = l + (h - l) / 2;

    // sort left part
    mergesort(arr, l, mid);

    // sort right part
    mergesort(arr, mid + 1, h);

    // merge both left part and right part
    merge(arr, l, h);
}

void p1() {
    // Implementing merge sort

    // Explanation :
    // merge sort is a sorting algorithm
    // it devides array into smaller subarrays
    // sort each subarrays
    // and then merge them back
    // to form the final sorted array

    // Logic :
    // create two function
    // a recursive function mergesort() to devide the array
    // till we dont get only one element
    // and a function merge() to join two part of arrays
    // mergesort() function will take three arguments
    // int arr[], int low_index, int high_index
    // inside mergesort() function add base condition
    // if l >= h return
    // processing part :
    // find mid = l + int((h-l)/2)
    // make a recursive call for left part of the array l to =mid
    // and another recursive call for right part of the array mid+1 to =h
    // after that call the merge() function to merge the above to sorted array
    // with arguments
    // int arr[], int low_index and int high_index
    // inside merge() function
    // find mid
    // then length of left part of the array len_1
    // and also for the right part of the array len_2
    // then create 2 new array arr_1 and arr_2 of size len_1 and len_2
    // and then copy the left part into arr_1 and right part into arr_2
    // after that add all elements of both arr_1 and arr_2 arrays into arr

    // Code :
    // int arr[] = {5, 2, 1, 7, 8, 6, 2, 0, 5};
    // int arr[] = {5, 2, -1, 7, 8, 6, -2, 0, -5};
    // int arr[] = {8, 4, 2, 1};
    int arr[] = {1, 2, 3, 4, 0};
    int size = sizeof(arr) / sizeof(int);

    mergesort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int merge_2(int *arr, int l, int h) {
    // for mergesort_inv(int *arr, int l, int h)
    int mid = l + (h - l) / 2;

    int arr_1_len = mid - l + 1;
    int arr_2_len = h - mid;

    int *arr_1 = new int[arr_1_len]; // dynamic array
    int *arr_2 = new int[arr_2_len];

    // copy left part value in arr_1
    int k = l; // starting index
    for (int i = 0; i < arr_1_len; i++) {
        arr_1[i] = arr[k++];
    }

    // copy right part value in arr_2
    k = mid + 1; // starting index
    for (int i = 0; i < arr_2_len; i++) {
        arr_2[i] = arr[k++];
    }

    // merge both array
    int i = 0;         // for left array
    int j = 0;         // for right array
    int x = l;         // for main array
    int int_count = 0; // to count inversions
    while ((i < arr_1_len) && (j < arr_2_len)) {
        if (arr_1[i] <= arr_2[j]) {
            arr[x++] = arr_1[i++];
        } else {
            for (int m = i; m < arr_1_len - i; m++) {
                // EXTRA
                // print all the inversions
                cout << arr_1[m] << " " << arr_2[j] << endl;
            }
            // below line is to count all the inversions
            int_count += arr_1_len - i;
            arr[x++] = arr_2[j++];
        }
    }

    // merge rest elements
    // for left array
    while (i < arr_1_len) {
        arr[x++] = arr_1[i++];
    }

    // for right array
    while (j < arr_2_len) {
        arr[x++] = arr_2[j++];
    }

    // deallocating memory
    delete arr_1;
    delete arr_1;

    // returning count of inversions
    return int_count;
}

int mergesort_inv(int *arr, int l, int h) {
    // for p2()
    if (l >= h)
        return 0;

    int mid = l + (h - l) / 2;
    int inv_count = 0;

    // sort left part
    inv_count += mergesort_inv(arr, l, mid);

    // sort right part
    inv_count += mergesort_inv(arr, mid + 1, h);

    // merge both left part and right part
    inv_count += merge_2(arr, l, h);

    return inv_count;
}

void p2() {
    // Problem 1 : Inversion count - https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

    // Statement : Given an array of integers.
    // Find the Inversion Count in the array.
    // Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
    // If array is already sorted then the inversion count is 0.
    // If an array is sorted in the reverse order then the inversion count is the maximum.
    // Formally, two elements a[i] and a[j] form an inversion
    // if a[i] > a[j] and i < j.

    // Logic :
    // create two functions
    // 1. mergesort_inv(int arr[], int l, int h) -> int
    // 2. merge_2(int arr[], int l, int h) -> int
    // in mergesort_inv() function add base condition
    // if l >= h return 0
    // find mid = (l+h)/2 
    // and devide the array into two halves 
    // initialise a variable inversion_count = 0;
    // make two recursive calls to function mergesort_inv()
    // low = low, high = mid
    // inversion_count = inversion_count + mergesort_inv()
    // and another with
    // low = mid+1, high = high
    // inversion_count = inversion_count + mergesort_inv()
    // and lastly make a call to merge_2() function to merge both part of the array
    // from low to high
    // at the end return inversion_count
    // in merge_2() function
    // find mid
    // then make two temporary arrays
    // one for left part (from low to mid)
    // and second for right part (from mid+1 to high)
    // add values in both arrays
    // merge the both arrays into main array arr
    // while merging if it is found that elements we in wrong order than
    // increament count of inversion by counting of the elements of left side

    // Code :
    // int arr[] = {8, 4, 2, 1};
    // int arr[] = {9, 8, 7, 6, 4, 2, 0};
    // int arr[] = {1, 2, 3, 4};
    // int arr[] = {1, 2, 3, 4, 0};
    int arr[] = {1, 2, 3, 4, 1, 0, 0};
    int size = sizeof(arr) / sizeof(int);

    int inv_count = mergesort_inv(arr, 0, size - 1);

    cout << inv_count << endl;
}

int main() {
    // Lecture 35 : Merge sort using recursion

    // p1();

    // p2();

    // To learn more about merge sort
    // - https://www.geeksforgeeks.org/merge-sort/

    return 0;
}
