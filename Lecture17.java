public class Lecture17 {
    public static void main(String[] args) {
        // Lecture 17 : Bubble sort 
        
        p1();
    }

    public static void p1() {
        // Problem 1 : Implement Bubble Sort

        // Statement : Given an array of N non negative integers
        // sort the array using Bubble Sort

        // Logic : Using Bubble Sort
        // in this algorithm we sort the array by sorting elements in pairs
        // This is a stable sorting algorithm

        // code :
        int arr[] = { 29, 72, 98, 13, 87, 66, 52, 51, 36 };

        // printing array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();

        // for all elements
        for (int i = 1; i < arr.length; i++) {
            Boolean hasSorted = false;
            for (int j = 0; j < arr.length - i; j++) {
                // take elements in pair compare them
                if (arr[j] > arr[j + 1]) {
                    // swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    hasSorted = true;
                }
            }
            if (!hasSorted) {
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
    }

    public static void p3() {
        // Problem 3 : is Bubble Sort stable algo or unstable 
        // a stable sorting algorithm doesnot change the sequence 
        // of similar type of elements that occured 
        
        // Solution : see Lecture17.js 
    }
}
