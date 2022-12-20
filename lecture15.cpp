#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void p1() {
    // Problem 1 : Book allocation problem - https://www.codingninjas.com/codestudio/problems/allocate-books_1090540

    // Statement : given an array of n integers,
    // representing n number of book's pages, 
    // and an integer m denoting number of students 
    // the task is to allocate books in m students such that 
    // 1. all books should be allocated 
    // 2. every student should have atleast one book 
    // 3. book allocation should be in contiguous manner 
    // books should be allocated such that maximum number of pages,
    // allocated to a student should be minimum 

    // Logic : using Binary Search 
    // first find the search space 
    // in worst case low can be maximum number of pages of books, 
    // and high can be sum of all pages 
    // find mid and check if it can be a solution or not 
    // if it is a solution save it as ans = mid and high = mid-1
    // else update low = mid+1
    // then update mid 
    // to check wether mid is a solution or not 
    // allocate mid number of pages to m students 
    // if it is possible to allocate mid number of pages to m students 
    // then it could be our ans 

    // Code : 
    // int n_of_books = 4, books_arr[4] = {10, 20, 30, 40};
    // int n_of_students = 2;
    // int n_of_books = 5, books_arr[5] = {25, 46, 28, 49, 24};
    // int n_of_students = 4;
    int n_of_books = 4, books_arr[4] = {5, 17, 100, 11};
    int n_of_students = 4;

    int min_max_pages = -1; // ans 

    int low = 0, high = 0;

    // for high 
    for (int i = 0; i < n_of_books; i++) {
        high += books_arr[i];
        if (books_arr[i] > low) {
            low = books_arr[i];
        }
    }

    int mid = low + (high-low)/2;

    // search space is ready low = max pages book, high = sum of all book's pages 

    // performing binary search 
    while (low <= high) {
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

    cout << min_max_pages;
}

void p2() {
    // Problem 2 : Painters partition problem - https://www.codingninjas.com/codestudio/problems/painter's-partition-problem_1089557

    // Statement : given an array of length of N number of boards 
    // and an integer K represents number of painters 
    // to paint each unit of board takes 1 unit of time 
    // allocate the area of board such that it takes minimum time to paint the N boards 
    // allocation should be in contiguous manner

    // Logic : using binary search 
    // make search space 
    // low = area of biggest board, high = sum of area of all boards 
    // find mid
    // apply binary search 
    // allocate mid area of board 
    // if is is possible to allocate mid area of board to K painters 
    // then it can be the answer 
    // if it is an answer,
    // store mid as answer and update high = mid-1
    // else, 
    // update low = mid+1
    // lastly update mid 

    // Code : 
    int n_of_boards = 4, boards_area_arr[4] = {5, 5, 5, 5};
    int n_of_painters = 2;

    int ans = -1;

    int low = 0, high = 0, mid;

    for (int i = 0; i < n_of_boards; i++) {
        high += boards_area_arr[i];
        if (low < boards_area_arr[i]) {
            low = boards_area_arr[i];
        }
    }

    // search space is ready 

    mid = low + (high-low)/2;

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

    cout << ans;
}

bool canPlace(vector<int> &stalls, int cows, int dist) {
    // Helper functiom for p3();
    // check if we are able to place all cows by mainting dist distance 

    int placed_cows = 1;
    int placed_position = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - placed_position >= dist) {
            placed_cows++;
            placed_position = stalls[i];
        }
    }

    return placed_cows >= cows;
}

void p3() {
    // Problem 3 : Aggressive Cows - https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559
  
    // Statement : given an array of N position of stalls,
    // and K number of cows,
    // task is to place cows such that minimum distance between is maximum 
    // find that largest minimum distance 

    // Logic : Using Binary Search 
    // sort the array 
    // create search space 
    // low = 0, 
    // and high = maximum distance between two stalls 
    // calculate mid 
    // apply binary search 
    // check if we can place cows by maintaining mid distance 
    // if yes store mid as answer and update low = mid+1 
    // else update high = mid-1
    // finally update mid 
    // logic to place cows 
    // take placed cows count and last placed cows position 
    // place all cows by checking if distance between last placed cows position and current cows position is equal to or bigger then mid 

    // Code : 
    vector<int> stalls{1, 2, 3}; // answer : 2 
    int k = 2;

    sort(stalls.begin(), stalls.end());

    int low, high, mid;
    int ans = -1;

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < stalls.size(); i++) {
        if (stalls[i] < min) {
            min = stalls[i];
        }
        if (stalls[i] > max) {
            max = stalls[i];
        }
    }

    low = 0;
    high = max-min;

    mid = low + (high-low)/2;

    while (low <= high) {
        if (canPlace(stalls, k, mid)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }

        mid = low + (high-low)/2;
    }

    cout << ans << endl;
}

int main() {
    // Lecture 15 : Binary search interview questions 

    // p1();

    // p2();

    // p3();

    return 0;
}