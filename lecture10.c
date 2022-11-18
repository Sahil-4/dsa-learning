#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // Problem 1 : Swap alternates 
    // problem statement : given an array as input, 
    // swap all alternate elements 
    // eg 1 : {1, 2, 7, 8, 5}; => {2, 1, 8, 7, 5} 
    // eg 2 : {1, 2, 3, 4, 5, 6}; => {2, 1, 4, 3, 6, 5}

    // logic : loop through the array, 
    // take elements in pair 
    // swap the alternates 
    // go to next pair and perform the same task till i <= n;

    // code : 
    // array initialisation 
    int size = 7, arr[7] = {2, 12, 1, 7, 3, 3, 14};
    // int size = 8, arr[8] = {2, 12, 1, 7, 3, 3, 14, 12};

    // swaping alternate elements 
    for (int i = 0; i < size; i+=2) {
        // swaping if array has next element 
        if (size > i+1) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }

    // printing all elements 
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void p2() {
    // Problem 2 : Find unique - https://www.codingninjas.com/codestudio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
    // Problem Statement : You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1]. 
    // Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
    // You need to find and return that number which is unique in the array/list.

    // Logic : initialise the answer with 0,
    // loop through the array 
    // perform ans = ans ^ arr[index]
    // in case if ans is same as arr[index] ans will become 0 
    // else ans will become arr[index] 

    // Code : 
    // int size = 7, arr[7] = {14, 12, 12, 4, 3, 14, 3};
    int size = 5, arr[5] = {11, 12, 12, 1, 11};
    int ans = 0;

    for (int i = 0; i < size; i++) {
        printf("%d^%d\n", ans, arr[i]);
        ans = ans^arr[i];
        printf("ans : %d\n", ans);
    }

    // printf("%d\n", ans);
}

void p3() {
    // Problem 3 : find duplicate - https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
    // Problem statement : given an array of size n,
    // array contains all integers from 1 to n-1,
    // and a single integer is present twice 

    // logic : initialise ans with 0,
    // traverse the array,
    // xor ans with element[index] till index < size,
    // after that xor the ans with 1 to n-1;
    
    int size = 12, arr[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11};
    int ans = 0;

    printf("ans : %d\n", ans);

    for (int i = 0; i < size; i++) {
        printf("%d^%d\n", ans, arr[i]);
        ans = ans^arr[i];
    }

    printf("ans : %d\n", ans);

    for (int i = 1; i < size; i++) {
        printf("%d^%d\n", ans, arr[i]);
        ans = ans^i;
    }

    printf("ans : %d\n", ans);
}

void p4() {
    // Problem 4 : Intersection Of Two Sorted Arrays - https://www.codingninjas.com/codestudio/problems/intersection-of-2-arrays_1082149?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
    // Problem statement : You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively,
    // Both these arrays are sorted in non-decreasing order,
    // You have to find the intersection of these two arrays.
    // Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

    // Logic : run a loop from i = 0 to size_of_first_array 
    // initialise variable start as 0 
    // take element of the array one by one 
    // run another loop from j = start to size_of_second_array 
    // first check if first_array[i] > second_array[j] 
    // if above condition is true break the second loop (inner jth loop)
    // check if first_array[i] == second_array[j] 
    // if above condition is true 
    // update start = j; and print the second_array[j] element 

    int size_1 = 11, arr_1[11] = {1, 4, 7, 12, 14, 15, 15, 16, 18, 20, 21};
    int size_2 = 3, arr_2[3] = {5, 15, 16};

    int i = 0, j = 0;

    while (i < size_1 && j < size_2) {
        if (arr_1[i] < arr_2[j]) {
            i++;
        } else if (arr_1[i] == arr_2[j]) {
            // !TODO : add element in vector 
            printf("%d ", arr_1[i]);
            i++;
            j++;
        } else {
            j++;
        }
    }
}

void p5() {
    // Problem 5 : Pair sum - https://www.codingninjas.com/codestudio/problems/pair-sum_697295
    // Problem statement : You are given an integer array 'ARR' of size 'N' and an integer 'S',
    // Your task is to return the list of all pairs of elements such that,
    // each sum of elements of each pair equals 'S'. 
    // Each pair should be sorted i.e the first value should be less than or equals to the second value. 
    int size = 5, arr[5] = {1, 2, 3, 4, 5}, S = 5;
    
    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] + arr[j] == S) {
                printf("{%d, %d} = %d\n", arr[i], arr[j], S);
            }
        }
    }
}

