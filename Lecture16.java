
public class Lecture16 {
    public static void main(String[] args) {
        // Lecture 16 : Selection sort

        p1();
    }

    public static void p1() {
        // Problem 1 : Implement Selection sort

        // Statement : given an array of n integers
        // sort the array using Selection sort

        // Logic : Using Selection sort
        // in Selection sort we devide array into two parts
        // sorted part and unsorted part
        // initially in sorted part we hava 0 elements
        // and rest in unsorted part
        // then we traverse the array,
        // find minimum element
        // then place it at the end of sorted array

        int arr[] = { 29, 72, 98, 13, 87, 66, 52, 51, 36 };

        // printing array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();

        // sorting
        for (int i = 0; i < arr.length; i++) {
            // assuming minimum element index as i
            int index_min = i;

            // finding minimum element
            for (int j = i; j < arr.length; j++) {
                if (arr[j] < arr[index_min]) {
                    index_min = j;
                }
            }

            // swapping minimum element with arr[i]
            int temp = arr[i];
            arr[i] = arr[index_min];
            arr[index_min] = temp;
        }

        // printing array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();
    }
}
