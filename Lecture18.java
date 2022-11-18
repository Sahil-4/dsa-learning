public class Lecture18 {
    public static void main(String[] args) {
        // Lecture 18 : Insertion sort 
        
        p1();
    }

    public static void p1() {
        // Problem 1 : Implement insertion sort

        // statement given an array of n integers
        // sort the array using insertion sort

        // Logic

        // Code :
        int arr[] = { 29, 72, 98, 13, 87, 66, 52, 51, 36 };

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println();

        for (int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            int j = 0;
            for (j = i - 1; j >= 0; j--) {
                if (arr[j] > temp) {
                    arr[j + 1] = arr[j];
                } else {
                    break;
                }
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
