#include <iostream>
#include <vector>

using namespace std;

void p1() {
    // Problem 1 : 204. Count Primes - https://leetcode.com/problems/count-primes/ 

    // Statement : Given an integer n, 
    // return the number of prime numbers that are strictly less than n.

    // logic : using sieve of eratosthenes 

    int n = 40;

    // is prime 
    // for (int i = 2; i < n; i++) {
    //     if (n%i == 0) {
    //         cout << "not prime" << endl;
    //     } else if (i == n-1) {
    //         cout << "prime" << endl;
    //     }
    // }

    // count all prime numbers less then n 
    int count = 0;
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;

    vector<int> all_primes; // contains all prime number !EXTRA 

    for (int i = 2; i < n; i++) {
        // check prime 
        if (primes[i]) {
            // update count if ith number is prime 
            count++;
            all_primes.push_back(i);

            // false all numbers that are present in ith table 
            for (int j = i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }

    cout << count << " prime numbers" << endl;

    // printing all prime numbers 
    for (int i = 0; i < all_primes.size(); i++) {
        cout << all_primes[i] << " ";
    }
    cout << endl;
}

void p2() {
    // Problem 2 : GCD 

    // logic : using Euclids algorithm 
    // gcd(a, b) = gcd(a-b, b) or gcd(a%b, b) 

    int n = 48, m = 72;

    if (n == 0) {
        cout << "answer is : " << m;
        return;
    }
    if (m == 0) {
        cout << "answer is : " << n;
        return;
    }

    while(n != m) {
        if (n > m) {
            n -= m;
        } else {
            m -= n;
        }
    }

    cout << "answer is : " << n;
}

void p3() {
    // Problem 3 : Modular Exponentiation - https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146 

    // Statement : You are given a three integers 'X', 'N', and 'M'. 
    // Your task is to find ('X' ^ 'N') % 'M'. 
    // A ^ B is defined as A raised to power B 
    // and A % C is the remainder when A is divided by C.

    // Logic : using fast exponentiation 

    int x = 4, n = 3, m = 10;

    int ans = 1;

    while(n > 0) {
        if (n&1) {
            // odd case 
            ans = (1LL * ans * (x%m)) % m;
        }

        x = (1LL * (x%m) * (x%m)) % m;
        n = n >> 1;
    }

    cout << ans;
}

int main() {
    // Lecture 24 : Maths for DSA 
    // g++ lecture24.cpp -o main; ./main 

    // p1();

    // p2();
    
    // p3();

    return 0;
}
