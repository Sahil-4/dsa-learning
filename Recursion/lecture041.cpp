#include <iostream>

using namespace std;


void p1() {
    // Time and space complexity recap

    // Time complexity analysis : determining time taken by an algorithm
    // on the basis on its input size

    // Space complexity analysis : determining space taken by an algorithm
    // on the basis on its input size

    // below is the algotithm to find key in arr[]
    int arr[] = {1, 5, 13, 15, 17, 21, 32, 42, 55};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 13;

    // searching key
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found";
            break;
        }
    }

    // in above algorithm
    // Time complexity :
    // T(n) = 1 * n
    // = n
    // T(n) = O(n)

    // Space complexity :
    // T(n) = 1
    // T(n) = O(1)
}

int factorial(int n) {
    // for p2()
    if (n == 0) {
        return 1; // O(1)
    }

    return n * factorial(n - 1); // O(1 * T(n-1))

    // Time -> T(n) = O(n)

    // Space -> T(n) = O(n)
    // because factorial(int n) will be get stored in stack
}

void p2() {
    // Problem 1 : find the time complexity of function factorial(int n) -> int

    // Method :
    // find the recursive relation of given program
    // devide program/algorithm into components
    // and find the time complexity of each components
    // make a equation with all
    // then solve it

    // Solution :
    // recursive relation of factorial(int n) -> int
    // F(n) = n * F(n-1)
    // time complexity of base case
    // T(n) = K1
    // time complexity of return statement
    // T(n) = K1 + K2
    // time complexity for function call
    // T(n) = K1 + K2 + T(n-1)
    // T(n) = K + T(n-1)
    // T(n-1) = K + T(n-2)
    // T(n-2) = K + T(n-3)
    // T(1) = K + T(0)
    // T(0) = K1
    // After adding them up
    // T(n) = K + T(n-1) + (T(n-1) = K + T(n-2)) + (T(n-2) = K + T(n-3)) + (T(1) = K + T(0)) + (T(0) = K1)
    // T(n) = K + T(n-1) + (-(T(n-1)) + K + T(n-2)) + (-(T(n-2)) + K + T(n-3)) + (-(T(1)) + K + T(0)) + (-(T(0)) + K1)
    // T(n) = K + T(n-1) - (T(n-1)) + K + T(n-2) - (T(n-2)) + K + T(n-3) - (T(1)) + K + T(0) - (T(0)) + K1
    // T(n) = K + (T(n-1) - T(n-1)) + K + (T(n-2) - T(n-2)) + K + (T(n-3) - T(1)) + K + (T(0) - T(0)) + K1
    // T(n) = K + K + K + K + K1
    // T(n) = (K + K + K + K) + K1
    // T(n) = (K)*n + K1
    // T(n) = (K)*n
    // T(n) = n
    // T(n) = O(n)

    // Time complexity for factorial() function is O(n)
}

int binary_search(int *arr, int key, int l, int h) {
    // for p3()

    if (l > h) {
        return -1;
    }

    int mid = l + (h - l) / 2;

    if (arr[mid] == key) {
        return mid;
    }

    if (arr[mid] > key) {
        h = mid - 1;
    } else {
        l = mid + 1;
    }

    return binary_search(arr, key, l, h);

    // Time : T(n) = O(log(n))
    // Space : T(n) = log(n)
}

void p3() {
    // Problem 2 : find the time complexity for binary_search(int *arr, int key, int l, int h) -> int

    // Method :
    // find the recursive relation of given program
    // devide program/algorithm into components
    // and find the time complexity of each components
    // make a equation with all
    // then solve it

    // Solution :
    // recursive relation of binary_search(int *arr, int key, int l, int h) -> int
    // F(n) = K + F(n/2)
    // Time complexity till base case
    // T(n) = K1
    // Time complexity till calculating mid
    // T(n) = K1 + K2
    // Time complexity till all the comparisons and updating low or high
    // T(n) = K1 + K2 + K3
    // Time complexity till return statement
    // T(n) = K1 + K2 + K3 + T(n/2)
    // time complexity for function call to end
    // T(n) = K + T(n/2)
    // T(n/2) = K + T(n/4)
    // T(n/4) = K + T(n/8)
    // T(2) = K + T(1)
    // T(1) = K
    // on adding them up
    // T(n) = K + T(n/2) + (T(n/2) = K + T(n/4)) + (T(n/4) = K + T(n/8)) + (T(2) = K + T(1)) + (T(1) = K)
    // T(n) = K + T(n/2) + (-T(n/2) + K + T(n/4)) + (-T(n/4) + K + T(n/8)) + (-T(2) + K + T(1)) + (-T(1) + K)
    // T(n) = K + T(n/2) -T(n/2) + K + T(n/4) -T(n/4) + K + T(n/8) -T(2) + K + T(1) -T(1) + K
    // T(n) = K + (T(n/2) - T(n/2)) + K + (T(n/4) - T(n/4)) + K + (T(n/8) - T(2)) + K + (T(1) - T(1)) + K
    // T(n) = K + K + K + K + K
    // T(n) = (K + K + K + K + K)
    // T(n) = (K)*a
    // a = n -> n/2 -> n/4 -> 4 -> 2 -> 1
    // a = log(n)
    // T(n) = (K) * log(n)
    // T(n) = O(log(n))
}

