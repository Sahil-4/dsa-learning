#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

void p1() {
    // 1. Char : contains only a single character 

    // char declaration and initialisation 
    char ch = 'A';

    // taking char input from user 
    // cin >> ch;

    // printing output 
    // cout << "Your character is " << ch << endl;

    // 2. string : 1D char array 

    // string declaration and initialisation 
    // char str[6] = {'H', 'e', 'l', 'l', 'o'};

    // stl sting 
    string str;

    // taking string input from user 
    cin >> str;

    // printing output 
    cout << str << endl;
}

void p2() {
    // Problem 1 : find the length of string 

    // given an array of characters 
    // return the length of string 

    // logic : 
    // take i = 0
    // traverse the array of chars 
    // if arr[i] != 0 
    // increament count by 1 
    // else return the count 

    char ch[12];

    cout << "enter your string : ";
    cin >> ch;
    cout << endl;

    int count = -1;
    // for (count; ch[++count] != 0;) {}
    while (ch[++count] != 0) {}

    cout << "your string is : " << ch << " and length is : " << count;
}

void p3() {
    // Problem 2 : 344. Reverse String - https://leetcode.com/problems/reverse-string/ 

    // Statement : given an char array,
    // reverse the array 
    // then print 

    // logic : 
    // traverse the whole array from i = 0 to i <= size/2 
    // replace first element by last element 

    char ch[12] = "this"; // output : siht 

    int l = 0, h = 3;
    while (l <= h) {
        swap(ch[l++], ch[h--]);
    }

    cout << ch << endl;
}

void p4() {
    // Problem 3 : Check If The String Is A Palindrome - https://www.codingninjas.com/codestudio/problems/check-if-the-string-is-a-palindrome_1062633 

    // Statement : given a string, 
    // ignore all symbols and whitespaces, case sensitive 
    // then check is the string is palindrome or not 

    // logic : 
    // first traverse the string and remove all symbols and whitespaces in the array 
    // and make the srtring case in-sensitive 
    // now traverse the array from i = 0 to i < size/2 
    // check if arr[i] is == to arr[size-i-1] 
    // if not true return that string is not palindrome 
    // else increament i by 1 and go to next element 

    // string s = "N2 i&nJA?a& jnI2n";
    string s = "A1b22Ba";

    // remove all charactors other then [a-z]([97-122]), [A-Z]([65-90]) and [0-9]([48-57])
    int index = 0;
    int i = 0;
    while(i < s.size()) {
        // if ith char is [a-z], [A-Z] or [0-9] add it in string at index index 
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) {
            // make char lowercase 
            if (!(s[i] >= 48 && s[i] <= 57)) {
                int c = s[i];
                if (c >= 65 && c <= 90) {
                    // converting to lowercase 
                    char c2 = 122 - (90 - c);
                    s[i] = c2;
                }
            }
            // adding char in string 
            s[index++] = s[i];
        }
        i++;
    }

    // erasing extra chars 
    s.erase(s.begin() + index, s.end());

    // we have our string ready 
    cout << s << endl;

    // check for palindrome 
    int l = 0, h = s.size()-1;
    while (l < h) {
        if (s[l++] != s[h--]) {
            cout << "not a palindrome";
            return;
        }
    }
    cout << "palindrome";
}

void p5() {
    // Problem 4 : LC 125. Valid Palindrome - https://leetcode.com/problems/valid-palindrome/

    // Statement : Given a string s or phrase, 
    // return true if it is a palindrome, 
    // or false if it is not a palindrome
    // ignore all whitespaces and chars other than alphanumeric 

    // Logic : using two pointer 
    // initialise l = 0, h = length of string - 1 
    // run a loop till l < h 
    // check for string[l] and string[h] 
    // if anyone char is not alphanumeric skip that 
    // else convert them into lowercase 
    // check if string[l] == string[h] 
    // if yes go to next indices 
    // else return not palindrome 

    string s = "A man, a plan, a canal: Panama";
    int l = 0, h = s.length()-1;

    while (l < h) {
        char ch_l = s[l], ch_h = s[h];

        // if a char is not alphanumeric at l index simply skip that character 
        if (!((ch_l >= 'a' && ch_l <= 'z') || (ch_l >= 'A' && ch_l <= 'Z') || (ch_l >= '0' && ch_l <= '9'))) {
            l++;
            continue;
        }

        // if a char is not alphanumeric at h index simply skip that character 
        if (!((ch_h >= 'a' && ch_h <= 'z') || (ch_h >= 'A' && ch_h <= 'Z') || (ch_h >= '0' && ch_h <= '9'))) {
            h--;
            continue;
        }

        // converting to lowercase 
        if (ch_l >= 'A' && ch_l <= 'Z') {
            ch_l = 'a' + (ch_l - 'A');
        }

        // converting to lowercase 
        if (ch_h >= 'A' && ch_h <= 'Z') {
            ch_h = 'a' + (ch_h - 'A');
        }

        // checking for not palindrome 
        if (ch_l != ch_h) {
            cout << "not a palindrome" << endl;
            return;
        }

        l++;
        h--;
    }

    cout << "palindrome" << endl;
}

