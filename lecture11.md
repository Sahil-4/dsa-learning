# Lecture 11 : Time and Space Complexity

### Asymptotic analysis :

Evaluating the performance of an algorithm in terms of input size and how it changes according to the size of input

### Time Complexity :

Time taken by an algorithm is called Time Complexity.

### Space Complexity :

Space taken by an algorithm is called Space Complexity.

### Asymptotic Notations :

Mathematical notations used to analyse an algorithm

| Name      | Represented by | Usage                                      | Explanation                                          |
| --------- | -------------- | ------------------------------------------ | ---------------------------------------------------- |
| Big O     | O              | Used to show Upper bound of an algorithm   | Show the Maximum Time or Space taken by an algorithm |
| Big Omega | Ω              | used to show lower bound of an algorithm   | Show the Minimum Time or Space taken by an algorithm |
| Big Theta | Θ              | Used to show Average bound of an algorithm | Show the Average Time or Space taken by an algorithm |

### Some Complexities

| Term        | Represented by | Meaning                                                                                    | Graph                                                                                                                                                                         |
| ----------- | -------------- | ------------------------------------------------------------------------------------------ | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Constant    | O(1)           | Algorithm that has contant running time and takes same space even after changing the input | ![Constant](<https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2FO(1).jpg?alt=media&token=6f5c6733-6f91-4b8c-aefe-9627e20fa4c3>)         |
| Linear      | O(n)           | Algorithm that has runtime or space same as input size                                     | ![Linear](<https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2FO(n).jpg?alt=media&token=5c430aae-bcff-4305-add0-fa5d2cb9c2dc>)           |
| Logarithmic | O(log(n))      | Algorithm that has runtime or space logarithm of input size                                | ![Logarithmic](<https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2FO(log(n)).jpg?alt=media&token=6b82210c-8376-44fa-ac3e-6d178c93474f>) |
| Loglinear   | O(n\*log(n))   | Algorithm that has runtime or space n times of logarithm of input size                     | ![Loglinear](<https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2Fo(n_log(n)).jpg?alt=media&token=500cbd1d-5f66-4e03-bef1-f9182026783d>) |
| Quadratic   | O(n^2)         | Algorithm that has runtime or space quadratic of its input size                            | ![Quadratic](<https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2FO(n%5E2).jpg?alt=media&token=8ef3845f-8ce8-4af0-8098-70e81c35a056>)    |
| Cubic       | O(n^3)         | Algorithm that has runtime or space cubic of its input size                                | ![Cubic](<https://firebasestorage.googleapis.com/v0/b/storage4otherprojs.appspot.com/o/dsa-notes%2FO(n%5E3).jpg?alt=media&token=03fd7c68-6ce2-4f70-899e-190b5885d907>)        |

### Questions and Solutions

1. F(n) = 2n^2 + 3n
   => O(n^2)

2. F(n) = 4n^4 + 3n^3
   => O(n^4)

3. F(n) = n^2 + log(n)
   => O(n^2)

4. F(n) = 12001
   => O(1)

5. F(n) = 3n^3 + 2n^2 + 5
   => O(n^3)

6. F(n) = (n^3)/300
   => O(n^3)

7. F(n) = 5n^2 + log(n)
   => O(n^2)

8. F(n) = n/4
   => O(n)

9. F(n) = (n+4)/4
   => O(n)

10. F(n) = log(n)\*n + n + 12
    => O(n\*log(n))

### Find the time complexity of below programs

1.

```c
int a = 0, b = 0; // --------------------- O(1)

for (int i = 0; i < n; i++) { // --------- O(n)
    a = a + random(); // ----------------- O(1)
}

for (int j = 0; j < n; j++) { // --------- O(n)
    b = b + random(); // ----------------- O(1)
}

```

Time complexity :

F(n) = 1 + (n\*1) + (n\*1)
=> 1 + n + n
=> O(n)

2.

```c
int a = 0, b = 0; // ------------------------ O(1)

for (int i = 0; i < n; i++) { // ------------ O(n)
    for (int j = 0; j < n; j++) { // -------- O(n)
        a = a + i; // ----------------------- O(1)
    }
}

for (int k = 0; k < n; k++) { // ------------ O(n)
    b = b + k;// ---------------------------- O(1)
}

```

Time complexity :

F(n) = 1 + (n\*n\*1) + (n\*1)
=> 1 + n^2 + n
=> O(n^2)

3.

```c
int a = 0; // ------------------------------- O(1)

for (int i = 0; i < n; i++) { // ------------ O(n)
    for (int j = n; j > i; j--) { // -------- O(n)
        a = a + i + j; // ------------------- O(1)
    }
}

```

Time complexity :

F(n) = 1 + (n\*n\*1)
=> 1 + n^2
=> O(n^2)

### Find the space complexity of below programs

1.

```c
int a = 0, b = 0; // ------------ O(1)

for (int i = 0; i < n; i++) {
   a = a + random();
}

for (int j = 0; j < n; j++) {
   b = b + random();
}

```

Space complexity :

F(n) = 1
=> O(1)

2.

```c
int a = 0, b = 0; // ------------ O(1)

for (int i = 0; i < n; i++) {
   int arr[n]; // --------------- O(n)
}

```

Space complexity :

F(n) = 1 + n
=> O(n)

### TLE and How to avoid it

TLE stands for Time Limit Exceed, this happens when a algorithm try to process more then the limit set by online judges or server.
To avoid TLE we can optimize the algorithm by reducing processes made by the algorithm.

### Max Time Complexity on the basis of input size

| Input size | Time Complexity (Max)    |
| ---------- | ------------------------ |
|            |                          |
| 10^9       | O(logN) or Sqrt(N)       |
| 10^8       | O(N) (Border case)       |
| 10^7       | O(N) (Might be accepted) |
| 10^6       | O(N) (Perfect)           |
| 10^5       | O(N \* logN)             |
| 10^4       | O(N ^ 2)                 |
| 10^2       | O(N ^ 3)                 |
| <= 160     | O(N ^ 4)                 |
| <= 18      | O(2N\*N2)                |
| <= 10      | O(N!), O(2N)             |

We should always be within the upper bound and make algorithm accordingly

#### To know more about Time complexity of different Algorithms and Data Structurres check out below links :

1. https://www.bigocheatsheet.com/
2. https://www.hackerearth.com/practice/notes/big-o-cheatsheet-series-data-structures-and-algorithms-with-thier-complexities-1/
