#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void p1() {
    // working of 2d array 
    // creation of 2d array of 3x3 (row * col)
    int arr[9] /*3*3 = 9*/ = {1, 2, 3,
                                4, 5, 6,
                                7, 8, 9};

    // printing 2nd rows 3rd col 
    // cols * row_number + col_number (3 * 1 + 2 = 5)
    // cout << arr[5] << endl;

    // naive way to create 2d array 
    int arr_2d[3][3] = {{1, 2, 3}, 
                        {4, 5, 6}, 
                        {7, 8, 9}};

    // printing 2nd rows 3rd col 
    cout << arr_2d[1][2] << endl;

    // print all elements of 2d array 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr_2d[i][j] << " ";
        }
        cout << endl;
    }
}

void p2() {
    // Problem 1 : search in 2d array 

    int arr[4][5] = {{101, 102, 103, 104, 105}, 
                        {201, 202, 203, 204, 205}, 
                        {301, 302, 303, 304, 305}, 
                        {401, 402, 703, 404, 405}};
    int key = 703;

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 5; col++) {
            if (arr[row][col] == key) {
                cout << "element found at row : " << row << " col : " << col;
            }
        }
    }
}

void p3() {
    // Problem 2 : row wise sum 

    // given a matrix 
    // find the row wise sum 
    /*
    1 2 3 = 6 
    4 5 6 = 15 
    7 8 9 = 24 
    */

   int arr[2][4] = {{2, 5, 13, 7}, {3, 8, 2, 12}};

    // row wise sum 
    for (int row = 0; row < 2; row++) {
        int sum = 0;
        for (int col = 0; col < 4; col++) {
            sum += arr[row][col];
        }

        cout << "sum of row : " << row << " is " << sum << endl;
    }


    // col wise sum ---------- EXTRA ---------- 
    for (int col = 0; col < 4; col++) {
        int sum = 0;
        for (int row = 0; row < 2; row++) {
            sum += arr[row][col];
        }

        cout << "sum of col : " << col << " is " << sum << endl;
    }
}

void p4() {
    // Problem 3 : largest row sum 

    int arr[2][4] = {{2, 5, 13, 7}, {3, 8, 2, 12}};
    int sum = INT_MIN;
    int ans = -1;

    // row wise sum 
    for (int row = 0; row < 2; row++) {
        int temp_sum = 0;
        for (int col = 0; col < 4; col++) {
            temp_sum += arr[row][col];
        }

        if (temp_sum > sum) {
            sum = temp_sum;
            ans = row;
        }
    }

    cout << "largest sum is of row : " << ans << " is " << sum << endl;
}

void p5() {
    // Problem 4 : Print Like A Wave - https://www.codingninjas.com/codestudio/problems/print-like-a-wave_893268

    // Statement : For a given two-dimensional integer array ‘ARR’ of size (N x M), 
    // print the ‘ARR’ in a sine wave order, 
    // i.e., print the first column top to bottom, 
    // next column bottom to top, and so on.

    int arr[2][4] = {{2, 5, 13, 7}, {3, 8, 2, 12}};
    int v_size = 2, h_size = 4;

    vector<int> vcr;

    for (int h = 0; h < 4; h++) { 
        if (h%2 == 0) {
            // printing top to bottom 
            for (int v = 0; v <= v_size-1; v++) {
                vcr.push_back(arr[v][h]);
            }
        } else {
            // printing bottom to top 
            for (int v = v_size-1; v >=0; v--) {
                vcr.push_back(arr[v][h]);
            }
        }
    }

    for (int i = 0; i < vcr.size(); i++) {
        cout << vcr[i] << " ";
    }
}

void p6() {
    // Problem 5 : 54. Spiral Matrix - https://leetcode.com/problems/spiral-matrix/ 

    // Statement : Given an m x n matrix, 
    // return all elements of the matrix in spiral order. 

    // logic : using while loop 
    // print first row (left to right) 
    // last column (top to bottom) 
    // last row (right to left) 
    // first column (bottom to top) 
    // maintain a count variable after processing each element increament count by 1

    // vector<vector<int>> vc = {{1,2,3},{4,5,6},{7,8,9}}; // working 
    // vector<vector<int>> vc = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}; // working 
    // vector<vector<int>> vc = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}}; // working 
    vector<vector<int>> vc = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    for (int i = 0; i < vc.size(); i++) {
        for (int j = 0; j < vc[0].size(); j++) {
            cout << vc[i][j] << " ";
        }
        cout << endl;
    }

    int v_size = vc.size(), h_size = vc[0].size();

    // answer vector 
    vector<int> ans;

    // maintaining count of elements 
    int count = 0;
    int total = v_size*h_size;

    // indexes 
    int firstRow = 0;
    int firstCol = 0;
    int lastRow = v_size-1;
    int lastCol = h_size-1;

    // spriral printing 
    while (count < total) {
        // first row (left to right) 
        for (int col = firstCol; count < total && col <= lastCol; col++) {
            ans.push_back(vc[firstRow][col]);
            count++;
        }
        firstRow++;

        // last column (top to bottom) 
        for (int row = firstRow; count < total && row <= lastRow; row++) {
            ans.push_back(vc[row][lastCol]);
            count++;
        } 
        lastCol--;

        // last row (right to left) 
        for (int col = lastCol; count < total && col >= firstCol; col--) {
            ans.push_back(vc[lastRow][col]);
            count++;
        }
        lastRow--;

        // first column (bottom to top) 
        for (int row = lastRow; count < total && row >= firstRow; row--) {
            ans.push_back(vc[row][firstCol]);
            count++;
        }
        firstCol++;
    }

    // printing ans 
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

void p7() {
    // Problem 6 : 74. Search a 2D Matrix

    // Statement : search for a value target 
    // in an m x n integer matrix matrix. 
    // This matrix has the following properties:
    // Integers in each row are sorted from left to right.
    // The first integer of each row is greater than the last integer of the previous row.

    // Logic : using binary search 
    
    // Code : 
    
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 10;

    int row = matrix.size(), col = matrix[0].size();

    for (int h = 0; h < row; h++) {
        for (int v = 0; v < col; v++) {
            cout << matrix[h][v] << " ";
        }
        cout << endl;
    }

    // creating search space 
    int low = 0, high = (row*col) - 1;
    int mid = low + (high-low)/2;

    while (low <= high) {
        // int element = matrix[mid/col][mid%col];
        int element = matrix[mid/row][mid%row];

        if (element == target) {
            cout << "element : " << element << " fount at row : " << mid/col << " col : " << mid%col << endl;
            return;
        }

        if (element < target) {
            low = mid+1;
        } else {
            high = mid-1;
        }

        mid = low + (high-low)/2;
    }

    cout << "element not found" << endl;
}

void p8() {
    // Problem 7 : 240. Search a 2D Matrix II 

    // Statement : Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
    // Integers in each row are sorted in ascending from left to right.
    // Integers in each column are sorted in ascending from top to bottom.

    // Logic : using two pointer approach  

    // Code : 
    // vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;

    // two pointer approach 
    int r = 0, c = matrix[0].size()-1;

    while (r < matrix.size() && c >= 0) {
        int element = matrix[r][c];

        if (element == target) {
            cout << "element " << target << " fount at " << r << " " << c << endl;
            return;
        }

        if (element < target) {
            r++;
        } else {
            c--;
        }
    }

    cout << target << " not found" << endl;
}

int main() {
    // Lecture 23 : Introduction to 2d arrays 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();
    
    // p8();

    return 0;
}
