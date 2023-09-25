#include <iostream>
#include <vector>

using namespace std;

void solve(string str, vector<vector<char>> &key_mapping, vector<string> &ans, string co, int i) {
    if (i >= str.length()) {
        if (str.length() != 0) {
            // storing answer in ans vector
            ans.push_back(co);
        }
        return;
    }

    // current digit
    int c_digit = stoi(string(1, str[i]));

    // trying all possible combinations
    for (int x = 0; x < key_mapping[c_digit].size(); x++) {
        co.push_back(key_mapping[c_digit][x]);
        solve(str, key_mapping, ans, co, i + 1);
        // removing last char to work with next char
        co.pop_back();
    }
}

void p1() {
    // Problem : LC 17 - Letter Combinations of a Phone Number - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

    // Statement : Given a string containing digits from 2-9 inclusive,
    // return all possible letter combinations
    // that the number could represent. Return the answer in any order.
    // A mapping of digits to letters (just like on the telephone buttons) is given below.
    /*
    2 : a b c
    3 : d e f
    4 : g h i
    5 : j k l
    6 : m n o
    7 : p q r s
    8 : t u v
    9 : w x y z
    */
    // Note that 1 does not map to any letters.

    // Logic :
    // create an array/vector ans to store answers
    // another array to store mapping of keypad digits and letters
    // create a function solve(),
    // which will take a string of digits
    // array of key mapping
    // answers array
    // a temporary string co to store current combination
    // and lastly index i
    // inside function add base condition
    // if i >= string_length
    // simply return the function
    // after adding current combination in ans
    // add current combination in answers array if string_length is not 0
    // after base case
    // get current digit (ith char of str)
    // append all the possible mappings of current digit
    // at the end of co one by one
    // and make call to itself
    // after increamenting i by 1

    // Code :
    // string number = "2";  // output : a b c
    // string number = "22";  // output : aa ab ac ba bb bc ca cb cc
    // string number = ""; // output :
    string number = "23"; // output : ad ae af bd be bf cd ce cf

    // answers vectore
    vector<string> ans;

    // digits and letters mapping
    vector<vector<char>> key_mappings{
        {}, // 0
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'}, // 1 2 3
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'}, // 4 5 6
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'} // 7 8 9
    };

    // solving
    solve(number, key_mappings, ans, "", 0);

    // printing answers
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    // Lecture 38 : Recursion Day 8 - Phone keypad problem

    // p1();

    return 0;
}