void p6() {
    // Problem 5 : LC 186 Reverse words in a string ii - https://leetcode.com/problems/reverse-words-in-a-string-ii/

    // Statement : given an array of char, 
    // reverse the order of the words, 
    // word : sequence of non space characters 

    // Logic : using Bruteforce 
    // take an array w_chars to store reverse of given string 
    // take a variable count = 0 
    // and i = 0 
    // run a loop till count < size of string 
    // check s[count] != " " (whitespace)
    // if true put s[count] in chars at index i 
    // now increament i by 1 
    // else update i = 0 
    // add a space at the very beginning of chars 
    // at the end increament count by 1 

    char s[] = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    int size = 15;
    // char s[] = {'s', 'h', 'e', ' ', 'b', ' ', 'a'};
    // size = 7;
    // char s[] = {'t', 'h', 'e'};
    // size = 3;

    vector<char> v_cr;

    int count = 0;
    int i = 0;
    while (count < size) {
        if (s[count] != ' ') {
            v_cr.insert(v_cr.begin()+i, s[count]);
            i++;
        } else {
            i = 0;
            v_cr.insert(v_cr.begin()+i, ' ');
        }

        count++;
    }

    for (int i = 0; i < size; i++) {
        cout << v_cr[i];
    }
}

void p7() {
    // Problem 6 : Maximum Occuring Character - https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1 

    // Statement : Given a string str. 
    // The task is to find the maximum occurring character 
    // in the string str. 
    // If more than one character occurs the maximum number of time 
    // then print the lexicographically smaller character.

    // Logic : 
    // take an array freq of size 26 
    // in that array every element denotes the frequency of char from a to z 
    // now traverse the given string i = 0 to i < size of string 
    // get the char at str[i]
    // and increament frequency of that perticular char 
    // finally check the maximum occurring element 

    string s = "testsample";
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            freq[s[i] - 'a']++;
        } else if(s[i] >= 'A' && s[i] <= 'Z') {
            freq[s[i] - 'A']++;
        }
    }

    int ans = -1;
    char ch;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > ans) {
            ans = freq[i];
            ch = 'a'+i;
        }
    }

    cout << ch;
}

void p8() {
    // Problem 7 : Replace Spaces - https://www.codingninjas.com/codestudio/problems/replace-spaces_1172172

    // Statement : You have been given a string 'STR' of words. 
    // You need to replace all the spaces between words with “@40”.

    // logic : 
    // traverse the string 
    // find all the whitespaces and replace it with "@40"
    // to find whitespaces use String.find(character);
    // to replace use String.replace(position, character_to_replace, new_character);

    string str = "Coding Ninjas Is A Coding Platform";

    while (str.find(' ') != 0 && str.find(' ') <= str.length()) {
        str.replace(str.find(' '), 1, "@40");
    }

    cout << str;
}

void p9() {
    // Problem 8 : 1910. Remove All Occurrences of a Substring - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/ 

    // Statement : Given two strings str and part, 
    // perform the following operation on str until all occurrences of the substring part are removed:
    // Find the leftmost occurrence of the substring part and remove it from s.
    // Return s after removing all occurrences of part.

    // Logic : 
    // find part in str 
    // if found erase that part 
    // using String.erase(position, length_of_part);

    string str = "daabcbaabcbc";
    string part = "abc";

    while (str.find(part) <= str.length()) {
        // str.replace(str.find(part), part.length(), "");
        str.erase(str.find(part), part.length());
    }

    cout << str;
}

int checkEquality(int arr_1[], int arr_2[]) {
    // for p10();
    for (int j = 0; j < 26; j++) {
        if (arr_1[j] != arr_2[j]) {
            return 0;
        }
    }
    return 1;
}

