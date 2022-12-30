#include <iostream>
#include <vector>

using namespace std;

void p1() {
    // Problem 1 : 204. Count Primes - https://leetcode.com/problems/count-primes/ 

    // Statement : Given an integer n, 
    // return the number of prime numbers that are strictly less than n.

    // logic : using sieve of eratosthenes 
    // take a array/vector primes[] of bool of size n+1
    // mark all elements true in primes 
    // mark false to 0th and 1st index of prime 
    // run a loop from i = 2 to i < n 
    // check if primes[i] is true or false 
    // if true it means primes[i] is a prime number 
    // next except i mark false to all the indexes that can be devisible by i till n 
    // after this go to next index 
    // at the end primt all the indexes from i to n that are true in primes 

    int n = 40;

    // count all prime numbers less then n 
    int count = 0;
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i < n; i++) {
        // check prime 
        if (primes[i]) {
            // update count if ith number is prime 
            count++;

            // false all numbers that are divisible by ith number 
            for (int j = i+i; j < n; j += i) {
                primes[j] = false;
            }
        }
    }

    cout << count << " prime numbers" << endl;

    // printing all prime numbers 
    for (int i = 2; i < n; i++) {
        if (primes[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void p2() {
    // Problem 2 : GCD 

    // logic : using Euclids algorithm 
    // gcd(a, b) = gcd(a-b, b) or gcd(a%b, b) 
    // check if any a or b is zero 
    // if a is zero return b as answer 
    // else return b 
    // if no one is zero 
    // run a loop while n != m 
    // and perform max(a, b) = max(a, b) - min(a, b);
    // at the end return a or b as answer 

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
    // a^b = (a^(b/2))^2 
    // first initialise ans = 1 
    // run a loop till n > 0 
    // check if n is odd or even 
    // if n is odd answer = (answer * (x%m)) % m 
    // else only update x = ((x%m) * (x%m)) % m 
    // right shift n 1 time 
    // in the end print answer 

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

    // p1();

    // p2();
    
    // p3();

    return 0;
}