void p6() {
    // Problem : sort 0s and 1s 
    // Statement : given an array of 0s and 1s,
    // return the sorted the array 

    int size = 7, arr[7] = {0, 1, 0, 0, 1, 1, 0};
    int low = 0, high = size-1;

    while (low < high) {
        if (low >= high) {
            break;
        }

        if (arr[low] == 0) {
            low++;
        } else if (arr[high] == 1) {
            high--;
        } else if (arr[low] == 1 && arr[high] == 0) {
            arr[low] = 0;
            arr[high] = 1;
            low++;
            high--;
        } else {
            low++;
            high--;
        }
    }

    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void p7() {
    // Problem 7 : Triplet sum - https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028
    // Statements : Given an array of n integers, and an integer K
    // find all the distinct triplets that sums upto K 

    // int size = 17, arr[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 16, 14, 8, 5, 13};
    // int size = 5, arr[5] = {10, 5, 5, 5, 2}; // => [ {5, 5, 2} ]
    int size = 6, arr[6] = {1, 2, 3, 1, 2, 3};
    int K = 6;

    for (int i = 0; i < size-2; i++) {
        for (int j = i+1; j < size-1; j++) {
            for (int k = j+1; k < size; k++) {
                if (arr[i] + arr[j] + arr[k] == K) {
                    printf("%d %d %d\n", arr[i], arr[j], arr[k]);
                    i++;
                    j++;
                }
            }
        }
    }
}

void p8() {
    // Problem 8 : Sort an array of 0s, 1s and 2s - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
    // Statement : Given an array of size N containing only 0s, 1s, and 2s,
    // sort the array in ascending order 
    // Logic : 
    // Keep three indices low = 1, mid = 1, and high = N,
    // and there are four ranges, 
    // 1 to low (the range containing 0), 
    // low to mid (the range containing 1), 
    // mid to high (the range containing unknown elements),
    // and high to N (the range containing 2).
    // Traverse the array from start to end,
    // and mid is less than high. (Loop counter is i),
    // If the element is 0,
    // then swap the element with the element at index low,
    // and update low = low + 1 and mid = mid + 1.
    // If the element is 1 then update mid = mid + 1.
    // If the element is 2 then swap the element with the element at index high,
    // and update high = high – 1 and update i = i – 1. As the swapped element is not processed

    int size = 12, arr[12] = {0, 1, 1, 0, 0, 1, 2, 2, 2, 2, 0, 1}; // output : {0, 0, 1, 1, 1, 1, 2}
    // sorting algorithm 
    int low = 0, mid = 0, high = size-1;

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (mid <= high) {
        switch(arr[mid]) {
            case 0: {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low += 1;
                mid += 1;
                break;
            }

            case 1: {
                mid += 1;
                break;
            }

            case 2: {
                int temp = arr[high];
                arr[high] = arr[mid];
                arr[mid] = temp;
                high -= 1;
                break;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void p9() {
    // Problem 9 : 442. Find All Duplicates in an Array - https://leetcode.com/problems/find-all-duplicates-in-an-array/
    // Statement : Given an integer array nums of length n,
    // where all the integers of nums are in the range [1, n],
    // and each integer appears once or twice, 
    // return an array of all the integers that appears twice.

    // Logic : 
    // traverse the whole array from i = 1 to (=n) 
    // if arr[i-1] < 0 return i as i is occured twice 
    // else perform arr[arr[i]] *= -1; this will flip the arr[i]th element to negative 

    // code : 
    int size = 8, arr[8] = {4,3,2,7,8,2,3,1}; // output : {2, 3}
    int arr2[size], count = 0;

    for (int i = 1; i <= size; i++) {
        if (arr[i] < 0) {
            // integer i has occured twice 
            arr2[count++] = i;
        } else {
            arr[arr[i-1]] *= -1;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}

int main() {
    // lecture 10 : Solving leetcode codestudio questions 
    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7(); // triplet sum not done 

    // p8();

    p9();

    return 0;
}