void merge(int *arr, int l, int h) {
    // for mergesort(int *arr, int l, int h)
    int mid = l + (h - l) / 2;

    int arr_1_len = mid - l + 1;
    int arr_2_len = h - mid;

    int *arr_1 = new int[arr_1_len]; // dynamic array
    int *arr_2 = new int[arr_2_len];

    // copy left part value in arr_1
    int k = l; // starting index
    for (int i = 0; i < arr_1_len; i++) {
        arr_1[i] = arr[k++];
    }

    // copy right part value in arr_2
    k = mid + 1; // starting index
    for (int i = 0; i < arr_2_len; i++) {
        arr_2[i] = arr[k++];
    }

    // merge both array
    int i = 0; // for left array
    int j = 0; // for right array
    int x = l; // for main array
    while (i < arr_1_len && j < arr_2_len) {
        if (arr_1[i] <= arr_2[j]) {
            arr[x++] = arr_1[i++];
        } else {
            arr[x++] = arr_2[j++];
        }
    }

    // merge rest elements
    // for left array
    while (i < arr_1_len) {
        arr[x++] = arr_1[i++];
    }

    // for right array
    while (j < arr_2_len) {
        arr[x++] = arr_2[j++];
    }

    delete arr_1;
    delete arr_1;

    // T(n) = O(n)
}

void mergesort(int *arr, int l, int h) {
    // for p4()
    if (l >= h)
        return;

    int mid = l + (h - l) / 2;

    // sort left part
    mergesort(arr, l, mid);

    // sort right part
    mergesort(arr, mid + 1, h);

    // merge both left part and right part
    merge(arr, l, h);

    // Time : T(n) = O(n*log(n))
    // Space : T(n) = O(n)
}

void p4() {
    // Problem 3 : find the time complexity of merge sort algorithm/function

    // Solution :
    // deviding into components and creating equation by
    // calculating all the time complexities
    // T(n) = K1 + K2 + T(n/2) + T(n/2) + K3*n + K4*4
    // T(n) = (K1 + K2) + (T(n/2) + T(n/2)) + (K3*n + K4*n)
    // T(n) = K + 2T(n/2) + n(K3 + K4)
    // T(n) = K + 2T(n/2) + n*K5
    // Equation
    // T(n) = 2T(n/2) + n*K5
    // T(n) = 2T(n/2) + n*K
    // 2[T(n/2) = 2T(n/4) + (n/2)*K] = 4T(n/4) + nK
    // 4[T(n/4) = 2T(n/8) + (n/4)*K] = 8T(n/8) + nK
    // [T(1) = K]
    // adding them up
    // T(n) = 2T(n/2) + nK + (2T(n/2) = 4T(n/4) + nK) + (4T(n/4) = 8T(n/8) + nK) + (T(1) = K)
    // T(n) = 2T(n/2) + nK -2T(n/2) + 4T(n/4) + nK - 4T(n/4) + 8T(n/8) + nK - T(1) + K
    // T(n) = nK + (2T(n/2) - 2T(n/2)) + nK + (4T(n/4) - 4T(n/4)) + nK + (8T(n/8) - T(1)) + K
    // T(n) = nK + nK + nK + mK
    // T(n) = (nK)*x
    // x is height of tree which is log(n)
    // so T(n) = (nK)*log(n)
    // T(n) = O(n*log(n))
}

int fibbonacci(int n) {
    // for p5()
    if (n == 1 || n == 0) {
        return n;
    }

    // rr
    return fibbonacci(n - 1) + fibbonacci(n - 2);

    // Time : T(n) = O(2^n)
    // Space : T(n) = O(n)
}

void p5() {
    // Problem 4 : find the time complexity of fibbonacci(int n) -> int

    // Solution :
    // using recursion tree
    // equation
    // T(n) = 2^0 + 2^1 + 2^2 + 2^n
    // where n is height of tree
    // T(n) = 2^n-1
    // T(n) = O(2^n)
}

void p6() {
    // Problem 5 : find the space complexity of function factorial(int n) -> int

    // Method :
    // devide algorithm/function into components
    // find space allocated by each component then sum them up

    // Solution :
    // in case of factorial(int n) -> int
    // its been called recursively
    // so it will get stored in stack
    // till return
    // T(n) = k*n
    // T(n) = O(n)
}

void p7() {
    // Problem 6 : find the space complexity of binary_search(int *arr, int key, int l, int h) -> int

    // Solution :
    // equation T(n) = (k * n) + (n/2) + (n/3) + (n/4) + (k * 2) + (k * 1)
    // T(n) = k * (n + n/2 + n/3 + n/4 + 2 + 1)
    // T(n) = k * (log(n))
    // T(n) = log(n)
}

void p8() {
    // Problem 7 : find the space complexity of mergesort(int *arr, int l, int h) algorithm/function

    // Solution :
    // equation T(n) = n + n/2 + n/4 + 2 + 1
    // T(n) = n
    // T(n) = O(n)
}

void p9() {
    // Problem 4 : find the space complexity of fibbonacci(int n) -> int

    // Solution :
    // equation T(n) = k * n, n is depth of recursion calls
    // T(n) = O(n)
}

int main() {
    // Lecture 41 : Time and space complexity

    // p1();

    // p2();

    // p3();

    // p4();

    // p5();

    // p6();

    // p7();

    // p8();

    // p9();

    // To learn more about time and space complexity refer below :
    // - https://www.codingninjas.com/codestudio/guided-paths/competitive-programming/content/126222/offering/1476042

    return 0;
}
