
public class Lecture17 {
    public static void main(String[] args) {
        // Lecture 17 : Bubble sort

        p1();
    }

    public static void p1() {
        // Problem 1 : Implement Bubble Sort

        // Statement : Given an array of N non negative integers
        // sort the array using Bubble Sort

        // Logic : Using Bubble Sort - UN-Optimised
        // in this algorithm we sort the array by sorting elements in pairs
        // traverse the array from i = 0 to i < n
        // take elements in pair arr[i], arr[i+1]
        // compare them and arrange in right order
        // after that increament i by 1
        // and again compare arr[i], arr[i+1]
        // and arrange them into right order
        // after completion we will have our last element at its right position
        // we have to perform this task for n-1 time

        // code :
        int arr[] = { 29, 72, 98, 13, 87, 66, 52, 51, 36 };

        // printing array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();

        // sorting the arr in accending order
        for (int i = 1; i < arr.length; i++) {
            // optimised bubble sort
            Boolean hasSorted = false;

            for (int j = 0; j < arr.length - i; j++) {
                // take elements in pair compare them
                // and arrange them into right order
                if (arr[j] > arr[j + 1]) {
                    // swapping elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    hasSorted = true;
                }
            }

            // check if swapping has not done
            if (!hasSorted) {
                // if swapping done
                // them it means all elements are at their right position
                break;
            }
        }

        // printing array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();
    }

    public static void p2() {
        // Problem 2 : What is inplace sort

        // answer : any sorting algorithm that sorts the array or any other object
        // without using any extra space
        // though using a small amount of constant space for variables is allowed
        // is called inplace sort
    }

    public static void p3() {
        // Problem 3 : is Bubble Sort stable algo or unstable

        // NOTE : a stable sorting algorithm does not change the sequence
        // of similar type of elements that occured in the array

        // Solution : see Lecture17.js
    }
}
