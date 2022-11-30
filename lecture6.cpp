#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void p1() {
    // P1 : convert to binary 

    // Statement : given int n 
    // return binary form of n 

    int n = 12; // output : 1100 
    n = 5; // out : 101 
    n = 6; // out : 110 
    n = 0; // out : 0 
    n = 1; // out : 1 
    n = 3; // out : 11 
    n = 100; // out : 1100100 
    // n = 1000; // out : 1111101000 
    // n = 1200; // out : 10010110000 

    uint32_t bin = 0;
    int i = 1;

    // devide method 
    // while (n >= 1) {
    //     int bit = n&1;
    //     bin = (bit * i) + bin;
    //     n /=2;
    //     i *= 10;
    // }

    // using bit manupilation 
    while (n != 0) {
        int bit = n&1;
        bin = (bit * i) + bin; // i = 10^x 
        n = n>>1;
        i *= 10;
    }

    printf("%d", bin);
}

void p2() {
    // P2 : convert to Decimal 

    // Statement : given binary form as int n 
    // return decimal form of n 

    uint32_t n = 1100100; // out : 100 
    n = 101; // out : 5 
    n = 111; // out : 7 
    n = 1111; // out : 15 
    n = 10000; // out : 16 
    n = 100000; // out : 32 
    n = 1000000; // out : 64 
    n = 1000000000; // out : 512 

    int i = 1;
    int dec = 0;

    while (n > 0) {
        int bit = n%10;
        dec += bit*i;

        i *= 2;
        n /= 10;
    }

    cout << dec;
}

void p3() {
    // P3 : Convert negative integer to binary 

    // Statement : given an negative integer n 
    // convert n to binary 

    int n = -5; // 11111011 
    uint32_t bin = 0;

    n *= -1; // ignore negative sign 

    // convert n to binary 
    vector<int> bits(8);
    int s = 8;
    while (n != 0) {
        bits.at(--s) = n&1; 
        n = n>>1;
    }

    // 2's Compliment 
    // first finding 1s compliment 
    for (int i = 0; i < bits.size(); i++) {
        bits.at(i) = !bits[i];
    }

    // adding 1 
    for (int i = bits.size()-1; i >= 0; i--) {
        if (bits.at(i) == 0) {
            bits.at(i) = 1;
            break;
        }
    }

    // printing answer 
    for (int i = 0; i < bits.size(); i++) {
        cout << bits.at(i);
    }
    cout << endl;
}

void p4() {
    // convert binary to negative integer 

    long long bin = 11111011; // out : -5 

    vector<int> bits(8);
    int n = 8;

    // adding bits to vector 
    while (bin > 0) {
        bits.at(--n) = bin%10;
        bin /= 10;
    }

    // minus 1 
    for (int i = bits.size()-1; i >= 0; i--) {
        if (bits.at(i) == 1) {
            bits.at(i) = 0;
            break;
        }
    }

    // flip all bits 
    for (int i = 0; i < bits.size(); i++) {
        bits.at(i) = !bits[i];
    }

    // make final answer 
    long long ans = 0;
    int p = 1;
    for (int i = bits.size()-1; i >= 0; i--) {
        ans += bits[i] * p;
        p *= 2;
    }

    ans *= -1;
    cout << ans;
}

int main() {
    // Lecture 6 : Binary Decinal conversion  

    // p1();

    // p2();

    // p3();

    p4();

    return 0;
}
