#include <iostream>

using namespace std;

int partition(int *arr, int l, int h) {
    // pivot index initial 
    int piv = l;
    int c = 0; // count of elements smaller or equal to pivot element 
    for (int i = l+1; i <= h; i++) {
        if (arr[i] <= arr[piv]) {
            c++;
        }
    }

    // pivot index 
    piv = l + c;

    // placing pivot element at its right position 
    swap(arr[l], arr[piv]);

    // placing all smaller elements at left side and bigger elements at right side 
    int i = l, j = h;
    while (i < piv && piv < j) {
        if (arr[i] > arr[piv] && arr[j] <= arr[piv]) {
            swap(arr[i++], arr[j--]);
        } else if (arr[i] <= arr[piv]) {
            i++;
        } else {
            j--;
        }
    }

    // pivot elements final index 
    return piv;
}

void quicksort(int *arr, int l, int h) {
    if (l >= h) {
        return;
    }

    // piv index 
    int pi = partition(arr, l, h);

    // rr 
    quicksort(arr, l, pi-1); // for left partition 
    quicksort(arr, pi+1, h); // for right partition 
}

void p1() {
    // Implement quicksort 

    // Explanation : 
    // quicksort is a sorting algorithm 
    // based on devide and conquerer technique 
    // in quicksort we take an element as pivot 
    // place all the elements less then pivot at left side of pivot element 
    // and all the bigger elements at right side of pivot element 
    // then makes two partition of the given array 
    // one is from low_index to <pivot_element_index 
    // and second is from pivot_element_index+1 to < high_index 
    // and perform the same task for both parts 

    // Logic : 
    // create a function mergesort(), 
    // which will take an array, low index and high index 
    // add base condition 
    // if l >= h return 
    // place the pivot index at its right position 
    // and also place all elements less then pivot to the left side 
    // and bigger right side 
    // after that call quicksort() function for left and right part of the array 
    // to place pivot element at its right position and get
    // create a function partition() -> int, 
    // which will take an array, low index and high index 
    // make a variable piv = l 
    // count all the elements less then or equal to arr[piv] 
    // then place the piv element at l+count 
    // after that use two pointer approach 
    // and place all the elements which are less then or equal to pivot left side 
    // and elements bigger then pivot to right side 
    // after that return the pivot elements index 

    // Code : 
    // int arr[] = { 8, 1, 0, 2, 1, 3, 7, 5, 2, 5};
    // int arr[] = {5, 4, 8, 1, 10, 5, 7, 4, 2};
    // int arr[] = {5, 2, 13, 2, 1, 7};
    // int arr[] = {9, 9, 9, 8, 2, 3, -6}; // -6 2 3 8 9 9 9 
    // int arr[] = {9, 9, 9, 8, 2, 3, -1}; // -1 2 3 8 9 9 9 
    // int arr[] = {9, 9, 9, -8, 2, -3, -1}; // 
    int arr[] = {9, 9, 9, 8, 2, -3, -1}; // 
    int size = sizeof(arr)/sizeof(int);

    // given array 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // sorting 
    quicksort(arr, 0, size-1);

    // after sorting 
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Lecture 36 : Quick sort using recursion

    // p1();

    // To learn more about quick sort 
    // - https://www.geeksforgeeks.org/quick-sort/

    return 0;
}