void p10() {
    // Problem 9 : LC 567. Permutation in String - https://leetcode.com/problems/permutation-in-string/ 

    // Statement : Given two strings s1 and s2, 
    // return true if s2 contains a permutation of s1, 
    // or false otherwise.
    // permutation : making a new string, 
    // after rearranging the chars of old string 

    // Logic : using sliding window 
    // first traverse the string s1 
    // and store thw frequency of chars of s1 in s1_char_freq[] 
    // then traverse the string s2 from i = 0 to i < s1.length and i < s2.length 
    // and store thw frequency of chars of s2 in s2_char_freq[] 
    // now check if both s1_char_freq[] and s2_char_freq[] are same 
    // if same return true as string s2 has a permutation of string s1 
    // else move to next elements of s2 if exists 
    // run a loop till i < s2.length 
    // increament freq of ith char of string s2 
    // and decreament freq of the element that is not visible in window i.e. i - s1.length 
    // now check if both array of frequency has same freq of elements 
    // if yes then return true 
    // else increament i by 1 and move to next element 

    string s1 = "ab", s2 = "eidbaooo";

    // char array to store frequency of chars of string s1 
    int s1_char_freq[26] = {0};

    // traversing s1 
    for (int j = 0; j < s1.length(); j++) {
        // storing freq 
        int index = s1[j] - 'a';
        s1_char_freq[index]++;
    }

    // traversing s2 
    int i = 0;
    int window_size = s1.length();
    // char array to store frequency of chars of string s2 
    int s2_char_freq[26] = {0};

    // for first window 
    while (i < window_size && i < s2.length()) {
        // storing freq 
        int index = s2[i]-'a';
        s2_char_freq[index]++;
        i++;
    }

    // checking equality of freq 
    if (checkEquality(s1_char_freq, s2_char_freq) == 1) {
        cout << "true" << endl;
        return;
    }

    // for all other windows 
    while (i < s2.length()) {
        // new char freq 
        int index = s2[i]-'a';
        s2_char_freq[index]++;

        // old char freq 
        index = s2[i-window_size]-'a';
        s2_char_freq[index]--;

        // checkEquality 
        if (checkEquality(s1_char_freq, s2_char_freq) == 1) {
            cout << "true" << endl;
            return;
        }

        i++;
    }

    cout << "false" << endl;
}

void p11() {
    // Problem 10 : LC 1047. Remove All Adjacent Duplicates In String - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/ 

    // Statement : You are given a string s consisting of lowercase English letters. 
    // A duplicate removal consists of choosing two adjacent and equal letters and removing them.
    // We repeatedly make duplicate removals on s until we no longer can.
    // Return the final string after all such duplicate removals have been made. 
    // It can be proven that the answer is unique.

    // Logic : using stack 
    // initialise a stack st 
    // traverse the string str from i = 0 to i < str.length 
    // if stack is empty or top element of stack is not equal to str[i]
    // push the str[i] into stack 
    // else pop the last element from stack 
    // increament i by 1 and move to next element 
    // lastly make a new string using the stack 
    // then reverse the final string 

    string str = "abbaca"; // output : ca 
    string final_str;
    stack<char> st;

    for (int i = 0; i < str.length(); i++) {
       if (st.empty() || st.top() != str[i]) {
            st.push(str[i]);
        } else {
            st.pop();
        }
    }

    while (st.size() > 0) {
        final_str.push_back(st.top());
        st.pop();
    }

    reverse(final_str.begin(), final_str.end());

    cout << final_str;
}

void p12() {
    // Problem 11 : 443. String Compression - https://leetcode.com/problems/string-compression/ 

    // Statement : Given an array of characters chars, 
    // compress it using the following algorithm:
    // Begin with an empty string s. 
    // For each group of consecutive repeating characters in chars:
    // If the group's length is 1, append the character to s.
    // Otherwise, append the character followed by the group's length.
    // The compressed string s should not be returned separately, but instead, be stored in the input character array chars. 
    // Note that group lengths that are 10 or longer will be split into multiple characters in chars.
    // After you are done modifying the input array, return the new length of the array.
    // You must write an algorithm that uses only constant extra space.

    // Logic : using two pointer approach 
    // take a variable count = 0 
    // traverse the chars array from s = 0 to s < size of chars array 
    // inside run a loop from j = s+1 to j < size  
    // and find the count of all the consecutive elements (==chars[s])
    // then store the char chars[s] in chars at count index 
    // then increament count by 1 
    // now store the occurrence of chars[s] in chars at count index 
    // go to next different element in chars 
    // lastly remove all the extra chars from chars array 
    // from i = count to i < size 

    char chars[8] = {'a','a','b','b','c','c','c'};
    int size = 7;

    int count = 0;
    int s = 0;

    while (s < size) {
        // count all duplicate chars 
        int j = s+1;
        while (j < size && chars[s] == chars[j]) {
            j++;
        }

        // store char 
        chars[count++] = chars[s];

        int char_count = j-s;

        if (char_count > 1) {
            string dgts = to_string(char_count);
            for (char dgt : dgts) {
                chars[count++] = dgt;
            }
        }

        s = j;
    }

    // remove other characters 
    for (int i = count; i < size; i++) {
        chars[i] = 0;
    }

    cout << chars << " " << count;
}

int main() {
    // Lecture 22 : All about Char, Arrays and Strings 

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();

    // p8();

    // p9();

    // p10();

    // p11();

    // p12();

    return 0;
}
