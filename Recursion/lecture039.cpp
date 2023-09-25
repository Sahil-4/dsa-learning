#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int> arr, vector<vector<int>> &ans, int index) {
    // base condition 
    if (index >= arr.size()) {
        // adding permutaion in answers vector 
        ans.push_back(arr);
        return;
    }

    // putting all the elements at current index one by one 
    for (int i = index; i < arr.size(); i++) {
        swap(arr[index], arr[i]);
        permutation(arr, ans, index + 1);
        swap(arr[index], arr[i]);
    }
}

void p1() {
    // Problem 1 : LC 46 Permutations - https://leetcode.com/problems/permutations/

    // Statement : Given an array nums of distinct integers, 
    // return all the possible permutations. 
    // Permutation : creating a new string/array by only 
    // changing the index of given array/string's elements 

    // Logic : 
    // create a vector ans to store all the permutations 
    // then create a function with signature 
    // void permutation(vector<int> arr, vector<vector<int>> &ans, int index); 
    // arr is main/given vector of integers 
    // ans is vector to store all the permutations 
    // index is current index 
    // add base condition 
    // if index >= size of arr 
    // add the arr in ans vector 
    // and return from the function 
    // loop through the array/vector from i = 0 to i < size of arr 
    // swap all the arr[i] with arr[index]
    // and call permutation() function after increamenting index by 1 
    // after returing of function 
    // swap the arr[i] with arr[index] again 
    // Note : increament index in parameters only 
    // else it will be get updated inside function also 
    // and will cause unexpected swapping of elements 

    // Code :
    // vector<int> arr{0, 1};
    // vector<int> arr{1};
    vector<int> arr{1, 2, 3};

    // vector to store answers/all permutations 
    vector<vector<int>> ans;

    // solving/finding all the permutations 
    permutation(arr, ans, 0);

    // printing all the permutations 
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Lecture 39 : Recursion Day 9

    // p1();

    return 0;
}