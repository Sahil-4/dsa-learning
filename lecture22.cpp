#include <iostream>
#include <vector>

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
    char str[6] = {'H', 'e', 'l', 'l', 'o'};

    // taking string input from user 
    cin >> str;

    // printing output 
    cout << str << endl;
}

void p2() {
    // Problem 1 : find the length of string 

    // given an array of characters 
    // return the length of string 

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
            break;
        }
    }
    cout << "palindrome";
}

void p5() {
    // Problem 4 : LC 125. Valid Palindrome - https://leetcode.com/problems/valid-palindrome/

    // Statement : Given a string s or phrase, 
    // return true if it is a palindrome, 
    // or false if it is not a palindrome

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

        if (ch_l >= 'A' && ch_l <= 'Z') {
            ch_l = 'a' + (ch_l - 'A');
        }

        if (ch_h >= 'A' && ch_h <= 'Z') {
            ch_h = 'a' + (ch_h - 'A');
        }

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

    // char s[] = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    // int size = 15;
    // char s[] = {'s', 'h', 'e', ' ', 'b', ' ', 'a'};
    // int size = 7;
    char s[] = {'t', 'h', 'e'};
    int size = 3;

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

    string str = "Coding Ninjas Is A Coding Platform";

    while (str.find(' ') != 0 && str.find(' ') <= str.length()) {
        str.replace(str.find(' '), 1, "@40");
    }

    cout << str;
}

void p9() {
    // Problem 8 : 1910. Remove All Occurrences of a Substring - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/ 

    // Statement : Given two strings s and part, 
    // perform the following operation on s until all occurrences of the substring part are removed:
    // Find the leftmost occurrence of the substring part and remove it from s.
    // Return s after removing all occurrences of part.

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

    // Logic : using sliding window 
    // store string s1 chars count 
    // traverse s2 using window of size s1 
    // store s2 chars count 
    // check if s1 chars count is same as s2 chars count 

    string s1 = "ab", s2 = "eidbaooo";

    int s1_count[26] = {0};

    for (int j = 0; j < s1.length(); j++) {
        int index = s1[j] - 'a';
        s1_count[index]++;
    }

    // traversing s2 
    int i = 0;
    int window_size = s1.length();
    int s2_count[26] = {0};

    // first window 
    while (i < window_size && i < s2.length()) {
        int index = s2[i]-'a';
        s2_count[index]++;
        i++;
    }

    // checkEquality 
    if (checkEquality(s1_count, s2_count) == 1) {
        cout << "true" << endl;
        return;
    }

    // all windows 
    while (i < s2.length()) {
        // new char count 
        int index = s2[i]-'a';
        s2_count[index]++;

        // old char count 
        index = s2[i-window_size]-'a';
        s2_count[index]--;

        i++;

        // checkEquality
        if (checkEquality(s1_count, s2_count) == 1) {
            cout << "true" << endl;
            return;
        }
    }

    cout << "false" << endl;
}

void p11() {
    // Problem 10 : 1047. Remove All Adjacent Duplicates In String - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/ 

    // Statement : You are given a string s consisting of lowercase English letters. 
    // A duplicate removal consists of choosing two adjacent and equal letters and removing them.
    // We repeatedly make duplicate removals on s until we no longer can.
    // Return the final string after all such duplicate removals have been made. 
    // It can be proven that the answer is unique.

    string str = "abbaca"; // output : ca 

    // -------------- Not Optimised ---------------- // 
    // int i = 0;
    // while (i < str.length()) {
    //     if (str[i] == str[i+1]) {
    //         str.erase(i, 2);
    //         i = 0;
    //         continue;
    //     }
    //     i++;
    // }
    // -------------- Not Optimised ---------------- // 

    string final_str = "";

    for (int i = 0; i < str.length(); i++) {
        if (final_str.back() != str[i]) {
            final_str.push_back(str[i]);
        } else {
            final_str.pop_back();
        }
    }

    cout << final_str;

    // !!!!!!!!!!!!!!!!!! not done !!!!!!!!!!!!!!!!!!!!!!!!!!! // 
    // !!!!!!!!!!!!!!!!!! homework !!!!!!!!!!!!!!!!!!!!!!!!!!! // 
}

void p12() {
    // Problem 11 : 443. String Compression - https://leetcode.com/problems/string-compression/ 

    // Statement : Given an array of characters chars, 
    // compress it using the following algorithm:
    // Begin with an empty string s. 
    // For each group of consecutive repeating characters in chars:
    // If the group's length is 1, append the character to s.
    // Otherwise, append the character followed by the group's length.
    // The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
    // After you are done modifying the input array, return the new length of the array.
    // You must write an algorithm that uses only constant extra space.

    char chars[8] = {'a','a','b','b','c','c','c'};;
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
