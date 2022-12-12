#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // Problem 1 : Swap alternates - https://www.codingninjas.com/codestudio/problems/swap-alternate_624941 

    // problem statement : given an array as input, 
    // swap all alternate elements 
    // eg 1 : {1, 2, 7, 8, 5}; => {2, 1, 8, 7, 5} 
    // eg 2 : {1, 2, 3, 4, 5, 6}; => {2, 1, 4, 3, 6, 5}

    // logic : loop through the array, 
    // take elements in pair of 2 
    // swap the alternates 
    // go to next pair and perform the same task till i <= n; (i = index)

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
    // Problem 2 : Find unique - https://www.codingninjas.com/codestudio/problems/find-unique_625159 

    // Problem Statement : You have been given an integer array/list(ARR) 
    // of size N. Where N is equal to [2M + 1]. 
    // Now, in the given array/list, 
    // 'M' numbers are present twice and one number is present only once.
    // You need to find and return that number which is unique in the array/list.

    // Logic : initialise the answer with 0,
    // loop through the array 
    // perform ans = ans ^ arr[index], (xor)
    // in case if ans is same as arr[index] ans will become 0 
    // else ans will become arr[index] 

    // Code : 
    // int size = 7, arr[7] = {14, 12, 12, 4, 3, 14, 3}; // out : 4 
    // int size = 5, arr[5] = {11, 12, 12, 1, 11}; // out : 1 
    // int size = 5, arr[5] = {11, 12, 12, 0, 11}; // out : 0 
    int size = 5, arr[5] = {11, 12, 0, 0, 11}; // out : 12 

    int ans = 0;

    for (int i = 0; i < size; i++) {
        ans = ans^arr[i];
    }

    printf("%d\n", ans);
}

