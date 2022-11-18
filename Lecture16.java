
// javac Lecture16.java; java Lecture16

class Lecture16 {
    public static void main(String[] args) {
        // Lecture 16 : Selection sort
        p1();
    }

    public static void p1() {
        // Problem 1 : Selection sort

        // Statement : given an array of n integers
        // sort the array using Selection sort

        // Logic : Using Selection sort
        // traverse the array for (i = 0; i < arr_size;)
        // run another for loop for (j = i+1; j < arr_size)
        // in i+1; to j < arr_size find the minimum element and swap that element with i
        // This is a stable sorting algorithm 

        int arr[] = { 29, 72, 98, 13, 87, 66, 52, 51, 36 };

        // printing array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();

        for (int i = 0; i < arr.length; i++) {
            if (i == arr.length - 1) {
                break;
            }

            int min = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }

            // Swaping
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }

        // printing array
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();
    }
}
