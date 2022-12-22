#include <iostream>  // input output stream
#include <array>     // to use Array
#include <vector>    // to use Vector
#include <deque>     // to use Deque
#include <list>      // to use list
#include <stack>     // to use Stack
#include <queue>     // to use Queue and also for priority queue
#include <set>       // to use Set
#include <map>       // to use Map
#include <algorithm> // to use Algorithms

using namespace std;

void p1() {
    // 1. Arrays : used to store similar types of elements
    // on contiguous memory location
    // it is dynamic
    // random access is possible

    // Basic Array 
    // Declaration
    // int basic[5];

    // adding elements
    // basic[0] = 12;
    // basic[2] = 61;

    // Declaration and Initialisation
    int basic[5] = {12, 45, 61, 5, 5};

    // Updating values
    basic[0] = 1200;

    // Accessing values
    int n = basic[0];
    cout << n;

    // STL Array 
    // Declaration
    // array<int, 5> stl_array;

    // Initialisation 
    // stl_array[0] = 12;
    // stl_array[1] = 45;

    // Declaration and Initialisation
    array<int, 5> stl_array = {12, 45, 61, 5, 5}; // static array, implemented with basic array

    // traversing STL array
    for (int i = 0; i < stl_array.size() /* returns size pf array */; i++) {
        // printing/accessing array elements
        // cout << stl_array[i] << " ";
        cout << stl_array.at(i) << " ";
    }
    cout << endl;

    // array methods and functions
    cout << "element at front in array is " << stl_array.front() << endl;
    cout << "element at back in array is " << stl_array.back() << endl;
}

void p2() {
    // 2. Vector : dynamic array used to store similar types of data on contiguous memory location
    // it is dynamic
    // random access is possible

    // declaration
    // vector<int> v;

    // adding elements/vector initialisation
    // v.push_back(5);
    // v.push_back(2);
    // v.push_back(3);

    // Declaration and Initialisation 
    vector<int> v{5, 2, 3};

    // vector functions
    cout << "size of vector : " << v.size() << " capacity of vector : " << v.capacity() << endl;

    // Accessing vector
    cout << "element at index 1 in vector is " << v.at(1) << endl;
    cout << "element at front in vector is " << v.front() << endl;
    cout << "element at back in vector is " << v.back() << endl;

    // removing last element in vector
    v.pop_back();
    cout << "size of vector : " << v.size() << " capacity of vector : " << v.capacity() << endl;

    v.shrink_to_fit();
    cout << "size of vector : " << v.size() << " capacity of vector : " << v.capacity() << endl;

    v.clear();
    cout << "size of vector : " << v.size() << " capacity of vector : " << v.capacity() << endl;

    // iterator of vector
    // v.begin();

    vector<int> v2(5, 1); // vector size is 5 and every element is assigned value 1

    // accessing values
    for (int i = 0; i < v2.size(); i++) {
        cout << v2.at(i) << " ";
    }
    cout << endl;

    // create a vector and copy all values from old vector
    vector<int> v3(v2); // copying values from v2

    // printing/accessing values
    for (int i = 0; i < v2.size(); i++) {
        cout << v3.at(i) << " ";
    }
    cout << endl;
}

void p3() {
    // 3. Deque : Doubly ended queue, can perform operation from both start and end side
    // deque does not store data in contiguous memory
    // it is dynamic
    // random access is possible

    // Declaring Deque
    // deque<int> d;

    // adding elements
    // d.push_back(1);
    // d.push_front(2);
    // d.push_front(5);
    // d.push_front(12);
    // d.push_front(3);

    // Declaration and Initialisation of Deque 
    // Method 1 : initializer list 
    // deque<int> d = {3, 12, 5, 2, 1};

    // Method 2 : uniform initialization
    deque<int> d {3, 12, 5, 2, 1};

    // accessing values
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    // removing last element
    d.pop_back();
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    // removing first element
    d.pop_front();
    for (int i = 0; i < d.size(); i++) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    // other functions
    cout << "front element in deque " << d.front() << endl;
    cout << "last element in deque " << d.back() << endl;
    cout << "deque size : " << d.size() << endl;

    // delete element in a range
    d.erase(d.begin(), d.begin() + 1);
    cout << "deque size : " << d.size() << endl;
}

void p4() {
    // 4. List : implements using doubly linked list,
    // direct access is not possible

    // declaration of list
    // list<int> l;

    // adding elements
    // l.push_back(1);
    // l.push_front(2);
    // l.push_front(2);

    // Declaration and Initialisation 
    list<int> l{1, 2, 2};

    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;

    // insert at the beginning of list ie at 0th index
    l.insert(l.begin(), 10);
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;

    // copy old list l into new list l_new
    list<int> l_new(l);

    // printing values 
    for (int i : l_new) {
        cout << i << " ";
    }
    cout << endl;

    // create another list with 10 elements with value 5
    list<int> l_new2(10, 5);
    for (int i : l_new2) {
        cout << i << " ";
    }
    cout << endl;
}

void p5() {
    // 5. Stack : every element is placed one above below, stack follows lifo(last in first out) concept

    // declaration of stack
    stack<string> s;

    s.push("first");
    s.push("second");
    s.push("third");

    cout << "Top element is : " << s.top() << endl; // last placed element is top element

    // removing element
    s.pop();

    cout << "Top element is : " << s.top() << endl; // after removing last element second last element will be top element

    // checking size of stack
    cout << "size of stack s is : " << s.size() << endl;
}

