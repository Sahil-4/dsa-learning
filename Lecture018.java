
public class Lecture18 {
    public static void main(String[] args) {
        // Lecture 18 : Insertion sort

        p1();
    }

    public static void p1() {
        // Problem 1 : Implement insertion sort

        // statement given an array of n integers
        // sort the array using insertion sort

        // Logic :
        // in insertion sort,
        // we devide array into two parts
        // sorted part and unsorted part
        // initially we have one element arr[0] in the sorted part
        // and rest in unsorted part
        // we take elements one by one from unsorted part of array
        // and place that element at its right position into sorted part

        // Code :
        int arr[] = { 29, 72, 98, 13, 87, 66, 52, 51, 36 };

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();

        // insertion sort algorithm
        for (int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            int j = i - 1;

            // swapping arr[j+1] with arr[j]
            while (j >= 0 && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = temp;
        }

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();
    }
}
