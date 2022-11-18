#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void p1() {
    // sum of all elements in the array 
    int arr[12] = {1, 5, 7, 12, 4, 3, 0, 5, 7, 45, 10, 11};
    int size = 12, sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("%d\n", sum);
}

int main() {
    p1();

    return 0;
}