void p3() {
    // Problem 3 : find duplicate - https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397 

    // Problem statement : given an array of size n,
    // array contains all integers from 1 to n-1,
    // and a single integer is present twice 
    // find the duplicate integer 

    // logic : initialise ans with 0,
    // traverse the array,
    // xor ans with element[index] till index < size,
    // after that xor the ans with 1 to n-1;

    // int size = 12, arr[12] = {11, 2, 4, 5, 6, 9, 10, 7, 8, 3, 1, 11}; // out : 11 
    int size = 3, arr[3] = {2, 1, 2}; // out : 2 

    int ans = 0;

    for (int i = 0; i < size; i++) {
        ans = ans^arr[i];
    }

    for (int i = 1; i < size; i++) {
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

    // Logic : init i = 0 and j = 0,
    // run a loop till i < size_of_first_arr and j < size_of_second_arr 
    // check if both (arr1[i] and arr[j]) are equal if yes add them in answer,
    // then increament both i and j by 1 
    // if (arr1[i] < arr2[j]) increament only i by 1 
    // if (arr1[i] > arr2[j]) increament only j by 1 
    // in the end print all the answer elements 

    // T1 : 
    // int size_1 = 11, arr_1[11] = {1, 4, 7, 12, 14, 15, 15, 16, 18, 20, 21};
    // int size_2 = 3, arr_2[3] = {5, 15, 16};

    // T2 : 
    // int size_1 = 3, arr_1[3] = {1, 4, 5};
    // int size_2 = 3, arr_2[3] = {3, 4, 5};

    // T3 : 
    int size_1 = 6, arr_1[6] = {1, 2, 2, 2, 3, 4};
    int size_2 = 4, arr_2[4] = {2, 2, 3, 3};

    int ans_arr_size = 0, ans_arr[10];

    int i = 0, j = 0;

    while (i < size_1 && j < size_2) {
        if (arr_1[i] == arr_2[j]) {
            ans_arr[ans_arr_size++] = arr_1[i];
            i++;
            j++;
        } else if (arr_1[i] < arr_2[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (int i = 0; i < ans_arr_size; i++) {
        printf("%d ", ans_arr[i]);
    }
    printf("\n");
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
    // Problem : sort 0s and 1s - https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1 

    // Statement : given an array of 0s and 1s,
    // return the sorted the array 

    // logic : two pointer 
    // take low = 0 and high = size_of_arr - 1 
    // run loop till low < high 
    // if low >= high break the loop 
    // if arr[low] == 0 and arr[high] == 1 just increament low by 1 and decreament high by 1 
    // if arr[low] == 1 and arr[high] == 0 swap the low and high elements, 
    // then increament low by 1 and decreament high by 1 
    // if (arr[low] == 0) increament low by 1 
    // if (arr[high] == 0) decreament high by 1 

    int size = 7, arr[7] = {0, 1, 0, 0, 1, 1, 0};
    int low = 0, high = size-1;

    while (low < high) {
        if (low >= high) {
            break;
        }

        if (arr[low] == 0 && arr[high] == 1) {
            low++;
            high--;
        } else if (arr[low] == 1 && arr[high] == 0) {
            arr[low] = 0;
            arr[high] = 1;
            low++;
            high--;
        }  else if (arr[high] == 1) {
            high--;
        } else if (arr[low] == 0) {
            low++;
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arr_sort(int *arr, int size) {
    // helper function for p7 
    // sorting array 
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {
            break;
        }

        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swaping
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void p7() {
    // Problem 7 : 3Sum - https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028 

    // Statements : Given an array of n integers, and an integer K 
    // find all the distinct triplets that sums upto K 

    // Logic : Using two pointer approach + a loop 
    // first sort the array 
    // run a loop (i = 0 to i < n-2), (excluding last 2 elements to make triplets) 
    // if i is equal to 0 or bigger then 0 and not equal to prev element, 
    // make a = arr[i] 
    // now two pointer 
    // take l = i+1, h = n-1 
    // and now we have to find K-a (using arr[l]+arr[h]) 
    // if (arr[l] + arr[h] == K - a), 
    // add arr[l], arr[h], and a in the answers set, 
    // increase l and decrease h by 1, 
    // till arr[l] and arr[h] is not equal to prev ones 
    // if (arr[l] + arr[h] < K - a), 
    // increase l by 1, 
    // if (arr[l] + arr[h] > K - a), 
    // decrease h by 1, 

    // int size = 17, K = 5, arr[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 15, 16, 14, 8, 5, 13}; // => [ -1 ] 
    // int size = 6, K = 6, arr[6] = {1, 2, 3, 1, 2, 3}; // => [{1, 2, 3}] 
    int size = 5, K = 12, arr[5] = {10, 5, 5, 5, 2}; // => [ {5, 5, 2} ] 

    // sorting array 
    arr_sort(arr, size);

    // for loop for element a 
    for (int i = 0; i < size-2; i++) {
        // condition to check whether this element is not equal to prev one 
        if (i == 0 || (i > 0 && arr[i] != arr[i-1])) {
            // make a 
            int a = arr[i];

            // start two pointer 
            int l = i+1, h = size-1;

            while (l < h) {
                // checking for answer 
                if (arr[l] + arr[h] == K-a) {
                    printf("%d %d %d", a, arr[l], arr[h]);

                    while (l < h && arr[l] == arr[l+1]) l++;
                    while (l < h && arr[h] == arr[h-1]) h--;

                    l++;
                    h--;
                } else if (arr[l] + arr[h] < K-a) {
                    l++;
                } else {
                    h--;
                }
            }
        }
    }
}

void p8() {
    // Problem 8 : Sort an array of 0s, 1s and 2s - https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1 

    // Statement : Given an array of size N containing only 0s, 1s, and 2s,
    // sort the array in ascending order 

    // Logic : using three pointer 
    // Keep three indices low = 0, mid = 0, and high = N-1,
    // now there will be four ranges, 
    // 0 to low (the range containing 0s), 
    // low to mid (the range containing 1s), 
    // mid to high (the range containing unknown elements),
    // and high to N (the range containing 2s).
    // Traverse the array till mid <= high, 
    // check if (arr[mid] == 0) simply swap arr[low] with arr[mid],
    // and increament low and mid by 1 
    // if (arr[mid] == 1) increament mid by 1 
    // if (arr[mid] == 2) swap arr[mid] with arr[high],
    // and decreament only high by 1 
    // we are not increamenting mid because we had an unknown element at index high 

    int size = 12, arr[12] = {0, 1, 1, 0, 0, 1, 2, 2, 2, 2, 0, 1}; // output : {0, 0, 1, 1, 1, 1, 2}

    int low = 0, mid = 0, high = size-1;

    while (mid <= high) {
        switch(arr[mid]) {
            case 0: {
                int temp = arr[low];
                arr[low] = arr[mid];
                arr[mid] = temp;
                low++;
                mid++;
                break;
            }

            case 1: {
                mid++;
                break;
            }

            case 2: {
                int temp = arr[high];
                arr[high] = arr[mid];
                arr[mid] = temp;
                high--;
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

    // Logic : T(n) = O(n), space : O(1), 
    // traverse the array from i = 0 to i < n, n is the size of array 
    // create index by minusing 1 from absolute diffrence of arr[i] from 0 
    // check if element at index ie arr[index] < 0, is no then multiply arr[index] by -1 
    // else add index+1 in the answer 

    // code : 
    // int size = 8, arr[8] = {4,3,2,7,8,2,3,1}; // output : {2, 3} 
    int size = 10, arr[10] = {10,2,5,10,9,1,1,4,3,7}; // output : {10, 1} 

    for (int i = 0; i < size; i++) {
        int index = abs(arr[i]) - 1; // get index by element value - 1 
        if (arr[index] < 0) {
            // visited 
            printf("%d ", index+1);
        } else {
            arr[index] *= -1;
        }
    }
}

int main() {
    // lecture 10 : Solving leetcode codestudio questions 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();

    // p8();

    // p9();

    return 0;
}