void p6() {
    // 6. queue : queue follows fifo(first in first out) principle

    // declaration of queue
    queue<int> q;

    // adding elements
    q.push(3);
    q.push(2);
    q.push(1);

    // printing first element of queue
    cout << "first element of queue is : " << q.front() << endl;

    // removing last element of queue
    q.pop();
    cout << "first element of queue is : " << q.front() << endl;

    // other methods are also same as other data structures
}

void p7() {
    // 7. priority queue : first element is always greatest,
    // there are two types of priority queue
    // max heap : this will always return max value
    // min heap : this will always return min value

    // declaration of max heap priority queue
    priority_queue<int> pq_max;

    // declaration of min heap priority queue
    priority_queue<int, vector<int>, greater<int>> pq_min;

    // adding element in priority queue
    pq_max.push(1);
    pq_max.push(5);
    pq_max.push(8);
    pq_max.push(3);

    // printing elements of max heap priority queue
    int n = pq_max.size();
    for (int i = 0; i < n; i++) {
        // accessing top value 
        cout << pq_max.top() << " ";
        // removing last value 
        pq_max.pop();
    }
    cout << endl;

    // adding element in priority queue
    pq_min.push(1);
    pq_min.push(5);
    pq_min.push(8);
    pq_min.push(3);

    // printing elements of min heap priority queue
    n = pq_min.size();
    for (int i = 0; i < n; i++) {
        // accessing top value 
        cout << pq_min.top() << " ";
        // removing top value 
        pq_min.pop();
    }
    cout << endl;
}

void p8() {
    // 8. Set : set contains only unique values
    // implemented using bst
    // elements cannot be modified
    // return in sorted order
    // but we can also use unordered set that is faster then ordered set

    // declaration of set
    set<int> s; // this is ordered set

    // adding elements in set
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(8);
    s.insert(8);
    s.insert(8);
    s.insert(3);

    // accessing sets elements
    for (auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    // s.erase(s.begin()+2);

    set<int>::iterator s_it = s.begin();
    s_it++;

    cout << "accessing element using iterator " << *s_it << endl;

    s.erase(s_it);
    for (auto i : s) {
        cout << i << " ";
    }
    cout << endl;

    // check if an element is present or not
    if (s.count(5)) {
        cout << "5 is present in set s" << endl;
    } else {
        cout << "5 is not present in set s" << endl;
    }

    if (s.count(-5)) {
        cout << "-5 is present in set s" << endl;
    } else {
        cout << "-5 is not present in set s" << endl;
    }

    // remove an element
    s.erase(s.find(5));
    for (auto i : s) {
        cout << i << " ";
    }
    cout << endl;
}

void p9() {
    // 9. Map : stores data in key value pairs
    // in map every key should be unique, values can be duplicates

    // declaration of map
    map<string, int> mp; // this is ordered map

    // adding elements in map
    mp["gamma"] = 3;
    mp["alpha"] = 1;
    mp["beta"] = 2;

    // another way to add elements in map 
    mp.insert({"delta", 4});

    // accessing elements of map
    for (auto i : mp) {
        cout << i.first << " : " << i.second << endl;
    }

    // finding key
    if (mp.count("beta")) {
        cout << "beta is available in map mp" << endl;
    } else {
        cout << "beta is not available in map mp" << endl;
    }

    if (mp.count("beta200")) {
        cout << "beta200 is available in map mp" << endl;
    } else {
        cout << "beta200 is not available in map mp" << endl;
    }

    // deleting map element
    mp.erase("alpha");
    for (auto i : mp) {
        cout << i.first << " : " << i.second << endl;
    }
}

void p10() {
    // 10. STL algorithms : built-in functions for sorting searching etc

    vector<int> v {5, 2, 9, 1, 0, 12, 7};

    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;

    // sort vector
    sort(v.begin(), v.end());

    // after sorting 
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;

    // searching element using binary search
    if (binary_search(v.begin(), v.end(), 5)) {
        cout << "5 is present in the vector v";
    } else {
        cout << "5 is not present in the vector v";
    }
    cout << endl;

    // finding lower and upper bound
    cout << "lower bound of 5 is : " << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;
    cout << "upper bound of 5 is : " << upper_bound(v.begin(), v.end(), 5) - v.begin() << endl;

    // finding max and min
    int max_i = max(5, 2);
    int min_i = min(5, 2);

    cout << "max is : " << max_i << endl
         << "min is : " << min_i << endl;

    swap(max_i, min_i);
    cout << "max is : " << max_i << endl
         << "min is : " << min_i << endl;

    string str = "abcde";
    reverse(str.begin(), str.end());
    cout << "reverse of abcd is : " << str << endl;

    // rotating vector
    rotate(v.begin(), v.begin() + 2, v.end());

    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    // sort vector
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

int main() {
    // Lecture 19 : c++ STL

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

    // to learn more about STL check below links :
    // - https://www.geeksforgeeks.org/cpp-stl-tutorial/ 
    // - https://takeuforward.org/c/c-stl-tutorial-most-frequent-used-stl-containers/ 

    return 0;
}
