#include <iostream>

using namespace std;

void p1() {
    // p1 : Allocation of memory for 2d array 

    // dynamically allocating memory for storing n integers 
    // int *arr = new int[n]; // this can hold n integers 

    // but what about 2d arrays 
    // till now, creation of 2d arrays :
    // int arr2d[n][m] = {{}, {}}; // this can hold n arrays, and that n arrays can hold m integers 
    // but this has a problem we cannot use this for variable size array 

    // to make a 2d array of variable size 
    // we have to use dynamic memory allocation 

    // method 1 : 
    // as we know the working of 2d arrays we can use that method 
    // first we take input n and m 
    // then create a 1d dynamic array 
    // then we will use n and m relation (n * m + n) to access the values 

    // Method 2 : 

    // when we do below :
    // int *arr = new int[n];
    // it gives us a pointer arr and some memory in Heap to store n integers 

    // now we have to create a 2d dynamic array, 
    // means we have to create another pointer 
    // to store above pointer 

    // simply we have to create a double pointer 
    // which stores pointers 
    // and those pointers will store values 

    // create an integer array to store n integers 
    // int *arr_1d = new int[n];

    // create another double pointer which store above m pointer 
    // int **arr_2d = new int*[m];

    // now arr_2d will store m numbers of arr_1d 
    // and arr_1d will store n number of integers 
}

void p2() {
    // p2 : Initialising dynamically created 2d array 

    // taking input of size of 2d array 
    int n, m;
    cout << "Enter number of rows and columns : ";
    cin >> m >> n;

    // creating dynamic 2d array 
    int **arr_2d = new int*[m]; // this will allocate memory for m pointers 

    // allocate memory for storing n integers 
    for (int i = 0; i < m; i++) {
        arr_2d[i] = new int[n];
    }

    // till we have created a dynamic 2d array 
    
    // taking inputs in this array 
    int x = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr_2d[i][j] = x++;
        }
    }

    // output of this array 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr_2d[i][j] << " ";
        }
        cout << endl;
    }

    // in the sane way we can also create other multi-dimentional arrays 

    // VERY IMPORTANT : Releasing memory 
    // we have to first release all 1d arrays 
    // else if we first release 2d arrays that store our 1d array 
    // we will lost access of our all 1d arrays 
    // so this is why we should always release memory from top to bottom (first 2d then 1d)

    // releasing memory 
    for (int i = 0; i < m; i++) {
        delete[] arr_2d[i];
    }

    delete []arr_2d;
}

void p3() {
    // p3 : create jagged array using dynamic memory 

    // Jagged array : array of arrays of different sizes
    /*
        example : 
        [
            [1, 2, 3, 5, 80],
            [1, 0],
            [1, 2, 7, 5],
            [1, 2, 5, 8, 12, 1, 0, 0, 5],
            [0]
        ]
    */

    // Logic : 
    // first create 2 variables 
    // one for row size and second for column 
    // take input of row size 
    // now create a 2d array of row size dynamically 
    // then create another dynamic array columns_size to store column size 
    // then run a loop from i = 0 to i < row_size 
    // take input of column size 
    // add column size in array columns_size at ith index 
    // and create array accordingly 
    // after initialising array 
    // run a loop from i = 0 to i < row size 
    // and traverse the 2d loop 
    // and then run a loop from j = 0 to j < columns_size[i] 
    // inside this take input for jth column of ith row 
    // just like taking input print the output 

    // Code : 
    int m, n;

    // taking input of row size 
    cout << "Enter number of rows : ";
    cin >> m;

    // creating dynamic 2d array 
    int **arr_2d = new int*[m]; // this will allocate memory for m pointers 

    // creating another array to store number of columns 
    int *cols_arr = new int[m];

    // allocate memory for storing n integers 
    for (int i = 0; i < m; i++) {
        cout << "Enter number of columns in "<< i << " array : ";
        cin >> n;
        *(cols_arr+i) = n;
        arr_2d[i] = new int[n];
    }

    // till now, we have initialised the array 

    // taking inputs in array 
    for (int i = 0; i < m; i++) {
        cout << "Enter values for column " << i << endl;
        for (int j = 0; j < *(cols_arr+i); j++) {
            cin >> arr_2d[i][j];
        }
    }

    // output 
    for (int i = 0; i < m; i++) {
        cout << "values in column " << i << endl;
        for (int j = 0; j < *(cols_arr+i); j++) {
            cout << arr_2d[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Lecture 29 : Dynamic memory allocation

    // p1();
    
    // p2();

    // p3();

    return 0;
}

