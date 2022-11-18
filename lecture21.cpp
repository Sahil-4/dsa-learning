#include <iostream>
#include <vector>

using namespace std;

void p1() {
    // Problem 1 : Rotate the array 

    // Statement : Given an array, 
    // rotate the array to the right by k steps, (k >= 0) 

    // Logic : create new array/vector temp 
    // copy arrays value to temp 
    // traverse the temp array 
    // update value of arr[(i+k)%arr.size()] = temp[i];
    // (i+k)%arr.size() will rotate ith element to kth position 

    vector<int> arr; // 1,2,3,4,5,6,7
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    int k = 3;
    // output : 5,6,7,1,2,3,4 
    // 0 1 2 3 4 5 6 

    vector<int> temp(arr);

    for (int i = 0; i < arr.size(); i++) {
        arr[(i+k)%arr.size()] = temp[i];
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void p2() {
    // Problem 2 : 1752. Check if Array Is Sorted and Rotated 

    // Statement : Given an array nums, 
    // return true 
    // if the array was originally sorted in non-decreasing order, 
    // then rotated some number of positions (including zero). 
    // Otherwise, return false. 

    // Logic : take a variable count = 0; 
    // traverse the given array i = 1 to i < size_of_array 
    // check arr[i-1] > arr[i] 
    // if true increament count by 1 
    // after ending loop 
    // check arr[size_of_array-1] > arr[0] 
    // finally check if count is less then or equal to 1 
    // if true then return true, given array is sorted and rotated 
    // else return false 

    // Code : 

    // int size = 5, v[5] = {3,4,5,1,2};
    int size = 5, v[5] = {3,4,5,1,2};

    int count = 0;
    for (int i = 1; i < size; i++) {
        if (v[i-1] > v[i]) {
            count++;
        }
    }

    if (v[size-1] > v[0]) {
        count++;
    }

    if (count <= 1) {
        cout << "array is sorted and rotated";
    } else {
        cout << "array is not sorted and rotated";
    }
    cout << endl;
}

void p3() {
    // Problem 3 : Sum of two arrays 

    // Statement : given integers in the form of two arrays arr_1 and arr_2 of size n and m respectively 
    // return the array of sum of both arrays 

    int size_1 = 4, arr_1[4] = {1, 2, 3, 4};
    int size_2 = 1, arr_2[1] = {6};

    vector<int> sums;
    int carry = 0;
    
    // calculating both arrays digits sums 
    int i =size_1-1, j = size_2-1;
    while (i >= 0 && j >= 0) {
        int sum = arr_1[i--] + arr_2[j--] + carry;
        carry = sum/10;
        sums.push_back(sum%10);
    }

    // calculating remained elements sum of arr_1
    while (i >= 0) {
        int sum = arr_1[i--] + carry;
        carry = sum/10;
        sums.push_back(sum%10);
    }

    // calculating remained elements sum of arr_2
    while (j >= 0) {
        int sum = arr_2[j--] + carry;
        carry = sum/10;
        sums.push_back(sum%10);
    }

    // adding remained carry 
    while (carry != 0) {
        int sum = carry%10;
        carry = sum/10;
        sums.push_back(sum%10);
    }

    // reversing vector 
    int l = 0, h = sums.size()-1;
    while(l < h) {
        swap(sums[l++], sums[h--]);
    }

    // printing final answer 
    for (int i = 0; i < sums.size(); i++) {
        cout << sums[i];
    }
    cout << endl;
}

int main() {
    // Lecture 21 : Solving Arrays Problems 

    // p1();

    // p2();

    // p3();

    return 0;
}
