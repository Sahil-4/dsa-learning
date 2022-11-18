#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// function to check if we are able to place all cows by mainting dist distance 
int placeCows(int *arr, int size, int cows, int dist);

void p1() {
    // Problem 1 : Book allocation problem - https://www.codingninjas.com/codestudio/problems/ayush-and-ninja-test_1097574
    // Statement : given an array of n integers,
    // representing n number of books pages 
    // and an integer m denoting number of students 
    // the task is to allocate books in m students such that 
    // 1. all books should be allocated 
    // 2. every student should have a book 
    // 3. book allocation should be in contiguous manner 
    // books should be allocated such that maximum number of pages allocated to a student 
    // should be minimum 

    // Logic : using Binary Search 
    // first find the search space 
    // in worst case low can be maximum number of pages of books 
    // and high can be sum of all pages 
    // find mid and check if it can be a solution or not 
    // if it is a solution save it as ans = mid and high = mid-1
    // else update low = mid+1
    // then update mid 
    // to check wether mid is a solution or not 
    // allocate mid number of pages to m students 
    // if it is possible to allocate mid number of pages to m students 
    // then it could be our ans 

    // Code 

    // int n_of_books = 4, books_arr[4] = {10, 20, 30, 40};
    // int n_of_students = 2;
    // int n_of_books = 5, books_arr[5] = {25, 46, 28, 49, 24};
    // int n_of_students = 4;
    int n_of_books = 4, books_arr[4] = {5, 17, 100, 11};
    int n_of_students = 4;
    int min_max_pages = -1;

    int low = 0, high = 0;

    // for high 
    for (int i = 0; i < n_of_books; i++) {
        high += books_arr[i];
    }

    int mid = low + (high-low)/2;

    // search space is ready low = 0, high = sum of all book's pages 

    // performing binary search 
    while (low <= high) {
        printf("low : %d high : %d mid : %d\n", low, high, mid);

        int students = 1;
        int n_of_pages = 0;
        int flag = 1;

        // allocating books to students 
        for (int i = 0; i < n_of_books; i++) {
            if (books_arr[i] > mid) { // if books pages are more then mid number of pages 
                flag = -1;
                low = mid+1;
                break;
            }

            if (n_of_pages + books_arr[i] <= mid) {
                n_of_pages += books_arr[i];
            } else { // allocating books to another student 
                students++;
                n_of_pages = books_arr[i];
            }
        }

        if (students > n_of_students) {
            flag = -1;
        }

        if (flag == 1) {
            min_max_pages = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }

        // updating mid 
        mid = low + (high-low)/2;
    }

    printf("Answer is %d", min_max_pages);
}

void p2() {
    // Problem 2 : Painters partition problem - https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557
    // Statement : given an array of length of N number of boards 
    // and an integer K represents number of painters 
    // to paint each unit of board takes 1 unit of time 
    // allocate the area of board such that it takes minimum time to paint the N boards 
    // allocation should be in contiguous manner

    // Logic : using binary search 

    // Code : 
    
    int n_of_boards = 4, boards_area_arr[4] = {5, 5, 5, 5};
    int n_of_painters = 2;
    int ans = -1;

    int low = INT_MIN, high = 0, mid = 0;

    for (int i = 0; i < n_of_boards; i++) {
        high += boards_area_arr[i];
        if (low < boards_area_arr[i]) {
            low = boards_area_arr[i];
        }
    }

    mid = low + (high-low)/2;

    printf("low : %d high : %d mid : %d\n", low, high, mid);

    // search space is ready 

    // binary searching
    while(low <= high) {
        // allote the boards to painters 
        int painter = 1;
        int area = 0;
        int flag = 1;

        for (int i = 0; i < n_of_boards; i++) {
            if (boards_area_arr[i] > mid) {
                flag = -1;
                break;
            }
            
            if (area + boards_area_arr[i] <= mid) {
                area += boards_area_arr[i];
            } else {
                painter++;
                area = boards_area_arr[i];
            }
        }

        if (painter > n_of_painters) {
            flag = -1;
        }

        if (flag == 1) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }

        mid = low + (high-low)/2;
    }

    printf("Answer is %d", ans);
}

void p3() {
    // Problem 3 : Aggressive Cows - https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

    // Statement : given an array of N position of stalls,
    // and K number of cows,
    // task is to place cows such that minimum distance between is maximum 
    // find that largest minimum distance 

    // Logic : Using Binary Search 
    // sort array 
    // create search space 
    // find low = minimum distance between two stalls 
    // and high = maximum distance between two stalls 
    // calculate mid
    // apply binary search 
    // check if we can place cows by maintaining mid distance 
    // if so store mid as answer and update low = mid+1 
    // else update high = mid-1
    // finally update mid 
    // logic to place cows 
    // take placed cows count and last placed cows position 
    // place all cows by checking if distance between last placed cows position and current cows position is equal to or bigger then mid 
 
    // Code : 
    int size = 3, stalls_position[3] = {1, 2, 3}; // answer : 2 
    int cows = 2;

    int low = 0, high = 0;
    int mid = 0;
    int ans = -1;

    // Have to Sort Array -----------------

    // make or find the search space 
    // low = minimum distance between two stalls 
    // high = maximum distance between two stalls 

    high = stalls_position[size - 1]; // last element 
    mid = low + (high-low)/2;

    // Binary search 
    while (low <= high) {
        // place cows to stalls 
        if (placeCows(stalls_position, size, cows, mid) == 1) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }

        mid = low + (high-low)/2;
    }

    printf("answer is : %d", ans);
}

int placeCows(int *arr, int size, int cows, int dist) {
    int cow_count = 1;
    int cow_place = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] - cow_place >= dist) {
            cow_count++;
            cow_place = arr[i];
        }

        if (cow_count == cows) {
                return 1;
        }
    }

    return 0;
}

int main() {
    // Lecture 15 : Binary search interview questions 

    // p1();

    // p2();

    // p3();

    return 0;
}